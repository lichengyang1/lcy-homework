# 我的游戏制作过程

## 1.游戏策划
### **楔子**：
宇宙诞生之初，世界就由光明滑稽与黑暗滑稽所统治。原本，两股力量相互制衡，互不侵犯。可是，黑暗滑稽的野心不断膨胀，妄图一统世界，让世界陷入黑暗。请你操控主角小滑稽来打败黑暗滑稽来拯救世界。
<br><br><br>
### **游戏玩法**：  
玩家可以通过方向键来操控小滑稽的移动。玩家可以通过发射滑稽弹来消灭黑稽。玩家碰到怪物和陷阱会损失生命值。若生命值为0，则游戏失败，世界陷入黑暗。玩家打败最终BOSS，则游戏胜利。
<br><br><br>
### **人设与道具**： 
①角色:  
小滑稽,拥有5点血量，使用方向键进行移动，同时能发射稽弹。  

![](https://s1.ax1x.com/2018/11/11/iqUGBq.png)

②敌人:  
黑暗滑稽，拥有3点血量，会左右移动阻碍玩家。

![](https://s1.ax1x.com/2018/11/11/iqUQ3Q.png) 

③子弹:
由黑暗滑稽界射来的子弹，会时不时的出现，触碰会损失一点血量。

![](https://s1.ax1x.com/2018/11/11/iqUM9g.png)

④BOSS:
黑暗滑稽界的统领，拥有20点血量，出现后会吸收所有的子弹。

![](https://s1.ax1x.com/2018/11/11/iqUoDI.png)

<br><br><br><br>
## 2.游戏成果展示  
[![iqzrQ0.gif](https://s1.ax1x.com/2018/11/11/iqzrQ0.gif)](https://imgchr.com/i/iqzrQ0)

[![iqzsyV.gif](https://s1.ax1x.com/2018/11/11/iqzsyV.gif)](https://imgchr.com/i/iqzsyV)

<br><br><br>
## 3.游戏设计  

Object Name：小滑稽  
Attributes： 左下角  
Collaborator：精灵  
Events & Actions：  
与怪物，子弹碰撞&生命值减一  
生命值为0&小滑稽摧毁  
点击鼠标左键&发射一枚子弹  

Object Name：子弹  
Attributes： 布局左侧  
Collaborator：精灵  
Events & Actions：  
与其他精灵碰撞&摧毁，且其他生命值减一  
运动到边界&摧毁  

Object Name：黑暗滑稽  
Attributes： 平台上  
Collaborator：精灵  
Events & Actions：  
与子弹碰撞&生命值减一  
与空气墙碰撞&反向  
