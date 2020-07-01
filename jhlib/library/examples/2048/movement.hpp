#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "jhlib.hpp"
#include "game_data.hpp"
#include "new_led.hpp"
#include <array>

void movement(std::array<std::array<hwlib::color, 5>, 5> & matrix, const game_data & game, const int & direction, int & highest_value);

#endif