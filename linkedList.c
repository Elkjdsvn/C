#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node* newLinkedListNode(int value, Node* next)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = next;
    return newNode;
}

Node* loopLinkedList(int arr[], int arrLength)
{
    Node* head = newLinkedListNode(arr[0], NULL);
    Node* actualNode = head;

    for (int i = 1; i < arrLength; i++)
    {
        actualNode->next = newLinkedListNode(arr[i], NULL);
        actualNode = actualNode->next;
    }

    return head;
}

Node* recursiveLinkedList(int arr[], int arrLength)
{
    if (0 == arrLength)
    {
        return NULL;
    }

    return newLinkedListNode(*arr, recursiveLinkedList(arr+1, arrLength-1));
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
    Node* recListHead = recursiveLinkedList(b, sizeof(b)/sizeof(b[0]));
    printLinkedList(loopListHead);
    freeLinkedListMem(loopListHead);
    printLinkedList(recListHead);
    freeLinkedListMem(recListHead);
    // system("pause");

    return 0;
}