#include "buttons.hpp"
#include "effect.hpp"

void buttons(jhlib::jhlib_window & w, jhlib::WS2812B & leds, hwlib::target::pin_in & button_left, hwlib::target::pin_in & button_right, hwlib::target::pin_in & button_on_off, int & effect_number){
    if(!button_right.read()){
        effect_number++;
        if(effect_number < 0){
            effect_number=0;
        }else if(effect_number > 10){
            effect_number=10;
        }
        hwlib::cout << effect_number;
        hwlib::wait_ms(1000);
        effect(w, leds, button_right, button_left, button_on_off, effect_number);
    }else if(!button_left.read()){
        effect_number--;
        if(effect_number < 0){
            effect_number=0;
        }else if(effect_number > 10){
            effect_number=10;
        }
        hwlib::cout << effect_number;
        hwlib::wait_ms(1000);
        effect(w, leds, button_right, button_left, button_on_off, effect_number);
    }else if(!button_on_off.read()){
        w.clear();
        w.flush();
        hwlib::wait_ms(100);
        for(;;){
            if(!button_on_off.read()){
                hwlib::wait_ms(1000);
                effect(w, leds, button_right, button_left, button_on_off, effect_number);
                break;
            }
        }
    }
}