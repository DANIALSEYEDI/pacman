
#ifndef PRO_PRINTMAP_H
#define PRO_PRINTMAP_H
extern char map1[20][30];
void printmap1();
void getmap(int d);
void gotoxy(int x,int y);
void printit(int type,int newx,int newy,int oldx,int oldy);
void resetmap();
void resetGameVariables(int n);
void updateinfo();
#endif
