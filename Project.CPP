#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include <dos.h>

char matrix[3][3];  /* the tic tac toe matrix */
char check(void);
void rocket();
int game();
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);
/**********MAIN******************/
int main()
{
int gd,gm;
int j,i,kk,choice;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"c:\\tc\\bgi");
setcolor(WHITE);
settextstyle(7,HORIZ_DIR,7);
outtextxy(220,200,"WELCOME");
circle(380,250,220);
circle(380,250,210);
circle(380,250,200);
setbkcolor(4);
delay(1900);
//closegraph();
//getch();

setcolor(3);
cleardevice();
settextstyle(7,HORIZ_DIR,5);
outtextxy(150,20,"PRESENTATORS");
settextstyle(7,HORIZ_DIR,4);
outtextxy(150,110,"Abubakar Khan");
outtextxy(220,140,"F15-08");
outtextxy(120,190,"Saif Ur Rehman Khan");
outtextxy(220,220,"F15-41");
outtextxy(120,270,"Waqas Nazir");
outtextxy(220,300,"F15-46");

setbkcolor(6);
delay(900);
cleardevice();
/**********case******/
loop:setbkcolor(8);
printf("Enter your case:\n");
printf("Pres  1 for Rocket.\nPress 2 for Tic Tac Toe game.\nPress 3 for exit.\n\t");
scanf("%d",&choice);
switch(choice)
{
case 1:
rocket();
goto loop;
case 2:
game();
goto loop;
case 3:
return 0;
}
return 0;
}
void rocket()
{
cleardevice();
int j,i,kk,choice;
setcolor(WHITE);
setbkcolor(7);

/***Stand****/
line(245,450,245,190);
line(445,450,445,190);

/***SMOKE***/
setcolor(YELLOW);

//circle(325,300,5);
circle(310,455,4);
circle(330,455,4);

setcolor(4);
/***Rocket****/


line(290,200,290,450);
line(400,200,400,450);
line(290,450,400,450);
line(290,200,345,120);
line(400,200,345,120);
line(290,200,400,200);
line(290,320,400,320);
line(290,330,400,330);
line(260,440,290,440);
line(400,440,430,440);
line(430,440,400,320);
line(260,440,290,320);
outtextxy(30,280,"PRESS ANY KEY TO IGNITE THE ROCKET");
getch();


for(j=400;j<640;j++)
{
cleardevice();
setcolor(WHITE);
line(0,j,640,j);
rectangle(300,j-70,340,j);
rectangle(310,j-80,330,j-70);

setcolor(RED);
line(290,200,290,450);
line(400,200,400,450);
line(290,450,400,450);
line(290,200,345,120);
line(400,200,345,120);
line(290,200,400,200);
line(290,320,400,320);
line(290,330,400,330);
line(260,440,290,440);
line(400,440,430,440);
line(430,440,400,320);
line(260,440,290,320);

setcolor(YELLOW);
circle(325,300,5);
circle(310,455,4);
circle(330,455,4);
setcolor(14);
line(330,455,330,470);
line(330,455,340,470);
line(330,455,320,470);
delay(5);
}

for(i=0;i>200;i++)
{
cleardevice();

setcolor(RED);
line(290,200+i,290,450+i);
line(400,200+i,400,450+i);
line(290,450+i,400,450+i);
line(290,200+i,345,120+i);
line(400,200+i,345,120+i);
line(290,200+i,400,200+i);
line(290,320+i,400,320+i);
line(290,330+i,400,330+i);
line(260,440+i,290,440+i);
line(400,440+i,430,440+i);
line(430,440+i,400,320+i);
line(260,440+i,290,320+i);

setcolor(YELLOW);
circle(325,i-100,2);
delay(25);
}

cleardevice();
kk=0;
for(j=100;j<350;j++)
{
if(j%20==0)
{
setcolor(kk);
kk=kk+3;
delay(50);
}
ellipse(320,30,0,360,j+100,j+0);
}
for(j=100;j<350;j++)
{
if(j%20==0)
{
setcolor(BLACK);
delay(2);
}
ellipse(320,30,0,360,j+100,j+0);
}
cleardevice();
//for(i=0;i<70;i++)
{
setcolor(i);
settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
outtextxy(110,150,"HAPPY NEWYEAR");
delay(90);
}
cleardevice();
getch();
}/**********Tic Tac Toe***********/
int game()
{
  char done;
  cleardevice();
  setbkcolor(7);
  printf("****************Tic Tac Toe***************");
  printf("This is the game of Tic Tac Toe.\n");
  printf("You will be playing against the computer.\n");

  done =  ' ';
  init_matrix();

  do {
    disp_matrix();
    get_player_move();
    done = check(); /* see if winner */
    if(done!= ' ') break; /* winner!*/
    get_computer_move();
    done = check(); /* see if winner */
  } while(done== ' ');

  if(done=='X') printf("You won!\n");
  else printf("I won!!!!\n");
  disp_matrix(); /* show final positions */

  return 0;
}

/* Initialize the matrix. */
void init_matrix(void)
{
  int i, j;

  for(i=0; i<3; i++)
    for(j=0; j<3; j++) matrix[i][j] =  ' ';
}

/* Get a player's move. */
void get_player_move(void)
{
  int x, y;

  printf("Enter X,Y coordinates for your move: ");
  scanf("%d%*c%d", &x, &y);

  x--; y--;

  if(matrix[x][y]!= ' '){
    printf("Invalid move, try again.\n");
    get_player_move();
  }
  else matrix[x][y] = 'X';
}

/* Get a move from the computer. */
void get_computer_move(void)
{
  int i, j;
  for(i=0; i<3; i++){
    for(j=0; j<3; j++)
      if(matrix[i][j]==' ') break;
    if(matrix[i][j]==' ') break;
  }

  if(i*j==9)  {
    printf("draw\n");
   // exit(1);
  }
  else
    matrix[i][j] = 'O';
}

/* Display the matrix on the screen. */
void disp_matrix(void)
{
  int t;

  for(t=0; t<3; t++) {
    printf(" %c | %c | %c ",matrix[t][0],
            matrix[t][1], matrix [t][2]);
    if(t!=2) printf("\n---|---|---\n");
  }
  printf("\n");
}

/* See if there is a winner. */
char check(void)
{
  int i;

  for(i=0; i<3; i++)  /* check rows */
    if(matrix[i][0]==matrix[i][1] &&
       matrix[i][0]==matrix[i][2]) return matrix[i][0];

  for(i=0; i<3; i++)  /* check columns */
    if(matrix[0][i]==matrix[1][i] &&
       matrix[0][i]==matrix[2][i]) return matrix[0][i];

  /* test diagonals */
  if(matrix[0][0]==matrix[1][1] &&
     matrix[1][1]==matrix[2][2])
       return matrix[0][0];

  if(matrix[0][2]==matrix[1][1] &&
     matrix[1][1]==matrix[2][0])
       return matrix[0][2];

  return ' ';
  cleardevice();
}
