#include "samd10c14a.h"
#include "ASCII.h"

#define LED_PIN 5

#define CLOCK           4
#define MOSI            2
#define DATA_COMMAND    24
#define CHIP_SELECT     8
#define RESET           25

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ROWS 8

uint8_t buffer[SCREEN_WIDTH * SCREEN_ROWS];

void delay(uint16_t n)
{
    uint8_t i;

    for (;n >0; n--)
    {
        for (i=0;i<100;i++)
            __asm("nop");
    }
}

void shift_out(uint8_t data)
{
    for (uint8_t i=0; i < 8; i++)
    {
        if ( data & (1 << (7 - i)) )
        {
            REG_PORT_OUT0 |= 1 << MOSI;
        }
        else
        {
            REG_PORT_OUT0 &= ~(1 << MOSI);
        }

        REG_PORT_OUT0 |= 1 << CLOCK;      // HIGH
        REG_PORT_OUT0 &= ~(1 << CLOCK);   // LOW
    }
}

void initialise_oled(void)
{
    REG_PORT_OUT0 &= ~(1 << CHIP_SELECT);                // LOW (Enabled)

    REG_PORT_OUT0 |= 1 << RESET;          // HIGH
    delay(10);
    REG_PORT_OUT0 &= ~(1 << RESET);       // LOW
    delay(10);
    REG_PORT_OUT0 |= 1 << RESET;          // HIGH
    delay(10);

    REG_PORT_OUT0 &= ~(1 << DATA_COMMAND);        // LOW (Command Mode)

    shift_out(0xAE);         // DISPLAYOFF

    shift_out(0xD5);         // SETDISPLAYCLOCKDIV
    shift_out(0x80);         // the suggested ratio 0x80

    shift_out(0xA8 );        // SSD1306_SETMULTIPLEX
    shift_out(SCREEN_HEIGHT - 1);

    shift_out(0xD3 );        // SETDISPLAYOFFSET
    shift_out(0x0);          // no offset
    shift_out(0x40  | 0x0);  // SETSTARTLINE line #0

    shift_out(0x8D);        // CHARGEPUMP
    shift_out(0x14);         // Not External Vcc

    shift_out(0x20 );        // MEMORYMODE
    shift_out(0x00);         // 0x0 act like ks0108
    shift_out(0xA0  | 0x1);  // SEGREMAP
    shift_out(0xC8 );        // COMSCANDEC


    shift_out(0xDA);        // SETCOMPINS
    shift_out(0x12);

    shift_out(0x81 );        // SETCONTRAST
    shift_out(0xCF);         // Not External Vcc


    shift_out(0xD9 );        // SETPRECHARGE
    shift_out(0xF1);         // Not External Vcc

    shift_out(0xDB);        // SETVCOMDETECT
    shift_out(0x40);

    shift_out(0xA4 );        // DISPLAYALLON_RESUME
    shift_out(0xA6 );        // NORMALDISPLAY

    //shift_out(0x2E );        // DEACTIVATE_SCROLL

    shift_out(0xAF);         // DISPLAYON

    REG_PORT_OUT0 |= 1 << DATA_COMMAND;      // Data Mode
}

void clear_buffer(void)
{
    for (uint16_t i=0 ; i<SCREEN_WIDTH*SCREEN_ROWS ; i++)
        buffer[i] = 0x00;
}

void draw( void )
{
    for (uint16_t i=0 ; i<SCREEN_WIDTH*SCREEN_ROWS ; i++)
        shift_out(buffer[i]);
}

void draw_tile(const uint8_t *tile, int16_t x, int16_t y)
{
    /* is the tile actually visible */
    if (x < -7 || x >= SCREEN_WIDTH || y < -7 || y >= SCREEN_HEIGHT)
        return;

    int16_t y_ = y;

    if (y < 0)
        y_ = 0-y;

    int16_t tile_start = ((y_ >> 3) * SCREEN_WIDTH) + x;

    uint8_t y_offset_a = y & 7; // y % 8
    uint8_t y_offset_b = 8-y_offset_a;

    uint8_t tile_index = 0;
    int8_t tile_dir = 1;
    uint8_t tile_width = 8;
    if (x < 0)
    {
        tile_start -= x;
        tile_index = 0-x;
        tile_width -= tile_index;
    }

    if (x > SCREEN_WIDTH-8)
    {
        tile_width = SCREEN_WIDTH-x;
    }

    if (y < 0)
    {
        y_offset_a = 8;
        y_offset_b = 0-y;
        tile_start -= SCREEN_WIDTH;
    }

    if (y > SCREEN_HEIGHT-8)
    {
        y_offset_b = 8;
    }

    for(uint8_t tile_offset=0 ; tile_offset<tile_width ; tile_offset++, tile_index+=tile_dir)
    {
        if (y_offset_a < 8)
        {
            buffer[tile_start+tile_offset] = tile[tile_index] << y_offset_a;
        }
        if (y_offset_b < 8)
        {
            buffer[tile_start+SCREEN_WIDTH+tile_offset] = tile[tile_index] >> y_offset_b;
        }
    }
}

void draw_int(int16_t n, uint8_t width, int16_t x, int16_t y)
{
    //TODO: Negative numbers
    int32_t n_;
    for (uint8_t i=0 ; i<width ; i++)
    {
        n_ = (6554*(int32_t)n)>>16;
        draw_tile(&DIGITS[(n - (n_*10))*8], x+((width-i-1)*8), y);
        n = (int16_t)n_;
    }
}

//https://electronics.stackexchange.com/questions/332569/how-to-configure-atmel-sam-d20-for-internal-48mhz-clock-source
void set_clock()
{
    // Change the timing of the NVM access
    NVMCTRL->CTRLB.bit.RWS = NVMCTRL_CTRLB_RWS_HALF_Val; // 1 wait state for operating at 2.7-3.3V at 48MHz.

    // Enable the bus clock for the clock system.
    PM->APBAMASK.bit.GCLK_ = 1; //true;

    // Initialise the DFLL to run in closed-loop mode at 48MHz
    // 1. Make a software reset of the clock system.
    GCLK->CTRL.bit.SWRST = 1; //true;
    while (GCLK->CTRL.bit.SWRST && GCLK->STATUS.bit.SYNCBUSY) {};
    // 2. Make sure the OCM8M keeps running.
    SYSCTRL->OSC8M.bit.ONDEMAND = 0;
    // 3. Set the division factor to 64, which reduces the 1MHz source to 15.625kHz
    GCLK->GENDIV.reg =
        GCLK_GENDIV_ID(3) | // Select generator 3
        GCLK_GENDIV_DIV(64); // Set the division factor to 64
    // 4. Create generic clock generator 3 for the 15KHz signal of the DFLL
    GCLK->GENCTRL.reg =
        GCLK_GENCTRL_ID(3) | // Select generator 3
        GCLK_GENCTRL_SRC_OSC8M | // Select source OSC8M
        GCLK_GENCTRL_GENEN; // Enable this generic clock generator
    while (GCLK->STATUS.bit.SYNCBUSY) {}; // Wait for synchronization
    // 5. Configure DFLL with the
    GCLK->CLKCTRL.reg =
        GCLK_CLKCTRL_ID_DFLL48 | // Target is DFLL48M
        GCLK_CLKCTRL_GEN(3) | // Select generator 3 as source.
        GCLK_CLKCTRL_CLKEN; // Enable the DFLL48M
    while (GCLK->STATUS.bit.SYNCBUSY) {}; // Wait for synchronization
    // 6. Workaround to be able to configure the DFLL.
    SYSCTRL->DFLLCTRL.bit.ONDEMAND = 0;  //false
    while (!SYSCTRL->PCLKSR.bit.DFLLRDY) {}; // Wait for synchronization.
    // 7. Change the multiplication factor.
    SYSCTRL->DFLLMUL.bit.MUL = 3072; // 48MHz / (1MHz / 64)
    SYSCTRL->DFLLMUL.bit.CSTEP = 1; // Coarse step = 1
    SYSCTRL->DFLLMUL.bit.FSTEP = 1; // Fine step = 1
    while (!SYSCTRL->PCLKSR.bit.DFLLRDY) {}; // Wait for synchronization.
    // 8. Start closed-loop mode
    SYSCTRL->DFLLCTRL.reg |=
        SYSCTRL_DFLLCTRL_MODE | // 1 = Closed loop mode.
        SYSCTRL_DFLLCTRL_QLDIS; // 1 = Disable quick lock.
    while (!SYSCTRL->PCLKSR.bit.DFLLRDY) {}; // Wait for synchronization.
    // 9. Clear the lock flags.
    //SYSCTRL->INTFLAG.bit.DFLLLCKC = 1;
    //SYSCTRL->INTFLAG.bit.DFLLLCKF = 1;
    //SYSCTRL->INTFLAG.bit.DFLLRDY = 1;
    // 10. Enable the DFLL
    SYSCTRL->DFLLCTRL.bit.ENABLE = 1;//true;
    while (!SYSCTRL->PCLKSR.bit.DFLLRDY) {}; // Wait for synchronization.
    // 11. Wait for the fine and coarse locks.
    while (!SYSCTRL->INTFLAG.bit.DFLLLCKC && !SYSCTRL->INTFLAG.bit.DFLLLCKF) {};
    // 12. Wait until the DFLL is ready.
    while (!SYSCTRL->INTFLAG.bit.DFLLRDY) {};

    // Switch the main clock speed.
    // 1. Set the divisor of generic clock 0 to 0
    GCLK->GENDIV.reg =
        GCLK_GENDIV_ID(0) | // Select generator 0
        GCLK_GENDIV_DIV(0);
    while (GCLK->STATUS.bit.SYNCBUSY) {}; // Wait for synchronization
    // 2. Switch generic clock 0 to the DFLL
    GCLK->GENCTRL.reg =
        GCLK_GENCTRL_ID(0) | // Select generator 0
        GCLK_GENCTRL_SRC_DFLL48M | // Select source DFLL
        GCLK_GENCTRL_IDC | // Set improved duty cycle 50/50
        GCLK_GENCTRL_GENEN; // Enable this generic clock generator
    while (GCLK->STATUS.bit.SYNCBUSY) {}; // Wait for synchronization
}

int main()
{
    set_clock();

    REG_PORT_DIR0 |= (1<<CLOCK) | (1<<MOSI) | (1<<DATA_COMMAND) | (1<<CHIP_SELECT) | (1<<RESET);

    initialise_oled();

    uint8_t i = 0;

    while(1)
    {
        //clear_buffer();
        draw_int(255-i, 3, 12*8, 6*8);
        draw_int(i++, 3, 8, 8);
        draw();

        //delay(100);
    }
}
