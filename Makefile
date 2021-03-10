CC		= gcc
FLAGS	= -Wall -Wextra -Werror
NAME	= my_mastermind

all: $(NAME)

$(NAME): get_options.o my_mastermind.o 
	$(CC) $(FLAGS) get_options.o my_mastermind.o -o $(NAME)

my_mastermind.o: my_mastermind.c 
	$(CC) $(FLAGS) -c my_mastermind.c

get_option.o: get_options.c 
	$(CC) $(FLAGS) -c get_options.c

clean:
	rm *.o $(NAME)

.PHONY: all clean
