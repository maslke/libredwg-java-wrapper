package io.github.maslke.dwg;

import lombok.Getter;
import lombok.Setter;

@Setter
@Getter
public final class Dwg {

    private long ref;
    private String file;

    static {
        System.loadLibrary("dwg_java");
    }

    private Dwg() {

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

    public boolean save(String path) {
        int ret = save(this.ref, path);
        return ret == 0;
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

    public native int save(long ref, String path);

    public static native long open(String path);

    public native long getHeaderNative(long dwg);

}
