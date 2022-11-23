#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node* newLinkedListNode(int value) 
{
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Node* loopLinkedList(int arr[], int arrLength)
{
    Node* head = newLinkedListNode(arr[0]);
    Node* actualNode = head;
    int i;

    for (i = 1; i < arrLength; i++)
    {
        actualNode->next = newLinkedListNode(arr[i]);
        actualNode = actualNode->next;
    }

    return head;
}

Node* recursiveLinkedList(int arr[], int acc, Node* head, Node* actualNode)
{
    if (acc == 4)
    {
        return head;
    }

    if (head == NULL) 
    {
        head = newLinkedListNode(arr[0]);
        actualNode = head;
    }
    actualNode->next = newLinkedListNode(arr[acc+1]);
    actualNode = actualNode->next;

    return recursiveLinkedList(arr, acc+1, head, actualNode);
}

// could be refactored as a for loop
void printLinkedList(Node* head)
{
    Node* actualNode = head;
    int i = 0;
    while (actualNode != NULL) 
    {
        i++;
        printf("Node %d holds value : %d\n", i, actualNode->value);
        actualNode = actualNode->next;
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
    Node* loopListHead = loopLinkedList(a, sizeof(a)/sizeof(a[0]));
    Node* recListHead = recursiveLinkedList(b, 0, NULL, NULL);
    printLinkedList(loopListHead);
    freeLinkedListMem(loopListHead);    
    printLinkedList(recListHead);
    freeLinkedListMem(recListHead);
}