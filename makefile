CXX = clang++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

SRCS := $(wildcard *.cpp)

OBJS := $(patsubst %.cpp, %.o, $(SRCS))

PROGRAM = data

all: $(PROGRAM)

$(PROGRAM):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM)$(OBJS)

%.o:%.cpp LinkedList.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(PROGRAM) $(OBJS)

