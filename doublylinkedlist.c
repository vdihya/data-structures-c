#include<stdio.h>
#include<stdlib.h>
struct employee
{
    char SSN[20];
    char name[100];
    char department[100];
    char designation[100];
    double salary;
    char pno[10];
    struct employee *next;
    struct employee *prev;

}; typedef struct employee *E;
    E head = NULL;

E create_node()
{   E newemp = (E)malloc(sizeof(struct employee));
    printf("Enter Employee's name: ");
    scanf("%s",newemp->name);
    printf("Enter Employee's SSN: ");
    scanf("%s",newemp->SSN);
    printf("Enter Employee's department: ");
    scanf("%s",newemp->department);
    printf("Enter Employee's designation: ");
    scanf("%s",newemp->designation);
    printf("Enter Employee's salary: ");
    scanf("%lf",&newemp->salary);
    printf("Enter Employee's phone number: ");
    scanf("%s",newemp->pno);
    newemp->next = NULL;
    newemp->prev = NULL;
    return (newemp);
}

void create_list()
{E newemp;
     int value;
   while(1)
   {
    printf("Enter -999 to stop accepting values, enter any other to continue accepting values: ");
    scanf("%d",&value);
    if(value==-999)
    return;

        newemp = create_node();
        if(head == NULL)
           {
              head = newemp;
            }

        else
        {   E temp = head;
            while(temp->next!=NULL)
        {
             temp = temp->next;
        }

            newemp->prev = temp;
            temp->next= newemp;

            }

        }

    }


void display_nodes()
{   printf("\n\tSSN\t\tName\t\tDepartment\t\tDesignation\t\tSalary\t\tPhone Number\n\n");
    E temp;
    temp = head;
    while(temp!=NULL)
    {
         printf("%s\t\t%s\t\t%s\t\t%s\t\t%lf\t\t\t%s\n\n",temp->SSN,temp->name,temp->department,temp->designation,temp->salary,temp->pno);
        temp = temp->next;
    }

}
void insert_beg()
{
    E newemp = create_node();
    if(head == NULL) {head = newemp;}
    else
        {
        newemp->next = head;
        head->prev = newemp;
        head = newemp;//to move to new node//
        }
    return;
}
void insert_end()
{
    E newemp = create_node();
    E temp = head;
    if(head==NULL)
    {
        head = newemp;

    }
    else
        {
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next = newemp;
    newemp->prev = temp;
        }
    return;
}
void delete_end()
{
    if(head == NULL) printf("No Employee to delete.");
    E temp = head;
    if(temp->next==NULL) {free(temp); head == NULL;}
    else
        {
            while(temp->next->next!=NULL)
                temp = temp->next;
            E nextnode = temp->next;
            temp->next = NULL;
            free(nextnode);
        }

    return;
}
void delete_beg()
{
    E temp = head;
    if(head == NULL) printf("No employee to delete.");
    else if(temp->next==NULL)//there's only one node.
    {free(temp); head= NULL;} // free that node and set head to null
    else
    {
        head = temp->next;
        temp->next->prev = NULL; // or head->prev = NULL;
        free(temp);
    }
    return;
}
void insert_pos()
{   int pos; E temp = head; int count = 0;
    printf("Enter position where you want to insert a new Employee: ");
    scanf("%d",&pos);
    int i=0;
    while(temp!=NULL){ temp = temp->next; count++;}
    if(pos > count || pos < 0) {printf("Invalid position, choose again: "); return;}
    if(head == NULL) {printf("No Employee to delete."); return;}
    temp = head;
    if(pos == 1) {insert_beg(); return;}
    while(temp->next!=NULL && i<pos-2)
    {temp=temp->next; i++;}
    E newemp = create_node();
    newemp->next = temp->next;
    newemp->prev = temp;
    temp->next->prev = newemp;
    temp->next = newemp;

    return;

}
void delete_pos()
{
    int pos; E temp = head; int count = 0; int i = 0;
    printf("Enter position where you want to delete a Employee: ");
    scanf("%d",&pos);
    while(temp!=NULL){ temp = temp->next; count++;}
    if(pos > count || pos < 0) {printf("Invalid position, choose again: "); return;}
    if(pos==1) {delete_beg(); return;}
    if(head == NULL){ printf("No Employee to delete."); return;}
    temp = head;
    while(temp->next!=NULL && i<pos-2)
    {
        temp=temp->next; i++;
    }
        E nextnode = temp->next; //node to be freed
        temp->next = temp->next->next;
        temp->next->prev = temp;
        free(nextnode);

    return;

}

void DEqueue()
{
    int ch;
   for( ; ; )
   {

    printf("\n 1: enqueue element from the front,\n 2: enqueue element from rear,\n 3: Dequeue element from front,\n 4: dequeue element from rear,\n 5: exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: insert_beg(); break;
        case 2: insert_end(); break;
        case 3: delete_beg(); break;
        case 4: delete_end(); break;
        case 5: exit(0);
        default: printf("invalid input");
    }
   }

}
int main()
{
    int choice;
     for( ; ; )
   {

        printf("\n 1: Create a Employee linked list database,\n 2: Display Employee details,\n 3: Add a Employee to the beginning of the list,\n 4: Add a Employee to the end of the list,\n 5: Delete a Employee from the beginning of the list,\n 6: Delete a Employee from the end of the list,\n 7: Add a Employee at a specified position,\n 8: Delete a Employee from a specified position,\n 9: To demonstrate the working of a double ended queue,\n 10:Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);


       switch(choice)
    {
        case 1: create_list(); break;
        case 2: display_nodes(); break;
        case 3: insert_beg(); break;
        case 4: insert_end(); break;
        case 5: delete_beg(); break;
        case 6: delete_end(); break;
        case 7: insert_pos(); break;
        case 8: delete_pos(); break;
        case 9: DEqueue(); break;
        case 10: exit(0);
        default: printf("Invalid Input, try again: ");
    }
    }
    return(0);
}
