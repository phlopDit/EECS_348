CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g -Iinclude

TARGET = build/evaluator

SRC_DIR = src
BUILD_DIR = build

SRCS = 	src/main.cpp \
				src/ExpressionError.cpp \
				src/Token.cpp \
				src/Tokenizer.cpp \
				src/Parser.cpp \
				src/NumberNode.cpp \
				src/UnaryOpNode.cpp \
				src/BinaryOpNode.cpp 

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)