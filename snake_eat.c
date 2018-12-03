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
void snakeheadmove(int x,int y);
void snakemove();
void putfood();
int gameover();

int main(){
	int game=0;
	char step,junk;	 

	putfood();
	output();	//输出字符矩阵 
	

	while(game==0){
	scanf("%c%c",&step,&junk);	//输入
	switch(step){
			 case 'w': snakeheadmove(0,-1); break;		
             case 's': snakeheadmove(0,1); break;
             case 'a': snakeheadmove(-1,0); break;
             case 'd': snakeheadmove(1,0); break;		//操作移动 
	}	
	game=gameover();
	if(game==1)
	break; 
	}
	printf("Game over");
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
void snakeheadmove(int x,int y){
		
	snakeX[length]=snakeX[length-1]+x;
    snakeY[length]=snakeY[length-1]+y;	//蛇头移动 
	
}
void snakemove(){
	int i,j,swap;
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
int gameover(){
	int i,j,mid;
    char ins;
    if(map[snakeY[length]][snakeX[length]]==SNAKE_BODY||map[snakeY[length]][snakeX[length]]==WALL_CELL)//蛇碰到身体或撞墙 
        return 1;//蛇死亡 
    else if(map[snakeY[length]][snakeX[length]]=='$')//吃食物 
        {
            mid = length;
            map[snakeY[mid]][snakeX[mid]] = SNAKE_BODY;	
            ins = map[snakeY[mid-1]][snakeX[mid-1]];
            map[snakeY[mid-1]][snakeX[mid-1]] = map[snakeY[mid]][snakeX[mid]];
            map[snakeY[mid]][snakeX[mid]] = ins;//改变位置 
            length++;//蛇变长 
            putfood();
            output();
            return 0;
        }
    else 
        {
            snakemove(0,0);
            output();
            return 0;
        }
}
void putfood(void){	//随机放食物 
    int x=0,y=0; 
    srand((unsigned int)time(0));
    while(map[x][y]=='*'||map[x][y]==SNAKE_BODY||map[x][y]==SNAKE_HEAD)
    {
        x = rand()%10 + 1;
        y = rand()%10 + 1;
    }
    map[x][y] = '$';
}

