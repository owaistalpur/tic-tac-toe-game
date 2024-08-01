#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_DIMENSIONS 3
#define X           'X'
#define O           'O'
#define ASCII_CONST '0'
typedef struct _ticHandler{

   char gamePositions[MAX_DIMENSIONS][MAX_DIMENSIONS];
   
   uint8_t gameTurnsCount;
   uint8_t errCode;
   bool Xsolved, Osolved;
   bool isGameSolved;
   bool quitGame;

}tictactoe_t;

tictactoe_t is_game_solved(void);