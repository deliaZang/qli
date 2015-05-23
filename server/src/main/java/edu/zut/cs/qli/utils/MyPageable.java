package edu.zut.cs.qli.utils;

import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Sort;
import org.springframework.data.domain.Sort.Direction;

import java.lang.reflect.Field;

public class MyPageable extends PageRequest{
	/**
	 *
	 */
	private static final long serialVersionUID = -6665380431264357448L;

	private static final int DEFAULT_PANGE_NUM = 0; //后台分页从0开始，前台从1开始
	private static final int DEFAULT_SIZE = 2;
	public MyPageable(){
		super(DEFAULT_PANGE_NUM, DEFAULT_SIZE); //忌讳这里直接写0和20，这叫神仙数
	}

	public MyPageable(int page, int size, Direction direction,
					  String... properties) {
		super(page, size, direction, properties);
	}

	public MyPageable(int page, int size, Sort sort) {
		super(page, size, sort);
	}

	public MyPageable(int page, int size) {
		super(page, size);
	}

	public void setNumPerPage(int size){
		//得到AbstractPageRequest的class对象
		Class<?> claz = this.getClass().getSuperclass().getSuperclass();
		try {
			Field sizeField = claz.getDeclaredField("size");
			sizeField.setAccessible(true);
			sizeField.set(this, size); //修改哪个对象的size属性？传递的是当前对象即可
		} catch (NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
			throw new RuntimeException("通过反射修改AbstractPageRequest的size属性出现异常", e);
		}
	}
	public void setPageNum(int page){
		//得到AbstractPageRequest的class对象
		Class<?> claz = this.getClass().getSuperclass().getSuperclass();
		try {
			Field pageField = claz.getDeclaredField("page");
			pageField.setAccessible(true);
			pageField.set(this, page - 1); //修改哪个对象的size属性？传递的是当前对象即可
		} catch (NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
			throw new RuntimeException("通过反射修改AbstractPageRequest的page属性出现异常", e);
		}
	}

}