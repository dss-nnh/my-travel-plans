#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<time.h>

#define ROWS 50
#define COLS 50
bool map[ROWS][COLS];


int count_cellsNumber(int xline,int yline)
{
	int living_cellsnumber=0,i,j;
	for(i=xline-1;i<=xline+1;i++){
		for(j=yline-1;j<=yline+1;j++){
			if(map[i][j]==1)
				living_cellsnumber++;
		}
	}
	living_cellsnumber=living_cellsnumber-1;
	return living_cellsnumber;
}


void cells_state(int xline,int yline)
{
	int living_cellsnumber=0;
	living_cellsnumber=count_cellsNumber(xline,yline);
	if((living_cellsnumber>=4)&&(map[xline][yline]==1))
		map[xline][yline]=0;
	else if((living_cellsnumber==3)&&(map[xline][yline]==0))
		map[xline][yline]=1;
	else if(living_cellsnumber==2);
	else if(((living_cellsnumber==1)||(living_cellsnumber==0))&&(map[xline][yline]==1))
		map[xline][yline]=0;
}	



void run_game()
{
	int i,j;
	while(1){
		system("cls");
		for(j=1;j<ROWS;j++){
			for(i=1;i<COLS;i++){
				if(map[i][j]==1)
					printf("●");
				else
					printf("○");
				if(i==49)
					printf("\n");
			}
		}
		for(j=1;j<ROWS;j++){
			for(i=1;i<COLS;i++){
				cells_state(i,j);
			}
		}
		Sleep(1);
		//getchar();
	}
}

void Date()
{
	int i,j;
	srand((unsigned)time(NULL));
	for(i=0;i<ROWS;i++){
		for(j=0;j<COLS;j++)
			map[i][j]=rand()%2;
	}
}


void main()
{
	system("mode con cols=100 lines=50");
	Date();
	run_game();
}
