# 字符游戏 - 智能蛇（2）


## 一、实验目的

了解 算法 与 “智能” 的关系  
通过算法赋予蛇智能  
了解 Linux IO 设计的控制  


## 二、实验环境    
Ubuntu  

![FJnsu6.png](https://s1.ax1x.com/2018/12/10/FJnsu6.png)


## 三、控制输入/输出设备

### 1、VT 100 终端标准  
 在字符终端上完成“清屏”“修改光标位置”“设置字符前景和背景色”等操作，是通过输出 esc序列实现的。对于 VT100 终端, printf(“\033[2J”) 就实现了清屏。 

![FJn5vt.gif](https://s1.ax1x.com/2018/12/10/FJn5vt.gif)

### 2、实现 kbhit()

检测 tty 输入的程序，检测是否有键盘的输入。

# 四、编写智能算法

伪代码：  
```
 // Hx,Hy: 头的位置
    // Fx,Fy：食物的位置
	function whereGoNext(Hx,Hy,Fx,Fy) {
	// 用数组movable[3]={“a”,”d”,”w”,”s”} 记录可走的方向
	// 用数组distance[3]={0,0,0,0} 记录离食物的距离
	// 分别计算蛇头周边四个位置到食物的距离。H头的位置，F食物位置
	//     例如：假设输入”a” 则distance[0] = |Fx – (Hx-1)| + |Fy – Hy|
	//           如果 Hx-1，Hy 位置不是Blank，则 distance[0] = 9999
	// 选择distance中存最小距离的下标p，注意最小距离不能是9999
	// 返回 movable[p]
	}
```

实现:
```c  
char wherego() {
     int k=0, i;
     int a = snakeX[snakeLength-1]; 
     int b = snakeY[snakeLength-1]; 
     int distence[4] = {0, 0, 0, 0}; 
     distence[0] = abs(fx - (a-1)) + abs(fy - b);  

     distence[1] = abs(fx - (a+1)) + abs(fy - b);  

     distence[2] = abs(fx - a) + abs(fy - (b - 1));   
     
     distence[3] = abs(fx - a) + abs(fy - (b + 1));  
     if(map[a-1][b] == '*' || map[a-1][b] == 'X') {
     distence[0] = 9999;} 
     if(map[a+1][b] == '*' || map[a+1][b] == 'X') {
     distence[1] = 9999;} 
     if(map[a][b-1] == '*' || map[a][b-1] == 'X') {
     distence[2] = 9999;} 
     if(map[a][b+1] == '*' || map[a][b+1] == 'X') {
     distence[3] = 9999;} 
     int min = distence[0]; 
     for( i = 0; i < 4; i++) { 
         if(distence[i] < min) { 
             min = distence[i]; k = i;/ } 
             } 
             return movable[k]; }

```  


## 实验小结
智能蛇的实现，也要通过伪代码一步步将问题分解，实现自顶向下的问题求解方法，进而将问题解决。
