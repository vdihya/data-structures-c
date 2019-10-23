#include<stdio.h>
char A[10];
void string(int n,int k);
int main()
{
    string(2,2);
}
void string(int n,int k)
{
    if(n<1) printf("%d\n",A);
    else
    {
    for(int i=0;i<k;i++)
    {

    A[n-1] = i;
    string(n-1,k);

    }
    }

}
