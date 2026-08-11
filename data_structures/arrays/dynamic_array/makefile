CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

SRCS := $(wildcard *.cpp)
TARGET := main

.PHONY: all build run clean

all: build

build: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET)