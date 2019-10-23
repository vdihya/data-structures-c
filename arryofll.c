   #include<stdio.h>
   #include<stdlib.h>
#include<string.h>
struct list
{
char name[100];
char price[100];
char shippingcost[100];
struct list *next;
};
typedef struct list node;
node *A[2];

   int main()
      {char *s[50];
   FILE *fptr;
   fptr = fopen("C:\\Users\\vidhya\\Downloads\\foo\\data.txt","r");
  fseek(fptr, -1, SEEK_SET);
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }

    int count = 0;
   fflush(stdin);
   while(getc(fptr)!=EOF)
    {

       fscanf(fptr,"%[^\n]",&s);
      printf("%s",s); printf("\n\n\n");
    count++;
      }
      fclose(fptr);








    FILE *pptr;
    pptr = fopen("C:\\Users\\vdihya\\Downloads\\foo\\products.txt","r");
    fseek(pptr,-1,SEEK_SET);
   if(pptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   int a;
   while(a<2) A[a] = NULL;
   int i,j;char *str[100];
   for(i=0;i<2;i++)
   {




    A[i] = (node*)malloc(sizeof(node));
   for(j=0;j<2;j++)
   { while(getc(pptr)!=EOF)
   {
    fscanf(pptr," %[^\t]s ",A[i]->name);
    fscanf(pptr,"%[^\t]s",A[i]->price);
    fscanf(pptr,"%[^\t]s",A[i]->shippingcost);
    A[i]->next = (node*)malloc(sizeof(node));
    printf("%s_\t %s_\t %s_\t\n",A[i]->name,A[i]->price,A[i]->shippingcost);
    A[i] = A[i]->next->next;
   }printf("\n");
   }
      }

fclose(pptr);
}
