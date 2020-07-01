#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include "jhlib.hpp"
#include "flush.hpp"
#include "movement.hpp"
#include "game_data.hpp"
#include "reset.hpp"
#include "win_lose.hpp"
#include <array>

void buttons(
            jhlib::jhlib_window & w, 
            std::array<std::array<hwlib::color, 5>, 5> & matrix, 
            const game_data & game, 
            hwlib::target::pin_in & button_up, 
            hwlib::target::pin_in & button_down, 
            hwlib::target::pin_in & button_left, 
            hwlib::target::pin_in & button_right,
            hwlib::target::pin_in & button_reset,
            hwlib::target::pin_in & button_on_off,
            hwlib::terminal_from & display,
            bool check=0
            );

#endif