#include "tic_tac_toe.h"



int main(void){


   tictactoe_t gameHandler = is_game_solved();

   if(gameHandler.Osolved){
      puts("O wins !!!");
   }
   else if(gameHandler.Xsolved){
      puts("X wins !!!");
   }

   else if(!gameHandler.Xsolved && !gameHandler.Osolved){
      puts("Its a draw!! Nice game!!");
   }

   
   return EXIT_SUCCESS;
}