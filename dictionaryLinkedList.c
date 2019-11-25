#include "stdlib.h"
#include "stdio.h"

#define size 20


typedef struct linkedList
{
    int key;
    int value;
    struct linkedList *next;
}node;

node *hashTable[size];

void insertElement(int key, int value)
{
    int hashVal = key % size;

    node *newNode = malloc(sizeof(node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    node *temp = hashTable[hashVal];

    if(hashTable[size] == NULL)
    {
        hashTable[hashVal] = newNode;
    }

    else
    {
        while(temp != NULL)
        {
            temp = temp->next;
        }

        temp = newNode;
    }
}


int main()
{
    insertElement(2, 5);
    insertElement(3, 6);
    printf("The first key is %d", hashTable[3]->value);

    return 0;
}
