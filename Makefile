# 编译器
CC := g++

# 编译器标志
CFLAGS := -Wall -Iinclude -MMD -std=c++20

# 链接器标志
LDFLAGS := -Lbin -lSDL2

# 源文件
SRCS := $(wildcard src/*.cpp)

# 目标文件
OBJS := $(patsubst src/%.cpp,obj/%.o,$(SRCS))

# 依赖文件
DEPS := $(OBJS:.o=.d)

# 可执行文件
TARGET := bin/test

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking..."
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

obj/%.o: src/%.cpp
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(TARGET)
	@echo "Running..."
	@./$(TARGET)

clean:
	@echo "Cleaning..."
	@rm -f $(OBJS) $(DEPS) $(TARGET)

-include $(DEPS)

.PHONY: all run clean