#include <stdio.h>
#include <stdlib.h>
#include "printmap.h"
#include "game.h"
#include "menu.h"
#include "color.h"
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <math.h>

 int tekrarstars=0;
int tekrarghosts=0;
int tekrarfruits=0;
int k=-1;


 player player1;
 packman packman1;
star stars[10];
ghost ghosts[7];
 gilas gilas1;
 felfel  felfel1;
 sib sib1;
 gharch gharch1;
 record record1[20];
 ghostseeker ghostseeker1;


void startgame(int x) {
    system("cls");
    red();
    printf(" Please enter your name: ");
    reset();
    scanf("%s",player1.name);
    system("cls");
    green();
    printf("                We have 9 symbols in this Game:\n\n");
    reset();
    resetGameVariables(x);
    printf(" 1- Packman: %c      2- Stars: %c      3- Ghost: %c     4- Wall: %c    5-Ghostseeker: $\n\n", packman1.symbol, stars[0].symbol, ghosts[0].symbol,'#');
    printf(" 6- Gilas: %c        7- Felfel: %c     8- Sib: %c        9- Gharch: %c", gilas1.symbol, felfel1.symbol, sib1.symbol,gharch1.symbol);
    while(1){
        if(kbhit()){
            char c=_getch();
            if(c==13){
                system("cls");
                break;
            }
        }
    }
    int t;
    int e=1;
    resetmap();
    getmap(x);
    placefruits(x);
    placestars(x);
    placeghosts(x);
    system("cls");
    PlaySound(TEXT("C:\\Users\\ASUS\\Desktop\\pro\\pacman (4).wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    printmap1();
    printf("\n");
    green();
    printf("player Name: %s  |  Score: %d  | Lives: %d  | Power: %d  |  Speed: %d\n\n", player1.name, player1.score,
           player1.lives, player1.ispoweful, player1.powerspeed);
    cyan();
    printf("Player position: (%d,%d)\n\n", packman1.pack.x, packman1.pack.y);
    red();
    printf("STOP GAME PRESS F");
    reset();
    while (1) {
        if (kbhit()) {
            char direction = (char) tolower(_getch());
            if (direction == 'f') {
                k++;
                PlaySound(NULL, NULL, SND_ASYNC);
                PlaySound(TEXT("C:\\Users\\ASUS\\Desktop\\pro\\pacman (3).wav"), NULL,
                          SND_FILENAME | SND_ASYNC | SND_LOOP);
                afterlose();
            }
            movepackman(&packman1.pack.x, &packman1.pack.y, direction, x);
        }
        else {
            if (map1[packman1.pack.x][packman1.pack.y] == '$') {
                map1[ghostseeker1.seeker.x][ghostseeker1.seeker.y] = ' ';
                map1[1][28] = '$';
                if (player1.ispoweful > 0) {
                    ghostseeker1.seeker.y = 28;
                    ghostseeker1.seeker.x = 1;
                    printit(4, 1, 28, packman1.pack.x, packman1.pack.y);
                    printit(1,packman1.pack.x,packman1.pack.y,packman1.pack.x,packman1.pack.y);
                    moveGhostSeeker(packman1.pack.x, packman1.pack.y);
                } else {
                    player1.lives--;
                    ghostseeker1.seeker.y = 28;
                    ghostseeker1.seeker.x = 1;
                    printit(4, 1, 28, packman1.pack.x, packman1.pack.y);
                    printit(1,packman1.pack.x,packman1.pack.y,packman1.pack.x,packman1.pack.y);
                    moveGhostSeeker(packman1.pack.x, packman1.pack.y);
                }
            }
            else if (map1[packman1.pack.x][packman1.pack.y] == '&') {
                if (player1.ispoweful > 0) {
                    placeghosts(x);
                } else {
                    player1.lives--;
                    placeghosts(x);
                }
            }
        }
        e++;
        if(e%2==0) {
            if (x == 1 || x == 2) {
                moveGhostSeeker(packman1.pack.x, packman1.pack.y);
            }
        }
        if (e % 9 == 1) {
            placeghosts(x);
        }
        updateinfo();
        if (player1.timer > 0) {
            player1.timer--;
        } else {
            player1.ispoweful = 0;
        }
        if (player1.numspeed > 0) {
            t = 70;
            player1.numspeed--;
        } else if (player1.numspeed <= 0) {
            player1.powerspeed = 0;
            t = 150;
        }
        if (player1.lives <= 0) {
            k++;
            PlaySound(NULL, NULL, SND_ASYNC);
            PlaySound(TEXT("C:\\Users\\ASUS\\Desktop\\pro\\pacman (3).wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            afterlose();
            break;
        }
        if (player1.score % 13==0 && player1.score>0 ) {
            player1.score++;
            placefruits(x);
        }
        Sleep(t);
    }
}






void afterlose() {
    system("cls");
    red();
    printf("     GAME OVER !!\n\n");
    reset ();
    printf("  Player Name: %s \n  Score: %d",player1.name ,player1.score);
    strcpy(record1[k].name, player1.name);
    record1[k].score=player1.score;
    while(1){
        char c=_getch();
        if(c==13){
            break;
        }
    }
    PlaySound(NULL, NULL, SND_ASYNC);
    menu();
}




void placeghosts(int n) {
    int g;
    if (n == 0) {
        g = 3;
    } else if (n == 1) {
        g = 5;
    } else if (n == 2) {
        g = 7;
    }
    for (int i = 0; i < g; i++) {
        while (1) {
            int x = (rand() % 18) + 1;
            int y = (rand() % 28) + 1;
            if (map1[x][y] != '#' && map1[x][y] != '&'  && map1[x][y] != 'G' &&
                map1[x][y] != 'F' && map1[x][y] != 'S' && map1[x][y] != 'R'&& map1[x][y]!='*' && map1[x][y]!='$') {
                if(tekrarghosts>0){
                    printit(3,x,y,ghosts[i].st.x,ghosts[i].st.y);
                }
                ghosts[i].st.x = x;
                ghosts[i].st.y = y;
                map1[x][y]='&';
                break;
            }
        }
    }
    tekrarghosts++;
}



void placefruits(int n){
    for(int i=0;i<4;i++){
        while(1){
            int x = (rand() % 18) + 1;
            int y = (rand() % 28) + 1;
            if (i==0 && map1[x][y] != '#' && map1[x][y] != 'G' &&
            map1[x][y] != 'F' && map1[x][y] != 'S' && map1[x][y] != 'R' && map1[x][y]!='@' && map1[x][y]!='$') {
                if(tekrarfruits>0){
                    printit(6,x,y,sib1.si.x,sib1.si.y);
                }
                sib1.si.x=x;
                sib1.si.y=y;
                map1[x][y] = 'S';
                break;
            }
            else if (i==1 && map1[x][y] != '#' && map1[x][y] != 'G' &&
                map1[x][y] != 'F' && map1[x][y] != 'S' && map1[x][y] != 'R' && map1[x][y]!='@' && map1[x][y]!='$') {
                if(tekrarfruits>0){
                    printit(7,x,y,gharch1.ghar.x,gharch1.ghar.y);
                }
                gharch1.ghar.x=x;
                gharch1.ghar.y=y;
                map1[x][y] = 'R';
                break;
            }
            else if (i==2 && map1[x][y] != '#' && map1[x][y] != 'G' &&
                map1[x][y] != 'F' && map1[x][y] != 'S' && map1[x][y] != 'R' && map1[x][y]!='@' && map1[x][y]!='$') {
                if(tekrarfruits>0){
                    printit(5,x,y,gilas1.gi.x,gilas1.gi.y);
                }
                gilas1.gi.x=x;
                gilas1.gi.y=y;
                map1[x][y] = 'G';
                break;
            }
            else if (i==3 && map1[x][y] != '#' && map1[x][y] != 'G' &&
                map1[x][y] != 'F' && map1[x][y] != 'S' && map1[x][y] != 'R' && map1[x][y]!='@' && map1[x][y]!='$') {
                if(tekrarfruits>0){
                    printit(8,x,y,felfel1.fel.x,felfel1.fel.y);
                }
                felfel1.fel.x=x;
                felfel1.fel.y=y;
                map1[x][y] = 'F';
                break;
            }
        }
        tekrarfruits++;
    }
}




void placestars(int n) {
    int g;
    if(n==0){
        g=10;
    }
    if(n==1){
        g=7;
    }
    if(n==2){
        g=4;
    }
    for(int i=0;i<g;i++) {
        while (1) {
            int x = (rand() % 18) + 1;
            int y = (rand() % 28) + 1;
            if (map1[x][y] != '#' && map1[x][y] != '@' && map1[x][y] != 'G' && map1[x][y] != 'F' &&
                map1[x][y] != 'S' && map1[x][y] != 'R' && map1[x][y] != '&' && map1[x][y]!='$') {
                if(tekrarstars>0){
                    printit(2,x,y,stars[i].st.x,stars[i].st.y);
                }
                stars[i].st.x=x;
                stars[i].st.y=y;
                map1[x][y]='*';
                break;
            }
        }
    }
    tekrarstars++;
}


void movepackman(int *x,int *y,char direction,int n){
    int newx=*x;
    int newy=*y;
    int oldx=*x;
    int oldy=*y;
    switch (direction) {
        case 'w':
            newx--;
            break;
        case 's':
            newx++;
            break;
        case 'a':
            newy--;
            break;
        case'd':
            newy++;
            break;
        default:
            return;
    }
    if(newx>=0 && newx<20 && newy>=0 && newy<30 && map1[newx][newy]!='#'){
        if(map1[newx][newy]=='*'){
            player1.score++;
            if((n==0 && player1.score>0 && player1.score%10==0)|| (n==1 && player1.score>0 && player1.score%7==0) || (n==2 && player1.score>0 && player1.score%4==0)){
                placestars(n);
            }
        }
        else if(map1[newx][newy]=='&'){
            if(player1.ispoweful>0){
                placeghosts(n);
            }
            else {
                player1.lives--;
                placeghosts(n);
            }
        }
        else if(map1[newx][newy]=='S'){
            player1.lives++;
        }
        else if(map1[newx][newy]=='R'){
            player1.lives--;
        }
        else if(map1[newx][newy]=='G'){
            player1.ispoweful++;
            player1.timer+=30;
        }
        else if(map1[newx][newy]=='F'){
            player1.powerspeed=1;
            player1.numspeed+=30;
        }
        else if(map1[newx][newy]=='$'){
            map1[ghostseeker1.seeker.x][ghostseeker1.seeker.y] = ' ';
            map1[1][28] ='$';
            if(player1.ispoweful>0){
                ghostseeker1.seeker.y=28;
                ghostseeker1.seeker.x=1;
                printit(4,1,28,packman1.pack.x,packman1.pack.y);
            }
            else {
                player1.lives--;
                ghostseeker1.seeker.y=28;
                ghostseeker1.seeker.x=1;
                printit(4,1,28,packman1.pack.x,packman1.pack.y);
            }


        }
        if(*x!=newx || *y!=newy){
            map1[oldx][oldy]=' ';
            map1[newx][newy]='@';
            printit(1,newx,newy,*x,*y);
            *x=newx;
            *y=newy;
        }
    }

}
void showrecord(){
    system("cls");
    int temp;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            if(record1[j].score<record1[i].score){
                 temp=record1[i].score;
                record1[i].score=record1[j].score;
                record1[j].score= temp;
            }
        }
    }
    cyan();
    for(int j=0;j<=k;j++){
        printf("  %d- Name: %s  | Score: %d\n",j+1,record1[j].name,record1[j].score);
    }
    reset();
    while(1){
        char c=_getch();
        if(c==13){
            break;
        }
    }
    menu();
}
void moveGhostSeeker(int packmanx, int packmany) {
    int ghostx= ghostseeker1.seeker.x;
    int ghosty=ghostseeker1.seeker.y;
    int newx=ghostx, newy =ghosty;
    int a=abs(ghostx-packmanx);
    int b=abs(ghosty-packmany);
    if(a>=b) {
        if (packmanx < ghostx) {
            newx = ghostx - 1;
        } else if (packmanx > ghostx) {
            newx = ghostx + 1;
        }
        if (map1[newx][ghosty] != '#' && map1[newx][ghosty] != '&' && map1[newx][ghosty] != 'R' &&
            map1[newx][ghosty] != 'S' && map1[newx][ghosty] != 'G' && map1[newx][ghosty] != 'F' &&
            map1[newx][ghosty] != '*') {
            printit(4, newx, ghosty, ghostseeker1.seeker.x, ghostseeker1.seeker.y);
            ghostseeker1.seeker.x = newx;
            ghostseeker1.seeker.y = ghosty;
            return;
        } else {
            newx = ghostx;
        }
    }
        if (packmany < ghosty) {
            newy = ghosty -1;
        } else if (packmany > ghosty) {
            newy = ghosty + 1;
        }
    if (map1[newx][newy] != '#' && map1[newx][newy] != '&' && map1[newx][newy]!='R' && map1[newx][newy]!='S' && map1[newx][newy]!='G' && map1[newx][newy]!='F' && map1[newx][newy]!='*') {
        printit(4,newx,newy,ghostseeker1.seeker.x,ghostseeker1.seeker.y);
        ghostseeker1.seeker.x=newx;
        ghostseeker1.seeker.y=newy;
        return;
    }
    else{
        newy=ghosty;
    }
    if(ghostx==newx && ghosty==newy){
        if(map1[ghostx+1][ghosty]==' '){
            printit(4,ghostx+1,ghosty,ghostseeker1.seeker.x,ghostseeker1.seeker.y);
            ghostseeker1.seeker.x=ghostx+1;
            ghostseeker1.seeker.y=ghosty;
        }
        else if(map1[ghostx-1][ghosty]== ' '){
            printit(4,ghostx-1,ghosty,ghostseeker1.seeker.x,ghostseeker1.seeker.y);
            ghostseeker1.seeker.x=ghostx-1;
            ghostseeker1.seeker.y=ghosty;
        }
        else if(map1[ghostx][ghosty+1]==' '){
            printit(4,ghostx,ghosty+1,ghostseeker1.seeker.x,ghostseeker1.seeker.y);
            ghostseeker1.seeker.x=ghostx;
            ghostseeker1.seeker.y=ghosty+1;
        }
        else if(map1[ghostx][ghosty-1]== ' '){
            printit(4,ghostx,ghosty-1,ghostseeker1.seeker.x,ghostseeker1.seeker.y);
            ghostseeker1.seeker.x=ghostx;
            ghostseeker1.seeker.y=ghosty-1;
        }

    }
}








