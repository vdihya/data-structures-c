#include<stdio.h>
typedef char s[100];
s str, substr, repstr;

  int top=-1;
char stack[100];
int main()
{

    int t,i;

accept();
t=compare(str,substr);
replace(t);


}


int compare(char str[],char substr[])
{
int i=0,j=0;

int x,y,z,t;
while(str[i]!='\0') i++;
while(substr[j]!='\0') j++;
for(x=0;x<=(i-j);x++)
{
z=0;
 y=x;
while(str[y]==substr[z])
{   int t=x;
    y++;
    z++;
if(z==len(substr))

    {return t;}

}
}
}

void replace(int t)
{    printf("%d",t);
    int i=0; int j=0;
    while(i<t) { push(str[i]); i++;}
    while(repstr[j]!='\0') {push(repstr[j]); j++;}
int r=i+len(substr);
while(r<len(str)){ push(str[r]); r++;}

/*while(i>t){push(str[i-1]); i--;}
while(j>0) {push(repstr[j-1]); j--;}
    while(j<(i-len(repstr))) {push(str[j]); j++;}*/
}
   void push(char ch)
   {
  top++;
  stack[top]=ch;
  printf("%c",stack[top]);}

void accept()
{
printf("enter string:");
scanf("%s",str);
printf("enter substring:");
scanf("%s",substr);
printf("enter replacement string:");
scanf("%s",repstr);
}
int len(char s[])
{int i,n=0;
for(i=0;s[i]!='\0';i++) {n++;}
return n;
}

