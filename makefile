SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj
BIN_DIR := bin

CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -MMD -MP -I$(INC_DIR)

# Output executable name
EXECUTABLE := $(BIN_DIR)/MatrixApp

# Automatically takes the whole .cpp files in currect directory
SOURCE_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCE_FILES))
DEP_FILES := $(OBJ_FILES:.o=.d)

$(EXECUTABLE) : $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(EXECUTABLE)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ_DIR) $(BIN_DIR) 

# Also include dependencies
-include $(DEP_FILES)
