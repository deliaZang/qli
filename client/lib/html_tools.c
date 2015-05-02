#include "qli.h"

#define H_SIMPLE  0
#define H_HTML    1
#define H_HEAD    2
#define H_TITLE   3
#define H_BODY    4
#define H_H       5
#define H_P       6
#define H_PRE     7
#define H_A       8
#define H_IMG     9
#define H_INPUT   10
#define H_BUTTON  11
#define H_VIDEO   12
#define H_CHECKBOX 13
#define H_TABLE   14
#define H_TR      15
#define H_TB      16
#define H_FORM    17

struct html{
    int type;
    struct html *parent;
    struct html *child;
    void (*before)(struct html *);
    void (*after)(struct html *);
    void (*dothis)(struct html *);
    void *data;
};

struct tab{
    struct html *root;
    FILE * file;
};

struct link{
    struct html *entity;
};


struct html *
parse_html(FILE *file){

}

void
display_html(const struct html *root){

}

// TODO
struct tab*
init_tab(FILE *file){
    return NULL;
}

// TODO
void
display_tab(const struct tab *tab){

}