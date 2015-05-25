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

	private static final int DEFAULT_PANGE_NUM = 0; //��̨��ҳ��0��ʼ��ǰ̨��1��ʼ
	private static final int DEFAULT_SIZE = 10;
	public MyPageable(){
		super(DEFAULT_PANGE_NUM, DEFAULT_SIZE); //�ɻ�����ֱ��д0��20�����������
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
		//�õ�AbstractPageRequest��class����
		Class<?> claz = this.getClass().getSuperclass().getSuperclass();
		try {
			Field sizeField = claz.getDeclaredField("size");
			sizeField.setAccessible(true);
			sizeField.set(this, size); //�޸��ĸ������size���ԣ����ݵ��ǵ�ǰ���󼴿�
		} catch (NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
			throw new RuntimeException("ͨ�������޸�AbstractPageRequest��size���Գ����쳣", e);
		}
	}
	public void setPageNum(int page){
		//�õ�AbstractPageRequest��class����
		Class<?> claz = this.getClass().getSuperclass().getSuperclass();
		try {
			Field pageField = claz.getDeclaredField("page");
			pageField.setAccessible(true);
			pageField.set(this, page - 1); //�޸��ĸ������size���ԣ����ݵ��ǵ�ǰ���󼴿�
		} catch (NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
			throw new RuntimeException("ͨ�������޸�AbstractPageRequest��page���Գ����쳣", e);
		}
	}

}