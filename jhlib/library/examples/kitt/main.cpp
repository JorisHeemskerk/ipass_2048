#include "jhlib.hpp"


int main(){
    //to write data to the LEDs we need to use a gpio pin, i used pin d53.
    auto gpio = hwlib::target::pin_out(hwlib::target::pins::d53);
    //to write data to the LEDs we need to call the WS2812B class from the library. We give it a gpio pin and an amount of LEDs we want to use
    //(giving to much or to little should not harm the system)
    auto leds = jhlib::WS2812B(gpio, 26);

    //these loops draw different hues of blue acting like the hwlib::kitt function.
    for(;;){
        for(int i=0; i<28; i++){
            leds.draw(i-4, 0, 0, 0);
            leds.draw(i-3, 0, 0, 31);    
            leds.draw(i-2, 0, 0, 63);    
            leds.draw(i-1, 0, 0, 127);    
            leds.draw(i, 0, 0, 255);    
            leds.flush();
            hwlib::wait_ms(100);
        }for(int i=24; i>-4; i--){
            leds.draw(i+4, 0, 0, 0);
            leds.draw(i+3, 0, 0, 31);
            leds.draw(i+2, 0, 0, 63);
            leds.draw(i+1, 0, 0, 127);    
            leds.draw(i, 0, 0, 255);    
            leds.flush();
            hwlib::wait_ms(100);
        }
    }
}