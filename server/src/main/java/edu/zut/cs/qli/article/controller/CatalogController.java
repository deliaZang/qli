package edu.zut.cs.qli.article.controller;

import edu.zut.cs.qli.article.domain.Catalog;
import edu.zut.cs.qli.article.service.CatalogManager;
import edu.zut.cs.qli.base.controller.BaseEntityController;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

/**
 * Created by ZL on 2015/4/18.
 */
@Controller
@RequestMapping("/catalog")
public class CatalogController extends BaseEntityController<Catalog,Long,CatalogManager>{

    CatalogManager catalogManager ;

    @Autowired
    public void setCatalogManager(CatalogManager catalogManager) {
        this.catalogManager = catalogManager;
    }

    public void init(){

    }
}
