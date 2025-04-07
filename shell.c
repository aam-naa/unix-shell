#include <stdio.h>
#include <stdlib.h>
#include "lhs_funcs.h"

//lsh_loop()
//Read, parse and execute command from stdin.
void lsh_loop(void) {
	char *line; //line being read
	char **args; //line is split into args
	int status; //status returned by lsh_execute()
	
	//do-while so we have a value for status
	do {
		printf("> "); //print prompt
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
	} while (status);

}

int main(int argc, char* argv) {
	printf("hello world");
	exit(0);
}
