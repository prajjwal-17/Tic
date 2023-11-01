#include <stdio.h>
#include <conio.h>

void printBoard();
int checkWin();


char board[]={'0','1','2','3','4','5','6','7','8','9'};

void main() {
    int player = 1, input, status = -1;
    printBoard();

    while (status == -1) {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';
        printf("Please enter Number For Player %d\n", player);

        while (1) {
            scanf("%d", &input);
            if (input < 1 || input > 9) 
            {
                printf("Invalid input. Please enter a number between 1 and 9.\n");
            } 
            else if (board[input] != 'X' && board[input] != 'O') 
            {
                board[input] = mark;
                printBoard();
                break;  // Break out of the input loop when a valid move is made.
            }
            else 
            {
                printf("Invalid input. Cell already marked. Please choose an empty cell.\n");
            }
        }

        status = checkWin();

        if (status == 1) {
            printf("Player %d is the Winner", player);
            break;
        } else if (status == 0) {
            printf("Draw");
            break;
        }

        player++;
    }
}



void printBoard(){
    system("cls");
    printf("\n\n");
    printf("=== TIC TAC TOE ===\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[1],board[2],board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[4],board[5],board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[7],board[8],board[9]);
    printf("     |     |     \n");
    printf("\n\n");
}


int checkWin(){

    if(board[1]==board[2] && board[2]==board[3]){
        return 1;
    }
    if(board[1]==board[4] && board[4]==board[7]){
        return 1;
    }
    if(board[7]==board[8] && board[8]==board[9]){
        return 1;
    }
    if(board[3]==board[6] && board[6]==board[9]){
        return 1;
    }
    if(board[1]==board[5] && board[5]==board[9]){
        return 1;
    }
    if(board[3]==board[5] && board[5]==board[7]){
        return 1;
    }
    if(board[2]==board[5] && board[5]==board[8]){
        return 1;
    }
    if(board[4]==board[5] && board[5]==board[6]){
        return 1;
    }

    int count=0;
    for (int i = 1; i <=9; i++)
    {
        if(board[i]=='X' || board[i]=='O'){
            count++;
        }
    }
    
   if (count==9 ) 
   
    return 0; // All cells are filled, and there is no winner, so it's a draw. }
    return -1;
}