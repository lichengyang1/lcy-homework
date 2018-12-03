#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLAN_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'
	int snakeX[SNAKE_MAX_LENGTH]={1,2,3,4,5};
	int snakeY[SNAKE_MAX_LENGTH]={1,1,1,1,1};  //蛇的坐标 
	int length=5;
	char map[12][12]={{"************"},
					  {"*XXXXH     *"},
					  {"*          *"},
					  {"*          *"},
					  {"*          *"},
					  {"*          *"},
					  {"*          *"},
					  {"*          *"},
					  {"*          *"},
					  {"*          *"},
					  {"*          *"},
					  {"************"}};

void output();
void snakemove(int x,int y);


int main(){
	int num=1;
	char step;	 

	output();	//输出字符矩阵 
	

	
	scanf("%c",&step);	//输入
	switch(step){
			 case 'w': snakemove(0,-1); break;		
             case 's': snakemove(0,1); break;
             case 'a': snakemove(-1,0); break;
             case 'd': snakemove(1,0); break;		//操作移动 
	}	
	output();	//输出字符矩阵 

}
void output(){
	int i,j;
	for(i=0;i<12;i++){
		for(j=0;j<12;j++){
			if(j==11)
			printf("%c\n",map[i][j]);
			else
			printf("%c",map[i][j]);
		}
	}
}
void snakemove(int x,int y){
	int i,j,swap;	
	snakeX[length]=snakeX[length-1]+x;
    snakeY[length]=snakeY[length-1]+y;	//蛇头移动 
	for(i=length;i>0;i--){
		swap=map[snakeY[i]][snakeX[i]];
        map[snakeY[i]][snakeX[i]]=map[snakeY[i-1]][snakeX[i-1]];
        map[snakeY[i-1]][snakeX[i-1]]=swap;			//交换坐标与实际位置 
	}
	for(j=0;j<=length-1;j++){
		snakeX[j]=snakeX[j+1];
        snakeY[j]=snakeY[j+1];			//更新坐标 
	}
	snakeX[length]=0;
    snakeY[length]=0;
}

