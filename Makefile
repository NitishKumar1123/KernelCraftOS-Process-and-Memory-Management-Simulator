CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude
SRCS = main.cpp \
       process\process.cpp \
       scheduler\scheduler.cpp \
       memory\memory_manager.cpp \
       file_system\file_system.cpp \
       segmentation\segmentation.cpp
OBJS = $(SRCS:.cpp=.o)

all: main

main: $(OBJS)
    $(CXX) -o $@ $^

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) main


