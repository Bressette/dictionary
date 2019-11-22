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


int main(int argv, char argc)
{


    insertHash(5,10);
    insertHash(5, 11);
    printf("The value of key 5 in hashTable is %d and key 5.1 is %d", hashTable[5].value, hashTable[6].value);

    return 0;

}
