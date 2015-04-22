package edu.zut.cs.qli.base.domain;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.MappedSuperclass;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

import org.apache.commons.lang.builder.HashCodeBuilder;
import org.apache.commons.lang.builder.ToStringBuilder;
import org.apache.commons.lang.builder.ToStringStyle;

@MappedSuperclass
public class BaseEntityDomain extends BaseDomain {

	private static final long serialVersionUID = -6163675075289529459L;

	/**
	 * 实体创建时间
	 */
	@Temporal(TemporalType.TIMESTAMP)
	@Column(name = "DATECREATED")
	protected Date dateCreated = new Date();

	/**
	 * 实体修改时间
	 */
	@Temporal(TemporalType.TIMESTAMP)
	@Column(name = "DATEMODIFED")
	protected Date dateModified = new Date();

	/**
	 * 实体是否被删除
	 */
	@Column(name = "DELETED")
	protected Boolean deleted = false;

	/**
	 * 实体主键
	 */
	@Id
	@Column(name = "ID")
	@GeneratedValue(strategy = GenerationType.AUTO)
	Long id;

	@Override
	public boolean equals(Object obj) {
		if (null != obj) {
			if (obj instanceof BaseEntityDomain) {
				BaseEntityDomain domain = (BaseEntityDomain) obj;
				if (this.id == domain.id) {
					return true;
				}
			}
		}
		return false;
	}

	public Date getDateCreated() {
		return dateCreated;
	}

	public Date getDateModified() {
		return dateModified;
	}

	public Long getId() {
		return id;
	}

	@Override
	public int hashCode() {
		if (this.id == null) {
			this.id = Long.valueOf(0);
		}
		return HashCodeBuilder.reflectionHashCode(this.id);
	}

	public Boolean isDeleted() {
		return deleted;
	}

	public void setDateCreated(Date dateCreated) {
		this.dateCreated = dateCreated;
	}

	public void setDateModified(Date dateModified) {
		this.dateModified = dateModified;
	}

	public void setDeleted(Boolean deleted) {
		this.deleted = deleted;
	}

	public void setId(Long id) {
		this.id = id;
	}

	@Override
	public String toString() {
		return ToStringBuilder.reflectionToString(this,
				ToStringStyle.MULTI_LINE_STYLE);
	}

}
