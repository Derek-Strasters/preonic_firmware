/*
Copyright 2013 Mathias Andersson <wraul@dbox.se>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifndef BACKLIGHT_LEVELS
#    define BACKLIGHT_LEVELS 3
#elif BACKLIGHT_LEVELS > 31
#    error "Maximum value of BACKLIGHT_LEVELS is 31"
#endif

#ifndef BACKLIGHT_ON_STATE
#    define BACKLIGHT_ON_STATE 1
#endif

#ifndef BREATHING_PERIOD
#    define BREATHING_PERIOD 6
#endif

typedef union {
    uint8_t raw;
    struct {
        bool    enable : 1;
        bool    breathing : 1;
        uint8_t reserved : 1;  // Reserved for possible future backlight modes
        uint8_t level : 5;
    };
} backlight_config_t;

void    backlight_init(void);
void    backlight_toggle(void);
void    backlight_enable(void);
void    backlight_disable(void);
bool    is_backlight_enabled(void);
void    backlight_step(void);
void    backlight_increase(void);
void    backlight_decrease(void);
void    backlight_level_noeeprom(uint8_t level);
void    backlight_level(uint8_t level);
uint8_t get_backlight_level(void);

uint8_t eeconfig_read_backlight(void);
void    eeconfig_update_backlight(uint8_t val);
void    eeconfig_update_backlight_current(void);
void    eeconfig_update_backlight_default(void);

// implementation specific
void backlight_init_ports(void);
void backlight_set(uint8_t level);
void backlight_task(void);
void set_pwm(uint16_t val);

// See http://jared.geek.nz/2013/feb/linear-led-pwm
static inline uint16_t cie_lightness(uint16_t v) {
    if (v <= 5243)     // if below 8% of max
        return v / 9;  // same as dividing by 900%
    else {
        uint32_t y = (((uint32_t)v + 10486) << 8) / (10486 + 0xFFFFUL);  // add 16% of max and compare
        // to get a useful result with integer division, we shift left in the expression above
        // and revert what we've done again after squaring.
        y = y * y * y >> 8;
        if (y > 0xFFFFUL)  // prevent overflow
            return 0xFFFFU;
        else
            return (uint16_t)y;
    }
};

#ifdef BACKLIGHT_BREATHING

void backlight_toggle_breathing(void);
void backlight_enable_breathing(void);
void backlight_disable_breathing(void);
bool is_backlight_breathing(void);

void    breathing_period_set(uint8_t value);
uint8_t get_breathing_period(void);
void    breathing_period_default(void);
void    breathing_period_inc(void);
void    breathing_period_dec(void);

void breathing_toggle(void);

// implementation specific
void breathing_enable(void);
void breathing_disable(void);
bool is_breathing(void);
void breathing_pulse(void);
#endif
