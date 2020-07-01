#include "win_lose.hpp"

//this function checks if the player has won or lost
void win_lose(jhlib::jhlib_window & w, std::array<std::array<hwlib::color, 5>, 5> & matrix, const game_data & game, hwlib::terminal_from & display){
    bool check = 1;
    for(unsigned int i=0; i<matrix.size(); i++){
        for(unsigned j=0; j<matrix[i].size(); j++){
            //when you win the 2048 piece will alternate between the collors Red Green & Blue, after wich the oled will display "GOOD \n JOB!".
            if(matrix[i][j]== game.val_2048){
                display
                << "\f" 
                << "\t0200" << "GOOD"
                << "\t0202" << "JOB!"
                << hwlib::flush;
                for(unsigned int k=0; k<18 ;k++){
                    matrix[i][j] = hwlib::color(0xFF0000);
                    flush(w, matrix);
                    hwlib::wait_ms(100);
                    matrix[i][j] = hwlib::color(0x00FF00);
                    flush(w, matrix);
                    hwlib::wait_ms(100);
                    matrix[i][j] = hwlib::color(0x0000FF);
                    flush(w, matrix);
                    hwlib::wait_ms(100);
                }
            }
            //if there are no more empty spaces for LEDs to go the player loses.
            else if(matrix[i][j] == hwlib::color(0x000000)){
                check = 0;
            }
        }
    }
    //when the player loses the whole grid will become a soft red and the oled will display the text: " Oh no! \n you lost".
    if(check){
        for(unsigned int i=0; i<matrix.size(); i++){
            for(unsigned j=0; j<matrix[i].size(); j++){
                matrix[i][j] = hwlib::color(0x200000);
            }
        }
        flush(w, matrix);
        display
         << "\f" 
         << "\t0100" << "Oh no!"
         << "\t0002" << "you lost"
         << hwlib::flush;
        hwlib::wait_ms(4000);
    }
}