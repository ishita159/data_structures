#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int value;
    struct linkedList *previous;
    struct linkedList *next;
}node;

node* createMemory()
{
    node* temp = (node*)malloc(sizeof(node));
    temp->value = 0;
    temp->previous = NULL;
    temp->next = NULL;
    return temp;
}

void insert(int value, node* memory)
{
    memory->value = value;
}

void printOutput(node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->nextAdress;
    }
    printf("\n");
}

node* insertAtBeginning(node* head, node* memory)
{
    memory->next = head;
    head->previous = memory;
    head = memory;
    return head;
}

node* insertAtEnding(node* last, node* memory)
{
    last->next = memory;
    memory->previous = last;
    last = memory;
    return last;
}

void insertInBetween(node* head, int position, mode* memory)
{
    int c = 1;
    while(c < position-1)
    {
        head = head->next;
    }
    node *temp = head->next;
    memory->previous = head;
    memory->next = temp;
    temp->previous = memory;
    head->next = memory;
}


int main()
{
    int val,no_of_nodes,option,position;
    node* head = NULL;
    printf("Enter number of nodes: ");
    scanf("%d",&no_of_nodes);
    no_of_nodes = no_of_nodes - 1;
    printf("GIVE VALUES....\n");
    node* memory = createMemory();
    scanf("%d",&val);
    insert(val, memory);
    head = memory;
    node* last = head;
    printf("%d",memory->value);
    while(no_of_nodes--)
    {
        scanf("%d",&val);
        memory = createMemory();
        insert(val,memory);
        last->next = memory;
        memory->previous = last;
        last = memory;
        printf("%d",memory->value);
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
            scanf("%d", &val);
            node *tempMemory = createMemory();
            insert(val,tempMemory);
            head = insertAtBeginning(head, tempMemory);
            break;

        case 2:
            printf("Insert Value: ");
            scanf("%d", &val);
            tempMemory = createMemory();
            insert(val,tempMemory);
            last = insertAtEnding(last, tempMemory);
            break;

        case 3:
            printf("Insert Value: ");
            scanf("%d", &val);
            tempMemory = createMemory();
            insert(val,tempMemory);
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
            scanf("%d", &position);
            deleteInBetween(head, position);
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