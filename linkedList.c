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

    // printLinkedList(loopListHead);
    // freeLinkedListMem(loopListHead);
    
    recursiveBulkInsertEnd(a, sizeof(a)/sizeof(*a), recListHead, recListHead);
    recursiveBulkInsertEnd(c, sizeof(c)/sizeof(*c), recListHead, recListHead);
    printLinkedList(recListHead);
    freeLinkedListMem(recListHead);

    return 0;
}