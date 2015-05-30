package edu.zut.cs.qli.utils;

import org.junit.Test;

import java.io.File;

/**
 * Created by shouhutsh on 15-4-20.
 */
public class FileParseUtilTest {

    @Test
    public void testGetPPTContent() throws Exception {
        System.out.print(FileParseUtil.getPPTContent(new File("/home/shouhutsh/test.ppt")));
    }
}
