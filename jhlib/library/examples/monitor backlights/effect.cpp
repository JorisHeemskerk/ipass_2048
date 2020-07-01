#include "effect.hpp"
#include "buttons.hpp"

void effect(jhlib::jhlib_window & w, jhlib::WS2812B & leds, hwlib::target::pin_in & button_left, hwlib::target::pin_in & button_right, hwlib::target::pin_in & button_on_off, int & effect_number){

    //kitt
    if(effect_number == 0){
        w.clear();
        w.flush();
        while(true){
            for(int i=0; i<28; i++){
                buttons(w, leds, button_right, button_left, button_on_off, effect_number);
                leds.draw(i-4, 0, 0, 0);
                leds.draw(i-3, 0, 0, 31);    
                leds.draw(i-2, 0, 0, 63);    
                leds.draw(i-1, 0, 0, 127);    
                leds.draw(i, 0, 0, 255);    
                leds.flush();
                hwlib::wait_ms(100);
            }
            for(int i=24; i>-4; i--){
                buttons(w, leds, button_right, button_left, button_on_off, effect_number);
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

    //slow rainbow
    else if(effect_number == 1){
        w.clear();
        w.flush();
        while(true){
            for(unsigned int i=0; i<256; i++){
                buttons(w, leds, button_right, button_left, button_on_off, effect_number);
                auto line = hwlib::line(hwlib::xy(0,0), hwlib::xy(5,5), hwlib::color(255-i, i, 0));
                line.draw(w);
                w.flush();
            }for(unsigned int i=0; i<256; i++){
                buttons(w, leds, button_right, button_left, button_on_off, effect_number);
                auto line = hwlib::line(hwlib::xy(0,0), hwlib::xy(5,5), hwlib::color(0, 255-i, i));
                line.draw(w);
                w.flush();
            }for(unsigned int i=0; i<256; i++){
                buttons(w, leds, button_right, button_left, button_on_off, effect_number);
                auto line = hwlib::line(hwlib::xy(0,0), hwlib::xy(5,5), hwlib::color(i, 0, 255-i));
                line.draw(w);
                w.flush();
            }
        }
    }


    //fast rainbow
    else if(effect_number == 2){
        w.clear();
        w.flush();
        while(true){
            for(unsigned int i=0; i<63; i++){
                buttons(w, leds, button_right, button_left, button_on_off, effect_number);
                auto line = hwlib::line(hwlib::xy(3,2), hwlib::xy(0,2), hwlib::color(255-(i*4), (i*4), 0));
                line.draw(w);
                w.flush();
            }for(unsigned int i=0; i<63; i++){
                buttons(w, leds, button_right, button_left, button_on_off, effect_number);
                auto line = hwlib::line(hwlib::xy(3,2), hwlib::xy(0,2), hwlib::color(0, 255-(i*4), (i*4)));
                line.draw(w);
                w.flush();
            }for(unsigned int i=0; i<63; i++){
                buttons(w, leds, button_right, button_left, button_on_off, effect_number);
                auto line = hwlib::line(hwlib::xy(3,2), hwlib::xy(0,2), hwlib::color((i*4), 0, 255-(i*4)));
                line.draw(w);
                w.flush();
            }
        }
    }


    //red
    else if(effect_number == 3){
        w.clear();
        w.flush();
        while(true){
            buttons(w, leds, button_right, button_left, button_on_off, effect_number);
            auto line = hwlib::line(hwlib::xy(0, 0), hwlib::xy(5, 5), hwlib::color(0xFF0000));
            line.draw(w);
            w.flush();
        }
    }


    //green
    else if(effect_number == 4){
        w.clear();
        w.flush();
        while(true){
            buttons(w, leds, button_right, button_left, button_on_off, effect_number);
            auto line = hwlib::line(hwlib::xy(0, 0), hwlib::xy(5, 5), hwlib::color(0x00FF00));
            line.draw(w);
            w.flush();
        }
    }


    //blue
    else if(effect_number == 5){
        w.clear();
        w.flush();
        while(true){
            buttons(w, leds, button_right, button_left, button_on_off, effect_number);
            auto line = hwlib::line(hwlib::xy(0, 0), hwlib::xy(5, 5), hwlib::color(0x0000FF));
            line.draw(w);
            w.flush();
        }
    }

    //breathing blue
    else if(effect_number == 6){
        w.clear();
        w.flush();
        while(true){
            for(unsigned int i=0; i<256; i++){
                buttons(w, leds, button_right, button_left, button_on_off, effect_number);
                auto line = hwlib::line(hwlib::xy(0,0), hwlib::xy(5,5), hwlib::color(0, 0, i));
                line.draw(w);
                w.flush();
                hwlib::wait_ms(5);
            }for(unsigned int i=0; i<256; i++){
                buttons(w, leds, button_right, button_left, button_on_off, effect_number);
                auto line = hwlib::line(hwlib::xy(0,0), hwlib::xy(5,5), hwlib::color(0, 0, 255-i));
                line.draw(w);
                w.flush();
                hwlib::wait_ms(5);
            }
        }
    }

}