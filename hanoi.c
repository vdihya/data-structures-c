#include<stdio.h>
long int k=0;
void hanoi(int n,char source[],char dest[],char aux[])
{
if(n>0)
{
hanoi(n-1,source,aux,dest);
printf("\n Move disk %d from %s to %s",n,source,dest);
hanoi(n-1,aux,dest,source);
}
}
int main()
{
int n;
printf("\n how many disks?\n");
scanf("%d",&n);
hanoi(n,"S","D","A");
}
