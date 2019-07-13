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

int main()
{
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
