#ifndef NEW_LED_HPP
#define NEW_LED_HPP

#include "jhlib.hpp"
#include "game_data.hpp"
#include <array>

void new_led(std::array<std::array<hwlib::color, 5>, 5> & matrix, const game_data & game, unsigned int amount = 1);

#endif