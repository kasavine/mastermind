# mastermind game

It is a simple game for one player (default mode).
- code will be randomly chosen by computer - 4 symbols
- from 8 pieces - 01234567
- and you have 10 attempts to guess

Or for two players.
- code you can provide after -c option - Ex.: -c 2222
- pieces you can provide after -p option - Ex.: -p 01234567
- attempts you can provide after -t option - Ex. -t 20

For each guess program provides feedback in the following form:
- Well placed pieces: 1   // are correct and in the correct position
- Misplaced pieces: 2   // are correct but in the wrong position.


#### Before
`git clone https://github.com/kasavine/mastermind.git`
`cd mastermind`
`make`

#### Run (play with default pieces)
`./my_mastermind`

#### How to play not in a default mode
`./my_mastermind -c XXXX -p XXXXXXXX -t X`
`./my_mastermind -c abcd -p abcdefgh -t 5`

If something is not provided - default mode