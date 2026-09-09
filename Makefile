CXX := c++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
BUILD_DIR := build

all: $(BUILD_DIR)/algorithms_demo $(BUILD_DIR)/algorithms_tests

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/algorithms.o: src/algorithms.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: examples/main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/test_algorithms.o: tests/test_algorithms.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/algorithms_demo: $(BUILD_DIR)/algorithms.o $(BUILD_DIR)/main.o
	$(CXX) $^ -o $@

$(BUILD_DIR)/algorithms_tests: $(BUILD_DIR)/algorithms.o $(BUILD_DIR)/test_algorithms.o
	$(CXX) $^ -o $@

test: $(BUILD_DIR)/algorithms_tests
	./$(BUILD_DIR)/algorithms_tests

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean
