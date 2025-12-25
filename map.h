#ifndef MAP_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAP_H
#define PRIME 2654435761

typedef struct {
    char *k;
    char *v;
} Page;

typedef struct {
    size_t bucket;
    size_t size;
    Page **table;
} HashTable;

HashTable *init_map(size_t bucket);

void set(HashTable *ht, char *key,  char *value);
void del_map(HashTable *ht);
void clear(HashTable *ht);

char *get(HashTable *ht,const char *key);
uint32_t hash(const char *key);
bool has_collision(Page *p, const char *k);
#endif