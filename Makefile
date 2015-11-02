CC=g++
OUT=shell
TGT=it.cpp

default: command.o it.cpp
	$(CC) $(TGT) -o $(OUT) command.o

command.o: command.cpp
	$(CC) -c command.cpp -o command.o

clean: 
	rm $(OUT)
