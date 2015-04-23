package du.zut.cs.qli.test;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by ZL on 2015/4/18.
 */
public class RegexTest {
    private static String REGEX = "<[\\s\\S]";
    private static String INPUT = "<h2>";
    public static void main( String args[] ){
        Pattern p = Pattern.compile(REGEX);
        Matcher m = p.matcher(INPUT); // 获取 matcher 对象
        int count = 0;

        while(m.find()) {
            count++;
            System.out.println("Match number "+count);
            System.out.println("start(): "+m.start());
            System.out.println("end(): "+m.end());
        }
    }
}
