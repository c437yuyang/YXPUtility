CC=g++
CFLAGS= -std=c++11 -g -Wall -lpthread -lgtest 
src=$(wildcard *.cpp)
obj=$(patsubst %.cpp,%.o,$(src))
target=YXPUtilityTest

all:$(obj)
	 $(CC) $(obj) $(CFLAGS) -o YXPUtilityTest

%.o:%.cpp
	$(CC) $(CFLAGS) $< -I../ -c -o $@ 


.PHONY:clean test
clean:
	-rm -f $(target) $(obj)
test:
	./YXPUtilityTest
