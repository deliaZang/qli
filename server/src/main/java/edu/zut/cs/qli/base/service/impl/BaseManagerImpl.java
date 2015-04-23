package edu.zut.cs.qli.base.service.impl;

import java.io.Serializable;
import java.util.List;

import edu.zut.cs.qli.base.dao.BaseDao;
import edu.zut.cs.qli.base.domain.BaseEntityDomain;
import edu.zut.cs.qli.base.service.BaseManager;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.transaction.annotation.Transactional;

/**
 * This class serves as the Base class for all other Managers - namely to hold
 * common CRUD methods that they might all use. You should only need to extend
 * this class when your require custom CRUD logic.
 * <p/>
 * <p>
 * To register this class in your Spring context media, use the following XML.
 * 
 * 
 * 
 * @param <T>
 *            a type variable
 * @param <PK>
 *            the primary key for that type
 */
@Transactional
public class BaseManagerImpl<T extends BaseEntityDomain, PK extends Serializable>
		implements BaseManager<T, PK> {

	protected BaseDao<T, PK> dao;

	@Override
	public Page<T> findAll(Pageable page) {
		Page<T> result = this.dao.findAll(page);
		return result;
	}

	@Override
	public T findById(PK id) {
		return this.dao.findOne(id);
	}

	@Override
	public T save(T entity) {
		return this.dao.saveAndFlush(entity);
	}

	@Override
	public List<T> save(Iterable<T> entities) {
		return this.dao.save(entities);
	}

	@Override
	public List<T> findAll() {
		return this.dao.findAll();
	}

	@Override
	public void delete(PK id) {
		this.dao.delete(id);
	}

}
