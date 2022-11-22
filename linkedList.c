#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node newLinkedListNode(int value) 
{
    Node newNode = {.value = value, .next = NULL};
    return newNode;
}

Node* loopLinkedList(int arr[], int arrLength)
{
    Node head = newLinkedListNode(arr[0]);
    Node* actualNode = &head;
    Node* ptrHead = &head;
    int i;

    for (i = 1; i < arrLength; i++)
    {
        actualNode->next = malloc(sizeof(Node));
        actualNode->next->value = arr[i];
        actualNode->next->next = NULL;
        actualNode = actualNode->next;
    }

    // actualNode = &head;

    return ptrHead;
}

// could be refactored as a for loop
void printLinkedList(Node* head)
{
    Node* actualNode = head;

    while (actualNode != NULL) 
    {
        printf("%d\n", actualNode->value);
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

    Node* head = loopLinkedList(a, 5);
    printLinkedList(head);
    freeLinkedListMem(head);


}