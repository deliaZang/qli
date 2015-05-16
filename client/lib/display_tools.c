#include "qli.h"

#define max_row(tab) ((tab)->disp_info.max_row)
#define max_col(tab) ((tab)->disp_info.max_col)
#define win_tab(tab) ((tab)->disp_info.win)
#define MAX_PAGE_LINES 1000

#ifdef _MY_DEBUG
void
before_debug(struct html *cur){
    if(NULL == cur || NULL == cur->parent) return;
    before_debug(cur->parent);
    fputc('\t', stdout);
}

void
after_debug(struct html *cur){
    if(NULL == cur) return;
    fputc('\n', stdout);
}

void
dothis_debug(struct html *cur){
    if(NULL == cur) return;
    printf("%s ", html_tag[cur->type]);
    if(NULL != cur->data){
        printf("%s", (char *)cur->data);
    }
}

void
display_html(const struct DLlist *root){
    if(NULL == root) return;
    struct html *h;
    struct DLlist *temp = root;
    do{
        temp = temp->next;
        h = DLlist_getdata(temp);

        before_debug(h);
        dothis_debug(h);
        after_debug(h);

        display_html(h->child);
    }while(temp != root);
}

void
display_tab(struct tab *tab){
    display_html(tab->root);
}

#else

static void
display_html(const struct DLlist *root){
    if(NULL == root) return;
    struct html *h;
    const struct DLlist *temp = root;
    do{
        temp = temp->next;
        h = DLlist_getdata(temp);
        before(h);
        dothis(h);
        display_html(h->child);
        after(h);
    }while(temp != root);
}

void
display_tab(struct tab *tab){
    initscr();
    cbreak();
    noecho();

    getmaxyx(stdscr, max_row(tab), max_col(tab));
    win_tab(tab) = newpad(MAX_PAGE_LINES, max_col(tab));
    keypad(win_tab(tab), TRUE);

    display_html(tab->root);

    int ch;
    int cur_line = 0;
    move(0, 0);
    refresh();
    clear();
    prefresh(win_tab(tab), cur_line, 0, 0, 0, max_row(tab)-1, max_col(tab)-1);

    while('q' != (ch = wgetch(win_tab(tab)))){
        int y = getcury(win_tab(tab)), x = getcurx(win_tab(tab));
        switch(ch){
            case KEY_DOWN:
                if(y < max_row(tab)-1){
                    ++y;
                }else{
                    ++cur_line;
                }
                break;
            case KEY_UP:
                if(0 == y){
                    --cur_line;
                }else{
                    --y;
                }
                break;
            case KEY_LEFT:
                if(x != 0){
                    --x;
                }
                break;
            case KEY_RIGHT:
                if(x != max_col(tab)-1){
                    ++x;
                }
                break;
            default:
                break;
        }
        move(y, x);
        refresh();
        clear();
        prefresh(win_tab(tab), cur_line, 0, 0, 0, max_row(tab)-1, max_col(tab)-1);
    }

    delwin(win_tab(tab));
    endwin();
}

#endif

static void
before_default(struct html *cur){
}
static void
dothis_default(struct html *cur){
}
static void
after_default(struct html *cur){
}

static void
before_none(struct html *cur){
}
static void
dothis_none(struct html *cur){
    if(NULL == cur || NULL == cur->data) return;
    waddstr(win_tab(cur_tab), (char*)cur->data);
}
static void
after_none(struct html *cur){
}

static void
before_img(struct html *cur){
    wattron(win_tab(cur_tab), A_BOLD);
}
static void
dothis_img(struct html *cur){
    waddstr(win_tab(cur_tab), "[图片]\n");
}
static void
after_img(struct html *cur){
    wattroff(win_tab(cur_tab), A_BOLD);
}

static void
before_a(struct html *cur){
    wattron(win_tab(cur_tab), A_UNDERLINE);
}
static void
dothis_a(struct html *cur){
}
static void
after_a(struct html *cur){
    wattroff(win_tab(cur_tab), A_UNDERLINE);
}

static void
before_br(struct html *cur){
}
static void
dothis_br(struct html *cur){
    waddch(win_tab(cur_tab), '\n');
}
static void
after_br(struct html *cur){
}

static void
before_h(struct html *cur){
    wattron(win_tab(cur_tab), A_BOLD);
}
static void
dothis_h(struct html *cur){
}
static void
after_h(struct html *cur){
    waddch(win_tab(cur_tab), '\n');
    wattroff(win_tab(cur_tab), A_BOLD);
}

#define DEFAULT_FUNCS {(tag_func)before_default, (tag_func)dothis_default, (tag_func)after_default}
#define H_FUNCS {(tag_func)before_h, (tag_func)dothis_h, (tag_func)after_h}

const struct tag_funcs tag_funcs[HTML_TAGS] = {
	[HTML_TAG_NONE] = {(tag_func)before_none, (tag_func)dothis_none, (tag_func)after_none},
	
	[HTML_TAG_UNKNOWN] = DEFAULT_FUNCS,
	
	[HTML_TAG_COMMENT] = DEFAULT_FUNCS,
	[HTML_TAG_DOCTYPE] = DEFAULT_FUNCS,
	
	[HTML_TAG_A] = {(tag_func)before_a, (tag_func)dothis_a, (tag_func)after_a},
	[HTML_TAG_ABBR] = DEFAULT_FUNCS,
	[HTML_TAG_ACRONYM] = DEFAULT_FUNCS,
	[HTML_TAG_ADDRESS] = DEFAULT_FUNCS,
	[HTML_TAG_APPLET] = DEFAULT_FUNCS,
	[HTML_TAG_AREA] = DEFAULT_FUNCS,
	
	[HTML_TAG_B] = DEFAULT_FUNCS,
	[HTML_TAG_BASE] = DEFAULT_FUNCS,
	[HTML_TAG_BASEFONT] = DEFAULT_FUNCS,
	[HTML_TAG_BDO] = DEFAULT_FUNCS,
	[HTML_TAG_BIG] = DEFAULT_FUNCS,
	[HTML_TAG_BLOCKQUOTE] = DEFAULT_FUNCS,
	[HTML_TAG_BODY] = DEFAULT_FUNCS,
	[HTML_TAG_BR] = {(tag_func)before_br, (tag_func)dothis_br, (tag_func)after_br},
	[HTML_TAG_BUTTON] = DEFAULT_FUNCS,
	
	[HTML_TAG_CAPTION] = DEFAULT_FUNCS,
	[HTML_TAG_CENTER] = DEFAULT_FUNCS,
	[HTML_TAG_CITE] = DEFAULT_FUNCS,
	[HTML_TAG_CODE] = DEFAULT_FUNCS,
	[HTML_TAG_COL] = DEFAULT_FUNCS,
	[HTML_TAG_COLGROUP] = DEFAULT_FUNCS,
	[HTML_TAG_DD] = DEFAULT_FUNCS,
	[HTML_TAG_DEL] = DEFAULT_FUNCS,
	
	[HTML_TAG_DFN] = DEFAULT_FUNCS,
	[HTML_TAG_DIR] = DEFAULT_FUNCS,
	[HTML_TAG_DIV] = DEFAULT_FUNCS,
	[HTML_TAG_DL] = DEFAULT_FUNCS,
	[HTML_TAG_DT] = DEFAULT_FUNCS,
	
	[HTML_TAG_EM] = DEFAULT_FUNCS,
	[HTML_TAG_FIELDSET] = DEFAULT_FUNCS,
	[HTML_TAG_FONT] = DEFAULT_FUNCS,
	[HTML_TAG_FORM] = DEFAULT_FUNCS,
	[HTML_TAG_FRAME] = DEFAULT_FUNCS,
	[HTML_TAG_FRAMESET] = DEFAULT_FUNCS,
	
	[HTML_TAG_H1] = H_FUNCS,
	[HTML_TAG_H2] = H_FUNCS,
	[HTML_TAG_H3] = H_FUNCS,
	[HTML_TAG_H4] = H_FUNCS,
	[HTML_TAG_H5] = H_FUNCS,
	[HTML_TAG_H6] = H_FUNCS,
	[HTML_TAG_HEAD] = DEFAULT_FUNCS,
	[HTML_TAG_HR] = DEFAULT_FUNCS,
	[HTML_TAG_HTML] = DEFAULT_FUNCS,
	
	[HTML_TAG_I] = DEFAULT_FUNCS,
	[HTML_TAG_IFRAME] = DEFAULT_FUNCS,
	[HTML_TAG_IMG] = {(tag_func)before_img, (tag_func)dothis_img, (tag_func)after_img},
	[HTML_TAG_INPUT] = DEFAULT_FUNCS,
	[HTML_TAG_INS] = DEFAULT_FUNCS,
	
	[HTML_TAG_KBD] = DEFAULT_FUNCS,
	
	[HTML_TAG_LABEL] = DEFAULT_FUNCS,
	[HTML_TAG_LEGEND] = DEFAULT_FUNCS,
	[HTML_TAG_LI] = DEFAULT_FUNCS,
	[HTML_TAG_LINK] = DEFAULT_FUNCS,
	
	[HTML_TAG_MAP] = DEFAULT_FUNCS,
	[HTML_TAG_MENU] = DEFAULT_FUNCS,
	[HTML_TAG_META] = DEFAULT_FUNCS,
	
	[HTML_TAG_NOFRAMES] = DEFAULT_FUNCS,
	[HTML_TAG_NOSCRIPT] = DEFAULT_FUNCS,
	
	[HTML_TAG_OBJECT] = DEFAULT_FUNCS,
	[HTML_TAG_OL] = DEFAULT_FUNCS,
	[HTML_TAG_OPTGROUP] = DEFAULT_FUNCS,
	[HTML_TAG_OPTION] = DEFAULT_FUNCS,
	
	[HTML_TAG_P] = DEFAULT_FUNCS,
	[HTML_TAG_PARAM] = DEFAULT_FUNCS,
	[HTML_TAG_PRE] = DEFAULT_FUNCS,
	
	[HTML_TAG_Q] = DEFAULT_FUNCS,
	
	[HTML_TAG_S] = DEFAULT_FUNCS,
	[HTML_TAG_SAMP] = DEFAULT_FUNCS,
	[HTML_TAG_SCRIPT] = DEFAULT_FUNCS,
	[HTML_TAG_SELECT] = DEFAULT_FUNCS,
	[HTML_TAG_SMALL] = DEFAULT_FUNCS,
	[HTML_TAG_SPAN] = DEFAULT_FUNCS,
	[HTML_TAG_STRIKE] = DEFAULT_FUNCS,
	[HTML_TAG_STRONG] = DEFAULT_FUNCS,
	[HTML_TAG_STYLE] = DEFAULT_FUNCS,
	[HTML_TAG_SUB] = DEFAULT_FUNCS,
	[HTML_TAG_SUP] = DEFAULT_FUNCS,
	
	[HTML_TAG_TABLE] = DEFAULT_FUNCS,
	[HTML_TAG_TBODY] = DEFAULT_FUNCS,
	[HTML_TAG_TD] = DEFAULT_FUNCS,
	[HTML_TAG_TEXTAREA] = DEFAULT_FUNCS,
	[HTML_TAG_TFOOT] = DEFAULT_FUNCS,
	[HTML_TAG_TH] = DEFAULT_FUNCS,
	[HTML_TAG_THEAD] = DEFAULT_FUNCS,
	[HTML_TAG_TITLE] = DEFAULT_FUNCS,
	[HTML_TAG_TR] = DEFAULT_FUNCS,
	[HTML_TAG_TT] = DEFAULT_FUNCS,
	
	[HTML_TAG_U] = DEFAULT_FUNCS,
	[HTML_TAG_UL] = DEFAULT_FUNCS,
	
	[HTML_TAG_VAR] = DEFAULT_FUNCS,
};
