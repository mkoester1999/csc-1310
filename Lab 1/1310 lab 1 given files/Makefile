CC = g++
CFLAGS = -std=c++11 -Wall

all: driver

driver: course.o driver.o
    $(CC) $(CFLAGS) -o driver course.o driver.o

course.o: course.cpp course.h
    $(CC) $(CFLAGS) -c course.cpp

driver.o: driver.cpp course.h
    $(CC) $(CFLAGS) -c driver.cpp

clean:
    rm -rf *.o driver
