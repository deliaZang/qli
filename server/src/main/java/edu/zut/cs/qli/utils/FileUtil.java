package edu.zut.cs.qli.utils;

import java.io.*;

/**
 * Created by shouhutsh on 15-4-20.
 */
public class FileUtil {

    // FIXME
    public static String createUniqueName(){
        return System.currentTimeMillis()+"";
    }

    public static String getHtml(String name){
        StringBuilder builder = new StringBuilder();
        try {
            String path = Thread.currentThread().getContextClassLoader().getResource("").getPath();
            File file = new File(path + "../resources/html/" + name + ".html");
            if(file.exists()) {
                String line;
                BufferedReader reader = new BufferedReader(new FileReader(file));
                while((line = reader.readLine()) != null){
                    builder.append(line);
                }
                return builder.toString();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "";
    }

    public static void saveHtml(String name, String content){
        try {
            String path = Thread.currentThread().getContextClassLoader().getResource("").getPath();
            File file = new File(path + "../resources/html/" + name + ".html");
            if(!file.exists())
                file.createNewFile();

            BufferedWriter writer = new BufferedWriter(new FileWriter(file));
            writer.write(content);
            writer.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
