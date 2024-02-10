# Bulls-and-Cows-Game
"Bulls and cows" is a code-breaking game played between two players: one who makes the code, and the other who tries to guess it. 

How it works?
The program receives a 4-digit code from the first player (input digits 0-9 followed by space) and allows the other player to guess it. The second player has 10 attempts to guess the code (also inputting digits 0-9 followed by space). With each guess, the program counts the number of matching digits and gives a hint to the second player: the number of bulls means that some digits match the code digits AND are in their right place; the number of cows suggests that there are as many matches with the first player's code, but the place and order are differing, which means that some digits need to be swapped. The game lasts until the second player guesses the code or runs out of all tries.
