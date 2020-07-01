#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#   slightly modified by Joris Heemskerk
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := flush.cpp movement.cpp new_led.cpp buttons.cpp win_lose.cpp welcome.cpp reset.cpp 

# header files in this project
HEADERS := flush.hpp movement.hpp game_data.hpp new_led.hpp buttons.hpp win_lose.hpp welcome.hpp reset.hpp

# other places to look for files for this project
SEARCH  := ../..

# set RELATIVE to the next higher directory 
# and defer to the appropriate Makefile.* there
RELATIVE := ../../..
include $(RELATIVE)/Makefile.due
include $(RELATIVE)/Makefile.jhlib
