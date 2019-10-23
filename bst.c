#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *rightchild,*leftchild;

}; typedef struct tree TREE;
TREE *root = NULL;

TREE *insert_nodes(struct tree *node, int data)
{
    if(!node)
    {
        node = (TREE*)malloc(sizeof(TREE));
        (node)->data = data;
        (node)->leftchild = NULL;
        (node)->rightchild = NULL;
    }
    else
    {
        if(search(node,data)==1)
        {
            printf("value already present in BST, duplicate values are not supported in a binary tree, try again: ");
        }
        else if(data < (node)->data)
            (node)->leftchild = insert_nodes(((node)->leftchild),data);
        else if(data > (node)->data)
            (node)->rightchild = insert_nodes(((node)->rightchild),data);

    }
    return node;
}

void inorder(struct tree *node)
{
    if((node))
    {
        inorder(((node)->leftchild));
        printf("%d ",(node)->data);
        inorder(((node)->rightchild));
    }

}
void postorder(struct tree *node)
{
    if((node))
    {
        postorder(((node)->leftchild));
        postorder(((node)->rightchild));
        printf("%d ",(node)->data);
    }

}
void preorder(struct tree *node)
{
    if((node))
    {
        printf("%d ",(node)->data);
        preorder(((node)->leftchild));
        preorder(((node)->rightchild));
    }

}
int search(struct tree *node,int key)
{

    if(node)
    {
        if(node->data < key)
            search(node->rightchild,key);
        else if(node->data > key)
           search(node->leftchild,key);
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;

    }

}
TREE *clone(struct tree *node)
{
    if(node == NULL) return(node);
    TREE *temp = malloc(sizeof(TREE));
    temp->data = node->data;
    temp->rightchild = clone(temp->rightchild);
    temp->leftchild = clone(temp->leftchild);
    return(temp);

}
int equal()
{
    TREE *root1;
    TREE *root2;
    while(1)
    {
        printf("input -999 to stop accepting values");

    }


}
TREE *minleaf(struct tree *node)
{
    while(node->leftchild!=NULL)
        node = node->leftchild;
    return node;
}
/*void delete_(struct tree *node,int key)
{
    if(key < node->data)
        node->leftchild = delete_(node->leftchild,key);
    else if(key > node->data)
        node->rightchild = delete_(node->rightchild,key);
    else
    {
        if(node->rightchild == NULL)
        {
            TREE *temp = node->leftchild;
            free(node);
        }
        else if(node->leftchild == NULL)
        {
            TREE *temp = node->rightchild;
            free(node);
            return temp;
        }
        TREE *temp = minleaf(node->rightchild);
        node->data = temp->data;
        node->rightchild = delete_(node->rightchild,temp->data)
    }
}*/
int main()
{
    int choice;
    while(1)
    {
        printf("\n1: create a Binary Search Tree\n2: Display the inorder traversal\n3: Display the postorder traversal\n4: Display the preorder traversal\n5: search for a key in the BST\n6: delete an element from the BST\n7: exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                {
                    int data;
                    printf("Enter the value to be inserted into the bst: ");
                    scanf("%d",&data);
                    root = insert_nodes(root,data);
                } break;

            case 2: inorder(root); break;
            case 3: postorder(root); break;
            case 4: preorder(root); break;
            case 5:
                {
                    if(!root)
                        {
                            printf("tree doesnt exist");
                            break;
                        }
                    int key;
                    printf("enter the key you want to search for in the BST: ");
                    scanf("%d",&key);
                    int value = search(root,key);
                    switch(value)
                    {
                        case 1: printf("node present in tree"); break;
                        case 0: printf("node not present in BST"); break;
                    }
                } break;
            /*case 6:
                {
                    int value;
                    printf("enter the value you want to delete from the BST");
                    scanf("%d",&value);
                    if(!root) printf("tree doesnt exist.");
                    int check = search(root,value);
                    if(check == 0 )
                        printf("value isnt present in BST try again.");
                    else
                    {
                        TREE *newr = delete_(root,value);
                        inorder(newr);
                    }

                } break;*/
            case 7: exit(0);
            default: printf("Invalid choice, try again: ");
        }

    }

}
