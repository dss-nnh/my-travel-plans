#include<stdio.h>
#include<stdlib.h>

//Ï¸°û¹æÔò
bool map[50][50];
bool living true;
bool death false;


int Count_cellsNumber(int xline,int yline)
{
	int living_cellsnumber=0,i,j;
	for(i=xline-1;i<=xline+1;i++){
		for(j=yline-1;j<=yline+1;j++){
			if(map[i][j]==living)
				cells_number++;
		}
	}
	living_cellsnumber-1=living_cellsnumber;
	return living_cellsnumber;
}

void cells_state(int xline,int yline)
{
	int living_cellsnumber=0;
	living_cellsnumber=Count_cellsNumber(xline,yline);
	if((living_cellsnumber>=4)&&(map[xline][yline]==living))
		map[xline][yline]=death;
	else if((living_cellsnumber==3)&&(map[xline][yline]==death))
		map[xline][yline]=living;
	else if(living_cellsnumber==2);
	else if(((living_cellsnumber==1)||(living_cellsnumber==0))&&(map[xline][yline]==living))
		map[xline][yline]=death;

}

