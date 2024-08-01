#include "tic_tac_toe.h"

/**
 * @brief: Checks if the game is solved horizontally
 * 
 * @param: gameHandler
 */
static void check_horizontal(tictactoe_t * gameHandler){

   // Determines whether a horizontal row has been solved/won using X
   if(((gameHandler->gamePositions[0][0] & gameHandler->gamePositions[0][1] & gameHandler->gamePositions[0][2]) == X) ||
      ((gameHandler->gamePositions[1][0] & gameHandler->gamePositions[1][1] & gameHandler->gamePositions[1][2]) == X) ||
      ((gameHandler->gamePositions[2][0] & gameHandler->gamePositions[2][1] & gameHandler->gamePositions[2][2]) == X)){
         
         // Sets the Xsolved and isGameSolved flags to true and exits the function
         gameHandler->Xsolved = true;
         gameHandler->isGameSolved = true;
         
         return;
      }
   
   // Determines whether a horizontal row has been solved/won using O
   else if(((gameHandler->gamePositions[0][0] & gameHandler->gamePositions[0][1] & gameHandler->gamePositions[0][2]) == O) ||
           ((gameHandler->gamePositions[1][0] & gameHandler->gamePositions[1][1] & gameHandler->gamePositions[1][2]) == O) ||
           ((gameHandler->gamePositions[2][0] & gameHandler->gamePositions[2][1] & gameHandler->gamePositions[2][2]) == O)){

         // Sets the Osolved and isGameSolved flags to true and exits the function
         gameHandler->Osolved = true;
         gameHandler->isGameSolved = true;

         return;
      }

}

/**
 * @brief: Checks if the game is solved vertically
 * 
 * @param: gameHandler
 */
static void check_vertical(tictactoe_t * gameHandler){

   // Determines whether a vertical column has been solved/won using X
   if(((gameHandler->gamePositions[0][0] & gameHandler->gamePositions[1][0] & gameHandler->gamePositions[2][0]) == X) ||
      ((gameHandler->gamePositions[0][1] & gameHandler->gamePositions[1][1] & gameHandler->gamePositions[2][1]) == X) ||
      ((gameHandler->gamePositions[0][2] & gameHandler->gamePositions[1][2] & gameHandler->gamePositions[2][2]) == X)){
        
         // Sets the Xsolved and isGameSolved flags to true and exits the function
         gameHandler->Xsolved = true;
         gameHandler->isGameSolved = true;
         
         return;
      }

   // Determines whether a vertical column has been solved/won using O
   else if(((gameHandler->gamePositions[0][0] & gameHandler->gamePositions[1][0] & gameHandler->gamePositions[2][0]) == O) ||
         ((gameHandler->gamePositions[0][1] & gameHandler->gamePositions[1][1] & gameHandler->gamePositions[2][1]) == O) ||
         ((gameHandler->gamePositions[0][2] & gameHandler->gamePositions[1][2] & gameHandler->gamePositions[2][2]) == O)){
            
            // Sets the Osolved and isGameSolved flags to true and exits the function
            gameHandler->Osolved = true;
            gameHandler->isGameSolved = true;

            return;
         }
   
}

/**
 * @brief: Checks if the game is solved diagonally
 * 
 * @param: gameHandler
 */
static void check_diagonal(tictactoe_t * gameHandler){

   // Determines whether a diagonal has been solved/won using X
   if(((gameHandler->gamePositions[0][0] & gameHandler->gamePositions[1][1] & gameHandler->gamePositions[2][2]) == X) ||
      ((gameHandler->gamePositions[0][2] & gameHandler->gamePositions[1][1] & gameHandler->gamePositions[2][0]) == X)){
      
      // Sets the Xsolved and isGameSolved flags to true and exits the function
      gameHandler->Xsolved = true;
      gameHandler->isGameSolved = true;
      return;
      
   }
   
   // Determines whether a diagonal has been solved/won using O
   else if(((gameHandler->gamePositions[0][0] & gameHandler->gamePositions[1][1] & gameHandler->gamePositions[2][2]) == O) ||
           ((gameHandler->gamePositions[0][2] & gameHandler->gamePositions[1][1] & gameHandler->gamePositions[2][0]) == O)){
         
      // Sets the Osolved and isGameSolved flags to true and exits the function
      gameHandler->Osolved = true;
      gameHandler->isGameSolved = true;

      return;
   }

}
/**
 * @brief: Prompts the user for the row index
 * 
 * @param: none
 */
static uint8_t get_row_index(void){

   int rowIndex = 255U; 
   // Prompts the user for the row index         
   printf("Enter the row index: ");
   rowIndex = (uint8_t)getchar();
   // Flush the output to remove any trailing characters
   (void)fflush(stdin);

   // Convert the rowIndex value to a uint8_t
   rowIndex = (uint8_t)(rowIndex - (char)ASCII_CONST);

   // Handles any incorrect values
   while(rowIndex < 0 || rowIndex > 2) {

      puts("Error: Invalid row. Row index value must be 0, 1, 2");
      printf("Enter the row index: ");
      rowIndex = (uint8_t)getchar();
      // Flush the output to remove any trailing characters
      (void)fflush(stdin);

      // Convert the rowIndex value to a uint8_t
      rowIndex = (uint8_t)(rowIndex - (char)ASCII_CONST);
   }

   // Returns the row index
   return rowIndex;
}
/**
 * @brief: Prompts the user for the column index
 * 
 * @param: none
 */
static uint8_t get_column_index(void){

   uint8_t colIndex = 255U;
   // Prompts the user for the column index
   printf("Enter the column index: ");
   colIndex = (uint8_t)getchar();

   // Flush the output to remove any trailing characters
   (void)fflush(stdin);

   // Convert the colIndex value to a uint8_t
   colIndex = (uint8_t)(colIndex - (char)ASCII_CONST);
   // Handles any incorrect values
   while(colIndex < 0 || colIndex > 2) {
      puts("Error: Invalid column. Column index value must be 0, 1, 2");
      printf("Enter the column index :");
      colIndex = (uint8_t)getchar();
      // Flush the output to remove any trailing characters
      (void)fflush(stdin);

      // Convert the colIndex value to a uint8_t
      colIndex = (uint8_t)(colIndex - (char)ASCII_CONST);
   }

   // Returns the column index
   return colIndex;

}

/**
 * @brief: Prompts the user for the game character (X or O) they wish to enter
 * @param: none
 */

static char get_game_char(void){

   char charEntry  = 0U;

   // Prompts the user for the Character
   printf("Enter game character (X or O): ");
   charEntry = (char)getchar();
   // Flushes the output to remove any trailing characters
   (void)fflush(stdin);
   // Handles any incorrect values
   while(charEntry != X && charEntry != O){

      puts("Error: Invalid character, please enter X or O");
      printf("Enter game character (X or O): ");
      charEntry = getchar();
      // Flushes the output to remove any trailing characters
      (void)fflush(stdin);
   }

   // Returns the character entry
   return charEntry;
}
/**
 * @brief: Prints the game board
 * 
 * @param: game (Current game board)
 */
static void print_tictactoe_game(char game[MAX_DIMENSIONS][MAX_DIMENSIONS]){

   uint8_t i = 0, j = 0;

   // Prints the game board
   for(i = 0; i < MAX_DIMENSIONS; i++){

      for(j = 0; j < MAX_DIMENSIONS; j++){
         
         if(j < MAX_DIMENSIONS - 1){
            printf(" %c |", game[i][j]);
         }
         else{
            printf(" %c ", game[i][j]);
         }

      }
      if(i < MAX_DIMENSIONS - 1)
         printf("\n--- --- --- \n");
      else{
         putchar((char)'\n');
      }
   }
   
}

/**
 * @brief: This function launchs a tic tac toe game and plays by prompting the user for a row and column index to put their      desrised character
 * 
 * @param: none
 */
tictactoe_t is_game_solved(void){

   // Creates the game board
   char game[MAX_DIMENSIONS][MAX_DIMENSIONS] = {{' ', ' ', ' '},
                                                {' ', ' ', ' '},
                                                {' ', ' ', ' '}};
                                                
   // Initialises the game handler.
   tictactoe_t gameHandler = {
      .isGameSolved = false,
      .quitGame = false,
      .gameTurnsCount = 0U,
      .errCode = (uint8_t)false,
      .Xsolved = false, 
      .Osolved = false
   };
   size_t len = sizeof(char) * MAX_DIMENSIONS * MAX_DIMENSIONS;
   memcpy(gameHandler.gamePositions, game, len);

   // Prints the empty game board out
   printf("---STARTING GAME---\n");
   print_tictactoe_game(gameHandler.gamePositions);

   // Initialises the input variables for the character entry, row index and column index.
   char tmpCharEntry = 0;
   char prevEntry    = 0;
   uint8_t rowIndex = 255U;
   uint8_t colIndex = 255U;

   // The game is played in this while loop
   while(gameHandler.gameTurnsCount != 9 && gameHandler.isGameSolved != true){

      // Gets the row index
      rowIndex = get_row_index();
      // Gets the column index
      colIndex = get_column_index();
      while(gameHandler.gamePositions[rowIndex][colIndex] != ' '){
         puts("Error: Cell already contains a character");
         // Gets the row index
         rowIndex = get_row_index();
         // Gets the column index
         colIndex = get_column_index();

      }
      // Gets the character entry
      tmpCharEntry = get_game_char();

      while(tmpCharEntry == prevEntry){
         puts("Error: Invalid entry, it's the other players turn");
         tmpCharEntry = get_game_char();

      }
      // Places the user character at the specified location
      gameHandler.gamePositions[rowIndex][colIndex] = tmpCharEntry;
      // Prints out the current game board
      print_tictactoe_game(gameHandler.gamePositions);

      // Checks the vertical, diagonal and horizontal ... to determine if there is a winner
      check_diagonal(&gameHandler);
      check_horizontal(&gameHandler);
      check_vertical(&gameHandler);
      

      prevEntry = tmpCharEntry;
      // Increments the number of turns played so far in the game.
      gameHandler.gameTurnsCount++;

   }
   
   // Returns the game handler
   return gameHandler;
}
