package edu.zut.cs.qli.catalog.dao;

import edu.zut.cs.qli.base.dao.BaseDao;
import edu.zut.cs.qli.catalog.domain.Catalog;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import java.util.List;

/**
 * Created by shouhutsh on 15-4-12.
 */
public interface CatalogDao extends BaseDao<Catalog, Long> {
    @Query(value = "select o from Catalog o where o.article.id=:a_id order by o.count")
    public List<Catalog> listByArticle(@Param("a_id") long a_id);
}
