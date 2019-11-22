#include "stdio.h"
#include "stdlib.h"

#define size 20

struct hash
{
    int key;
    int value;
};

struct hash hashTable[size];

int hashCode(int key)
{
    return key % size;
}

void insertHash(int key, int value)
{
    int hashVal = hashCode(key);


    for(int i = hashVal; i < size; i++)
    {
        if(hashTable[i].key != NULL)
            continue;

        hashTable[i].key = key;
        hashTable[i].value = value;
        return;
    }

}

void deleteHash(int key)
{
    int hashVal = hashCode(key);

    for(int i = hashVal; i < size; i++)
    {
        if(hashTable[hashVal].key == key)
        {
            hashTable[hashVal].key = NULL;
            hashTable[hashVal].value = NULL;
        }
    }
}

void printHash()
{
    for(int i = 0; i < size; i++)
    {
        if(hashTable[i].key != NULL)
        {
            printf("%d: %d\n", hashTable[i].key, hashTable[i].value);
        }
    }
}


int main(int argv, char argc)
{


    insertHash(5,10);
    insertHash(5, 11);
    printf("The value of key 5 in hashTable is %d and key 5.1 is %d\n", hashTable[5].value, hashTable[6].value);
    printHash();
    deleteHash(5);
    printHash();

    return 0;

}
