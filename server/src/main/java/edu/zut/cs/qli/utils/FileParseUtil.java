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

    // FIXME 我假设 ppt 文档的结构有 title ，而且我假设为 Text 的第一个元素，此假设可能错误
    public static String getPPTContent(InputStream is) throws Exception {
        StringBuffer content = new StringBuffer("");
        SlideShow ss = new SlideShow(new HSLFSlideShow(is));
        Slide[] slides = ss.getSlides();
        for (int i = 0; i < slides.length; i++) {
            content.append("<h1>"+slides[i].getTitle()+"</h1><br/>");
            TextRun[] t = slides[i].getTextRuns();
            if(! slides[i].getTitle().equals(t[0].getText())){
                content.append("<pre>"+t[0].getText()+"</pre><br/>");
            }
            for (int j = 1; j < t.length; j++) {
                content.append("<pre>"+t[j].getText()+"</pre><br/>");
            }
        }
        return content.toString();
    }
}
