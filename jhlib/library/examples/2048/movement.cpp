#include "movement.hpp"

//this function will move the array accorind to wich direction of buttin is pressed. if 2 LEDs of the same value will collide it will upp the value, so 2 + 2 = 4.
void movement(std::array<std::array<hwlib::color, 5>, 5> & matrix, const game_data & game, const int & direction, int & highest_value){
    
    bool check = 0;
    //if button up is pressed this will make sure the movement will be corrected
    int i_start = 0;
    int i_end = matrix.size();
    int i_correction = 0;
    int j_start = 0;
    int j_end = matrix[0].size();
    int j_correction = 0;

    if(direction == 0){
        i_start = 1;
        i_correction = -1;
    }
    else if(direction == 1){
        i_end = matrix.size()-1;
        i_correction = 1;
    }
    else if(direction == 2){
        j_end = matrix[0].size()-1;
        j_correction = 1;
    }
    else if(direction == 3){
        j_start = 1;
        j_correction = -1;
    }
    
    //1st loop makes sure you do not have to press the button 4 times in order for a led to travel from 0,0 to 0,4.
    for(unsigned int z=0; z<matrix.size()-1; z++){
        for(int i=i_start; i<i_end; i++){
            for(int j=j_start; j<j_end; j++){
                
                //checks if the space a LED should move to is occupied, if not it will 'move'.
                if(matrix[i][j] != hwlib::color(0x000000) && matrix[i+i_correction][j+j_correction] == hwlib::color(0x000000)){
                    matrix[i+i_correction][j+j_correction] = matrix[i][j];  
                    matrix[i][j] = hwlib::color(0x000000);
                    check = 1;
                }
                //checks if 2 colors are equal.
                if(matrix[i][j] == matrix[i+i_correction][j+j_correction] && matrix[i][j] != hwlib::color(0x000000)){
                    check = 1;
                    hwlib::color new_position = hwlib::color(0x000000);
                    //2+2=4
                    if(matrix[i][j] == game.val_2){
                        new_position = game.val_4;
                        //by altering the highest_value, we can display the highest value on the oled display.
                        if(4>highest_value){
                            highest_value = 4;
                        }
                    }
                    //4+4=8
                    else if(matrix[i][j] == game.val_4){
                        new_position = game.val_8;
                        if(8>highest_value){
                            highest_value = 8;
                        }
                    }
                     //8+8=16
                    else if(matrix[i][j] == game.val_8){
                        new_position = game.val_16;
                        if(16>highest_value){
                            highest_value = 16;
                        }
                    }
                    //16+16 = 32
                    else if(matrix[i][j] == game.val_16){
                        new_position = game.val_32;
                        if(32>highest_value){
                            highest_value = 32;
                        }
                    }
                    //32+32 = 64
                    else if(matrix[i][j] == game.val_32){
                        new_position = game.val_64;
                        if(64>highest_value){
                            highest_value = 64;
                        }
                    }
                    //64+64 = 128
                    else if(matrix[i][j] == game.val_64){
                        new_position = game.val_128;
                        if(128>highest_value){
                            highest_value = 128;
                        }
                    }
                    //128+128 = 256
                    else if(matrix[i][j] == game.val_128){
                        new_position = game.val_256;
                        if(256>highest_value){
                            highest_value = 256;
                        }
                    }
                    //256+256 = 512
                    else if(matrix[i][j] == game.val_256){
                        new_position = game.val_512;
                        if(512>highest_value){
                            highest_value = 512;
                        }
                    }
                    //512+512 = 1024
                    else if(matrix[i][j] == game.val_512){
                        new_position = game.val_1024;
                        if(1024>highest_value){
                            highest_value = 1024;
                        }
                    }
                    //1024+1024 = 2048
                    else if(matrix[i][j] == game.val_1024){
                        new_position = game.val_2048;
                        if(1048>highest_value){
                            highest_value = 2048;
                        }
                    }
                    matrix[i][j] = hwlib::color(0x000000);
                    matrix[i+i_correction][j+j_correction] = new_position;
                }
            }
        }
    }
    //only if a LED has moved will it spawn a new one.
    if(check){
        new_led(matrix, game);
    }
}