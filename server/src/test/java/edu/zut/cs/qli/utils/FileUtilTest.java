package edu.zut.cs.qli.utils;

import org.junit.Test;

/**
 * Created by shouhutsh on 15-4-20.
 */
public class FileUtilTest {

    @Test
    public void testSaveFile(){
        FileUtil.saveHtml("test", "content");
    }
}
