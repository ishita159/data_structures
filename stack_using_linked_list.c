#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*top = NULL;


void push(int item)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = top;
    top = temp;
}

int pop()
{
    struct node* temp;
    int item;
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    temp = top;
    top = top->link;
    item = temp->data;
    free(temp);
    return item;
}

int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow]\n")
        exit(1);
    }
    return top->info;
}

int isEmpty()
{
    if(top==NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
    
}

void display()
{
    struct node* ptr;
    ptr = top;
    if(isEmpty())
    {
        printf("Stack is empty\n");
        return 0;
    }
    printf("Stack elements: \n");
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    int choice,item;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Item At The Top\n");
        printf("4. Display all the items of the stack\n");
        printf("5. Quit\n");
        printf("Enter Your Choice: \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("Enter the item to be pushed : ");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2:
                    item = pop();
                    printf("The popped item is: %d\n",item);
                    break;
            case 3: 
                    printf("Item at the top is %d\n",peek());
                    break;
            case 4: 
                    display();
                    break;
            case 5: 
                    exit(1);
            defalut: 
                    printf("Wrong Choice");
        }
        return 0;
    }
}        

        }

    }
}