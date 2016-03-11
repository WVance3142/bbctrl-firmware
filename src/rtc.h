/*
 * rtc.h - general purpose real-time clock
 * Part of TinyG project
 *
 * Copyright (c) 2010 - 2013 Alden S. Hart Jr.
 *
 * This file ("the software") is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public
 * License, version 2 as published by the Free Software
 * Foundation. You should have received a copy of the GNU General
 * Public License, version 2 along with the software.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * THE SOFTWARE IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL, BUT
 * WITHOUT ANY WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
 * NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef RTC_H
#define RTC_H

#include <stdint.h>

#define RTC_MILLISECONDS 10 // interrupt on every 10 RTC ticks (~10 ms)

// Interrupt level
#define RTC_COMPINTLVL RTC_COMPINTLVL_LO_gc;

// Note: sys_ticks is in ms but is only accurate to 10 ms as it's derived from
// rtc_ticks
typedef struct rtClock {
  uint32_t rtc_ticks; // RTC tick counter, 10 uSec each
  uint32_t sys_ticks; // system tick counter, 1 ms each
} rtClock_t;

extern rtClock_t rtc;

void rtc_init(); // initialize and start general timer
uint32_t rtc_get_time();

#endif // RTC_H
