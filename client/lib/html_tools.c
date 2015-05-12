#include "qli.h"

#define MAX_TAG_SIZE 20
enum HtmlTag{
	HTML_TAG_NONE,
	
	HTML_TAG_UNKNOWN,
	
	HTML_TAG_COMMENT,
	HTML_TAG_DOCTYPE,
	
	HTML_TAG_A,
	HTML_TAG_ABBR,
	HTML_TAG_ACRONYM,
	HTML_TAG_ADDRESS,
	HTML_TAG_APPLET,
	HTML_TAG_AREA,
	
	HTML_TAG_B,
	HTML_TAG_BASE,
	HTML_TAG_BASEFONT,
	HTML_TAG_BDO,
	HTML_TAG_BIG,
	HTML_TAG_BLOCKQUOTE,
	HTML_TAG_BODY,
	HTML_TAG_BR,
	HTML_TAG_BUTTON,
	
	HTML_TAG_CAPTION,
	HTML_TAG_CENTER,
	HTML_TAG_CITE,
	HTML_TAG_CODE,
	HTML_TAG_COL,
	HTML_TAG_COLGROUP,
	HTML_TAG_DD,
	HTML_TAG_DEL,
	
	HTML_TAG_DFN,
	HTML_TAG_DIR,
	HTML_TAG_DIV,
	HTML_TAG_DL,
	HTML_TAG_DT,
	
	HTML_TAG_EM,
	HTML_TAG_FIELDSET,
	HTML_TAG_FONT,
	HTML_TAG_FORM,
	HTML_TAG_FRAME,
	HTML_TAG_FRAMESET,
	
	HTML_TAG_H1,
	HTML_TAG_H2,
	HTML_TAG_H3,
	HTML_TAG_H4,
	HTML_TAG_H5,
	HTML_TAG_H6,
	HTML_TAG_HEAD,
	HTML_TAG_HR,
	HTML_TAG_HTML,
	
	HTML_TAG_I,
	HTML_TAG_IFRAME,
	HTML_TAG_IMG,
	HTML_TAG_INPUT,
	HTML_TAG_INS,
	
	HTML_TAG_KBD,
	
	HTML_TAG_LABEL,
	HTML_TAG_LEGEND,
	HTML_TAG_LI,
	HTML_TAG_LINK,
	
	HTML_TAG_MAP,
	HTML_TAG_MENU,
	HTML_TAG_META,
	
	HTML_TAG_NOFRAMES,
	HTML_TAG_NOSCRIPT,
	
	HTML_TAG_OBJECT,
	HTML_TAG_OL,
	HTML_TAG_OPTGROUP,
	HTML_TAG_OPTION,
	
	HTML_TAG_P,
	HTML_TAG_PARAM,
	HTML_TAG_PRE,
	
	HTML_TAG_Q,
	
	HTML_TAG_S,
	HTML_TAG_SAMP,
	HTML_TAG_SCRIPT,
	HTML_TAG_SELECT,
	HTML_TAG_SMALL,
	HTML_TAG_SPAN,
	HTML_TAG_STRIKE,
	HTML_TAG_STRONG,
	HTML_TAG_STYLE,
	HTML_TAG_SUB,
	HTML_TAG_SUP,
	
	HTML_TAG_TABLE,
	HTML_TAG_TBODY,
	HTML_TAG_TD,
	HTML_TAG_TEXTAREA,
	HTML_TAG_TFOOT,
	HTML_TAG_TH,
	HTML_TAG_THEAD,
	HTML_TAG_TITLE,
	HTML_TAG_TR,
	HTML_TAG_TT,
	
	HTML_TAG_U,
	HTML_TAG_UL,
	
	HTML_TAG_VAR,
	
	HTML_TAGS,
};

const char *html_tag[HTML_TAGS] = {
	[HTML_TAG_NONE] = "",
	
	[HTML_TAG_UNKNOWN] = "",
	
	[HTML_TAG_COMMENT] = "!--",
	[HTML_TAG_DOCTYPE] = "!doctype",
	
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


struct html{
    enum HtmlTag type;
    struct html *parent;
    struct DLlist *child;
    void (*before)(struct html *);
    void (*after)(struct html *);
    void (*dothis)(struct html *);
    void *data;
};

struct tab{
    struct DLlist *root;
    FILE * file;
};

struct link{
    struct html *item;
};

void
before_default(struct html *cur){
    if(NULL == cur || NULL == cur->parent) return;
    before_default(cur->parent);
    fputc('\t', stdout);
}

void
after_default(struct html *cur){
    if(NULL == cur) return;
    fputc('\n', stdout);
}

void
dothis_default(struct html *cur){
    if(NULL == cur) return;
    printf("%s", html_tag[cur->type]);
}

void
dothis_print_data(struct html *cur){
    if(NULL == cur || NULL == cur->data) return;
    printf("%s", (char *)cur->data);
}

struct DLlist *
parse_html(const struct html *parent, struct DLlist *list, FILE *file);

struct html *
new_tag_simple(enum HtmlTag type, const struct html *parent, void *data){
    struct html *h = Calloc(1, sizeof(struct html));
    h->type = type;
    h->parent = parent;
    h->before = before_default;
    h->dothis = dothis_default;
    h->after = after_default;
    return h;
}

struct html *
new_tag_complex(enum HtmlTag type, const struct html *parent, const struct DLlist *child, void *data, void *before, void *after, void *dothis){
    struct html *h = Calloc(1, sizeof(struct html));
    h->type = type;
    h->parent = parent;
    h->child = child;
    h->data = data;
    h->before = before;
    h->after = after;
    h->dothis = dothis;
    return h;
}

enum HtmlTag
jurge_entity(FILE *file){
    int i, c;
    static char buf[MAX_TAG_SIZE+1];
    for(i = 0; i < MAX_TAG_SIZE; ++i){
        if(EOF != (c = fgetc(file))){
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

#define PARSE_SUCCESS 0
#define PARSE_FAIL 1
#define PARSE_COMPLETE 2

int
parse_attribute(struct html *tag, FILE *file){
    int c;
    char *str;
    while(EOF != (c = fgetc(file))){
        if(isspace(c)) continue;
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

int
parse_tail(const struct html *tag, FILE *file){
    int i, c;
    c = fgetc(file);
    if('>' == c){
        // FIXME 我决定先放宽限制，因为我不清楚有哪些标签是可以用 '/>'结尾的
        return PARSE_COMPLETE;
    }else{
        for(i = 0; i < strlen(html_tag[tag->type]); ++i){
            if(html_tag[tag->type][i] != c){
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

// FIXME
int
do_tag(struct DLlist *list, FILE *file){
    int res;
    struct html *tag = getdata(list);
    if(PARSE_SUCCESS != (res = parse_attribute(tag, file))){
        return res;
    }
    tag->child = parse_html(tag, tag->child, file);
    return parse_tail(tag, file);
}

void
do_ignore(FILE *file){
    int c;
    while(EOF != (c = fgetc(file))){
        if('>' == c) break;
    }
}

struct DLlist *
parse_html(const struct html *parent, struct DLlist *list, FILE *file){
    int c;
    struct html *tag;
    while(EOF != (c = fgetc(file))){
        if(isspace(c)) continue;
        if('<' == c){
            c = fgetc(file);
            // FIXME 当注释中含有 '>' 时会有点问题
            if('!' == c){
                do_ignore(file);
                continue;
            }else if('/' == c){
                return list;
            }else{
                enum HtmlTag type;
                ungetc(c, file);
                type = jurge_entity(file);
                if(HTML_TAG_UNKNOWN == type){
                    do_ignore(file);
                    continue;
                }else if(HTML_TAG_IMG == type || HTML_TAG_A == type){
                    tag = new_tag_complex(type, parent, NULL, NULL,
                        before_default, after_default, dothis_print_data);
                }else{
                    tag = new_tag_simple(type, parent, NULL);
                }
                list = insert(list, tag);
                do_tag(list, file);
            }
        }else{
            ungetc(c, file);
            tag = new_tag_complex(HTML_TAG_NONE, parent, NULL, copy_end_with(file, '<'),
                before_default, after_default, dothis_print_data);
            list = insert(list, tag);
        }
    }
    return list;
}

void
display_html(const struct DLlist *root){
    if(NULL == root) return;
    struct html *h;
    struct DLlist *temp = root;
    do{
        temp = temp->next;
        h = getdata(temp);

        h->before(h);
        h->dothis(h);
        h->after(h);

        display_html(h->child);
    }while(temp != root);
}

void
distroy_html(struct DLlist *root){
    if(NULL == root) return;
    struct html *h;
    do{
        h = getdata(root);
        distroy_html(h->child);
        free(h->data);
        free(h);
        root = delete(root);
    }while(NULL != root);
}


struct tab*
init_tab(FILE *file){
    struct DLlist *root;
    struct tab *cur_tab = NULL;
    if(NULL != file){
        rewind(file);
        if(NULL != (root = parse_html(NULL, NULL, file))){
            cur_tab = Calloc(1, sizeof(struct tab));
            cur_tab->root = root;
        }else{
            distroy_html(cur_tab->root);
        }
    }
    return cur_tab;
}

void
display_tab(const struct tab *tab){
    display_html(tab->root);
}

void
distroy_tab(struct tab *tab){
    distroy_html(tab->root);
    free(tab);
}