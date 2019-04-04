#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList
{
    int value;
    struct linkedList *nextAdress;
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
    while (count < pos - 1) //earlier : count < pos
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

node *deleteAtLast(node *head)
{
    node *temp = head->nextAdress;
    while (temp->nextAdress != NULL)
    {
        head = head->nextAdress;
        temp = temp->nextAdress; //earlier we didn't update temp
    }
    free(temp);
    head->nextAdress = NULL;
    return head;
}

node *deleteAtBeginning(node *head)
{
    node *temp = head;
    head = head->nextAdress;
    free(temp);
    return head;
}

void deleteInBetween(node *head, int pos)
{
    int c = 1;
    while (c < pos - 1)
    {
        head = head->nextAdress;
        c++;
    }
    node *temp = head->nextAdress;
    head->nextAdress = temp->nextAdress;
    free(temp);
}

void printMiddle(node *head)
{
    int count = 0;
    node *mid = head;

    while (head != NULL)
    {

        if (count & 1)
            mid = mid->nextAdress;

        ++count;
        head = head->nextAdress;
    }

    if (mid != NULL)
        printf("The middle element is %d\n\n", mid->value);
}

node *removeRedundantNodes(node *head)
{
    if (head == NULL || head->nextAdress == NULL)
        return head;

    node *start = head;
    node *end = head;
    int sum = 0;

    while (start != NULL || end != NULL)
    {
        sum += end->value;
        if (sum == 0)
        {

            start = end->nextAdress;
            end = start;
        }
        else
        {
            end = end->nextAdress;
        }
    }

    return start;
}

node *deleteMid(node *head)
{

    if (head == NULL)
        return NULL;
    if (head->nextAdress == NULL)
    {
        free(head);
        return NULL;
    }

    node *slow_ptr = head;
    node *fast_ptr = head;

    node *prev;
    while (fast_ptr != NULL && fast_ptr->nextAdress != NULL)
    {
        fast_ptr = fast_ptr->nextAdress->nextAdress;
        prev = slow_ptr;
        slow_ptr = slow_ptr->nextAdress;
    }

    prev->nextAdress = slow_ptr->nextAdress;
    free(slow_ptr);

    return head;
}

void removeDuplicateNode(node *head)
{
    node *current = head;

    node *next;

    if (current == NULL)
        return;

    while (current->nextAdress != NULL)
    {
        if (current->value == current->nextAdress->value)
        {
            next = current->nextAdress->nextAdress;
            free(current->nextAdress);
            current->nextAdress = next;
        }
        else
        {
            current = current->nextAdress;
        }
    }
}

node *reverse(node *head)
{
    node *prev = NULL;
    node *current = head;
    node *next;
    while (current != NULL)
    {
        next = current->nextAdress;
        current->nextAdress = prev;
        prev = current;
        current = next;
    }
    return prev;
}

node *addOneUtil(node *head)
{

    node *res = head;
    node *temp, *prev = NULL;

    int carry = 1, sum;

    while (head != NULL)
    {
        sum = carry + head->value;
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        head->value = sum;
        temp = head;
        head = head->nextAdress;
    }

    if (carry > 0)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->value = carry;
        new_node->nextAdress = NULL;
        temp->nextAdress = new_node;
    }
    return res;
}

node *addOne(node *head)
{
    head = reverse(head);

    head = addOneUtil(head);
    head = reverse(head);
    return head;
}

void detectLoop(node *head)
{
    node *slow_p = head, *fast_p = head;

    while (slow_p && fast_p && fast_p->nextAdress)
    {
        slow_p = slow_p->nextAdress;
        fast_p = fast_p->nextAdress->nextAdress;
        if (slow_p == fast_p)
        {
            printf("Loop Found at %d", slow_p->value);
            return;
        }
    }
    printf("NO LOOP FOUND!!");
    return;
}

void detectAndRemoveLoop(node *head)
{
    node *slow_p = head, *fast_p = head;
    int flag = 0;

    while (slow_p && fast_p && fast_p->nextAdress)
    {
        slow_p = slow_p->nextAdress;
        fast_p = fast_p->nextAdress->nextAdress;

        if (slow_p == fast_p)
        {
            RemoveLoop(slow_p, head);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("NO LOOPS FOUND TO REMOVE\n\n");

    else
    {
        printf("LOOP REMOVED\n\n");
    }
}

void RemoveLoop(node *loop_node, node *head)
{
    int count = 0;
    while (head != NULL)
    {
        if (head == loop_node)
        {
            count++;
            if (count == 2)
            {
                head->nextAdress = NULL;
            }
        }
        head = head->nextAdress;
    }
}

void printNthFromLast(node *head, int n)
{
    node *main_ptr = head;
    node *ref_ptr = head;

    int count = 0;
    if (head != NULL)
    {
        while (count < n)
        {
            if (ref_ptr == NULL)
            {
                printf("%d is greater than the no. of "
                       "nodes in list",
                       n);
                return;
            }
            ref_ptr = ref_ptr->nextAdress;
            count++;
        }

        while (ref_ptr != NULL)
        {
            main_ptr = main_ptr->nextAdress;
            ref_ptr = ref_ptr->nextAdress;
        }
        printf("Node no. %d from last is %d ",
               n, main_ptr->value);
    }
}

node *rotate(node *head, int k)
{
    if (k == 0)
        return head;

    node *current = head;

    int count = 1;
    while (count < k && current != NULL)
    {
        current = current->nextAdress;
        count++;
    }
    if (current == NULL)
        return head;

    node *kthNode = current;

    while (current->nextAdress != NULL)
        current = current->nextAdress;

    current->nextAdress = head;

    head = kthNode->nextAdress;
    kthNode->nextAdress = NULL;
    return head;
}

void deleteLast(node *head, int x)
{
    node *temp = head, *ptr = NULL;
    while (temp)
    {

        if (temp->value == x)
            ptr = temp;
        temp = temp->nextAdress;
    }

    if (ptr != NULL && ptr->nextAdress == NULL)
    {
        temp = head;
        while (temp->nextAdress != ptr)
            temp = temp->nextAdress;
        temp->nextAdress = NULL;
    }

    if (ptr != NULL && ptr->nextAdress != NULL)
    {
        ptr->value = ptr->nextAdress->value;
        temp = ptr->nextAdress;
        ptr->nextAdress = ptr->nextAdress->nextAdress;
        free(temp);
    }
}

void skipMdeleteN(node *head, int M, int N)
{
    node *curr = head, *t;
    int count;

    while (curr)
    {
        for (count = 1; count < M &&
                        curr != NULL;
             count++)
            curr = curr->nextAdress;

        if (curr == NULL)
            return;
        t = curr->nextAdress;
        for (count = 1; count <= N && t != NULL; count++)
        {
            node *temp = t;
            t = t->nextAdress;
            free(temp);
        }

        curr->nextAdress = t;
        curr = t;
    }
}

node *deleteLinkedList(node *head)
{

    node *current = head;
    node *next;

    while (current != NULL)
    {
        next = current->nextAdress;
        free(current);
        current = next;
    }

    head = NULL;
    return head;
}

node *mergeAtAlternatePositions(node *p, node *q)
{
    node *p_curr = p, *q_curr = q;
    node *p_next, *q_next;

    while (p_curr != NULL && q_curr != NULL)
    {
        p_next = p_curr->nextAdress;
        q_next = q_curr->nextAdress;

        q_curr->nextAdress = p_next;
        p_curr->nextAdress = q_curr;

        p_curr = p_next;
        q_curr = q_next;
    }

    q = q_curr;
    return q;
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
        printf("Press 1:  To insert at beginning\n ");
        printf("Press 2:  To insert at Ending\n ");
        printf("Press 3:  To insert In Between\n ");
        printf("Press 4:  To delete at Last\n ");
        printf("Press 5:  To delete at Beginning\n ");
        printf("Press 6:  To delete in Between\n ");
        printf("Press 7:  print Output\n ");
        printf("Press 8:  To Print the Middle of a given linked list \n ");
        printf("Press 9:  To Delete the elements in an linked list whose sum is equal to zero\n ");
        printf("Press 10: To Delete middle of linked list\n ");
        printf("Press 11: To Remove duplicate elements from sorted linked list\n ");
        printf("Press 12: To Add 1 to a number represented as a linked list\n ");
        printf("Press 13: To Detect loop in linked list\n ");
        printf("Press 14: To Remove loop in linked list\n ");
        printf("Press 15: To Find nth node from the end of linked list\n ");
        printf("Press 16: To Function to check if a singly linked list is a palindrome\n ");
        printf("Press 17: To Delete last occurrence of an item from linked list;\n ");
        printf("Press 18: To Rotate a linked list\n ");
        printf("Press 19: To Delete n nodes after m nodes of a linked list\n ");
        printf("Press 20: To Merge a linked list into another linked list at alternate positions\n ");
        printf("Press 21: To delete a linked list\n ");
        printf("Press 22: To reverse the nodes of a linked list\n ");
        printf("Press 23: To Exit\n ");

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
            scanf("%d", &position);
            deleteInBetween(head, position);
            break;

        case 7:
            printOutput(head);
            break;

        case 8:
            printMiddle(head);
            break;

        case 9:
            head = removeRedundantNodes(head);
            break;

        case 10:
            head = deleteMid(head);
            break;

        case 11:
            removeDuplicateNode(head);
            break;

        case 12:
            head = addOne(head);
            break;

        case 13:
            detectLoop(head);
            break;

        case 14:
            detectAndRemoveLoop(head);
            break;

        case 15:
            printf("Insert Value of Nth node: ");
            scanf("%d", &temp);
            printNthFromLast(head, temp);
            break;
        /*
        case 16:
            break;
        */
        case 17:
            printf("Insert Value To Be Deleted: ");
            scanf("%d", &temp);
            deleteLast(head, temp);
            break;

        case 18:
            printf("Insert Value of Node to begin with: ");
            scanf("%d", &temp);
            head = rotate(head, temp);
            break;

        case 19:
            printf("Insert Value of n and m: ");
            int n, m;
            scanf("%d %d", &n, &m);
            skipMdeleteN(head, m, n);
            break;
        
        /*
        case 20:
            head2 = mergeAtAlternatePositions(head1, head2);
            break;
        */
       
        case 21:
            head = deleteLinkedList(head);
            break;

        case 22:
            head = reverse(head);
            break;

        case 23:
            return 0;

        default:
            break;
        }
    }
}
