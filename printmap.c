#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "game.h"
#include "printmap.h"
#include <windows.h>
char map1[20][30];

void getmap(int d) {

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            if (i == 0 || i == 19 || j == 0 || j == 29) {
                map1[i][j] = '#';
            } else {
                    int n = rand() % 4;
                    map1[i][j] = (n == 0) ? '#' : ' ';
            }
        }
    }
    map1[0][0]='#';
    map1[1][1] = '@';
    map1[1][2] = ' ';
    map1[2][1] = ' ';
    map1[2][2] = ' ';
    map1[3][1] = ' ';
    map1[1][27] = ' ';
    map1[2][28] = ' ';
    map1[2][27] = ' ';
    map1[1][26] = ' ';
    map1[3][28] = ' ';
    if(d==1 || d==2) {
        map1[1][28] = '$';
        ghostseeker1.seeker.x=1;
        ghostseeker1.seeker.y=28;
    }
}




void printmap1() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            char cell = map1[i][j];
            switch (cell) {
                case '#':
                    cyan();
                    break;
                case '@':
                    red();
                    break;
                case '*':
                    yellow();
                    break;
                case '&':
                    green();
                    break;
                case'G':
                    red();
                    break;
                case 'S':
                    yellow();
                    break;
                case 'R':
                    bright_purple();
                    break;
                case 'F':
                    red();
                    break;
                case '$':
                    bright_purple();
                    break;
                default:
                    reset();
                    break;
            }
            printf("%c",cell);
        }
        printf("\n");
        reset();
    }
}




void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



void printit(int type,int newx,int newy,int oldx,int oldy){
    gotoxy(oldy,oldx);
    printf(" ");
    map1[oldx][oldy]=' ';
    gotoxy(newy,newx);
    switch (type){
        case 1:
            red();
            printf("@");
            map1[newx][newy]='@';
            reset();
            break;
        case 2:
            yellow();
            printf("*");
            reset();
            map1[newx][newy]='*';
            break;
        case 3:
            green();
            printf("&");
            map1[newx][newy]='&';
            reset();
            break;
        case 4:
            bright_purple();
            printf("$");
            map1[newx][newy]='$';
            reset();
            break;
        case 5:
            red();
            printf("G");
            map1[newx][newy]='G';
            reset();
            break;
        case 6:
            yellow();
            printf("S");
            map1[newx][newy]='S';
            reset();
            break;
        case 7:
            bright_purple();
            printf("R");
            map1[newx][newy]='R';
            reset();
            break;
        case 8 :
            red();
            printf("F");
            map1[newx][newy]='F';
            reset();
            break;

    }
}




void resetmap() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            if (i == 0 || i == 19 || j == 0 || j == 29) {
                map1[i][j] = '#';
            } else {
                map1[i][j] = ' ';
            }
        }
    }
}




void resetGameVariables(int n){
    packman1.symbol='@';
    gilas1.symbol = 'G';
    felfel1.symbol = 'F';
    sib1.symbol = 'S';
    gharch1.symbol = 'R';
    ghosts[0].symbol='&';
    stars[0].symbol = '*';
    ghostseeker1.symbol='$';
        player1.score = 0;
        player1.lives = (n == 0) ? 7 : (n == 1) ? 5 : 3;
        player1.ispoweful = 0;
        player1.timer = 0;
        player1.powerspeed = 0;
        player1.numspeed = 0;
        packman1.pack.x = 1;
        packman1.pack.y = 1;
        for (int i = 0; i < 10; i++) {
            stars[i].st.x = -1;
            stars[i].st.y = -1;
        }
        for (int i = 0; i < 7; i++) {
            ghosts[i].st.x = -1;
            ghosts[i].st.y = -1;
        }
        gilas1.gi.x = -1;
        gilas1.gi.y = -1;
        felfel1.fel.x = -1;
        felfel1.fel.y = -1;
        sib1.si.x = -1;
        sib1.si.y = -1;
        gharch1.ghar.x = -1;
        gharch1.ghar.y = -1;
}

void updateinfo(){
        gotoxy(0, 21);
        green();
        printf("player Name: %s  |  Score: %d  | Lives: %d  | Power: %d  |  Speed: %d     ",
               player1.name, player1.score, player1.lives, player1.ispoweful, player1.powerspeed);
        gotoxy(0, 23);
        cyan();
        printf("Player position: (%d,%d)     ", packman1.pack.x, packman1.pack.y);
        reset();
    }



