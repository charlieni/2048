#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define _CRE_SECURE_NO_WAENINGS
IMAGE image[12];		 	//儲存12張照片
int imageIndex[12]= {0,2,4,8,16,32,64,128,256,512,1024,2048};  
int map[4][4]={0}; //初始化地圖 
int score=0;  //總分數 

int right() {
	int end=0;    //遊戲結束標記 
	int now,next,k;
	for(int i=0; i<4; i++) {
		for(int j=4-1; j>=0; j--) {
			now=map[i][j];
			k=j-1;   //去看下一個 
			while(k>=0) {
				next=map[i][k];
				if(next!=0) {
					if(now==next) {   //如果相鄰也相等，就相加 
						end=1;
						map[i][j]=2*map[i][k];    //相加 
						score+=map[i][j];   //分數++ 
						map[i][k]=0;    //移動完要讓原位為零 
					}
					k=-1;    //退出循環 
				}
				k--;   //k位置前變，繼續判斷 
			}
		}
	}
	for(int i=0; i<4; i++) {
		for(int j=3; j>=0; j--) {
			int now=map[i][j];
			if(now==0) {
				int k=j-1;
				while(k>=0) {
					int next=map[i][k];
					if(next!=0) {
						end=1;
						map[i][j]=next;   //把非零元素移動到零的地方 
						map[i][k]=0;
						k=-1;
					}
					k--;    //其他位置也要判斷 
				}
			}
		}
	}
	if(end) {
		return 0;
	} else
		return 4;
}
int left() {
	int end=0;
	int now,next,k;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			now=map[i][j];
			k=j+1;
			while(k<4) {     //從左到右跟從右到左k不一樣 
				next=map[i][k];
				if(next!=0) {
					if(now==next) {
						end=1;
						map[i][j]=2*map[i][k];
						score+=map[i][j];
						map[i][k]=0;
					}
					k=4;    //退出循環 
				}
				k++;  //循環 
			}
		}
	}
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			int now=map[i][j];
			if(now==0) {
				int k=j+1;
				while(k<4) {
					int next=map[i][k];
					if(next!=0) {
						end=1;
						map[i][j]=map[i][k];
						map[i][k]=0;
						k=4;
					}
					k++;
				}
			}
		}
	}
	if(end) {
		return 0;
	} else
		return 4;
}
int down() {
	int end=0;
	int now,next,k;
	for(int j=0; j<4; j++) {
		for(int i=4-1; i>=0; i--) {
			int now=map[i][j];
			if(now!=0) {
				int k=i-1;
				while(k>=0) {
					next=map[k][j];
					if(next!=0) {
						if(now==next) {
							end=1;
							map[i][j]=2*map[k][j];
							score+=map[i][j];
							map[k][j]=0;
						}
						k=-1;
					}
					k--;	
				}
				
			}
		}
	}
	for(int j=0; j<4; j++) {
		for(int i=3; i>=0; i--) {
			int now=map[i][j];
			if(now==0) {
				int k=i-1;
				while(k>=0) {
					int next=map[k][j];
					if(next!=0) {
						end=1;
						map[i][j]=next;
						map[k][j]=0;
						k=-1;
					}
					k--;
				}
			}
		}
	}
	if(end) {
		return 0;
	} else
		return 4;
}
int up() {
	int end=0;
	int now,next,k;
	for(int j=0; j<4; j++) {
		for(int i=0; i<4; i++) {
			now=map[i][j];
			if(now!=0) {
				k=i+1;
				while(k<4) {
					next=map[k][j];
					if(next!=0) {
						if(now==next) {
							end=1;
							map[i][j]=2*map[k][j];
							score+=map[i][j];
							map[k][j]=0;
						}
						k=4;
					}
					k++;
				}
				
			}
		}
	}
	for(int j=0; j<4; j++) {
		for(int i=0; i<4; i++) {
			int now=map[i][j];
			if(now==0) {
				int k=i+1;
				while(k<4) {
					int next=map[k][j];
					if(next!=0) {
						end=1;
						map[i][j]=next;
						map[k][j]=0;
						k=4;
					}
					k++;
				}
			}
		}
	}
	if(end) {
		return 0;
	} else
		return 4;
}
void resourse() {  //載入圖片  在image第i格載入各個數字 
	int i=0;
	loadimage(image+i,_T("D:\\HW\\shopee\\2048\\num\\0.png"));
	i++;
	loadimage(image+i,_T("D:\\HW\\shopee\\2048\\num\\2.png"));
	i++;
	loadimage(image+i,_T("D:\\HW\\shopee\\2048\\num\\4.png"));
	i++;
	loadimage(image+i,_T("D:\\HW\\shopee\\2048\\num\\8.png"));
	i++;
	loadimage(image+i,_T("D:\\HW\\shopee\\2048\\num\\16.png"));
	i++;
	loadimage(image+i,_T("D:\\HW\\shopee\\2048\\num\\32.png"));
	i++;
	loadimage(image+i,_T("D:\\HW\\shopee\\2048\\num\\64.png"));
	i++;
	loadimage(image+i,_T("D:\\HW\\shopee\\2048\\num\\128.png"));
	i++;
	loadimage(image+i,_T("D:\\HW\\shopee\\2048\\num\\256.png"));
	i++;
	loadimage(image+i,_T("D:\\HW\\shopee\\2048\\num\\512.png"));
	i++;
	loadimage(image+i,_T("D:\\HW\\shopee\\2048\\num\\1024.png"));
	i++;
	loadimage(image+i,_T("D:\\HW\\shopee\\2048\\num\\2048.png"));
	i++;
}
void drawmap(int a) {
	char scor[10];
	itoa(a,scor,10);   //把數字轉成字串 
	setbkcolor(RGB(240,215,215));  //背景顏色
	cleardevice();  //刷新文字
	settextcolor(RGB(210,105,30));  //文字顏色
	settextstyle(35,0,"Algerian");
	outtextxy(40,12,"2048 GAME");
	outtextxy(300,12,"Score:");
	outtextxy(440,12,scor);
	int x,y,k;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			x=120*j;
			y=120*i+50;
			//求出當前元素對應的圖片序號
			for(k=0; k<12; k++) {
				if(imageIndex[k]==map[i][j]) {     //有虛擬的數字map，所以map[i][j]只要等於某個index就輸出那個數字 
					break;
				}		
			}
			putimage(x,y,image+k);   //output圖片 
		}
	}
}
void randIntnum() {    //產生地圖隨機數 
	srand((unsigned int)time(NULL));   //要用rand一定要寫 
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if(map[i][j]==0) {
				map[i][j]=(rand()%3)*2;  //隨機產生0.2.4 
				if(map[i][j]==0)   //產生0重來 
					continue;
				return ;
			}
		}
	}
}
void anjian() {    //按鍵都在這處理 
	char key=_getch();
	switch(key) {
		case 'W':
		case 'w':
		case 72:   //鍵盤的上 
			
			up();
			randIntnum();
			break;
		case 'S':
		case 's':
		case 80:    //鍵盤的下 
			
			down();
			randIntnum();
			break;
		case 'A':
		case 'a':
		case 75:    //鍵盤的左 
			
			left();
			randIntnum();
			break;
		case 'D':
		case 'd':
		case 77:    //鍵盤的右 
			
			right();
			randIntnum();
			break;
	}
}
void over(){
	//PlaySound(TEXT("D:\\HW\\shopee\\2048\\fail.wav"),NULL,SND_FILENAME|SND_ASYNC);    //播放失敗音樂 
	setbkcolor(RGB(211,211,211));    //背景顏色 
	//cleardevice();
	settextcolor(RED);    //字的顏色 
	settextstyle(50,30,"Algerian");     //字的風格 
	outtextxy(125,200,"GAME OVER");     //輸出字 
	settextstyle(30,20,"Algerian");
	outtextxy(75,270,"Press Enter To LEAVE");
}
int gameover() {
	for(int i=0; i<4; ++i) {
		for(int j=0; j<4; ++j) {
			if(map[i][j]==0)    //還有空格就繼續 
				return 1;
			if(i>0) {
				if(map[i-1][j]==map[i][j])    //有在隔壁一樣的就繼續 
					return 1;
			}
			if(j>0) {
				if(map[i][j-1]==map[i][j])    //有在上下一樣的就繼續  
					return 1;
			}
		}
	}
	over();
	getchar();   //吃enter 
	return 0;
}
void win() {
	//PlaySound(TEXT("D:\\HW\\shopee\\2048\\victory.wav"),NULL,SND_FILENAME|SND_ASYNC);    //播放成功音樂  
	setbkcolor(RGB(255,0,255));   //背景顏色  
	//cleardevice;
	settextcolor(RED);   //字的顏色  
	settextstyle(50,30,"Algerian");    //字的風格  
	outtextxy(125,200,"VICTORY!!");    //輸出字  
	settextstyle(30,20,"Algerian");
	outtextxy(75,270,"Press Enter To LEAVE");
}

void start(){   //開始的畫面 
	setbkcolor(YELLOW);
	cleardevice();
	settextcolor(BLACK);
	settextstyle(50,30,"Calibri");
	outtextxy(125,200,"Press Enter");
	outtextxy(150,270,"To Start.");
}

int main() {

	int m=1,count=0;
	initgraph(120*4+20,120*4+70);     //初始化輸出頁面大小 
	//PlaySound(TEXT("D:\\HW\\shopee\\2048\\music.wav"),NULL,SND_FILENAME|SND_ASYNC|SND_LOOP);    //播放背景音樂 
	start();     //開始畫面 
	getchar();   //吃enter 
	resourse();   //讀所有圖片 
	randIntnum();   //放隨機2或4 
	randIntnum();
	drawmap(0);    //畫地圖 
	while(m==1) {
		anjian();    //鍵盤操作 
		drawmap(score);   //每操作一次要畫一次地圖 
		for(int i=0; i<4; i++) {     //循環判斷是否結束遊戲 
			for(int j=0; j<4; j++) {
				if(map[i][j]== imageIndex[11]) {    //imageIndex[11]就是2048 
					Sleep(500);     	//延緩跳出的時間 
					win();
				}
			}
		}
		m=gameover();    //遊戲結束標誌 
		if(m==0) {
			Sleep(1500);   //延遲一下再出循環 
		}
	}
	closegraph();    //關閉頁面 
	system("cls");   //清除頁面 
	return 0;

}

