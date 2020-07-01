#ifndef WIN_LOSE_HPP
#define WIN_LOSE_HPP

#include "jhlib.hpp"
#include "flush.hpp"
#include "game_data.hpp"
#include <array>

void win_lose(jhlib::jhlib_window & w, std::array<std::array<hwlib::color, 5>, 5> & matrix, const game_data & game, hwlib::terminal_from & display);

#endif