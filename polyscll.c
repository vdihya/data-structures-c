#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct poly
{
    int coeff;
    int x,y,z;
    struct poly *next;
}e;
e *head1 = NULL;


e *create_node(struct poly **head)
{
    e *newterm = malloc(sizeof(e));
    printf("Input the coefficient: ");
    scanf("%d",&newterm->coeff);
    printf("Enter the power of x: ");
    scanf("%d",&newterm->x);
    printf("Enter the power of y: ");
    scanf("%d",&newterm->y);
    printf("Enter the power of z: ");
    scanf("%d",&newterm->z);
    newterm->next = *head;
    return(newterm);
}

void create_list(struct poly **head)
{
    int value; e *newterm;
    while(1)
    {
            printf("Enter -999 to stop inputting terms, input other value to continue accepting values: ");
            scanf("%d",&value);
            if(value == -999)
            return;
            newterm = create_node(&(*head));
            e *temp = *head;
            if(*head!=NULL)
                {
                    while (temp->next != *head)
                        temp = temp->next;
                    temp->next = newterm;
                }
            else
                {

                    newterm->next = newterm;
                    (*head) = newterm;
                }



    }
}
void display(struct poly **head)
{
    e *temp = *head;
    if((*head)!=NULL)
    {

    do
    {

        printf("%d*(x^%d)*(y^%d)*(z^%d)+",temp->coeff,temp->x,temp->y,temp->z);
        temp = temp->next;
    }while(temp!=*head);
    }
    else printf("empty list!");
}
void plug(struct poly **head)
{   int x,y,z; e *temp = *head;
    printf("input a value for x to plug into polynomial: ");
    scanf("%d",&x);
    printf("input a value for y to plug into polynomial: ");
    scanf("%d",&y);
    printf("input a value for z to plug into polynomial: ");
    scanf("%d",&z);
    double sum=0;
    do
    {
        sum+= (temp->coeff) * pow(x,temp->x) * pow(y,temp->y) * pow(z,temp->z);
        temp = temp->next;
    }while(temp!=*head);

    printf("Evaluated polynomial: %f",sum);

}
void add()
{
    e *head2=NULL; e *head3=NULL;
    printf("Input the first polynomial: ");
    create_list(&head2);
    printf("Input the second polynomial: ");
    create_list(&head3);
    e *headfinal = NULL;
    e *temp2 = head2;
    e *temp3 = head3;
    e *tempfinal = headfinal;
    int flag;
    do
    {
        flag = 0;
        temp3 = head3;

        do
        {


            if((temp2->x == temp3->x)&&(temp2->y == temp3->y)&&(temp2->x == temp3->z))
            {

                e *node = malloc(sizeof(e));
                node->next = NULL;
                node->coeff = temp2->coeff + temp3->coeff;
                node->x = temp2->x;
                node->y = temp2->y;
                node->z = temp2->z;
                insert(&headfinal,&node);
                temp3->coeff = 0;
                flag = 1;
                break;

            }
           else temp3=temp3->next;

        }while(temp3!=head3);

        if(flag == 0)
        {

                e *node = malloc(sizeof(e));
                node->next = NULL;
                node->coeff = temp2->coeff;
                node->x = temp2->x;
                node->y = temp2->y;
                node->z = temp2->z;
                insert(&headfinal,&node);

        }
       temp2 = temp2->next;

    }while(temp2!=head2);

    temp3 = head3;
    do
    {
        if(temp3->coeff !=0)
        {

                e *node = malloc(sizeof(e));
                node->next = NULL;
                node->coeff = temp3->coeff;
                node->x = temp3->x;
                node->y = temp3->y;
                node->z = temp3->z;
                insert(&headfinal,&node);

        }
    temp3 = temp3->next;
    }while(temp3!=head3);

while(headfinal!=NULL)
    {

        printf("%d*(x^%d)*(y^%d)*(z^%d)+",headfinal->coeff,headfinal->x,headfinal->y,headfinal->z);
        headfinal = headfinal->next;
    }
    return;
}

void insert(struct poly **head,struct poly **node)
{
    if((*head) == NULL)
    {

        (*head) = (*node);
    }
     else
        {
            (*node)->next = (*head);
            (*head) = (*node);
        }


}
int main()
{
    int choice;
    for( ; ; )
    {
    printf("\n1) create a polynomial and plug in values\n2) display polynomial\n3) plug in values into polynomial\n4) add two polynomials\n");
    printf("Enter: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: create_list(&head1); break;
        case 2: display(&head1); break;
        case 3: plug(&head1); break;
        case 4:
            {
                add();

            } break;
        default: printf("invalid choice, try again: ");
    }
    }
    return(0);
}


