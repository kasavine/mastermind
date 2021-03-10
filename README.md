# mastermind

## Before:
- git clone https://github.com/kasavine/mastermind.git
- cd mastermind
- make

## Run (play with default pieces)
- ./my_mastermind
- code: four symbols, ex: 1234 - chosen randomly by computer
- pieces: 01234567
- attempts: 10

## How to play not in a default mode
- ./my_mastermind -c 1234 -p 12346789 -t 5
- ./my_mastermind -c abcd -p abcdefgh -t 5
- -c stands for the code - after you provide code (4 symbols)
- -p stands for the pieces - after you proide your pieces (8 symbols)
- -t stands for attmepts - after you provide how many attempts (number)
