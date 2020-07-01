#include "jhlib.hpp"


int main(){
    //to write data to the LEDs we need to use a gpio pin, i used pin d53.
    auto gpio = hwlib::target::pin_out(hwlib::target::pins::d53);
    //to write data to the LEDs we need to call the WS2812B class from the library. We give it a gpio pin and an amount of LEDs we want to use
    //(giving to much or to little should not harm the system)
    auto leds = jhlib::WS2812B(gpio, 25);

    //this loop makes sure no unment LEDs turn the wrong collor
    for(;;){
        //now we draw a color in a specific location using a hex or RGB value
        leds.draw(0, 255, 255, 255);
        leds.draw(1, 0xFFFFFF);
        
        //after drawing these, they do not yet apear, for that we need to flush the leds.
        leds.flush();

    }
    //if all works correctly, the first two LEDs should turn white.
}