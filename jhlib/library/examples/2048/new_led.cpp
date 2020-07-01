#include "new_led.hpp"

void new_led(std::array<std::array<hwlib::color, 5>, 5> & matrix, const game_data & game, unsigned int amount){
    for(unsigned int i=0; i<amount; i++){

        int x = hwlib::random_in(0, 4);
        int y = hwlib::random_in(0, 4);

        if(matrix[x][y] == hwlib::color(0x000000)){        
            matrix[x][y] = game.val_2;
        }else{
            new_led(matrix, game);
        }
    }
}
