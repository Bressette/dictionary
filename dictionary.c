#include "stdio.h"
#include "stdlib.h"
#include "time.h"

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

void fillDictionary()
{
    int key = 0;
    int value = 0;

    for(int i = 0; i < size; i++)
    {
        key = rand() % 20 + 1;
        value = rand() % 100 + 1;
        insertHash(key, value);
    }
}


int main(int argv, char argc)
{
    srand(time(0));

    fillDictionary();

    printHash();

    return 0;

}
