#ifndef __DEBUG_H__
#define __DEBUG_H__

// #define DEBUG

#include <Arduino.h>

#ifndef CONSOLE_SERIAL
#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
#define CONSOLE_SERIAL SerialUSB
#else
#define CONSOLE_SERIAL Serial
#endif
#endif

#ifdef DEBUG
#define DMSG(args...) CONSOLE_SERIAL.print(args)
#define DMSG_STR(str) CONSOLE_SERIAL.println(str)
#define DMSG_HEX(num)                             \
    CONSOLE_SERIAL.print(' ');                    \
    CONSOLE_SERIAL.print((num >> 4) & 0x0F, HEX); \
    CONSOLE_SERIAL.print(num & 0x0F, HEX)
#define DMSG_INT(num)          \
    CONSOLE_SERIAL.print(' '); \
    CONSOLE_SERIAL.print(num)
#else
#define DMSG(args...)
#define DMSG_STR(str)
#define DMSG_HEX(num)
#define DMSG_INT(num)
#endif

#endif
