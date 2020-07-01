#include "flush.hpp"

//this function will go through the array of collors and will use jhlib to display them
void flush(jhlib::jhlib_window & w, std::array<std::array<hwlib::color, 5>, 5> & matrix){
    for(unsigned int i=0; i<5; i++){
        for(unsigned int j=0; j<5; j++){
            w.write(hwlib::xy(i, j), hwlib::color(matrix[i][j]));
        }
    }
    w.flush();
}