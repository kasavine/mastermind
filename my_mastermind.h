
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct t_option{
    char* c;
    char* p;
    int t;
} t_option;

void my_memset(char* buff, char c, int size);
void my_bzero(char* buff, int size);
char* my_init(int size);
int is_option(char* str);
void set_option(t_option* option, char* name, char* key);
t_option* get_option(int ac, char **av);

int count_well_placed(char* code, char* guess);
int check_position(char* pieces, char c);
int* count_pieces(char* pieces, char* code);
int count_misplaced(char* code, char* guess, char* pieces);
void execute_game(char* code, char* pieces, int attempts);