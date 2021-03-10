#include "my_mastermind.h"

int count_well_placed(char* code, char* guess){
    int count = 0;
    int i = 0;
    while (code[i]){
        if (code[i] == guess[i])
            count++;
        i++;
    }
    return (count);
}

int check_position(char* pieces, char c){
    int i = 0;
    while (pieces[i]){
        if (pieces[i] == c){
            return (i);
        }
        i++;
    }
    return (-1);
}

int* count_pieces(char* pieces, char* code){
    int* result_array = (int*)malloc(sizeof(int) * 8+1);
    int pos;
    int i = 0;
    while (code[i]){
        pos = check_position(pieces, code[i]);
        result_array[pos]++;
        i++;
    }
    return (result_array);
}

int count_misplaced(char* code, char* guess, char* pieces){
                                                            //  a b c d e f 
    int* code_array = count_pieces(pieces, code); // aab        // [2 1 0 0 0 0]
    int* guess_array = count_pieces(pieces, guess); // abc      // [1 1 1 0 0 0]
    int result = 0;
    int i = 0;
    while (i < 8){
        int left = code_array[i];
        int right = guess_array[i];

        if (left < right){
            result += left;
        }
        else {
            result += right;
        }
        i++;

    }   
    return (((int)result) - (count_well_placed(code, guess)));
}

void execute_game(char* code, char* pieces, int attempts){
    if ((strlen(code) == 4) && (strlen(pieces) == 8)){

        char *guess = (char*)malloc(sizeof(char) * 5);
        int i = 0;
        
        while (i < attempts){
            printf("Attempt number %d. Enter 4 digits: \n", i + 1);
            read(0, guess, 5);
            guess[4] = '\0';

            if (strcmp(guess, code) == 0){
                printf("Mm-hmm! That is THE number.\n");
                break;
            } 
            else {
                printf("It is not the number\n");
                printf("Well placed pieces: %d\n", count_well_placed(code, guess));
                printf("Misplaced pieces: %d\n\n", count_misplaced(code, guess, pieces));
                printf("Code: %s\n", code);
                printf("Guess: %s\n", guess);
                printf("Pieces: %s\n", pieces);
            }
            i++;
            if (i == attempts){
                printf("That was your last attempt. You lost");
            }
        }
    }
    else{
        printf("4 digits code, 8 pieces of elements");
    }
}

char* gen_random(char* pieces){
    char* res = (char*)malloc(sizeof(char) * 5);
    int i = 0;
    while (i < 4){
        res[i] = pieces[rand() % 4];
        i++;
    }
    res[4] = '\0';
    return res;
}

int main(int ac, char **av)
{
    char* code;
    int i = 0;
    t_option* options = get_option(ac, av);
    while (i < ac){
        if (options->c == 1){
            if (is_option(av[i+1]) == 0)
                code = av[i+1];
        }
        else {
            code = gen_random("01234567");
        }
        i++;
    }
    execute_game(code, "01234567", 6);
    return 0;
}
