//Returns the line read from stdin
char *lsh_read_line(void);

//Splits the line read from stdin into args
char **lsh_split_line(char *line);

int lsh_launch(char **args);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_execute(char **args);
