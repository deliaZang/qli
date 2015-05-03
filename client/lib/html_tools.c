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
    struct html *prev;
    struct html *next;
    struct html *parent;
    struct html *child;
    void (*before)(struct html *);
    void (*after)(struct html *);
    void (*dothis)(struct html *);
    void *data;
};

struct tab{
    struct tab *prev;
    struct tab *next;
    struct html *root;
    FILE * file;
};

struct link{
    struct link *prev;
    struct link *next;
    struct html *items;
};


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

struct html *
do_html(struct html **cur, FILE *file){
    int c;
    struct DLlist *html = Calloc(1, sizeof(struct DLlist));
    while(EOF != (c = fgetc(file))){
        if('>' == c) break;
    }
}

void
do_unknown(FILE *file){
    int c;
    while(EOF != (c = fgetc(file))){
        if('>' == c) break;
    }
}

int
parse_html(const struct html *parent, struct html **cur, FILE *file){
    int c;
    *cur = Calloc(1, sizeof(struct html));
    (*cur)->parent = parent;
    while(EOF != (c = fgetc(file))){
        if(isspace(c)) continue;
        if('<' == c){
            c = fgetc(file);
            if('!' == c){
            }else if('/' == c){
            }else{
                ungetc(c, file);
                switch(jurge_entity(file)){
                    case HTML_TAG_HTML:
                        (*cur)->type = HTML_TAG_HTML;
                        do_html(*cur, file);
                        break;
                    case HTML_TAG_HEAD:
                        break;
                    case HTML_TAG_TITLE:
                        break;
                    default:
                        do_unknown(file);
                }
            }
        }
    }
    return 0;
}

void
display_html(const struct html *root){
}

void
distroy_html(struct html *root){
}


struct tab*
init_tab(FILE *file){
    int c;
    struct html *root;
    struct tab *cur_tab = NULL;
    if(NULL != file){
        rewind(file);
        if(0 == parse_html(NULL, &root, file)){
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
