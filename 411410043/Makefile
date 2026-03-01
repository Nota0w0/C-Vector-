CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
BIN_DIR = bin
TARGET = $(BIN_DIR)/overloading_vectors.out

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Rules
all: directories $(TARGET)

# Create necessary directories
directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

# Compile the target executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean rule
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean directories