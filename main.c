#include "my_mastermind.h"

//  1    2    3   4         5  6
// -c "1234" -p "01234567" -t 10
int main(int ac, char **av)
{
    char* code = (char*)malloc(sizeof(char) * 5);
    char* pieces;
    char* attempts;

    int i = 0;
    t_option* options = get_option(ac, av);
    while (i < ac){
        if (options->c == 1){
            printf("My printf for argument of -c: |%s|\n", av[i+1]);
        }
        else
            code = "1234";
            printf("My printf if no argument: |%s|\n", code);

        if (options->p == 1)
            printf("My printf for argument of -p: |%s|\n", av[i+1]);
        else
            pieces = "01234567";
            printf("My printf if no argument: |%s|\n", pieces);

        if (options->t == 1){
            printf("My printf for argument of -t: |%s|\n", av[i+1]);
        }
        else
            attempts = "10";
            printf("My printf if no argument: |%s|\n", attempts);
        i++;
    }
    execute_game(code, pieces, atoi(attempts));
    return 0;
}

// int main(){
//     execute_game("3333", "01234567", 10);
//     return (0);
// }