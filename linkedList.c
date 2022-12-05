#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node* newNode(int value, Node* next)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = next;
    return newNode;
}

Node* insertEnd(int value, Node* head) 
{
    if(head->next != NULL)
    {
        return insertEnd(value, head->next);
    }

    return head->next = newNode(value, NULL);
}

Node* bulkInsertEnd(int arr[], int arrLength, Node* head)
{
    if(head->next != NULL)
    {
        return bulkInsertEnd(arr, arrLength, head->next);
    }

    Node* currentNode = head;

    for (int i = 0; i < arrLength; i++)
    {
        currentNode->next = newNode(arr[i], NULL);
        currentNode = currentNode->next;
    }

    return head;
}

Node* recursiveBulkInsertEnd(int arr[], int arrLength, Node* head, Node* currentNode)
{
    if (arrLength == 0)
    {
        return head;
    }

    if (currentNode->next != NULL) 
    {
        return recursiveBulkInsertEnd(arr, arrLength, head, currentNode->next);
    }

    currentNode->next = newNode(*arr, NULL);

    return recursiveBulkInsertEnd(arr+1, arrLength-1, head, currentNode->next);
}

Node* removeNthFromEnd(Node* head, int n)
{
    int i;
    int listLength = 0;
    Node* traversal = head;
    Node* temp;

    while(traversal)
    {
        traversal = traversal->next;
        listLength += 1;
    }

    traversal = malloc(sizeof(Node));
    traversal->next = head;
    i = listLength - n;

    if(n == listLength)
    {
        return head->next;
    }
    while(i > 0)
    {
        traversal = traversal->next;
        i -= 1;
    }
    if(!traversal->next)
    {
        return head;
    }

    temp = traversal->next;
    traversal->next = traversal->next->next;

    return head;
}

Node* mergeTwoLists(Node* list1, Node* list2)
{
    if(!list1)
    {
        return list2;
    }

    if(!list2)
    {
        return list1;
    }

    Node* temp = newNode(0, NULL);
    Node* head = temp;

    while(list1||list2)
    {
        if(list1->value <= list2->value)
        {
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
        } 
        else
        {
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }
        if(!list1)
        {
            temp->next = list2;
            return head->next;
        }
        if(!list2)
        {
            temp->next = list1;
            return head->next;
        }
    }

    return head->next;
}

void printLinkedList(Node* head)
{
    Node* currentNode = head;
    int i = 0;
    while (currentNode != NULL) 
    {
        i++;
        printf("Node %d holds value : %d\n", i, currentNode->value);
        currentNode = currentNode->next;
    }
}

void freeLinkedListMem(Node* head)
{
    Node* tmp;
    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main () 
{
    int a[5] = {1, 4, 7, 10, 13};
    int b[5] = {2, 5, 8, 11, 14};
    int c[11] = {17, 20, 23, 26, 29, 32, 35, 38, 41, 44, 47};

    Node* loopListHead = newNode(0, NULL);
    loopListHead = bulkInsertEnd(a, sizeof(a)/sizeof(*a), loopListHead);
    Node* recListHead = newNode(-1, NULL);
    recListHead = recursiveBulkInsertEnd(b, sizeof(b)/sizeof(*b), recListHead, recListHead);
    Node* l1 = loopListHead;
    Node* l2 = recListHead;

    Node* mergedList = mergeTwoLists(loopListHead, recListHead);
    printLinkedList(mergedList);
    freeLinkedListMem(mergedList);

    return 0;
}