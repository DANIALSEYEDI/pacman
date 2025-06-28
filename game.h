
#ifndef PRO_GAME_H
#define PRO_GAME_H
void startgame(int x);
void afterlose();
void placeghosts(int n);
void placefruits(int n);
void placestars(int n);
void movepackman(int *x,int *y,char direction,int n);
void showrecord();
void moveGhostSeeker(int packmanx, int packmany);

typedef struct {
    char name[30];
    int score;
    int lives;
    int ispoweful;
    int timer;
    int powerspeed;
    int numspeed;
}player;
extern player player1;


typedef struct{
    int x;
    int y;
}position;
typedef struct{
    char symbol;
    position pack ;
}packman;
extern packman packman1;


typedef struct{
    char symbol;
    position st;
}star;
extern star stars[10];


typedef struct{
    char symbol;
    position st;
}ghost;
extern ghost ghosts[7];


typedef struct {
    char symbol;
    position gi;
}gilas;
extern gilas gilas1;


typedef struct {
    char symbol;
    position fel;
}felfel;
extern felfel  felfel1;


typedef struct {
    char symbol;
    position si;
}sib;
extern sib sib1;
typedef struct {
    char symbol;
    position ghar;
}gharch;
extern gharch gharch1;


typedef struct {
    char name[30];
    int score;
}record;
extern record record1[20];


typedef struct {
    char symbol;
    position seeker;
}ghostseeker;
extern ghostseeker ghostseeker1;



#endif
