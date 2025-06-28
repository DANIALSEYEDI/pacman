#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include <conio.h>
#include "game.h"
#include "menu.h"
void showrecord();
void helpmenu(int n){
    system("cls");
    cyan();
    printf("     Welcome to pac man");
    if(n%3==0){
        green();
        printf("\n\n      *1:Start Game\n");
        red();
        printf("     2:Scores and Records\n");
        red();
        printf("     3:Exit");
    }
    else if(n%3==1){
        red();
        printf("\n\n     1:Start Game\n");
        green();
        printf("      *2:Scores and Records\n");
        red();
        printf("     3:Exit");
    }
    else if(n%3==2){
        red();
        printf("\n\n     1:Start Game\n");
        red();
        printf("     2:Scores and Records\n");
        yellow();
        printf("      *3:Exit");
    }
    reset();
}



void helpmenudifficult(int z){
    system("cls");
    if(z%3==0){
        green();
        printf("      *1:Easy\n");
        red();
        printf("     2:Normal\n");
        red();
        printf("     3:Hard");
    }
    else if(z%3==1){
        red();
        printf("     1:Easy\n");
        green();
        printf("      *2:Normal\n");
        red();
        printf("     3:Hard");
    }
    else if(z%3==2){
        red();
        printf("     1:Easy\n");
        red();
        printf("     2:Normal\n");
        green();
        printf("      *3:Hard");
    }
    reset();
}





void menudifficult(){
    int n=300;
    helpmenudifficult(n);
    while(1){
        if(kbhit()){
            char c=_getch();
            if(c==80){
                n++;
                helpmenudifficult(n);
            }
            else if(c==72){
                n--;
                helpmenudifficult(n);
            }
            else if(c==13){
                startgame(n%3);
                }
            }

        }
    }





void menu(){
    int n=300;
    helpmenu(n);
    while(1){
        if(kbhit()){
            char c=_getch();
            if(c==80){
                n++;
                helpmenu(n);
            }
            else if(c==72){
                n--;
                helpmenu(n);
            }
            else if(c==13){
                switch (n%3) {
                    case 0:
                        menudifficult();
                        return;
                    case 1:
                        showrecord();
                        return;
                    case 2:
                        system("cls");
                        red();
                        printf("Exiting the game. Goodbye!\n");
                        reset();
                        while(1) {
                                char c = _getch();
                                if (c == 13) {
                                    exit(0);
                                }
                        }
                }
            }
        }
    }
}

