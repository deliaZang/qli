#include <setjmp.h>
#include "qli.h"

#define MAX_TAG_SIZE 20

const char *html_tag[HTML_TAGS] = {
	[HTML_TAG_NONE] = "",
	
	[HTML_TAG_UNKNOWN] = "",
	
	[HTML_TAG_COMMENT] = "!--",
	[HTML_TAG_DOCTYPE] = "!DOCTYPE",
	
	[HTML_TAG_A] = "a",
	[HTML_TAG_ABBR] = "abbr",
	[HTML_TAG_ACRONYM] = "acronym",
	[HTML_TAG_ADDRESS] = "address",
	[HTML_TAG_APPLET] = "applet",
	[HTML_TAG_AREA] = "area",
	
	[HTML_TAG_B] = "b",
	[HTML_TAG_BASE] = "base",
	[HTML_TAG_BASEFONT] = "basefont",
	[HTML_TAG_BDO] = "bdo",
	[HTML_TAG_BIG] = "big",
	[HTML_TAG_BLOCKQUOTE] = "blockquote",
	[HTML_TAG_BODY] = "body",
	[HTML_TAG_BR] = "br",
	[HTML_TAG_BUTTON] = "button",
	
	[HTML_TAG_CAPTION] = "caption",
	[HTML_TAG_CENTER] = "center",
	[HTML_TAG_CITE] = "cite",
	[HTML_TAG_CODE] = "code",
	[HTML_TAG_COL] = "col",
	[HTML_TAG_COLGROUP] = "colgroup",
	[HTML_TAG_DD] = "dd",
	[HTML_TAG_DEL] = "del",
	
	[HTML_TAG_DFN] = "dfn",
	[HTML_TAG_DIR] = "dir",
	[HTML_TAG_DIV] = "div",
	[HTML_TAG_DL] = "dl",
	[HTML_TAG_DT] = "dt",
	
	[HTML_TAG_EM] = "em",
	[HTML_TAG_FIELDSET] = "fieldset",
	[HTML_TAG_FONT] = "font",
	[HTML_TAG_FORM] = "form",
	[HTML_TAG_FRAME] = "frame",
	[HTML_TAG_FRAMESET] = "frameset",
	
	[HTML_TAG_H1] = "h1",
	[HTML_TAG_H2] = "h2",
	[HTML_TAG_H3] = "h3",
	[HTML_TAG_H4] = "h4",
	[HTML_TAG_H5] = "h5",
	[HTML_TAG_H6] = "h6",
	[HTML_TAG_HEAD] = "head",
	[HTML_TAG_HR] = "hr",
	[HTML_TAG_HTML] = "html",
	
	[HTML_TAG_I] = "i",
	[HTML_TAG_IFRAME] = "iframe",
	[HTML_TAG_IMG] = "img",
	[HTML_TAG_INPUT] = "input",
	[HTML_TAG_INS] = "ins",
	
	[HTML_TAG_KBD] = "kbd",
	
	[HTML_TAG_LABEL] = "label",
	[HTML_TAG_LEGEND] = "legend",
	[HTML_TAG_LI] = "li",
	[HTML_TAG_LINK] = "link",
	
	[HTML_TAG_MAP] = "map",
	[HTML_TAG_MENU] = "menu",
	[HTML_TAG_META] = "meta",
	
	[HTML_TAG_NOFRAMES] = "noframes",
	[HTML_TAG_NOSCRIPT] = "noscript",
	
	[HTML_TAG_OBJECT] = "object",
	[HTML_TAG_OL] = "ol",
	[HTML_TAG_OPTGROUP] = "optgroup",
	[HTML_TAG_OPTION] = "option",
	
	[HTML_TAG_P] = "p",
	[HTML_TAG_PARAM] = "param",
	[HTML_TAG_PRE] = "pre",
	
	[HTML_TAG_Q] = "q",
	
	[HTML_TAG_S] = "s",
	[HTML_TAG_SAMP] = "samp",
	[HTML_TAG_SCRIPT] = "script",
	[HTML_TAG_SELECT] = "select",
	[HTML_TAG_SMALL] = "small",
	[HTML_TAG_SPAN] = "span",
	[HTML_TAG_STRIKE] = "strike",
	[HTML_TAG_STRONG] = "strong",
	[HTML_TAG_STYLE] = "style",
	[HTML_TAG_SUB] = "sub",
	[HTML_TAG_SUP] = "sup",
	
	[HTML_TAG_TABLE] = "table",
	[HTML_TAG_TBODY] = "tbody",
	[HTML_TAG_TD] = "td",
	[HTML_TAG_TEXTAREA] = "textarea",
	[HTML_TAG_TFOOT] = "tfoot",
	[HTML_TAG_TH] = "th",
	[HTML_TAG_THEAD] = "thead",
	[HTML_TAG_TITLE] = "title",
	[HTML_TAG_TR] = "tr",
	[HTML_TAG_TT] = "tt",
	
	[HTML_TAG_U] = "u",
	[HTML_TAG_UL] = "ul",
	
	[HTML_TAG_VAR] = "var",
};

#define PARSE_SUCCESS 0
#define PARSE_FAIL 1
#define PARSE_COMPLETE 2

struct tab *cur_tab = NULL;
jmp_buf jmp_init_tab;

static void
parse_html(const struct html *parent, struct DLlist **list, FILE *file);

static struct html *
new_tag(enum HtmlTag type, struct html *parent, void *data){
    struct html *h = Calloc(1, sizeof(struct html));
    h->type = type;
    h->parent = parent;
    h->data = data;
    return h;
}

static enum HtmlTag
jurge_entity(FILE *file){
    int i, c;
    static char buf[MAX_TAG_SIZE+1];
    for(i = 0; i < MAX_TAG_SIZE; ++i){
        c = fgetc(file);
        if(feof(file)){
            longjmp(jmp_init_tab, 1);
        }
        switch(c){
            case '>':
                ungetc(c, file);
            case ' ':
                buf[i] = 0;
                goto next;
            default:
                buf[i] = c;
        }
    }
next:
    if(MAX_TAG_SIZE == i){
        buf[MAX_TAG_SIZE] = 0;
    }
    for(i = 0; i < HTML_TAGS; ++i){
        if(0 == strcmp(html_tag[i], buf)){
            return i;
        }
    }
    return HTML_TAG_UNKNOWN;
}

static int
parse_attribute(struct html *tag, FILE *file){
    int c;
    char *str;
    while(1){
        c = fgetc(file);
        if(isspace(c)) continue;
        if(feof(file)){
            longjmp(jmp_init_tab, 1);
        }
        if('/' == c){
            if('>' == fgetc(file)){
                return PARSE_COMPLETE;
            }
            return PARSE_FAIL;
        }
        if('>' == c) return PARSE_SUCCESS;
        // FIXME
        if(HTML_TAG_IMG == tag->type || HTML_TAG_A == tag->type){
            char * attribute = (HTML_TAG_IMG == tag->type) ? "src" : "href";
            ungetc(c, file);
            str = copy_end_with(file, '=');
            if(0 != strcmp(str, attribute)){
                free(str);
                str = copy_end_with(file, ' ');
                free(str);
                continue;
            }
            fgetc(file), c = fgetc(file);
            if('\'' != c && '\"' != c){
                ungetc(c, file);
                c = ' ';
            }
            free(str);
            str = copy_end_with(file, c);
            fgetc(file);
            tag->data = str;
        }
    }
    return PARSE_FAIL;
}

static int
parse_tail(const struct html *tag, FILE *file){
    int i, c;
    c = fgetc(file);
    if('>' == c){
        // FIXME 我决定先放宽限制，因为我不清楚有哪些标签是可以用 '/>'结尾的
        return PARSE_COMPLETE;
    }else{
        for(i = 0; i < strlen(html_tag[tag->type]); ++i){
            if(feof(file)){
                longjmp(jmp_init_tab, 1);
            }
            if(html_tag[tag->type][i] != c){
                while(!feof(file) && '>' != fgetc(file));
                return PARSE_FAIL;
            }
            c = fgetc(file);
        }
        if('>' != c){
            return PARSE_FAIL;
        }
        return PARSE_COMPLETE;
    }
}

static int
do_tag(struct DLlist *list, FILE *file){
    int res;
    struct html *tag = DLlist_getdata(list);
    if(PARSE_SUCCESS != (res = parse_attribute(tag, file))){
        return res;
    }
again:
    parse_html(tag, &(tag->child), file);
    // FIXME 进一步提高容错，若是父标签的结尾则返回，否则继续
    if(PARSE_FAIL == parse_tail(tag, file)){
        goto again;
    }
    return PARSE_COMPLETE;
}

static void
do_ignore(FILE *file){
    int c;
    while(1){
        c = fgetc(file);
        if(feof(file)){
            longjmp(jmp_init_tab, 1);
        }
        if('>' == c) break;
    }
}

static void
parse_html(const struct html *parent, struct DLlist **list, FILE *file){
    int c;
    struct html *tag = NULL;
    while(1){
        c = fgetc(file);
        if(isspace(c)) continue;
        if(feof(file)){
            longjmp(jmp_init_tab, 1);
        }
        if('<' != c){
            ungetc(c, file);
            char *str = copy_end_with(file, '<');
            if(NULL == str){
                str = copy_to_eof(file);
            }
            tag = new_tag(HTML_TAG_NONE, parent, str);
            *list = DLlist_insert(*list, tag);
        }else{
            c = fgetc(file);
            if('/' == c){
                return;
            }else{
                ungetc(c, file);
                enum HtmlTag type = jurge_entity(file);
                int len;
                char *end;
                switch(type){
                    case HTML_TAG_DOCTYPE:
                    case HTML_TAG_UNKNOWN:
                        do_ignore(file);
                        break;
                    case HTML_TAG_HEAD:
                    case HTML_TAG_SCRIPT:
                        len = strlen(html_tag[type])+4;
                        *end = Calloc(len, sizeof(char));
                        snprintf(end, len, "</%s>", html_tag[type]);
                        file_over(file, end);
                        free(end);
                    case HTML_TAG_COMMENT:
                        file_over(file, "-->");
                        break;
                    default:
                        tag = new_tag(type, parent, NULL);
                        *list = DLlist_insert(*list, tag);
                        do_tag(*list, file);
                }
            }
        }
    }
}

static void
distroy_html(struct DLlist *root){
    if(NULL == root) return;
    struct html *h;
    do{
        h = DLlist_getdata(root);
        distroy_html(h->child);
        free(h->data);
        free(h);
        root = DLlist_delete(root);
    }while(NULL != root);
}

struct tab*
init_tab(FILE *file){
    struct DLlist *root;
    cur_tab = Calloc(1, sizeof(struct tab));
    if(NULL != file){
        if(0 == setjmp(jmp_init_tab)){
            rewind(file);
            parse_html(NULL, &(cur_tab->root), file);
        }
    }
    return cur_tab;
}

void
distroy_tab(struct tab *tab){
    distroy_html(tab->root);
    free(tab);
}