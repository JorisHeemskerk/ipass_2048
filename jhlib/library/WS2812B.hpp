 // ==========================================================================
 //
 // File      : WS2812B.hpp
 // Part of   : C++ jhlib library for WS2812B
 // Copyright : joris.heemskerk@hotmail.com 2020
 //
 // Distributed under the Boost Software License, Version 1.0.
 // (See accompanying file LICENSE_1_0.txt or copy at 
 // http://www.boost.org/LICENSE_1_0.txt)
 //
 // ==========================================================================
 
 // included only via jhlib.hpp, hence no multiple-include guard is needed
 
 // this file contains Doxygen lines
 



#ifndef WS2812B_HPP
#define WS2812B_HPP

#include "hwlib.hpp"
#include <array>

///@file

namespace jhlib{
    ///\brief
    ///This class lets a user define and controll a certain amount of WS2812B LEDs. 
    ///\details
    ///To use this class call it with a hwlib::pin_out() and a const unsigned int with the amount of LEDs. 
    /// \n To write a collor to a LED try variable.write(number, collor). Afterwards do variable.flush().
    class WS2812B{
    private:
        hwlib::pin_out & gpio;
        const unsigned int led_amount;
        std::array<unsigned int, 1000> leds;


        ///\brief
        ///The function zero writes a 0 to the LEDs.
        ///\details
        ///To write a 0 to the WS2812B LEDs a specific timing is needed (see the datasheet). To match these timings a hwlib::wait_ns() is used. 
        /// \n The function is only called by flush();
        void zero(hwlib::pin_out & gpio){
            gpio.write(1);
            gpio.write(0);
            hwlib::wait_ns(450); 
        }

        ///\brief
        ///The function one writes a 1 to the LEDs.
        ///\details
        ///To write a 1 to the WS2812B LEDs a specific timing is needed (see the datasheet). To match these timings a hwlib::wait_ns() is used. 
        /// \n The function is only called by flush();
        void one(hwlib::pin_out & gpio){
            gpio.write(1);
            hwlib::wait_ns(400);

            gpio.write(0);
            hwlib::wait_ns(50); 
        }

    public:

        ///\brief
        ///This constructor lets the user define a gpio pin and a amount of LEDs.
        ///\details
        ///In addition to letting the user define a gpio and a led_amount it also sets the needed numbers in the std::array<unsigned int, 1000> leds; to 0. 
        /// \n This is done to make sure no unwanted values are saved in the data slots of the array.
        WS2812B(hwlib::pin_out & gpio, const unsigned int led_amount):
            gpio(gpio),
            led_amount(led_amount)
        {
            for(unsigned int i=0; i<led_amount; i++){
                leds[i] = 0;
            }
        }

        ///\brief
        ///This public function write lets the user change a certain LED using a HEX value.
        ///\details
        ///To call this function simply give it a position (the first LED is position 0) and a HEX value in the shape of 0xRRGGBB. 
        /// \n The function will check if the given grb value is to high or low an will correct it accordingly.
        /// \n After this the function will convert and add the given color to the array leds in the correct position. 
        void draw(unsigned int position, int rgb){
            if(rgb > 0xFFFFFF){
                rgb = 0xFFFFFF;
            }else if(rgb < 0x000000){
                rgb = 0x000000;
            }
            
            int grb = 0;
            grb = (rgb & (0b11111111));
            grb |= ((rgb & (0b11111111 << 16))>>8);
            grb |= ((rgb & (0b11111111 << 8))<<8);
            leds[position] = grb;
        }

        ///\brief
        ///This public function write lets the user change a certain LED using three int values.
        ///\details
        ///To call this function simply give it a position (the first LED is position 0) and three int values in the shape of int red, int green, int blue. 
        /// \n The function will check if the given rgb value is to high or low an will correct it accordingly.
        /// \n After this the function will convert and add the given color to the array leds in the correct position.
        void draw(unsigned int position, int R, int G, int B){
            if(R > 255){
                R = 255;
            }else if(R < 0){
                R = 0;
            }
            if(G > 255){
                G = 255;
            }else if(G < 0){
                G = 0;
            }
            if(B > 255){
                B = 255;
            }else if(B < 0){
                B = 0;
            }

            if(position > led_amount){
                position = led_amount-1;
            }else if(position < 0){
                position = 0;
            }

            int grb = ((G << 16) + (R << 8) + B); 
            leds[position] = grb;
        }

        ///\brief
        ///This public function displays the written values to the LEDs.
        ///\details
        ///If called this function will loop through the array leds (containing all GRB values) and it will write zeros and ones to the LEDs accordingly.
        void flush(){
            for(unsigned int i=0; i<led_amount; i++){
                for(unsigned int j=0; j<24; j++){
                    if(leds[i] & (1 <<(23 - j))){
                        one(gpio);
                    }else{
                        zero(gpio);
                    }
                }
            }
            hwlib::wait_ms(1);
        }    
    };
};
#endif