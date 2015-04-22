package edu.zut.cs.qli.base.dao;

import java.io.Serializable;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.JpaSpecificationExecutor;

import edu.zut.cs.qli.base.domain.BaseEntityDomain;

/**
 * Generic DAO (Data Access Object) with common methods to CRUD POJOs.
 * Implemented with Spring-Data-JPA Repository
 * <p>
 * Extend this interface if you want type safe (no casting necessary) DAO's for
 * your domain objects.
 * 
 * @author <a href="mailto:ming616@gmail.com">Liu Xiaoming</a>
 * @param <T>
 *            a type variable,实体类型
 * @param <PK>
 *            the primary key for that type，实体类Id
 */
public interface BaseDao<T extends BaseEntityDomain, PK extends Serializable>
		extends JpaRepository<T, PK>, JpaSpecificationExecutor<T> {
}