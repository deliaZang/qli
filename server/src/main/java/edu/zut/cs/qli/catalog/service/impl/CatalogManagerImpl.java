package edu.zut.cs.qli.catalog.service.impl;

import edu.zut.cs.qli.base.service.impl.BaseManagerImpl;
import edu.zut.cs.qli.catalog.dao.CatalogDao;
import edu.zut.cs.qli.catalog.domain.Catalog;
import edu.zut.cs.qli.catalog.service.CatalogManager;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

/**
 * Created by shouhutsh on 15-4-12.
 */
@Service("CatalogManager")
@Transactional
public class CatalogManagerImpl extends BaseManagerImpl<Catalog, Long>
    implements CatalogManager {

    CatalogDao catalogDao;

    @Autowired
    public void setUserDao(CatalogDao catalogDao){
        this.catalogDao = catalogDao;
        this.dao = this.catalogDao;
    }

    @Override
    public List<Catalog> listByArticle(long a_id) {
        return catalogDao.listByArticle(a_id);
    }
}
