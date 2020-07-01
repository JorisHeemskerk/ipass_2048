#include "jhlib.hpp"


int main(){
    //to make a window, you will need a GPIO pin and a size, the size is saved in a hwlib::xy oject, the gpio pin is defined as hwlib::target::pin_out.
    auto gpio = hwlib::target::pin_out(hwlib::target::pins::d53);
    auto w = jhlib::jhlib_window(hwlib::xy(5, 5), gpio);
    
    //to prevent information from previous programs to remain we first clear the window.
    w.clear();

    
    for(;;){
        //these loops change the color from blue to off and back, slowly
        for(unsigned int i=0; i<256; i++){
            auto line = hwlib::line(hwlib::xy(0,0), hwlib::xy(5,5), hwlib::color(0, 0, i));
            line.draw(w);
            w.flush();
            hwlib::wait_ms(5);
        }for(unsigned int i=0; i<256; i++){
            auto line = hwlib::line(hwlib::xy(0,0), hwlib::xy(5,5), hwlib::color(0, 0, 255-i));
            line.draw(w);
            w.flush();
            hwlib::wait_ms(5);
        }
    }
}