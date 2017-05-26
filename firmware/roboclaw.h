#ifndef _ROBOCLAW_H
#define _ROBOCLAW_H<

#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

#define BAUD 115200

extern "C" {
#include "uart.h"
}
#ifndef RC_ADDRESS
#define RC_ADDRESS 0x80
#endif

#define TIMEOUT 10000UL

enum {
  RC_M1FORWARD = 0,       // send [addr, cmd, value, CRC] recv [0xFF]
  RC_M1BACKWARD = 1,      //
  RC_SETMINMB = 2,
  RC_SETMAXMB = 3,
  RC_M2FORWARD = 4,
  RC_M2BACKWARD = 5,
  RC_M17BIT = 6,
  RC_M27BIT = 7,
  RC_MIXEDFORWARD = 8,
  RC_MIXEDBACKWARD = 9,
  RC_MIXEDRIGHT = 10,
  RC_MIXEDLEFT = 11,
  RC_MIXEDFB = 12,
  RC_MIXEDLR = 13,
  RC_GETM1ENC = 16,
  RC_GETM2ENC = 17,
  RC_GETM1SPEED = 18,
  RC_GETM2SPEED = 19,
  RC_RESETENC = 20,
  RC_GETVERSION = 21,
  RC_SETM1ENCCOUNT = 22,
  RC_SETM2ENCCOUNT = 23,
  RC_GETMBATT = 24,
  RC_GETLBATT = 25,
  RC_SETMINLB = 26,
  RC_SETMAXLB = 27,
  RC_SETM1PID = 28,
  RC_SETM2PID = 29,
  RC_GETM1ISPEED = 30,
  RC_GETM2ISPEED = 31,
  RC_M1DUTY = 32,
  RC_M2DUTY = 33,
  RC_MIXEDDUTY = 34,
  RC_M1SPEED = 35,
  RC_M2SPEED = 36,
  RC_MIXEDSPEED = 37,
  RC_M1SPEEDACCEL = 38,
  RC_M2SPEEDACCEL = 39,
  RC_MIXEDSPEEDACCEL = 40,
  RC_M1SPEEDDIST = 41,
  RC_M2SPEEDDIST = 42,
  RC_MIXEDSPEEDDIST = 43,
  RC_M1SPEEDACCELDIST = 44,
  RC_M2SPEEDACCELDIST = 45,
  RC_MIXEDSPEEDACCELDIST = 46,
  RC_GETBUFFERS = 47,
  RC_GETPWMS = 48,
  RC_GETCURRENTS = 49,
  RC_MIXEDSPEED2ACCEL = 50,
  RC_MIXEDSPEED2ACCELDIST = 51,
  RC_M1DUTYACCEL = 52,
  RC_M2DUTYACCEL = 53,
  RC_MIXEDDUTYACCEL = 54,
  RC_READM1PID = 55,
  RC_READM2PID = 56,
  RC_SETMAINVOLTAGES = 57,
  RC_SETLOGICVOLTAGES = 58,
  RC_GETMINMAXMAINVOLTAGES = 59,
  RC_GETMINMAXLOGICVOLTAGES = 60,
  RC_SETM1POSPID = 61,
  RC_SETM2POSPID = 62,
  RC_READM1POSPID = 63,
  RC_READM2POSPID = 64,
  RC_M1SPEEDACCELDECCELPOS = 65,
  RC_M2SPEEDACCELDECCELPOS = 66,
  RC_MIXEDSPEEDACCELDECCELPOS = 67,
  RC_SETM1DEFAULTACCEL = 68,
  RC_SETM2DEFAULTACCEL = 69,
  RC_SETPINFUNCTIONS = 74,
  RC_GETPINFUNCTIONS = 75,
  RC_SETDEADBAND = 76,
  RC_GETDEADBAND = 77,
  RC_GETENCODERS = 78,
  RC_GETISPEEDS = 79,
  RC_RESTOREDEFAULTS = 80,
  RC_GETTEMP = 82,
  RC_GETTEMP2 = 83,  //Only valid on some models
  RC_GETERROR = 90,
  RC_GETENCODERMODE = 91,
  RC_SETM1ENCODERMODE = 92,
  RC_SETM2ENCODERMODE = 93,
  RC_WRITENVM = 94,
  RC_READNVM = 95, //Reloads values from Flash into Ram
  RC_SETCONFIG = 98,
  RC_GETCONFIG = 99,
  RC_SETM1MAXCURRENT = 133,
  RC_SETM2MAXCURRENT = 134,
  RC_GETM1MAXCURRENT = 135,
  RC_GETM2MAXCURRENT = 136,
  RC_SETPWMMODE = 148,
  RC_GETPWMMODE = 149,
  RC_FLAGBOOTLOADER = 255
};


void update_crc(uint8_t data);
void rc_init(void);

bool check_crc();
void send_cmd(uint8_t cmd);

bool write_n(uint8_t cnt, ...);

template <typename T> bool read_n(uint8_t cnt, uint8_t cmd, ...);
template <typename T> T read(bool *valid);

bool ReadCurrents(int16_t &current1, int16_t &current2);
bool ReadVersion(char *version);

#endif