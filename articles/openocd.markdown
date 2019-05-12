

1. apt install openocd (0.10.0-5)
1.1 apt remove OpenOCD
1.2 clone repo
1.3 edit src/flash/nor/at91samd.c, samd_issue_nvmctrl_command() change target_write_u16 to target_write_u32 (https://juju.nz/michaelh/post/2017/openocd/)
1.4 compile & install

2. set CPUTAPID 0x0bc11477 (wrong id, https://github.com/DeqingSun/Debug-Arduino-Zero-with-ST-Link-V2)

3. see full .cfg file

4. install gcc-arm-none-eabi
