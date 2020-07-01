#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include "jhlib.hpp"

void buttons(jhlib::jhlib_window & w, jhlib::WS2812B & leds, hwlib::target::pin_in & button_left, hwlib::target::pin_in & button_right, hwlib::target::pin_in & button_on_off, int & effect_number);

#endif