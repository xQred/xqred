#include<stdio.h>
#include<reg51.h>

void delay(int k)
{
int i;
int j;
for(i=0;i<k;i++)
{
for(j=0;j<10000;j++)
{
}
}
}
void main(void)
{
int i,j;
char a[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
P2=0x00;
P3=0x00;
while(1)
{
for(i=0;i<10;i++)
P2=a[i];
for(j=0;j<10;j++)
{
P3=a[j];
	delay(10);
}
}
}
