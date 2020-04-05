#include<stdio.h>
#include<stdlib.h>
#include <windows.h>

//Ï¸°û¹æÔò
int map[50][50];
// living 1;
// death 0;


int Count_cellsNumber(int xline,int yline)
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
	living_cellsnumber=Count_cellsNumber(xline,yline);
	if((living_cellsnumber>=4)&&(map[xline][yline]==1))
		map[xline][yline]=0;
	else if((living_cellsnumber==3)&&(map[xline][yline]==0))
		map[xline][yline]=1;
	else if(living_cellsnumber==2);
	else if(((living_cellsnumber==1)||(living_cellsnumber==0))&&(map[xline][yline]==1))
		map[xline][yline]=0;

}


void Run_game()
{
	int i,j;
	while(1){
		system("cls");
		for(j=1;j<50;j++){
			for(i=1;i<50;i++){
				if(map[i][j]==1)
					printf("¨€");
				else
					printf("  ");
				if(i==49)
					printf("\n");
			}
		}
		for(j=1;j<50;j++){
			for(i=1;i<50;i++){
				cells_state(i,j);
			}
		}
		Sleep(10);
	}
}

void Date()
{
	int i,j;
	map[5][5]=1;
	map[5][6]=1;
	map[4][4]=1;
	map[4][14]=1;
	map[5][15]=1;
	map[5][16]=1;


	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			if(map[i][j]!=1)
				map[i][j]=0;
		}
	}
}


void main()
{
	system("mode con cols=99 lines=50");
	Date();
	Run_game();
}