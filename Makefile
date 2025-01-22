# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I./nlohmann

# Source files and output binary
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = cfs-scheduler

# Build target
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(SRC_DIR)/*.o main.o $(TARGET)
