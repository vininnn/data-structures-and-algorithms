CXX := g++
CXXFLAGS := -Wall -Wextra -Wpedantic -std=c++17
SANITIZER_FLAGS := -fsanitize=address,undefined -g -O1

SRCS := $(wildcard *.cpp)
HEADERS := $(wildcard *.hpp)

# main.cpp -> main, linear.cpp -> linear, quadratic.cpp -> quadratic
TARGETS := $(patsubst %.cpp,%,$(SRCS))
SANITIZER_TARGETS := $(addsuffix _sanitize,$(TARGETS))
RUN_TARGETS := $(addprefix run-,$(TARGETS))
SANITIZE_RUN_TARGETS := $(addprefix sanitize-,$(TARGETS))

.PHONY: all build clean $(RUN_TARGETS) $(SANITIZE_RUN_TARGETS)

all: build

build: $(TARGETS)

$(TARGETS): %: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@

$(SANITIZER_TARGETS): %_sanitize: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SANITIZER_FLAGS) $< -o $@

$(RUN_TARGETS): run-%: %
	./$<

$(SANITIZE_RUN_TARGETS): sanitize-%: %_sanitize
	./$<

clean:
	rm -f $(TARGETS) $(SANITIZER_TARGETS)