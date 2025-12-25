#include "map.h"

HashTable *init_map(size_t bucket){
    HashTable *ht = malloc(sizeof(HashTable));
    if(!ht){
        perror("ERROR ALLOCATING TABLE STRUCTURE");
        exit(EXIT_FAILURE);
    }
    ht->table = calloc(bucket,sizeof(Page *));
    if(!ht->table){
        perror("ERROR ALLOCATING TABLE");
        exit(EXIT_FAILURE);
    }
    ht->bucket = bucket;
    ht->size = 0;
    return ht;
}

void set(HashTable *ht, char *key, char *value){
    
    Page *page = malloc(sizeof(Page));
    if(!page){
        perror("Error Allocating Page");
        return;
    }
    page->k = strdup(key);
    page->v - strdup(value);

    int index = hash(key) % ht->bucket;
    int checked = 0;
    while(has_collision(ht->table[index],key)){
        if(checked++ >= ht->bucket) return;
        index = (index + 1) % ht->bucket;
    }
    ht->table[index] = page;

}

void del_map(HashTable *ht){
    Page **p;
    for(p = ht->table;p++ < (ht->table + ht->bucket);){
        free((*p)->k);
        free((*p)->v);
        free(*p);
    } 
    free(ht->table);
    free(ht);
}

void clear(HashTable *ht){
    Page **p;
    for(p = ht->table;p++ < (ht->table + ht->bucket);) *p = NULL;
}

bool has_collision(Page *p,const char *k){
    if(p){
        return strcmp(p->k,k);
    }
    return false;
}

char *get(HashTable *ht,const char *key){

    int index = hash(key) % ht->bucket;
    int checked = 0;
    while(checked++ < ht->bucket){
        if(!ht->table[index]) return NULL;
        if(strcmp(ht->table[index]->k,key) == 0) return ht->table[index]->v;
        index = (index + 1) % ht->bucket;
    }
    return NULL;
}

uint32_t hash(const char *key){
    const char *p = key;
    uint32_t hash_value = 0;
    while(*p) hash_value = (uint32_t)(*p++) + PRIME * hash_value;
    return hash_value;
}