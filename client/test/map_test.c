#include "qli.h"

const char *key[] = {"1", "2", "3", "4"};
const char *value[]={"one", "two", "three", "fore"};

int main(void){
    int i;
    struct Map *map = NULL;
    for(i = 0; i < 4; ++i){
        map = Map_add(map, key[i], value[i]);
    }

    for(i = 0; i < 4; ++i){
        printf("key: %s, value: %s\n", key[i], Map_get(map, key[i]));
    }

    return 0;
}