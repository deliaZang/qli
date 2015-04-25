package edu.zut.cs.qli.article;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.article.service.ArticleManager;
import edu.zut.cs.qli.catalog.domain.Catalog;
import edu.zut.cs.qli.catalog.service.CatalogManager;
import edu.zut.cs.qli.utils.CatalogUtil;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by shouhutsh on 15-4-19.
 */
@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = {
        "classpath:/applicationContext-dao.xml",
        "classpath:/applicationContext-service.xml" })
public class ArticleServiceTest {

    @Autowired
    ArticleManager articleManager;

    @Autowired
    CatalogManager catalogManager;

    @Before
    public void setUp() {
    }

    @Test
    public void testSave(){
        Article article = new Article();
        article.setTitle("test");
        article.setName("name");

        articleManager.save(article);
    }

    @Test
    public void testList(){
        List<Article> articleList = articleManager.findAll();
        System.out.println();
    }

    @Test
    public void testCatalog(){
        String test_html = "<h1>h1</h1><h2 style=\"white-space: normal;\">h2</h2><h2 style=\"white-space: normal;\">h2</h2><h1>h1</h1><h2>h2</h2><h3>h3</h3>";

        Article a =  new Article();
        a.setTitle("test");
        a.setName("name");

        articleManager.doSave(a, test_html);
    }

    @Test
    public void testTest(){
        Article a = articleManager.findDetailById(1L);
        System.out.println(a);
    }
}
