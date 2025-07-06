package io.github.maslke.dwg;

import lombok.Getter;
import lombok.Setter;

@Setter
@Getter
public class Dwg {

    private long ref;
    private String file;

    static {
        System.loadLibrary("dwg_java");
    }

    public Dwg() {

    }

    public static Dwg openDocument(String path) {
        long handler = open(path);
        Dwg instance = new Dwg();
        instance.setRef(handler);
        return instance;
    }

    public static Dwg createDocument() {
        long handler = create();
        Dwg instance = new Dwg();
        instance.setRef(handler);
        return instance;
    }

    public DwgBlockHeader getBlockHeader() {
        long instance = getRef();
        DwgBlockHeader header = new DwgBlockHeader();
        header.setRef(this.getHeaderNative(instance));
        header.setDwg(this);
        return header;
    }

    public native String getVersion();

    public static native long create();

    public static native long open(String path);

    public native long getHeaderNative(long dwg);

}
