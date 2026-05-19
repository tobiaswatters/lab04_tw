# Makefile
# Tobias Watters

CXX = g++
CXXFLAGS = -std=c++11 -Wall

SOURCES = heap.cpp examheap.cpp
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = examheap

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean