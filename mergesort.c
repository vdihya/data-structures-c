#include<stdio.h>
#include<stdlib.h>

void mergesort(int arr[],int l,int u);
void merge(int arr[],int l,int m, int u);

int main()
{ int x;
int arr[]={3,1,2,4,5,2,4,4,3,2,2,4,3};
//printf("input number of elements in array:");scanf("%d",&n);

//printf("input array to be sorted:");
//for(x=0;x<n;x++)
//   {scanf("%d",&arr[x]);}
int l = 0;
int u = sizeof(arr)/sizeof(arr[0]);

printf("sorted array:");
for(x=0;x<u;x++)
    printf("%d",arr[x]);
mergesort(arr,l,u);

printf("sorted array:");
for(x=0;x<u;x++)
    printf("%d",arr[x]);
}
void merge(int arr[],int l,int m, int u)
{ int n1,n2;
int i,k,j;
     n1= m - l + 1;
    n2= u - m;
    int L[n1],R[n2];

     for(i=0;i<n1;i++)
        {L[i]=arr[l+i];}
     for(j=i;j<n2;j++)
        {R[j]=arr[m+1+j];}


 i=0;j=0;k=l;
    while(i<n1 && j<n2)
        {
    if(L[i]<=R[j])
     {arr[k]=L[i]; i++;}

        else
            { arr[k]=R[j]; j++;}
        k++;}
      while(i<n1)
      {
          arr[k]=L[i];
          i++; k++;
      }
      while(j<n2)
        {
        arr[k]=R[j]; j++; k++;
    }
}

void mergesort(int arr[],int l,int u)
{
int m;
if(l<u){
    m= l+(u-1)/2;

    mergesort(arr,l,m);
    mergesort(arr,m+1,u);
    merge(arr,l,m,u);

}
}
