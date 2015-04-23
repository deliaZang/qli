package edu.zut.cs.qli.base.controller;

import edu.zut.cs.qli.base.domain.BaseEntityDomain;
import edu.zut.cs.qli.base.service.BaseManager;
import org.apache.commons.lang3.StringUtils;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.data.domain.Sort.Direction;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.mvc.multiaction.MultiActionController;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.Serializable;
import java.util.Date;

public abstract class BaseEntityController<T extends BaseEntityDomain, PK extends Serializable, M extends BaseManager<T, PK>>
        extends MultiActionController {
    protected M manager;
    protected PK id;
    protected T model;
    protected Page<T> page;

    protected int pageNumber = 0;
    protected int pageSize = 20;

    protected Pageable pageable = new PageRequest(pageNumber, pageSize,
            new Sort(Direction.ASC, "id"));

    public T create(T model) {
        this.model = this.manager.save(model);
        return this.model;
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE, produces = "application/json", consumes = "application/json")
    @ResponseBody
    public void delete(@PathVariable Long id) throws IOException {
        this.manager.delete((PK) id);
    }

    @RequestMapping(value = "/", method = RequestMethod.GET, produces = "application/json")
    @ResponseBody
    public Page<T> get(HttpServletRequest request, HttpServletResponse response) {
        String page = request.getParameter("page");
        String limit = request.getParameter("limit");
        if (StringUtils.isNotBlank(page)) {
            this.pageNumber = Integer.valueOf(page) - 1;
        } else {
            this.pageNumber = 0;
        }
        if (StringUtils.isNotBlank(limit)) {
            this.pageSize = Integer.valueOf(limit);
        }
        this.pageable = new PageRequest(this.pageNumber, this.pageSize,
                new Sort(Direction.ASC, "id"));
        this.page = this.manager.findAll(this.pageable);
        logger.info(this.page);
        return this.page;
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.GET, produces = "application/json")
    @ResponseBody
    public T get(@PathVariable Long id) {
        this.model = this.manager.findById((PK) id);
        return this.model;
    }

    public T update(Long id, T model) {
        model.setId(id);
        model.setDateModified(new Date());
        this.model = this.manager.save(model);
        return this.model;
    }

}
