#include "qli.h"

struct DLlist *
DLlist_insert(struct DLlist *cur, void *data){
    struct DLlist *node = Calloc(1, sizeof(struct DLlist));
    node->data = data;
    if(NULL == cur){
        node->prev = node;
        node->next = node;
    }else{
        node->next = cur->next;
        node->prev = cur;
        cur->next->prev = node;
        cur->next = node;
    }
    return node;
}

struct DLlist *
DLlist_delete(struct DLlist *cur){
    if(NULL != cur){
        struct DLlist *prev = cur->prev, *next = cur->next;
        cur->prev->next = next;
        cur->next->prev = prev;
        free(cur);
        if(cur != prev && cur != next){
            return next;
        }
    }
    return NULL;
}

void *
DLlist_getdata(const struct DLlist *cur){
    if(NULL != cur){
        return cur->data;
    }
    return NULL;
}


static struct Map *
new_map(void *key, void *value){
    struct Map *m = Calloc(1, sizeof(struct Map));
    m->key = key;
    m->value = value;
    return m;
}

void *
Map_add(void *map, void *key, void *value){
    struct Map *m = new_map(key, value);
    return DLlist_insert(map, m);
}

void *
Map_get(const void *start, const void *key){
    if(NULL == start || NULL == key) return NULL;
    struct Map *temp = NULL;
    struct DLlist *cur = start;
    do{
        temp = DLlist_getdata(cur);
        if(0 == strcmp(key, temp->key)){
            return temp->value;
        }
        cur = cur->next;
    }while(start != cur);
    return NULL;
}

void
Map_delete(void *map, const void *key){
    if(NULL == map || NULL == key) return;
    struct Map *temp = NULL;
    struct DLlist *cur = map;
    do{
        temp = DLlist_getdata(cur);
        if(0 == strcmp(key, temp->key)){
            DLlist_delete(cur);
            return;
        }
        cur = cur->next;
    }while(map != cur);
}