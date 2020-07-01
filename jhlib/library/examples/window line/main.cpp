#include "jhlib.hpp"


int main(){
    //to make a window, you will need a GPIO pin and a size, the size is saved in a hwlib::xy oject, the gpio pin is defined as hwlib::target::pin_out.
    auto gpio = hwlib::target::pin_out(hwlib::target::pins::d53);
    auto w = jhlib::jhlib_window(hwlib::xy(5, 5), gpio);
    
    //to prevent information from previous programs to remain we first clear the window.
    w.clear();

    //now to make a line, you need a start xy and an end xy, the line, goes to end xy, and does not in fact draw the last coordiante.
    //this example should therefore draw a line from (0,0) all the way to (4,4), making a diagonal line on a 5x5 grid.
    auto line = hwlib::line(hwlib::xy(0,0), hwlib::xy(5,5), hwlib::color(0xFF0000));
    //to put the line onto the window, you need the following command.
    //note: this does not immedietly show the line, you need a flush for that.
    line.draw(w);

    //to make this line accualy appear we need to flush the window.
    w.flush();

    //if all works correctly, the LEDs in position (0,0), (1,1), (2,2), (3,3), (4,4) should turn red.

}