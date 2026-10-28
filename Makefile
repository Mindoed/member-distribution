CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Ilib -Isrc

BUILD_DIR := build
TARGET    := main

SRCS := $(wildcard main.cpp src/*.cpp)
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: run c clear 

run: $(TARGET)
	./$(TARGET) in out

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

c: clear
clear:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
