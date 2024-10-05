CXX = g++

CXXFLAGS = -Wall -g -Iinclude

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

EXECUTABLE = $(BIN_DIR)/app.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR) 
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)     
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
	@if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)
