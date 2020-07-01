#include "buttons.hpp"

//this function will check wich button is pressed and it will move the LEDs accoridngly.
void buttons(jhlib::jhlib_window & w, std::array<std::array<hwlib::color, 5>, 5> & matrix, const game_data & game, hwlib::target::pin_in & button_up, hwlib::target::pin_in & button_down, hwlib::target::pin_in & button_left, hwlib::target::pin_in & button_right, hwlib::target::pin_in & button_reset, hwlib::target::pin_in & button_on_off, hwlib::terminal_from & display, bool check){
    const int up = 0;
    const int down = 1;
    const int left = 2;
    const int right = 3;
    int highest_value = 2;
    for(;;){
        //to prevent buggs from occuring when a buttin is hold instead of quickly pressed,
        // this if statement will only allow a new press of the button when all buttons will not be pressed.
        if(button_down.read() && button_up.read() && button_left.read() && button_right.read() && button_reset.read() && button_on_off.read() && !check){
            check=1;
        }

        //when a button is pressed the movement function will be called to move the LEDs, then the updated array will be flushed and at last the win_lose will check if the player has won or lost.
        if(!button_down.read() && check){
            movement(matrix, game, down, highest_value);
            win_lose(w, matrix, game, display);
            flush(w, matrix);
            display << "\f" << "\t0101" << "score:" << "\t0202" << highest_value << hwlib::flush;
        }else if(!button_up.read() && check){
            movement(matrix, game, up, highest_value);
            win_lose(w, matrix, game, display);
            flush(w, matrix);
            display << "\f" << "\t0101" << "score:" << "\t0202" << highest_value << hwlib::flush;
        }else if(!button_right.read() && check){
            movement(matrix, game, right, highest_value);
            win_lose(w, matrix, game, display);
            flush(w, matrix);
            display << "\f" << "\t0101" << "score:" << "\t0202" << highest_value << hwlib::flush;
        }else if(!button_left.read() && check){
            movement(matrix, game, left, highest_value);
            win_lose(w, matrix, game, display);
            flush(w, matrix);
            display << "\f" << "\t0101" << "score:" << "\t0202" << highest_value << hwlib::flush;
        }else if(!button_reset.read() && check){
            reset(w, matrix, game, display);
            highest_value = 2;
        }
        //when the on/off button is pressed, thedisplay and leds will be turned off, then we wait until the button is pressed aigan
        else if(!button_on_off.read() && check){
            w.clear();
            w.flush();
            display << "\f" << hwlib::flush;
            
            hwlib::wait_ms(1000);
            for(;;){
                if(!button_on_off.read()){
                    flush(w, matrix);
                    display << "\f" << "\t0101" << "score:" << "\t0202" << highest_value << hwlib::flush;
                    break;
                }
            }
        }
        //if a button is pressed check will be set to 0, making sure no other buttons can be pressed until all are released. 
        check = 0;
    }
}