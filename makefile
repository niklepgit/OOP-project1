CC=g++
CFLAGS=-Wall

prog:main.o waggon.o train.o passenger.o list.o
	$(CC) $(CFLAGS) -o prog main.o waggon.o train.o passenger.o list.o

main.o:main.cpp train.h passenger.h waggon.h list.h
	$(CC) $(CFLAGS) -c main.cpp

waggon.o:waggon.cpp waggon.h passenger.h list.h train.h
	$(CC) $(CFLAGS) -c waggon.cpp

train.o:train.cpp train.h waggon.h
	$(CC) $(CFLAGS) -c train.cpp

passenger.o:passenger.cpp passenger.h 
	$(CC) $(CFLAGS) -c passenger.cpp

list.o:list.cpp list.h 
	$(CC) $(CFLAGS) -c list.cpp 

clean:
	rm *.o -f