#ifndef RESET_HPP
#define RESET_HPP

#include "jhlib.hpp"
#include "flush.hpp"
#include "game_data.hpp"
#include "welcome.hpp"
#include "new_led.hpp"
#include <array>

void reset(jhlib::jhlib_window & w, std::array<std::array<hwlib::color, 5>, 5> & matrix, const game_data & game, hwlib::terminal_from & display);

#endif