/**
 * Implementation of hashtable with linear probing.
 * Base methods at @link{https://github.com/jwasham/coding-interview-university#data-structures}
 * Functions:
 * - hash (k, m)
 * - add (key, value)
 * - exists(key)
 * - get_value(key)
 * - remove_key(key)
 * 
 * For data hashing, the algorithm will be simple:
 * 1. sum all ASCII values of a string
 * 2. hash function by division
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hashentry_str{
    int key;
    char *value;
} hashentry_str;

hashentry_str *create_hashentry_str(int key, char *value){
    hashentry_str *entry = malloc(sizeof(hashentry_str));
    
    *entry = (hashentry_str){
        .key = key,
        .value = value,
    };

    return entry;
}

void destroy_hashentry_str(hashentry_str *entry){
    free(entry);
}


typedef struct hashtable_str{
    int size;
    hashentry_str **entries;

    int (*hash)(char *input);
    void (*add)(struct hashtable_str *hashtable, char *input);
    int (*exists)(struct hashtable_str *hashtable, int key);

    char *(*get_value)(struct hashtable_str *hashtable, int key);
    int (*get_key)(struct hashtable_str *hashtable, char *value);

    void (*remove_key)(struct hashtable_str *hashtable, int key);
    void (*remove_value)(struct hashtable_str *hashtable, char *value);

    void (*transverse)(struct hashtable_str *hashtable);

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
        printf("[HashFunction] Unknow Error!\n");
    }
    return sum % size;
}

int hashtable_str_exists(hashtable_str *hashtable, int key){
    if(hashtable->entries[key]->value != NULL){
        return 1;
    }

    return 0;
}

void hashtable_str_add(hashtable_str *hashtable, char *value){
    int key = hashFunction(value);

    if(hashtable->exists(hashtable, key) == 0){
        hashentry_str *entry = create_hashentry_str(key, value);
        hashtable->entries[key]->key = key;
        hashtable->entries[key]->value = value;
    }
    else{
        while(hashtable->exists(hashtable, key) == 1){
            key += 1;
        }

        //if all go right
        hashentry_str *entry = create_hashentry_str(key, value);
        hashtable->entries[key]->key = key;
        hashtable->entries[key]->value = value;
    }
}

//Get the value from the table
char *hasthable_str_get_value(hashtable_str *hashtable, int key){
    if(hashtable->exists(hashtable, key) == 1){
        return hashtable->entries[key]->value;
    }

    printf("[hash_get] Value does not exist. Not performing\n");
    return NULL;
}


/**
 * Returns the key given a value
 * 
 * @return {int} key or -1 if not exists
*/
int hasthable_str_get_key(hashtable_str *hashtable, char *value){
    int key = hashtable->hash(value);
    int initialKey = key;

    if(hashtable->exists(hashtable, key) == 1){
        if(hashtable->entries[key]->value == value){
            return hashtable->entries[key]->key;
        }
        else{
            while (hashtable->entries[key]->value != value && key < hashtable->size)
            {
                key++;
            }
            //Redundancy
            if(hashtable->entries[key]->value == value){
                return hashtable->entries[key]->key;
            }
        }
        
    }

    printf("[hash_get] Value does not exist. Not performing");
    return -1;
}

/**
 * Removes a key association from the table
 * 
 * If you want to remove a value from table, see @see hashtable_str_remove_value
*/
void hasthable_str_remove_key(hashtable_str *hashtable, int key){
    if(hashtable->exists(hashtable, key) == 1){        
        hashtable->entries[key]->value = NULL;
    }
}

void hasthable_str_remove_value(hashtable_str *hashtable, char *value){
    int key = hashtable->hash(value);

    if(hashtable->exists(hashtable, key) == 1){
        while (hashtable->entries[key]->value != value && key < hashtable->size)
        {
            key++;
        }
        
        //Redundancy
        if(hashtable->entries[key]->value == value){
            hashtable->entries[key]->value = NULL;
        }
    }
}

void hashtable_str_transverse(hashtable_str *hashtable){
    if(!hashtable){
        printf("[hashtable_transverse] No Hastable found");
        return;
    }
    printf("Key\t|\tValue\n");
    for (size_t i = 0; i < hashtable->size; i++)
    {
        printf("%d\t|%s\n", hashtable->entries[i]->key, hashtable->entries[i]->value);
    }
}

hashtable_str *newHastable_str(int size){
    hashtable_str *hashtable = malloc(sizeof(hashtable_str));
    hashentry_str **entries = malloc(sizeof(hashentry_str) * size);
    
    //Initialize all to null
    for (size_t i = 0; i < size; i++)
    {
        //entries[i] = create_hashentry_str(i, NULL);
        entries[i] = create_hashentry_str(i, NULL);
    }
    

    *hashtable = (hashtable_str){
        .size = size,
        .hash = hashFunction,
        .exists = hashtable_str_exists,
        .add = hashtable_str_add,
        .get_value = hasthable_str_get_value,
        .get_key = hasthable_str_get_key,
        .remove_key = hasthable_str_remove_key,
        .remove_value = hasthable_str_remove_value,
        .transverse = hashtable_str_transverse,
        .entries = entries
    };
    
    
    return hashtable;
}


void destructHastable_str(hashtable_str *ptrHastTable_str){
    //All created instances
    for (size_t i = 0; i < ptrHastTable_str->size; i++)
    {
        destroy_hashentry_str(ptrHastTable_str->entries[i]);
    }
    
    free(ptrHastTable_str->entries);
    free(ptrHastTable_str);
}

int main(int argc, char const *argv[])
{

    int HASHTABLE_SIZE = 25;
    char myText[] = {"abcoijjid"};
    char myText2[] = {"ola"};
    char myText3[] = {"alo"};   //Will collide with myText2
    char myText4[] = {"lao"};   //Will collide with myText3
    char myText5[] = {"loa"};   //Will collide with myText4

    hashtable_str *table = newHastable_str(HASHTABLE_SIZE);
    
    table->add(table, myText);

    printf("Exists: %d\n", hashtable_str_exists(table, table->hash(myText2)));  //Value hasn't been added
    table->add(table, myText2);                                                 //Collision found: Expectrs linear probing
    printf("Exists: %d\n", hashtable_str_exists(table, table->hash(myText3)));  //Different key added


    table->add(table, myText3); //collision  
    table->add(table, myText4); //Collision
    table->add(table, myText5); //Collision

    table->transverse(table);

    table->remove_value(table, myText3);
    table->transverse(table);
    
    destructHastable_str(table);    
    return 0;
}