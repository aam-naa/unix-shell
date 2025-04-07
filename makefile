CC = gcc
TARGET = run_shell

default: shell 

shell: shell.o
	$(CC) shell.o -o $(TARGET)

shell.o: shell.c
	$(CC) -c shell.c

clean:
	del /f *.o $(TARGET).exe
