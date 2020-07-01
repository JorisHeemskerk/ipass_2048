#include "reset.hpp"

void reset(jhlib::jhlib_window & w, std::array<std::array<hwlib::color, 5>, 5> & matrix, const game_data & game, hwlib::terminal_from & display){    
    for(unsigned int i=0; i<matrix.size(); i++){
        for(unsigned int j=0; j<matrix[i].size(); j++){
            matrix[i][j] = hwlib::color(0x000000);
            }
        }
    flush(w, matrix);
    welcome(display);  
    new_led(matrix, game, 4);
    flush(w, matrix);
    
}
