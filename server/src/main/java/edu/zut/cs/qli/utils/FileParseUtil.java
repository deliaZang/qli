package edu.zut.cs.qli.utils;

import org.apache.poi.hslf.HSLFSlideShow;
import org.apache.poi.hslf.model.Slide;
import org.apache.poi.hslf.model.TextRun;
import org.apache.poi.hslf.usermodel.SlideShow;

import java.io.File;
import java.io.InputStream;

/**
 * Created by shouhutsh on 15-5-24.
 */

/**
 * 处理PPT文件
 */
public class FileParseUtil {

    public static String getPPTContent(String s) throws Exception {
        return getPPTContent(new java.io.FileInputStream(s));
    }

    public static String getPPTContent(File f) throws Exception {
        return getPPTContent(new java.io.FileInputStream(f));
    }

    public static String getPPTContent(InputStream is) throws Exception {
        StringBuffer content = new StringBuffer("");
        SlideShow ss = new SlideShow(new HSLFSlideShow(is));
        Slide[] slides = ss.getSlides();
        for (int i = 0; i < slides.length; i++) {
            TextRun[] t = slides[i].getTextRuns();
            for (int j = 0; j < t.length; j++) {
                content.append("<pre>"+t[j].getText()+"</pre><br/>");
            }
        }
        return content.toString();
    }
}
