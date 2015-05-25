package edu.zut.cs.qli.catalog.controller;

import edu.zut.cs.qli.base.controller.BaseEntityController;
import edu.zut.cs.qli.catalog.domain.Catalog;
import edu.zut.cs.qli.catalog.service.CatalogManager;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.SessionAttributes;

/**
 * Created by shouhutsh on 15-4-12.
 */
@Controller
@RequestMapping("/catalog")
@SessionAttributes("user")
public class CatalogController extends
        BaseEntityController<Catalog, Long, CatalogManager> {

    CatalogManager catalogManager;

    @Autowired
    public void setUserManager(CatalogManager catalogManager) {
        this.catalogManager = catalogManager;
        this.manager = this.catalogManager;
    }

    @RequestMapping(method = RequestMethod.GET, value = "/list")
    public String list(@RequestParam long a_id, Model model) {
        model.addAttribute("catalogs", catalogManager.listByArticle(a_id));
        return "catalog/list";
    }

}
