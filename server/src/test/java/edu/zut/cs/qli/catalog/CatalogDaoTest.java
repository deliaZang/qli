package edu.zut.cs.qli.catalog;

import edu.zut.cs.qli.catalog.dao.CatalogDao;
import edu.zut.cs.qli.catalog.domain.Catalog;
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
public class CatalogDaoTest {

    @Autowired
    CatalogDao catalogDao;

    @Test
    public void testFindByArticle(){
        List<Catalog> catalogs = catalogDao.listByArticle(1L);
    }
}
