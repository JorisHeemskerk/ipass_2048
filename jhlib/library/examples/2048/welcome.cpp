#include "welcome.hpp"

void welcome(hwlib::terminal_from & display){
    //Welcome
    display 
        << "\f" << "W"
        << hwlib::flush;
    hwlib::wait_ms(100);
    display 
        << "\f" << "We"
        << hwlib::flush;
    hwlib::wait_ms(100);
    display 
        << "\f" << "Wel"
        << hwlib::flush;
    hwlib::wait_ms(100);
    display 
        << "\f" << "Welc"
        << hwlib::flush;
    hwlib::wait_ms(100);
    display 
        << "\f" << "Welco"
        << hwlib::flush;
    hwlib::wait_ms(100);
    display 
        << "\f" << "Welcom"
        << hwlib::flush;
    hwlib::wait_ms(100);
    display 
        << "\f" << "Welcome"
        << hwlib::flush;
    hwlib::wait_ms(200);
    

    //to
    display
        << "\t0201" << "t"
        << hwlib::flush;
    hwlib::wait_ms(100);
    display
        << "\t0201" << "to"
        << hwlib::flush;
    hwlib::wait_ms(100);
    
    //2048
    display
        << "\t0203" << "2"
        << hwlib::flush;
    hwlib::wait_ms(100); 
    display
        << "\t0203" << "20"
        << hwlib::flush;
    hwlib::wait_ms(100);
    display
        << "\t0203" << "204"
        << hwlib::flush;
    hwlib::wait_ms(100);
    display
        << "\t0203" << "2048"
        << hwlib::flush;
    hwlib::wait_ms(100);
}
