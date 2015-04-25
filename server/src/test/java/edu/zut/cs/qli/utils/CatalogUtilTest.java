package edu.zut.cs.qli.utils;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.catalog.domain.Catalog;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by shouhutsh on 15-4-19.
 */
public class CatalogUtilTest {

    String test_html = "<h1>h1</h1><h2 style=\"white-space: normal;\">h2</h2><h2 style=\"white-space: normal;\">h2</h2><h1>h1</h1><h2>h2</h2><h3>h3</h3>";

    @Test
    public void testCreateCatalog(){
        Article article = new Article();
        article.setId(1L);
        article.setName("name");

        List<Catalog> catalogs = new ArrayList<>();
        CatalogUtil catalogUtil = new CatalogUtil(article, test_html);
        catalogUtil.parseCatalog(null, catalogs);

        System.out.println(catalogs);
        System.out.println(catalogUtil.getHtml());
    }
}
