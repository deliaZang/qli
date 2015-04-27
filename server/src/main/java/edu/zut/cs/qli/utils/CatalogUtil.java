package edu.zut.cs.qli.utils;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.catalog.domain.Catalog;

import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by shouhutsh on 15-4-19.
 */
// FIXME 这里逻辑有问题
public class CatalogUtil {

    private static final String REGEX = "<h([\\d]+)(.*?)>(.*?)</h";

    public CatalogUtil(Article article, String html) {
        this.count = 0;
        this.html = html;
        this.article = article;
        this.matcher = Pattern.compile(REGEX).matcher(html);
    }

    private String html;

    public String getHtml() {
        return html;
    }


    private long count;
    private Article article;
    private Matcher matcher;
    private boolean disNext = false;

    private long curLevel(){
        return Long.valueOf(matcher.group(1));
    }

    private Catalog initCatalog(){
        Catalog catalog = new Catalog();
        catalog.setCount(count);
        catalog.setArticle(article);
        catalog.setFlag(String.valueOf(count));
        catalog.setLevel(curLevel());
        catalog.setName(matcher.group(3));
        return catalog;
    }

    private void addFlagForHtml(){
        ++count;
        html = html.replace(matcher.group(0), "<h"+matcher.group(1)+matcher.group(2)+"><a name='" + count + "'>"+matcher.group(3)+"</a></h");
    }

    public void parseCatalog(Catalog parent, List<Catalog> catalogs){
        Catalog cur, last;

        while (disNext || matcher.find()){
            cur = initCatalog();

            if(0 == catalogs.size()){
                disNext = false;
                cur.setParent(parent);
                catalogs.add(cur);
                addFlagForHtml();
            }else {
                last = catalogs.get(catalogs.size()-1);
                if (curLevel() < last.getLevel()) {
                    disNext = true;
                    return;
                } else if (last.getLevel() == curLevel()) {
                    disNext = false;
                    cur.setParent(parent);
                    catalogs.add(cur);
                    addFlagForHtml();
                } else if (curLevel() > last.getLevel()) {
                    disNext = true;
                    parseCatalog(last, last.getChildren());
                }
            }
        }
    }
}
