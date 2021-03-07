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
    int* result_array = (int*)malloc(sizeof(int) * 8);
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
    int* code_a = count_pieces(pieces, code); // aab        // [2 1 0 0 0 0]
    int* guess_a = count_pieces(pieces, guess); // abc      // [1 1 1 0 0 0]
    int result = 0;
    int i = 0;
    while (i < 8){
        int left = code_a[i];
        int right = guess_a[i];

        if (left < right){
            result += left;
        }
        else {
            result += right;
        }
        i++;
    }   
    return (result - count_well_placed(code, guess));
}

void execute_game(char* code, char* pieces, int attempts){
    // char* pieces = "01234567";
    // int attempts = 5;
    char *guess = (char*)malloc(sizeof(char) * 5);
    int i = 0;
    
    while (i < attempts){
        printf("Attempt number %d. Enter 4 digits: \n", i + 1);
        read(0, guess, 5);
        guess[4] = '\0';

        if (strcmp(guess, code) == 0){
            printf("Smart one\n");
            break;
        } 
        else {
            printf("It is not the number\n");
            printf("Well placed pieces: %d\n", count_well_placed(code, guess));
            printf("Misplaced pieces: %d\n", count_misplaced(code, guess, pieces));
        }
        i++;
        if (i == attempts){
            printf("That was your last attempt. You lost");
        }
    }
}

// int main(){
//     char* code = "1234";
//     execute_game(code);
//     return (0);
// }

// int main() {
//     char* pieces = "01234567";
//     char* code = "1033";
//    int *array = count_pieces(pieces, code);
//    int loop;

//    for(loop = 0; loop < 8; loop++)
//       printf("%d ", array[loop]);
      
//    return 0;
// }