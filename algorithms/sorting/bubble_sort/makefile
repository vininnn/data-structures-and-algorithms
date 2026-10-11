CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -O2 -I../../../utils

SRCS := $(wildcard *.cpp) $(wildcard ../../../utils/*.cpp)
TARGET := main

.PHONY: all build run clean

all: build

build: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: build
	./$(TARGET)

run-time: build
	time ./$(TARGET)

clean:
	rm -f $(TARGET)