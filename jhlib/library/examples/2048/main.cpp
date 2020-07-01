#include "jhlib.hpp"
#include "buttons.hpp"
#include "game_data.hpp"
#include "reset.hpp"
#include <array>

int main(){
    //this gpio varable will be the data output from the arduino to the LEDs
    auto gpio = hwlib::target::pin_out(hwlib::target::pins::d53);
    //this window will make up the grid, wich we can later fill with colors. 
    auto w = jhlib::jhlib_window(hwlib::xy(5, 5), gpio);

    //these varables will account for the buttons used as inputs. put the buttin in the gpio pin d[number]. Or change the code according to your own configuration of buttons.
    auto button_right = hwlib::target::pin_in(hwlib::target::pins::d46);
    auto button_left = hwlib::target::pin_in(hwlib::target::pins::d44);
    auto button_up = hwlib::target::pin_in(hwlib::target::pins::d47);
    auto button_down = hwlib::target::pin_in(hwlib::target::pins::d45);
    auto button_reset = hwlib::target::pin_in(hwlib::target::pins::d49);
    auto button_on_off = hwlib::target::pin_in(hwlib::target::pins::d48);

    //(Optional) Oled screen. to comunicate with the chip you need to hook it up to the SCL and SDA ports on your arduino
    //If not hooked up no damage will be done to the system. 
    auto scl     = hwlib::target::pin_oc(hwlib::target::pins::scl );
    auto sda     = hwlib::target::pin_oc(hwlib::target::pins::sda );
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
    auto oled    = hwlib::glcd_oled( i2c_bus, 0x3c ); 
   
    auto font    = hwlib::font_default_16x16();
    auto display = hwlib::terminal_from( oled, font );
    
    
    //this struct game_data will consist out of the colors we wish to use for the different valued pieces of 2048. A set of collors autmaticly defined in game_data.hpp. 
    game_data game = {};
    //To change the colors for a specif piece try something like: game.val_2 = hwlib::color(0xFF0000);

    //this array will be our playing field, in this example a 5x5 grid is used. to change this, change anywhere it says 5 in all files to the new numbers.
    std::array<std::array<hwlib::color, 5>, 5> matrix;

    //this reset function will start the game.
    reset(w, matrix, game, display);
    
    //this function will continuously check for player inputs
    buttons(w, matrix, game, button_up, button_down, button_left, button_right, button_reset, button_on_off, display);
}