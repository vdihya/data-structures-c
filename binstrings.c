#include<stdio.h>
void binary(int n);
char A[];
int main()
{


    binary(4);
    return 0;
}

    void binary(int n)
    {
        if(n<1) printf("%s\n",A);

        else
            {
                A[n-1] = '0';
                binary(n-1);
                A[n-1] = '1';
                binary(n-1);
            }


    }

