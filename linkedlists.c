#include<stdio.h>
#include<stdlib.h>
struct list
{
float data;
struct list* next;
};typedef struct list node;


int main()
{
    choices();
}
void choices()
{
    int choice;
printf("1)Input elements into the linked list\n\n 2)Delete an element from the list\n\n 3)Insert an element into the linked list\n\n 4)Display the elements of the linked list\n\n 5)Exit the program\n\n");
printf("Input choice: ");
scanf("%d", &choice);
 node *head;
 head = (node*)malloc(sizeof(node));
 head=NULL;
switch(choice)
{
    case 1: create(head); break;
    case 2: del(head); break;
    case 3: insert(head); break;
    case 4: display(head); break;
    default: printf("Invalid input "); exit(0);
}
}

void create(node *list1)

{
float value;
printf("Input value, enter -999 to stop accepting values: ");
scanf("%f",&value);
if(value==-999) list1->next=NULL;
else{
list1->data=value;
list1->next=(node*)malloc(sizeof(node));
list1= list1->next;
create(list1->next);
}
choices();
}
void display(node *list1)
{
while(list1->next!=NULL)
{printf("%f\t",list1->data);
list1= list1->next;
}
choices();
}

void insert(node *list1)
{ int ch1; float newvalue;
printf("1) Insert a node at the beginning of the linked list\n\n 2) Insert a node at the end of the linked list\n\n 3) Insert node at a specified position after/before a particular node\n\n");
 printf("Enter choice: ");
 scanf("%d",&ch1);
  printf("Input the value to be stored in the new node: ");
  scanf("%f",&newvalue);
 node *newnode = (node*)malloc(sizeof(node));
 newnode->data = newvalue;

 switch(ch1)
 {
 case 1:
     {

     node *temp = list1;
     list1 = newnode;
     newnode->next = temp;
 } break;
 case 2:
 {
 while(list1->next!=NULL)
 {list1= list1->next;}
 list1->next=newnode;
 newnode->next = NULL;
 }break;
 case 3:
 { int i=0,pos;
 printf("Input the node after which you want to insert a new node, nodes start referencing from node 1: ");
 scanf("%d",&pos);
 while(i<=pos)
    {list1=list1->next;}
 newnode->next = list1->next;
 list1->next=newnode;
 }break;
 default:
     {printf("Invalid input"); exit(0);}
}
choices();
}

void del(node *list1)
{ int ch2;
    printf("1) Delete a node from the beginning of the list\n\n 2) Delete a node from the end of the linked list\n\n 3) Delete a node from a specified position before/after a node in the linked list\n\n");
    printf("Enter choice: ");
    scanf("%d",&ch2);
    switch(ch2)
    {
    case 1:
        {
            node *temp = list1;
            list1 = list1->next;
            free(temp);
        }break;
    case 2:
        {
            while(list1->next!=NULL)
            {list1 = list1->next;}
         node *temp = list1->next;
         list1->next = NULL;
         free(temp);

        }
    case 3:
        {   int pos; int i=0;
            printf("Input the node you want deleted: ");
            scanf("%d",&pos);
            while(i<pos)
                list1=list1->next;
            node *temp = list1->next;
            list1->next = temp->next;
        }
    default:
        {
            printf("Invalid input"); exit(0);
        }
    }
choices();
}


