CC=g++
OUT=shell
TGT=it.cpp

default: commands.o it.cpp command.o
	$(CC) $(TGT) -o $(OUT) commands.o command.o

commands.o: commands.cpp command.o
	$(CC) -c commands.cpp -o commands.o

command.o: command.cpp
	$(CC) -c command.cpp -o command.o

clean: 
	rm *.o
	rm -f $(OUT)
