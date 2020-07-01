#include "jhlib.hpp"


int main(){
    //to make a window, you will need a GPIO pin and a size. 
    //the size is saved in a hwlib::xy oject. 
    //the gpio pin is defined as hwlib::target::pin_out.
    auto gpio = hwlib::target::pin_out(hwlib::target::pins::d53);
    auto w = jhlib::jhlib_window(hwlib::xy(5, 5), gpio);
    
    for(;;){
        //to prevent residue from previous programs we first clear the window.
        w.clear();
        //after this we can write a color to a specific xy coordinate.
        w.write(hwlib::xy(2,1), hwlib::color(0x0000FF));
        //to make this LED accualy appear we need to flush the window.
        w.flush();

        //if all works correctly, the LED in position x = 2, y = 1 should turn blue.
    }
}




