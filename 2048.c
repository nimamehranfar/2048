#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int game[4][4],i,j,b[4][4],chk[4][4],CHK;

int point=0;

void delay(unsigned int msec){
    clock_t goal = msec+clock();
    while(goal>clock() );
}

void table(void){
    char c[4][4];
    for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
                if (game[i][j]==0)
                    c[i][j]='.';
                else
                    c[i][j]=game[i][j];
		}
	}
    printf("\t\t\t\t+-------------------------------------+\t\tpoint=%2d\n\t\t\t\t| ________ ________ ________ ________ |\n\t\t\t\t||                                   ||\n\t\t\t\t||%5d   |%5d   |%5d   |%5d   ||\n\t\t\t\t|| ______   ______   ______   ______ ||\n",point,game[0][0],game[0][1],game[0][2],game[0][3]);
    printf("\t\t\t\t||                                   ||\n\t\t\t\t||%5d   |%5d   |%5d   |%5d   ||\n\t\t\t\t|| ______   ______   ______   ______ ||\n",game[1][0],game[1][1],game[1][2],game[1][3]);
    printf("\t\t\t\t||                                   ||\n\t\t\t\t||%5d   |%5d   |%5d   |%5d   ||\n\t\t\t\t|| ______   ______   ______   ______ ||\n\t\t\t\t||                                   ||\n\t\t\t\t||%5d   |%5d   |%5d   |%5d   ||\n",game[2][0],game[2][1],game[2][2],game[2][3],game[3][0],game[3][1],game[3][2],game[3][3]);
    printf("\t\t\t\t||________ ________ ________ ________||\n\t\t\t\t|                                     |\n\t\t\t\t+-------------------------------------+\n\n\t\t\t\t'w'for UP\t's'for DOWN\t'd'for RIGHT\t'a'for LEFT");
}

void clear_screen(void){
#ifdef WINDOWS
system("cls");
#else
system("cls");
#endif

}

int Maxarr(int game[4][4]){
int max = game[0][0],x,y;
	for (x = 0; x < 4; x++) {
            for(y=0;y<4;y++){
                if (game[x][y] > max)
                    max = game[x][y];
            }
	}
	return max;
}

void firstrandom(int game[4][4]) {
    delay(110);
    srand(clock());
	int r = (rand()%5)+1;
	int r1 = rand() % 4;
	int r2 = rand() % 4;
	int m;
	if (r <= 4)
		m = 2;
	else
		m = 4;
	if (game[r1][r2] == 0)
		game[r1][r2] = m;
	else
		firstrandom(game);
}

void random(int game[4][4]) {
    delay(20);
    srand(clock());
	int r = (rand()%4)+1;
	int r1 = rand() % 4;
	int r2 = rand() % 4;
	int m;
	if (r <= 3)
		m = 2;
	else
		m = 4;
	if (game[r1][r2] == 0)
		game[r1][r2] = m;
	else
		random(game);
}
void rotateboard(int game[4][4]){
int a[4][4];
a[0][0]=game[3][0];
a[0][1]=game[2][0];
a[0][2]=game[1][0];
a[0][3]=game[0][0];
a[1][0]=game[3][1];
a[1][1]=game[2][1];
a[1][2]=game[1][1];
a[1][3]=game[0][1];
a[2][0]=game[3][2];
a[2][1]=game[2][2];
a[2][2]=game[1][2];
a[2][3]=game[0][2];
a[3][0]=game[3][3];
a[3][1]=game[2][3];
a[3][2]=game[1][3];
a[3][3]=game[0][3];
int k1,k2;
for(k1=0;k1<4;k1++){
    for(k2=0;k2<4;k2++)
        game[k1][k2]=a[k1][k2];
}
}

void shiftright(int game[4][4]){

    for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
                b[i][j]=game[i][j];
		}
    }
    for(int i=0; i<4 ;i++) // Traverse from right to left of a row
	 for(int j=3; j>=0 ;j--)
	 { if(game[i][j]==0) // If tile is empty
	   { for(int k=j-1; k>=0 ;k--) // Traverse left to find a non-zero element
	 	  if(game[i][k]!=0)
            { game[i][j]=game[i][k]; // Move the non-zero element to the empty tile
                game[i][k]=0; // Assign the non-zero element with zero
                break;
            }
	   }
	 }
}

void sum(int game[4][4]){
    for(int i=0;i<4;i++){
        for(int j=3;j>=0;j--){
            if(game[i][j]!=0){
                int k=j-1;
                if(game[i][k]==game[i][j]){
                    game[i][j]+=game[i][k];
                    point+=game[i][j];
                    game[i][k]=0;
                }
            }
        }
    }
}

int check(void){
for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if(b[i][j] == game[i][j])
                chk[i][j]=1;
		}
	}
	if (chk[0][0]==1&&chk[0][1]==1&&chk[0][2]==1&&chk[0][3]==1&&chk[1][0]==1&&chk[1][1]==1&&chk[1][2]==1&&chk[1][3]==1&&chk[2][0]==1&&chk[2][1]==1&&chk[2][2]==1&&chk[2][3]==1&&chk[3][0]==1&&chk[3][1]==1&&chk[3][2]==1&&chk[3][3]==1)
        return 1;
    else
        return 0;
}

void getin(void){
for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			chk[i][j] = game[i][j];
		}
	}
}

int main()
{
    system("color 3E");
    char command;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			game[i][j] = 0;
		}
	}
	firstrandom(game);
	firstrandom(game);
    int maxarr=Maxarr(game);
    table();

    while(maxarr!=2048){
    command=getch();
    switch (command)
    {
case 'd':shiftright(game);getin();sum(game);
 CHK=check();if(CHK==0){
shiftright(game);clear_screen();random(game);table();break;}else{break;}
case 'w':rotateboard(game);shiftright(game);getin();sum(game);
 CHK=check();if(CHK==0){shiftright(game);rotateboard(game);rotateboard(game);rotateboard(game);clear_screen();random(game);table();break;}else{break;}
case 's':rotateboard(game);rotateboard(game);rotateboard(game);shiftright(game);getin();sum(game);
CHK=check();if(CHK==0){shiftright(game);rotateboard(game);clear_screen();random(game);table();break;}else{break;}
case 'a':rotateboard(game);rotateboard(game);shiftright(game);getin();sum(game);
 CHK=check();if(CHK==0){shiftright(game);rotateboard(game);rotateboard(game);clear_screen();random(game);table();break;}else{break;}
    }
    maxarr=Maxarr(game);
    }
clear_screen();
printf("You Win");
a1:
delay(5000);
clear_screen();
printf("Are You Want To Countinue?\n  Press 'y' For Yes And 'n' For No !!");
command=getch();
if(command=='n')
{
    clear_screen();
    printf("Game Ended\nHope You Enjoyed It!\n\n");
    return 0;
}
else if(command=='y'){
    clear_screen();
    table();
while(1>0){


    command=getch();
    switch (command)
    {
case 'd':shiftright(game);sum(game);shiftright(game);clear_screen();random(game);table();break;
case 'w':rotateboard(game);shiftright(game);sum(game);shiftright(game);rotateboard(game);rotateboard(game);rotateboard(game);clear_screen();random(game);table();break;
case 's':rotateboard(game);rotateboard(game);rotateboard(game);shiftright(game);sum(game);shiftright(game);rotateboard(game);clear_screen();random(game);table();break;
case 'a':rotateboard(game);rotateboard(game);shiftright(game);sum(game);shiftright(game);rotateboard(game);rotateboard(game);clear_screen();random(game);table();break;
    }
}
    return 0;
}
else
    goto a1;
}
