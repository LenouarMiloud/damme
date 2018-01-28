#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
int x[8];
int compteur=0;
void echiquier()
{int i,j;
printf("\n\n\n");
for(i=0;i<=7;i++)
{
for(j=0;j<=7;j++)
printf("0");
printf("\n");
}
}
void poser()
{
int i;
clrscr();
compteur++;
printf("Voici la solution N=%d\nAppuyer sur une touche pour continuer...                    Esc pour sortir!!!",compteur);
echiquier();
for(i=0;i<=7;i++)
{
gotoxy(i+1,x[i]+5);printf("X");
}
}
int libre(int l ,int c)
{
int i;
for(i=0;i<c;i++)
if ((x[i]==l)||(abs(x[i]-l)==abs(i-c))) return 0;
return 1;
}
void solution(int n)
{
int i;
if(n==8)
{
poser();
if(getch()==27) exit(1);
}
else
for(i=0;i<8;i++)
if(libre(i,n))
{
x[n]=i;
solution(n+1);
}
}
void main()
{
solution(0);
}
