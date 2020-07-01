#include "jhlib.hpp"
#include "effect.hpp"


int main(){
    auto gpio = hwlib::target::pin_out(hwlib::target::pins::d53);
    auto leds = jhlib::WS2812B(gpio, 26);
    auto w = jhlib::jhlib_window(hwlib::xy(5,5), gpio);

    auto button_left = hwlib::target::pin_in(hwlib::target::pins::d44);
    auto button_right = hwlib::target::pin_in(hwlib::target::pins::d46);
    auto button_on_off = hwlib::target::pin_in(hwlib::target::pins::d48);

    bool check = 1;
    int effect_number = 0;
    effect(w, leds, button_right, button_left, button_on_off, effect_number);

    for(;;){
        if(button_left.read() && button_right.read() && !check){
            check = 1;
        }
        
        if(!button_right.read() && check){
            check = 0;
            effect_number++;
        }else if(!button_left.read() && check){
            check = 0;
            effect_number--;
        }
        effect(w, leds, button_right, button_left, button_on_off, effect_number);
    }
}