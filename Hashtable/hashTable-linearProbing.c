/**
 * Implementation of hashtable with linear probing.
 * Base methods at @link{https://github.com/jwasham/coding-interview-university#data-structures}
 * Functions:
 * - hash (k, m)
 * - add (key, value)
 * - exists(key)
 * - get(key)
 * - remove(key)
 * 
 * For data hashing, the algorithm will be simple:
 * 1. sum all ASCII values of a string
 * 2. hash function by division
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct hashtable_str{
    int (*hash)(char *input);
    void (*add)(struct hashtable_str *hashtable, char *value);
    int (*exists)(struct hashtable_str *hashtable, char *input);
    void (*get)(struct hashtable_str *hashtable);
    /* void (*remove)(hashtable_str hashtable, int key); */

    char *strings[50];
} hashtable_str;

int sumAsciiValuesFromString(char *string){
    int sum = 0;
    int length = strlen(string);

    if(length < 0){
        printf("LengthInvalidException\n");
        return -1;
    }

    //Read letters
    for (size_t j = 0; j < length; j++)
    {
        sum += (int)string[j];
    }
    return sum;
}

/**
 * Generates a hash by using the sum of ASCII characters. The table size is 25
 * 
 * Does not handle collisions whatsoever
 * @return index of table
*/
int hashFunction(char *input){
    int size = 25;

    int sum = sumAsciiValuesFromString(input);
    if(sum == -1){
        printf("[HashFunction] Unknow Error!");
    }
    return sum % size;
}

int hashtable_str_exists(hashtable_str *hashtable, char *input){
    int key = hashFunction(input);
    if(!(hashtable->strings[key] == NULL)){
        return 1;
    }
    
    return 0;
}

/**
 * Overwrites data on a specific key.
 * 
 * If you want to hash a value, use hashFunction instead.
*/
void hashtable_str_add(hashtable_str *hashtable, char *value){
    /* int newKey = key; */
    int newKey = hashFunction(value);

    if(hashtable->exists(hashtable, value) == 0){
        hashtable->strings[newKey] = malloc(sizeof(char)*strlen(value));
        strcpy(hashtable->strings[newKey], value);
    }
    else{
        while(hashtable->exists(hashtable, value)){
            newKey += 1;
        }

        //if all go right
        hashtable->strings[newKey] = malloc(sizeof(char)*strlen(value));
        strcpy(hashtable->strings[newKey], value);
    }
}


hashtable_str *newHastable_str(){
    hashtable_str *hashtable = malloc(sizeof(hashtable_str));

    *hashtable = (hashtable_str){
        .exists = hashtable_str_exists,
        .add = hashtable_str_add,
        .hash = hashFunction,
    };
    
    
    return hashtable;
}

char *hasthable_str_get(hashtable_str *hashtable, int hash){
    return hashtable->strings[hash];
}

void hasthable_str_remove(hashtable_str *hashtable, int hash){
    free(hashtable->strings[hash]);
}

void destructHastable_str(hashtable_str *ptrHastTable_str){
    free(ptrHastTable_str);
}

int main(int argc, char const *argv[])
{

    int HASHTABLE_SIZE = 25;
    char myText[] = {"abcoijjid"};
    
    //Keys
    //1, 5, 234, 15436, 1337, 7, 10, 2

    hashtable_str *myHash = newHastable_str();
    int keyIdx = myHash->hash(myText);
    printf("idx: [%d]\n", keyIdx);
    hashtable_str_add(myHash, myText);

    printf("String in idx %d exists? %d\n", keyIdx, hashtable_str_exists(myHash, myText));
    printf("String in idx %d: %s\n", keyIdx, myHash->strings[keyIdx]);

    printf("String in idx 10 exists? %d\n", hashtable_str_exists(myHash, "aa"));
    printf("String in idx 19: %s\n", myHash->strings[19]);
    printf("String gotten from hash %d is: %s\n", keyIdx, hasthable_str_get(myHash, keyIdx)); //expects abcoijjid
    printf("Killing text created\n");
    hasthable_str_remove(myHash, 2);
    printf("String gotten from hash %d is: %s\n", keyIdx, hasthable_str_get(myHash, keyIdx)); //expects nothing
    
    
    destructHastable_str(myHash);    
    return 0;
}