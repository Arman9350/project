#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

char square[10]={'0','1','2','3','4','5','6','7','8','9'};
int checkwin();
void drawboard();

int main()
{

    int player = 1,i,choice;
    char mark; // X,O
    do
    {
        drawboard();
        player = (player % 2) ? 1 : 2;
        printf("player %d, enter  the choice :  ",player);
        scanf("%d",&choice);
        mark = (player == 1) ?  'X':'O';
            if (choice == 1 && square[1] == '1')
            square[1] = mark;
            else if(choice == 2 && square [2] == '2')
            square[2] = mark;
            else if(choice == 3 && square[3] == '3')
            square[3] = mark;
            else if(choice == 4 && square [4] == '4')
            square[4] = mark;
            else if(choice == 5 && square [5] == '5')
            square[5] = mark;
            else if(choice == 6 && square [6] == '6')
            square[6] = mark;
            else if(choice == 7 && square [7] == '7')
            square[7] = mark;
            else if(choice == 8 && square [8] == '8')
            square[8] = mark;
            else if(choice == 9 && square [9] == '9')
            square[9] = mark;

            else{
                printf("invalid option ! \n");
                player--;
                return -1;
            }
        i=checkwin();
        player++; 
    }
     while(i==-1); 
    
    drawboard();
     if(i==1)
     { 
         printf("\nCongratulations! Player %d wins!\n",--player);
     }
            else
            {
                printf( "\nIt's a draw!");
            }
                getch();
                return 0;
            
}
int checkwin(){
    if(square[1] == square[2] && square[2] == square[3])
    return 1;
    else if (square[4] == square[5] && square[5] == square[6])
    return 1;
    else if (square[7] == square[8] && square[8] == square[9])
    return 1;
    else if (square[1] == square[4] && square[4] == square[7])
    return 1;
    else if (square[2] == square[5] && square[5] == square[8])
    return 1;
    else if (square[3] == square[6] && square[6] == square[9])
    return 1;
    else if (square[1] == square[5] && square[5] == square[9])
    return 1;
    else if (square[3] == square[5] && square[5] == square[7])
    return 1;
    else if (square[1] !='1' && square[2] !='2' && square[3] !='3' && square[4] !='4' && square[5] !='5' && square[6] !='6' && square[7] !='7' && square[8] !='8' && square[9] !='9')
    return 0;
    else
    return -1; //if the board is not filled yet, it returns -1.

}
void drawboard()
{
    printf("\n\n\t tic-tac-toe \n\n");
    printf("pplayer1 (X) - player2 (O) \n\n\n");
    printf("    |    |    \n");
    printf("  %c |  %c |  %c \n", square[1], square[2], square[3]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf("  %c |  %c |  %c \n", square[4], square[5], square[6]);
    printf("____|____|____\n"); 
    printf("    |    |    \n");
    printf("  %c |  %c |  %c \n", square[7], square[8], square[9]);
    printf("    |    |    \n");

}




