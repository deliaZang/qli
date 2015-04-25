package edu.zut.cs.qli.catalog.service;

import edu.zut.cs.qli.base.service.BaseManager;
import edu.zut.cs.qli.catalog.domain.Catalog;

import java.util.List;

/**
 * Created by shouhutsh on 15-4-19.
 */
public interface CatalogManager extends BaseManager<Catalog, Long> {

    public List<Catalog> listByArticle(long a_id);


}
