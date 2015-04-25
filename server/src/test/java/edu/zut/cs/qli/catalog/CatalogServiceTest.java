package edu.zut.cs.qli.catalog;

import edu.zut.cs.qli.article.domain.Article;
import edu.zut.cs.qli.article.service.ArticleManager;
import edu.zut.cs.qli.catalog.domain.Catalog;
import edu.zut.cs.qli.catalog.service.CatalogManager;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import java.util.List;

/**
 * Created by shouhutsh on 15-4-19.
 */
@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = {
        "classpath:/applicationContext-dao.xml",
        "classpath:/applicationContext-service.xml" })
public class CatalogServiceTest {

    @Autowired
    ArticleManager articleManager;
    @Autowired
    CatalogManager catalogManager;

    Article a;
    @Before
    public void setUp() {
    }

    @Test
    public void testSave(){
        a = new Article();
        a.setTitle("test");
        a.setName("name");
        articleManager.save(a);

        Catalog parent = new Catalog();
        parent.setParent(null);
        parent.setLevel(1L);
        parent.setName("test");
        parent.setArticle(a);
        parent.setFlag("a");
        parent.setCount(1L);

        Catalog child = new Catalog();
        child.setParent(parent);
        child.setLevel(2L);
        child.setName("test");
        child.setArticle(a);
        child.setFlag("b");
        child.setCount(2L);
        parent.getChildren().add(child);

        catalogManager.save(parent);
    }


    @Test
    public void testList(){
        List<Catalog> catalogs = catalogManager.findAll();
        System.out.println(catalogs);
    }
}
