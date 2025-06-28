#include <stdio.h>
void red(){
printf("\033[1;31m");
}
void green(){
    printf("\033[1;32m");
}
void yellow(){
    printf("\033[1;33m");
}
void cyan(){
    printf("\033[1;36m");
}
void bright_purple() {
    printf("\033[1;35m");
}
void reset(){
    printf("\033[0m");
}