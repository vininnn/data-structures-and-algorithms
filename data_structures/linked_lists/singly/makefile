CXX := g++
CXXFLAGS := -Wall -Wextra -Wpedantic -std=c++17
SANITIZER_FLAGS := -fsanitize=address,undefined -g -O1

SRCS := $(wildcard *.cpp)
TARGET := main
SANITIZER_TARGET := main_sanitize

.PHONY: all build run sanitize clean

all: build

build: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: build
	./$(TARGET)

$(SANITIZER_TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SANITIZER_FLAGS) $(SRCS) -o $(SANITIZER_TARGET)

sanitize: $(SANITIZER_TARGET)
	./$(SANITIZER_TARGET)

clean:
	rm -f $(TARGET) $(SANITIZER_TARGET)
