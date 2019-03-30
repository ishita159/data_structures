#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int value;
    struct linked *nextAdress;
} node;

node *createMemory()
{
    node *block = (node *)malloc(sizeof(node));
    block->value = 0;
    block->nextAdress = NULL;
    return block;
}

void insert(node *block, int val)
{
    block->value = val;
    block->nextAdress = NULL;
}

void prevMemoryUpdate(node *head, node *mem)
{
    head->nextAdress = mem;
}

node *headUpdate(node *head, node *mem)
{
    head = mem;
    return head;
}

node *insertAtBeginning(node *head, node *temp)
{
    temp->nextAdress = head;
    head = temp;
    return head;
}

node *insertAtEnding(node *last, node *temp)
{
    last->nextAdress = temp;
    last = temp;
    return last;
}

void insertInBetween(node *head, int pos, node *tempMemory)
{
    node *tempHead = head;
    int count = 1;
    while (count < pos-1)    //earlier : count < pos
    {
        tempHead = tempHead->nextAdress;
        count++;
    }
    tempMemory->nextAdress = tempHead->nextAdress;
    tempHead->nextAdress = tempMemory;
}

void printOutput(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->nextAdress;
    }
    printf("\n");
}

node* deleteAtLast(node* head)
{
    node* temp = head->nextAdress;
    while(temp->nextAdress != NULL)
    {
        head = head->nextAdress;
        temp = temp->nextAdress; //earlier we didn't update temp
    }
    free(temp);
    head->nextAdress = NULL;
    return head;
}

node* deleteAtBeginning(node* head)
{
    node* temp = head;
    head = head->nextAdress;
    free(temp);
    return head;
}

void deleteInBetween(node* head, int pos)
{
    int c = 1;
    while(c < pos-1)
    {
        head = head->nextAdress;
        c++;
    }
    node* temp = head->nextAdress;
    head->nextAdress = temp->nextAdress;
    free(temp);
}

int main()
{
    int count = 1;
    int val, option, temp, position;
    node *head = NULL;

    node *mem = createMemory();

    insert(mem, 5);
    head = mem;

    node *last = head;

    printf("%d\n", last->value);

    while (1)
    {
        if (count == 5)
        {
            break;
        }
        scanf("%d", &val);
        mem = createMemory();
        insert(mem, val);
        prevMemoryUpdate(last, mem);
        last = headUpdate(last, mem);
        printf("%d\n", last->value);
        count++;
    }

    while (1)
    {
        printf("Chhose Option: \n");
        printf("Press 1: To insert at beginning\n ");
        printf("Press 2: To insert at Ending\n ");
        printf("Press 3: To insert In Between\n ");
        printf("Press 4: To delete at Last\n ");
        printf("Press 5: To delete at Beginning\n ");
        printf("Press 6: To delete in Between\n ");
        printf("Press 7: print Output\n ");
        printf("Press 8: To Exit\n ");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Insert Value: ");
            scanf("%d", &temp);
            node *tempMemory = createMemory();
            insert(tempMemory, temp);
            head = insertAtBeginning(head, tempMemory);
            break;

        case 2:
            printf("Insert Value: ");
            scanf("%d", &temp);
            tempMemory = createMemory();
            insert(tempMemory, temp);
            last = insertAtEnding(last, tempMemory);
            break;

        case 3:
            printf("Insert Value: ");
            scanf("%d", &temp);
            tempMemory = createMemory();
            insert(tempMemory, temp);
            printf("Give Position To insert: ");
            scanf("%d", &position);
            insertInBetween(head, position, tempMemory);
            break;
        case 4:
            last = deleteAtLast(head);
            break;
        
        case 5: 
            head = deleteAtBeginning(head);
            break;
        
        case 6: 
            printf("Give psition to delete: ");
            scanf("%d",&position);
            deleteInBetween(head,position);
            break; 
        case 7:
            printOutput(head);
            break;

        case 8:
            return 0;

        default:
            break;
        }
    }
}
