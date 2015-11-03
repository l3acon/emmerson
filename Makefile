CC=g++
CFLAGS= -O3 #-v
OUT=shell
TGT=it.cpp


default: cmds.o it.cpp command.o
	$(CC) $(CFLAGS) $(TGT) -o $(OUT) cmds.o command.o

cmds.o: cmds.cpp command.o
	$(CC) $(CFLAGS)  -c cmds.cpp -o cmds.o

command.o: command.cpp
	$(CC) $(CFLAGS) -c command.cpp -o command.o

clean: 
	rm *.o
	rm -f $(OUT)
