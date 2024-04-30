#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define X 50
#define Y 15
#define I int
#define M main

I 
M(
){I
n[Y]
[X];I
f[Y][X
]={};s\
rand(ti\
me(NULL))
;for(I y=0
;y<Y;y++)f\
or(I x=0;x<X
;x++)f[y][x]=
rand()%2;for(;
;){printf("\e[\
1;1H\e[2J");for(
I i=0;i<Y;i++){f\
or(I j=0;j<X;j++){
printf("%c",".#"[f[
i][j]]);}printf("\n"
);}for(I y=0;y<Y;y++)
{for(I x=0;x<X;x++){n[
y][x]=0;for(I i=-1;i<2;
i++){for(I j=-1;j<2;j++)
{if(i==0&&j==0)continue;I
b=(y+i+Y)%Y;I c=(x+j+X)%X;
if(f[b][c])n[y][x]++;}}}}f\
or(I i=0;i<Y;i++){for(I j=0;
j<X;j++){if(f[i][j])f[i][j]=(
n[i][j]==2||n[i][j]==3)?1:0;e\
lse f[i][j]=(n[i][j]==3)?1:0;}}
/*   jesus wept   */Sleep(50);}}

