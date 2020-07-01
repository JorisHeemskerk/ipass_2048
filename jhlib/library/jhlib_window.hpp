 // ==========================================================================
 //
 // File      : window.hpp
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
 

#ifndef JHLIB_WINDOW_HPP
#define JHLIB_WINDOW_HPP

#include "hwlib.hpp"
#include "WS2812B.hpp"

///@file

namespace jhlib {
   
   ///\brief
   ///This class lets a user make a window containing WS2812B LEDs. 
   ///\details
   ///To use this class call it with a hwlib::xy(x, y) as size and a hwlib::target::pin_out gpio pin. 
   /// \n To write a collor to a LED try window.write(hwlib::xy(x, y), hwlib::color). Afterwards do window.flush().
   class jhlib_window : public hwlib::window, public jhlib::WS2812B {
   private:

      ///\brief
      ///This void write_implementation sets the leds in the correct place on a grid. 
      ///\details
      ///This function will take a (x, y) coordinate and translate it to a place on the LEDS if it were a strip.
      void write_implementation(hwlib::xy pos, hwlib::color col)override{
         int position = ((size.x * pos.x)+pos.y);
         WS2812B::draw(position, col.rgb());
      }      
      
   public:
      ///\brief
      ///This constructor lets the user make a window out of WS2812B LEDs. 
      ///\details
      ///To do so it will make a hwlib::window allongside with a WS2812B class to define the gpio and size of the LED strip.
      jhlib_window(const hwlib::xy & size, hwlib::pin_out & gpio): 
         window(size), 
         WS2812B(gpio, size.x*size.y)
      {}

      ///\brief
      ///This flush function will flush the saved LED data onto the LEDs. 
      ///\details
      ///This function simply calls the WS2812B::flush, causing all saved LED data to be displayed onto the LEDs.  
      void flush()override{
         WS2812B::flush();
      } 
   }; 
};

#endif