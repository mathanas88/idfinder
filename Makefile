CXX := g++
CXX_FLAGS := -Wall -Wextra -g -std=c++11
#CXX_LIBS := -l boost_regex -L/usr/lib/x86_64-linux-gnu/libboost_regex.so
CXX_LIBS := /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.53.0

all: id_finder
	
id_finder: main.o
	$(CXX) $(CXX_FLAGS) $(CXX_LIBS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

.PHONY: clean
clean:
	- rm *.o id_finder

