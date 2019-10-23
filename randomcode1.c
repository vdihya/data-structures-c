#include<time.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define heads printf("\t\tsl no.\tname of product\t\tprice\t\tshipping cost\n");\
printf("\t\t----------------------------------------------------------------\n"); //macros definition for displaying format of product catalog
#include "stock.h" //including stocks header
#define bar printf("_______\n\n");
//function prototype list:
void printtable(char *a[],float b[],int n);//function to initialize and print the table of contents of each product category
void printplus(char *a[],float b[],int n);//function to call the print and sort functions
int asksort();//function to ask for sorting
void options();//function to display sorting options (name,price,etc)
void pricesort(char *arr1[],float arr2[],int n,int ch1);//function to sort according to price
void sortit(char *x[],float y[],int n);//function to choose sort
void printtime();//function to print current date and time
void details();//function to accept customer details
void categ();//function to display categories and to start catalog display and shopping
//end of function prototype list


    int main()//main function
    {
        details();
        categ();
    }


    void printtime()
    {
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        bar
        printf("\t%s", asctime(tm));
        bar
    }


    void details()
    {
        char username[100];
        printtime();

        printf("\n\n\tWelcome to the online shopping portal!\n\n\t\tPlease enter your details below so we can make your experience better:\n");
        printf("\n\t\tEnter name: ");
        scanf("%[^\t\n]s\n",&username);
        bar
        printf("\tWelcome,%s!\n",username);
        bar

    }
    void categ()
    {
        catprint();

        int c1,c2;
        printf("\t\t\t\t\tenter choice here: ");
        scanf("%d",&c1);
        printf("\n");


        void (*ptr[])()={healthcateg,eleccateg,statcateg,clothcateg,dealcateg};


        if(c1>5)
        {
            while(1)
            {
                printf("\nInvalid choice: 1) choose again? \n 2) exit website \n 3) view cart\n");
                scanf("%d",&c2);

                switch(c2)
                    {
                        case 1:
                            categ();
                            break;
                        case 2:
                            printf("\nThank for shopping with us!\n");
                            exit(0);
                        case 3: printf("WIP");//WIPWIP
                        default:

                            continue;
                    }
            }
        }
        (*ptr[c1-1])();
    }

    struct prods //structure variable to store details of each product
        {
            char name[100];
            float price;
            float shippingcost;
        };

    void printtable(char *cat[],float prices[],int n) //function to initialize & print each struct array var with corresponding values
        {
            int i;
            struct prods h[25];
            heads
                for(i=0;i<n;i++)
                    {
                        strcpy((h[i].name),cat[i]);
                        h[i].price=prices[i];
                        h[i].shippingcost=(rand()%(150 - 50 + 1)) + 50;

                        printf("\t\t %d\t %-18s\t%6.1f\t%16.1f\n",i+1,h[i].name,h[i].price,h[i].shippingcost);
                        printf("\n");
                    }
        }



        void printplus(char *arr1[],float arr2[],int n)
        {
        printtable(arr1,arr2,n);

            options();

            if(asksort())
                {
                    sortit(arr1,arr2,n);
                    printtable(arr1,arr2,n);//to reprint new product list after sorting
                }}


    //function  prototypes start

    //function  prototypes end

    int asksort()
        {
            int ch=1;
            return ch;
        }

    void sortit(char *x[],float y[],int n)
        {
            int ch;
            printf("1) sort according to name\n 2) Lowest price to Highest\n 3)Highest price to lowest,\n");
            scanf("%d",&ch);
                switch(ch)
                    {
                        case 1: //namesort();
                            printf("sdasadjhs"); break;
                                break;
                        case 2:
                        case 3: pricesort(x,y,n,ch);
                                break;
                        default:
                                {
                                    printf("Invalid input enter again!\n");
                                    options();
                                }
                    }
        }

    void options()
        {
            int ch;
            printf("\n\t 1) sort \n\n\t 2) Select item to add to cart \n\n\t 3) Go back to categories \n\n\t 4)Exit website \n\n\t");
            printf("\t\t Enter choice here: ");
            scanf("%d",&ch);

                switch(ch)
                    {
                        case 1: asksort();
                                break;
                        case 2: printf("tbd");
                                break;
                        case 3: categ(); break;
                        default:
                                {
                                    printf("thanks for shopping with us!");
                                    exit(0);
                                }
                    }
        }

    void namesort(char *arr[],float arr2[],int n)
    { int i,j; char temp[50];
         for(i=0;i<=n;i++)
            for(j=i+1;j<=n;j++){
         if(strcmp(arr[i],arr[j])>0){
            strcpy(temp,arr[i]);
            strcpy(arr[i],arr[j]);
            strcpy(arr[j],temp);
    }}}

    void pricesort(char *arr1[],float arr2[],int n,int ch1)
        {
            int i, j; char *temp1;float temp;
            void swap(float *xp,float*yp)
                {
                    //for prices:
                    temp = *xp;
                    *xp=*yp;
                    *yp=temp;
                    //for parallel string elements:
                    temp1 = arr1[j];
                    arr1[j] = arr1[j + 1];
                    arr1[j + 1] = temp1;
                }

            for (i = 0; i < n-1; i++)
            for (j = 0; j < n-i-1; j++)
                {
                    if(ch1==2)
                    {
                        if (arr2[j] > arr2[j+1])
                        swap(&arr2[j],&arr2[j+1]);
                    }
                    if(ch1==3)
                    {
                        if(arr2[j]<arr2[j+1])
                        swap(&arr2[j],&arr2[j+1]);
                    }
                }
        }
