/* Copyright 2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "pin_defs.h"

typedef uint8_t pin_t;

/* Operation of GPIO by pin. */

void pinModeInputZ(uint8_t pin) ;
void pinModeOutputPushPull(uint8_t pin) ;
void pinModeOutputOpen(uint8_t pin) ;
void pinModeBiDi(uint8_t pin) ;

void pinModeInputHighQMK(uint8_t pin) ;
void pinModeOutputQMK(uint8_t pin) ;

void writePinLow(uint8_t pin) ;
void writePinHigh(uint8_t pin) ;
uint8_t readPin(uint8_t pin) ;

#define setPinInput     pinModeInputZ
#define setPinInputHigh pinModeInputHighQMK
#define setPinInputLow  _Static_assert(0, "MCS51 processors cannot implement an input as pull low")
#define setPinOutputPushPull pinModeOutputPushPull
#define setPinOutputOpenDrain pinModeOutputOpen
#define setPinOutput    pinModeOutputQMK

//#define writePinHigh(pin) (PORTx_ADDRESS(pin) |= _BV((pin)&0xF))
//#define writePinLow(pin) (PORTx_ADDRESS(pin) &= ~_BV((pin)&0xF))
#define writePin(pin, level) ((level) ? writePinHigh(pin) : writePinLow(pin))

//#define readPin(pin) ((bool)(PINx_ADDRESS(pin) & _BV((pin)&0xF)))

//#define togglePin(pin) (PORTx_ADDRESS(pin) ^= _BV((pin)&0xF))

