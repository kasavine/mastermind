CC		= gcc
FLAGS	= -g3 -fsanitize=address -Wall -Wextra -Werror
NAME	= my_mastermind

all: $(NAME)

$(NAME): main.o get_options.o my_mastermind.o 
	$(CC) $(FLAGS) main.o get_options.o my_mastermind.o -o $(NAME)

my_mastermind.o: my_mastermind.c 
	$(CC) $(FLAGS) -c my_mastermind.c

get_option.o: get_options.c 
	$(CC) $(FLAGS) -c get_options.c

main.o: main.c 
	$(CC) $(FLAGS) -c main.c

clean:
	rm *.o $(NAME)

.PHONY: all clean
