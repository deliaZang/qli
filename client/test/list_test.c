#include "qli.h"

int chs[] = {1, 2, 3, 4, 5};
int main(void){
    int i;
    struct DLlist *list = NULL;
    for(i = 0; i < 5; ++i){
        list = DLlist_insert(list, chs[i]);
    }
    for(i = 0; i < 5; ++i){
        list = DLlist_delete(list);
    }
    return 0;
}