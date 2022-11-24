#includestdio.h
#includestdlib.h
#includegraphics.h
#includeconio.h
#includetime.h
#includewindows.h
#includeMmsystem.h
#pragma comment(lib,winmm.lib)
#define _CRE_SECURE_NO_WAENINGS
IMAGE image[12];		 	儲存12張照片
int imageIndex[12]= {0,2,4,8,16,32,64,128,256,512,1024,2048};
int map[4][4]={0};
int score=0;

int right() {
	int end=0;
	int now,next,k;
	for(int i=0; i4; i++) {
		for(int j=4-1; j=0; j--) {
			now=map[i][j];
			k=j-1;
			while(k=0) {
				next=map[i][k];
				if(next!=0) {
					if(now==next) {
						end=1;
						map[i][j]=2map[i][k];
						score+=map[i][j];
						map[i][k]=0;
					}
					k=-1;
				}
				k--;
			}
		}
	}
	for(int i=0; i4; i++) {
		for(int j=3; j=0; j--) {
			int now=map[i][j];
			if(now==0) {
				int k=j-1;
				while(k=0) {
					int next=map[i][k];
					if(next!=0) {
						end=1;
						map[i][j]=next;
						map[i][k]=0;
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
int left() {
	int end=0;
	int now,next,k;
	for(int i=0; i4; i++) {
		for(int j=0; j4; j++) {
			now=map[i][j];
			k=j+1;
			while(k4) {
				next=map[i][k];
				if(next!=0) {
					if(now==next) {
						end=1;
						map[i][j]=2map[i][k];
						score+=map[i][j];
						map[i][k]=0;
					}
					k=4;
				}
				k++;
			}
		}
	}
	for(int i=0; i4; i++) {
		for(int j=0; j4; j++) {
			int now=map[i][j];
			if(now==0) {
				int k=j+1;
				while(k4) {
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
	for(int j=0; j4; j++) {
		for(int i=4-1; i=0; i--) {
			int now=map[i][j];
			if(now!=0) {
				int k=i-1;
				while(k=0) {
					next=map[k][j];
					if(next!=0) {
						if(now==next) {
							end=1;
							map[i][j]=2map[k][j];
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
	for(int j=0; j4; j++) {
		for(int i=3; i=0; i--) {
			int now=map[i][j];
			if(now==0) {
				int k=i-1;
				while(k=0) {
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
	for(int j=0; j4; j++) {
		for(int i=0; i4; i++) {
			now=map[i][j];
			if(now!=0) {
				k=i+1;
				while(k4) {
					next=map[k][j];
					if(next!=0) {
						if(now==next) {
							end=1;
							map[i][j]=2map[k][j];
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
	for(int j=0; j4; j++) {
		for(int i=0; i4; i++) {
			int now=map[i][j];
			if(now==0) {
				int k=i+1;
				while(k4) {
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
void resourse() {  載入圖片
	for(int i=0;i12;i++){
		char fileName[20]=;
		sprintf_s(fileName,%s,path[i]);
		loadimage(image+i,fileName);
	}
	int i=0;
	loadimage(image+i,_T(DHWshopee2048num0.png));
	i++;
	loadimage(image+i,_T(DHWshopee2048num2.png));
	i++;
	loadimage(image+i,_T(DHWshopee2048num4.png));
	i++;
	loadimage(image+i,_T(DHWshopee2048num8.png));
	i++;
	loadimage(image+i,_T(DHWshopee2048num16.png));
	i++;
	loadimage(image+i,_T(DHWshopee2048num32.png));
	i++;
	loadimage(image+i,_T(DHWshopee2048num64.png));
	i++;
	loadimage(image+i,_T(DHWshopee2048num128.png));
	i++;
	loadimage(image+i,_T(DHWshopee2048num256.png));
	i++;
	loadimage(image+i,_T(DHWshopee2048num512.png));
	i++;
	loadimage(image+i,_T(DHWshopee2048num1024.png));
	i++;
	loadimage(image+i,_T(DHWshopee2048num2048.png));
	i++;
}
void drawmap(int a) {
	char scor[10];
	itoa(a,scor,10);
	setbkcolor(RGB(240,215,215));  背景顏色
	cleardevice();  刷新文字
	settextcolor(RGB(210,105,30));  文字顏色
	settextstyle(35,0,Algerian);
	outtextxy(40,12,2048 GAME);
	outtextxy(300,12,Score);
	outtextxy(400,12,scor);
	int x,y,k;
	for(int i=0; i4; i++) {
		for(int j=0; j4; j++) {
			x=120j;
			y=120i+50;
			求出當前元素對應的圖片序號
			for(k=0; k12; k++) {
				if(imageIndex[k]==map[i][j]) {
					break;
				}		
			}
			putimage(x,y,image+k);
		}
	}
}
void randIntnum() {
	srand((unsigned int)time(NULL));
	for(int i=0; i4; i++) {
		for(int j=0; j4; j++) {
			if(map[i][j]==0) {
				map[i][j]=(rand()%3)2;
				if(map[i][j]==0)
					continue;
				return ;
			}
		}
	}
}
void anjian() {
	char key=_getch();
	switch(key) {
		case 'W'
		case 'w'
		case 72
			
			up();
			randIntnum();
			break;
		case 'S'
		case 's'
		case 80
			
			down();
			randIntnum();
			break;
		case 'A'
		case 'a'
		case 75
			
			left();
			randIntnum();
			break;
		case 'D'
		case 'd'
		case 77
			
			right();
			randIntnum();
			break;
	}
}
void over(){
	PlaySound(TEXT(DHWshopee2048fail.wav),NULL,SND_FILENAMESND_ASYNC);
	setbkcolor(RGB(211,211,211));

	settextcolor(RED);
	settextstyle(50,30,Algerian);
	outtextxy(125,200,GAME OVER);
	settextstyle(30,20,Algerian);
	outtextxy(75,270,Press Enter To LEAVE);
}
int gameover() {
	for(int i=0; i4; ++i) {
		for(int j=0; j4; ++j) {
			if(map[i][j]==0)
				return 1;
			if(i0) {
				if(map[i-1][j]==map[i][j])
					return 1;
			}
			if(j0) {
				if(map[i][j-1]==map[i][j])
					return 1;
			}
		}
	}
	over();
	getchar();
	return 0;
}
void win() {
	PlaySound(TEXT(DHWshopee2048victory.wav),NULL,SND_FILENAMESND_ASYNC);
	setbkcolor(RGB(255,0,255));
	cleardevice;
	settextcolor(RED);
	settextstyle(50,30,Algerian);
	outtextxy(125,200,VICTORY!!);
	settextstyle(30,20,Algerian);
	outtextxy(75,270,Press Enter To LEAVE);
}

void start(){
	setbkcolor(YELLOW);
	cleardevice();
	settextcolor(BLACK);
	settextstyle(50,30,Calibri);
	outtextxy(125,200,Press Enter);
	outtextxy(150,270,To Start.);
}

int main() {

	int k=0,m=1,count=0;
	initgraph(1204+20,1204+70);
	PlaySound(TEXT(DHWshopee2048music.wav),NULL,SND_FILENAMESND_ASYNCSND_LOOP);
	start();
	getchar();
	resourse();
	randIntnum();
	randIntnum();
	drawmap(0);
	while(m==1) {
		anjian();
		drawmap(score);
		k++;
		for(int i=0; i4; i++) {
			for(int j=0; j4; j++) {
				if(map[i][j]== imageIndex[11]) {
					Sleep(500);
					win();
				}
			}
		}
		m=gameover();
		if(m==0) {
			Sleep(1500);
		}
	}
	closegraph();
	system(cls);
	return 0;

}

