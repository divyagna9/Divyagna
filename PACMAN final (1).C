#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#define H 15
#define W 40
char playfield[H][W]={
{"*************************************"},
{"*...................................*"},
{"*..*..*..*..*..*..*..*..*..*..*..*..*"},
{"*..*..*..*..*..*..*..*..*..*..*..*..*"},
{"*..*..*..*..*..*..*..*..*..*..*..*..*"},
{"*..*..*..*..*..*..*..*..*..*..*..*..*"},
{"*..*..*..*..*..*..*..*..*..*..*..*..*"},
{"*...................................*"},
{"*..*..*..*..*..*..*..*..*..*..*..*..*"},
{"*..*..*..*..*..*..*..*..*..*..*..*..*"},
{"*..*..*..*..*..*..*..*..*..*..*..*..*"},
{"*..*..*..*..*..*..*..*..*..*..*..*..*"},
{"*..*..*..*..*..*..*..*..*..*..*..*..*"},
{"*...................................*"},
{"*************************************"},
};
int food_collect=0,game_end=0;
int py=1,px=1;
int gy1=1,gx1=38,gy2=13,gx2=1;
FILE *fp;
void game_result()
{
clrscr();
fp = fopen("RESULTS.txt","a");
if(food_collect==500)
{
fprintf(fp,"\n\n\n\n\n\n\n\n\n");
fprintf(fp,"\t\t\t   Congratualtions!\n");
fprintf(fp,"\t\t\t  You won the game!\n");
fprintf(fp,"\t\t\t  Your total score is %d",food_collect);
}
else
{
fprintf(fp,"\n\n\n\n\n\n\n\n\n");
fprintf(fp,"\t\t\t  Better luck!\n");
fprintf(fp,"\t\t\t  You lose the game!\n");
fprintf(fp,"\t\t\t  Yyour total score is %d\n",food_collect);
}
fclose(fp);
}
void move_ghosts()
{
if(gy1==1&&gx1>1)
{
gx1--;
}
else if(gx1==1&&gy1<7)
{
gy1++;
}
else if(gy1==7&&gx1<38)
{
gx1++;
}
else if(gx1==38&& gy1>1)
{
gy1--;
}
if(gy2==13&&gx2<38)
{
gx2++;
}
else if(gx2==38&&gy2>7)
{
gy2--;
}
else if(gy2==77&&gx2>1)
{
gx2--;
}
else if(gx2==1&&gy2<13)
{
gy2++;
}
}
void user_input()
{
char c1;
if(kbhit())
{
c1=getch();
switch(c1)
{
case 72:py-=1;break;
case 80:py+=1;break;
case 75:px-=1;break;
case 77:px+=1;break;
}
}
}
void setup()
{
int a,i,j;
for(i=0;i<H;i++)
{
for(j=0;j<W;j++)
{
if(playfield[i][j]=='#')
{
playfield[i][j]=' ';
}
if(playfield[i][j]=='@')
{
playfield[i][j]='.';
}
}
}
if(playfield[py][px]=='.')
{
food_collect++;
}
if(playfield[py][px]=='*')
{
py=1;
px=1;
}
playfield[py][px]='#';
playfield[gy1][gx1]='@';
playfield[gy2][gx2]='@';
if (playfield[py][px]=='@')
{
game_end=1;
}
}
void draw_playfield()
{
int i,j;
textcolor(YELLOW);
printf("\n\n\n\n");
for(i=0;i<H;i++)
{
printf("\t\t");
for(j=0;j<W;j++)
{
cprintf("%c",playfield[i][j]);
}
printf("\n");
}
printf("score is %d",food_collect);
}
void main()
{
int i=100;
while(game_end!=1)
{
clrscr();
sound(i);
setup();
user_input();
move_ghosts();
draw_playfield();
delay(200);
if(i<1000)
i=i+100;
else
i=100;
}
nosound();
game_result();
getch();
}
