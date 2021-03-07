#include "my_mastermind.h"

void my_memset(char* buff, char c, int size){
    int index = 0;
    while (index < size)
    {
        buff[index] = c;
        index++;
    }
}

void my_bzero(char* buff, int size){
    my_memset(buff, 0, size);
}

char* my_init(int size){
    char* buff = (char*)malloc(size);
    my_bzero(buff, size);
    return buff;
}

int is_option(char* str){
    if (str[0] == '-')
        return 1;
    return 0;
}

void set_option(t_option* option, char* str){
    int i = 0;
    while (str[i]){
        if (str[i] == 'c')
            option->c = 1;
        if (str[i] == 'p')
            option->p = 1;
        if (str[i] == 't')
            option->t = 1;
        i++;
    }
}

t_option* get_option(int ac, char **av){
    t_option* option = (t_option*)my_init(sizeof(t_option));
    int i = 0;
    while (i < ac){
        if (is_option(av[i]) == 1){
            set_option(option, av[i] + 1);
        }
        i++;
    }
    return option;
}

// int main(int argc, char **argv)
// {
//     t_option* s = get_option(argc, argv);
//     printf("%d", s->p);
//     return 0;
// }
