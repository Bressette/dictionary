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

    if(hashTable[hashVal] == NULL)
    {
        hashTable[hashVal] = newNode;
    }

    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void deleteValue(int key)
{
    int hashVal = key % size;

    node *temp, *prev;



}
void printDict()
{
    for(int i = 0; i < size; i++)
    {
        node *temp = hashTable[i];
        while(hashTable[i] != NULL)
        {
            printf("Index: %d Key: %d Value: %d\n", i, temp->key, temp->value);
            temp = temp->next;
        }
    }

}


int main()
{
    insertElement(2, 5);
    insertElement(2, 9);
    insertElement(3, 6);
    printDict();

    return 0;
}
