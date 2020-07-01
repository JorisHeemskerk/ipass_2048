#ifndef GAME_DATA_HPP
#define GAME_DATA_HPP

#include "jhlib.hpp"
#include <array>

//this struct is made up out of all the posible values for a LED, exept for 0.
//to change these collors check main.cpp or alter them right here.
struct game_data{
    hwlib::color val_2 = hwlib::color(0x303030);
    hwlib::color val_4 = hwlib::color(0x900000);
    hwlib::color val_8 = hwlib::color(0x8F1A00);
    hwlib::color val_16 = hwlib::color(0x303000);
    hwlib::color val_32 = hwlib::color(0x003000);
    hwlib::color val_64 = hwlib::color(0x008F30);
    hwlib::color val_128 = hwlib::color(0x003030);
    hwlib::color val_256 = hwlib::color(0x0000FF);
    hwlib::color val_512 = hwlib::color(0x7F0037);
    hwlib::color val_1024 = hwlib::color(0xB200FF);
    hwlib::color val_2048 = hwlib::color(0xFF0000);

};

#endif