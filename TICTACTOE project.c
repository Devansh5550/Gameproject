#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
 
char board[3][3];
const char PLAYER='X';
const char COMPUTER='O';


char square[10]={'0','1','2','3','4','5','6','7','8','9'};
int choice,player;
void displayboard();
void markboard(char mark);
int checkforWin();

void resetboard();
void printboard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);

int main()
{
    int mode;
    printf("CHOOSE GAME MODE :ENTER 1 FOR SINGLE PLAYER AND 2 FOR MULTIPLAYER \n");
    scanf("%d", &mode);
    if(mode==1){
    char winner=' ';
    resetboard();
    while(winner ==' ' && checkFreeSpaces() !=0)
    {
        printboard();
        playerMove();
        winner = checkWinner();
        
        if( winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
        
        computerMove();
         winner = checkWinner();
        
        if( winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
        
    }
    
    printboard();
    printWinner(winner);
    
    return 0;
}


 if (mode==2)
{
    int gamestatus;
    player=1;
 do {
    displayboard();
    player = (player % 2)?1:2;
    char mark = (player == 1)?'X': 'O';
 printf("PLAYER %d, please enter your choice :", player);
 scanf("%d", &choice);
 markboard(mark);
 gamestatus = checkforWin();
 player ++;

 } while (gamestatus ==-1);
 if(gamestatus==0){
    printf("==> GAME IS DRAWN <==\n");
 }
 if(gamestatus==1){
    printf("==> PLAYER %d is the winner <==", --player);
 }
 
 
 
 

}}


int checkforWin(){
    int gameStatus = 0;
    if(square[1]==square[2] && square[2]==square[3]){
        gameStatus=1;
    }
    else if (square[4]==square[5] && square[5]==square[6])
    {
        gameStatus=1;
    }
     else if (square[7]==square[8] && square[8]==square[9])
    {
        gameStatus=1;
    }
     else if (square[1]==square[4] && square[4]==square[7])
    {
        gameStatus=1;
    }
     else if (square[2]==square[5] && square[5]==square[8])
    {
        gameStatus=1;
    }
     else if (square[3]==square[6] && square[6]==square[9])
    {
        gameStatus=1;}
     
      else if (square[1]==square[5] && square[5]==square[9])
    {
        gameStatus=1;
    }
     else if (square[3]==square[5] && square[5]==square[7])
    {
        gameStatus=1;
    }
    else if (square[1]!='1' && square[2]!='2' && square[3]!='3' && square[4]!='4' && square[5]!='5' && square[6]!='6' && square[7]!='7' && square[8]!='8' && square[9]!='9'){
        gameStatus=0;
    }
    else{
        gameStatus = -1;
    }
    
    return gameStatus;
    
}


void displayboard () {
    
    printf("\n\n\n");
    printf("\n\n\t TIC TAC TOE \n\n");
    printf("Player-1(X)---- Player-2(O)\n");
    printf("\t   |   |   \n");
    printf("\t %c | %c | %c \n", square[1], square[2], square[3]);
    printf("\t___|___|___\n");
     printf("\t   |   |   \n");
    printf("\t %c | %c | %c \n", square[4], square[5], square[6]);
    printf("\t___|___|___\n");
     printf("\t   |   |   \n");
    printf("\t %c | %c | %c \n", square[7], square[8], square[9]);
    printf("\t   |   |   \n");
}
void markboard(char mark){
    if(choice==1){
        square[1]=mark;
    }
     else if(choice==2){
        square[2]=mark;
    }
     else if(choice==3){
        square[3]=mark;
    }
     else if(choice==4){
        square[4]=mark;
    }
     else if(choice==5){
        square[5]=mark;
    }
     else if(choice==6){
        square[6]=mark;
    }
    else if(choice==7){
        square[7]=mark;
    }
   else  if(choice==8){
        square[8]=mark;
    }
else if(choice==9){
        square[9]=mark;
 
   }
   else{
    printf("\tINVALID MOVE\n" );
     player--;
   }
}
void resetboard()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j]=' ';
        }
    }
}

void printboard()
{
    printf(" %c | %c | %c",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
    int freeSpaces=9;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!=' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove()
{
    int x;
    int y;
    do
    {
        printf("Enter row #(1-3): ");
        scanf("%d",&x);
        x--;
        printf("Enter columns #(1-3): ");
        scanf("%d",&y);
        y--;
    
        if(board[x][y]!=' ')
            {
               printf("Invalid Move!\n");
            }
        else
            {
               board[x][y]=PLAYER;
               break;
            }
    }
    
    while(board[x][y] !=' ');
}

char checkWinner()
{    
    //check rows
    for(int i=0;i<3;i++)
       {
         if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
           {
               return board[i][0];
           } 
       }
       
    //check columns
     for(int i=0;i<3;i++)
       {
         if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
           {
               return board[0][i];
           } 
       }
       
    //check 1st diagonal
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
           {
               return board[0][0];
           } 
    //check 2nd diagonal
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
           {
               return board[0][2];
           } 
           
           
     return ' ';
    
    
}

void computerMove()
{
    srand(time(0));
    int x;
    int y;
    
    if(checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        }
        while(board[x][y] != ' ');
        
        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}


void printWinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("YOU WIN");
    }
    else if(winner == COMPUTER)
    {
        printf("YOU LOSE!");
    }
    else
    {
        printf("IT'S A TIE!");
    }    
}