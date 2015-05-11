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
    int type;
    struct DLlist *parent;
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

struct DLlist *
parse_html(const struct html *parent, struct DLlist *list, FILE *file);

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

// FIXME
struct html *
do_html(struct DLlist *list, FILE *file){
    int i, c;
    struct html *h = list->data;
    while(EOF != (c = fgetc(file))){
        // TODO 解析属性
        if('/' == c){
            switch(h->type){
                case HTML_TAG_BR:
                case HTML_TAG_IMG:
                    goto tail;
            }
        }
        if('>' == c) break;
    }
    parse_html(h, h->child, file);
tail:
    c = fgetc(file);
    if('>' == c){
        switch(h->type){
            case HTML_TAG_BR:
            case HTML_TAG_IMG:
                return h;
        }
    }else{
        for(i = 0; i < strlen(html_tag[h->type]); ++i){
            if(html_tag[h->type][i] != c){
                goto error;
            }
            c = fgetc(file);
        }
        if('>' != c){
            goto error;
        }
        return h;
    }

error:
    return NULL;
}

void
do_unknown(FILE *file){
    int c;
    while(EOF != (c = fgetc(file))){
        if('>' == c) break;
    }
}

struct DLlist *
parse_html(const struct html *parent, struct DLlist *list, FILE *file){
    int c;
    struct html *cur = Calloc(1, sizeof(struct html));
    list = insert(list, cur);
    cur->parent = parent;
    while(EOF != (c = fgetc(file))){
        if(isspace(c)) continue;
        if('<' == c){
            c = fgetc(file);
            // FIXME 当注释中含有 '>' 时会有点问题
            if('!' == c){
                do_unknown(file);
            }else if('/' == c){
                return list;
            }else{
                int type;
                ungetc(c, file);
                type = jurge_entity(file);
                if(HTML_TAG_UNKNOWN == type){
                    do_unknown(file);
                }else{
                    cur->type = type;
                    do_html(list, file);
                }
            }
        }
    }
    return list;
}

void
display_html(const struct DLlist *root){
}

void
distroy_html(struct DLlist *root){
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
