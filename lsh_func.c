#include <stdio.h>
#include <stdlib.h>
#include "lsh_funcs.h"

#define LSH_RL_BUFSIZE 1024

//lsh_read_line()
//
//Reads a line from stdin and returns the line read on EOF or newline. Resizes buffer if input exceeds LSH_RL_BUFSIZE (can be implemented with getline - automatically resizes buffer).
//
//Returns: Failure on allocation error, else the line read as a null-terminated string.
char *lsh_read_line(void) {
	int bufferSize = LSH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c; //character being read
	
	//buffer isn't allocated properly
	if (!buffer) {
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while(true) {
		c = getchar();

		//if eof or new line, replace w null terminator
		//note to self: eof from stdin means ctrl-d
		if (c == EOF || c == '\n') {
			buffer[position] = '\0';
			return buffer;
		}
		else {
			buffer[position] = c;
		}
	position++;

	//if position (chars read) is more than the buffer,
	//double the buffer and realloc
	if (position >= bufsize) {
		bufsize += LSH+RL_BUFSIZE;
		buffer = realloc(buffer, bufsize);
		if (!buffer) {
			fprintf(stderr, "lsh: allocation error\n");
			exit(EXIT_FAILURE);
			}
		}
	}
}


