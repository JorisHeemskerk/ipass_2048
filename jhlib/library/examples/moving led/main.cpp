// ==========================================================================
//
// Lets user move a led in a jhlib::window using 4 buttons
//
// This file is in the public domain.
//
// ==========================================================================

#include "jhlib.hpp"


int main(){
    //first a gpio pin has to be defined, in this example pin 53 is used.
    auto gpio = hwlib::target::pin_out(hwlib::target::pins::d53);
    //now to make the window you give it a size and the gpio pin.
    auto w = jhlib::jhlib_window(hwlib::xy(5, 5), gpio);

    //now to define the buttons, give them a name and a pin
    auto button_right = hwlib::target::pin_in(hwlib::target::pins::d44);
    auto button_left = hwlib::target::pin_in(hwlib::target::pins::d46);
    auto button_up = hwlib::target::pin_in(hwlib::target::pins::d47);
    auto button_down = hwlib::target::pin_in(hwlib::target::pins::d45);

    //starting position and color are defined and drawn here
    hwlib::xy pos(0,0);
    auto color = hwlib::color(0x00FF00);
    w.write(pos, color);
    w.flush();

    //this check is here to make sure you cannot hold a button to move
    bool check = 1;

    for(;;){
        if(pos.x >=0 && pos.x <=4 && pos.y >=0 && pos.y <=4){
            //if all buttons are released, check will be set to one and the previous move will be drawn.
            if(button_down.read() && button_up.read() && button_left.read() && button_right.read() && !check){
                check=1;
                w.clear();
                w.write(pos,color);
                w.flush();
            }
            
            //if a button is pressed a new location will be calculated, wich will be drawn once the button is releaced
            if(!button_down.read() && check){
                pos.x++;
                check = 0;
            }else if(!button_up.read() && check){
                pos.x--;
                check = 0;
            }else if(!button_right.read() && check){
                pos.y++;
                check = 0;
            }else if(!button_left.read() && check){
                pos.y--;
                check = 0;
            }
        //these checks make shure you cannot go out of the playing field
        }else if(pos.x < 0){
            pos.x = 0;
        }else if(pos.x > 4){
            pos.x = 4;
        }else if(pos.y < 0){
            pos.y = 0;
        }else if(pos.y > 4){
            pos.y = 4;
        }
    }
}