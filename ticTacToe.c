#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <MMsystem.h>

int checkWin(char * square[]){
  if(square[1] == square[2] == square[3] || square[4] == square[5] == square[6] || square[7] == square[8] == square[9]){
    return 1;
  } else if(square[1] == square[4] == square[7] || square[2] == square[5] == square[8] || square[3] == square[6] == square[9]){
    return 1;
  } else if(square[1] == square[5] == square[9] || square[3] == square[5] == square[7]){
    return 1;
  } else if(square[1] != "1" && square[2] != "2" && square[3] != "3" && square[4] != "4" && square[5] != "5" && square[6] != "6" && square[7] != "7" && square[8] != "8" && square[9] != "9"){
    return 0;
  } else {
    return -1;
  }
}
void drawBoard(char * square[]){
  system("cls");
  printf("\n\n\t TicTacToe \n\n");
  printf("Player 1 (X) VS Player 2 (O) \n\n\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", square[1], square[2], square[3]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", square[4], square[5], square[6]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", square[7], square[8], square[9]);
  printf("     |     |     \n");
}


int main(){
  char answer;
  do{
    int player = 1, i , choice;
    char mark; //X or O
    char square[10] = {"o", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    do{
      drawBoard(square[10]);
      player = (player % 2) ? 1 : 2;
      printf("Player %d, enter the choice: ", player);
      scanf("%d", &choice);
      mark = (player == 1) ? 'X' : '0';
      for(int i = 1; i<10; i++){
        if(choice == i && square[i] == "i"){
          square[i] = mark;
        } else if (choice < 1 || choice > 9){
          print("Invalid option!");
          player--;
          getch();
        }
      }

      i = checkWin(square[10]);
      player++;

    } while (i == -1);

    drawBoard(square[10]);

    PlaySound(TEXT("D:\\Músicas\\win.mp3"), NULL, SND_SYNC);
    if(i == 1){
      printf(" Player 1 is the winner!\n");
    } else{
      printf(" Player 2 is the winner!\n");
    }

    printf(" Would you like to play again? (Y/N) : ");
    scanf("%c", &answer);
    printf("\n");

    getch();

  } while (answer == "Y");
  
  return 0;
}