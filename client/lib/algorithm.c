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