#arm-linux-g++
CXX = g++ -std=c++11   
CXXFLAGS = -Iinc
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin

# 自动生成源文件列表和目标文件列表
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

TARGET = $(BIN_DIR)/main

# 默认目标
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译源文件生成目标文件
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# 创建必要的目录
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# 清理生成的文件
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
