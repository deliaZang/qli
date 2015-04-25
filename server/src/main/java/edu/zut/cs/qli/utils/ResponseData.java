package edu.zut.cs.qli.utils;

/**
 * Created by shouhutsh on 15-4-19.
 */
public class ResponseData {
    private static final int STATUS_OK = 1;
    private static final int STATUS_ERR = 0;

    public final int statu;
    public final String message;

    public ResponseData() {
        this.statu = STATUS_ERR;
        this.message = "Error";
    }

    public ResponseData(String message) {
        this.statu = STATUS_OK;
        this.message = message;
    }
}
