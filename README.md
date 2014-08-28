Tic-Tac-Toe
===========

Game of tic tac toe in C++

This is a game in which the user plays against the computer. The computer is a little bit smart as it is able to recognize when the user has two symbols aligned or when he himself has two symbols aligned. When the computer has two symbols aligned, it will try to add a third symbol to win the game. When the user has two symbols aligned, the computer will try to add a third symbol in the same line to prevent the user to win. 
The main part of the program has a loop to allow the user to play multiple times.

Possible improvements: Add some intelligence to the computer who could put symbols only in positions that might lead to a win instead of putting them randomly. Add inheritance: the tic tac toe class could be a base class for other tic tac toe games with variations (bigger board, printing different symbols or letters, multiple players, ...). Add containment: we could have a super class that contains a vector/array? of tic tac toe games and keeps track of scores.
