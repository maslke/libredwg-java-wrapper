package io.github.maslke.dwg;

import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.obj.DwgObjectVport;
import lombok.Getter;
import lombok.Setter;

@Setter
@Getter
public final class Dwg {

    private long ref;
    private String file;
    private String codePage;

    static {
        System.loadLibrary("dwg_java");
    }

    private Dwg() {

    }

    public static Dwg open(String path) {
        long handler = openNative(path);
        Dwg instance = new Dwg();
        instance.setRef(handler);
        return instance;
    }

    public static Dwg create() {
        long handler = createNative();
        Dwg instance = new Dwg();
        instance.setRef(handler);
        return instance;
    }

    public boolean save(String path) {
        int ret = saveNative(this.ref, path);
        return ret == 0;
    }

    public DwgBlockHeader getBlockHeader() {
        DwgBlockHeader header = new DwgBlockHeader();
        header.setRef(this.getBlockHeaderNative(this.ref));
        header.setDwg(this);
        return header;
    }

    public void setCodePage(String codePage) {
        this.setCodePageNative(this.ref, codePage);
        this.codePage = codePage;
    }

    public String getVersion() {
        return this.getVersionNative();
    }

    public DwgObjectRef findTableHandle(String name, String table) {
        long handle = this.findTableHandleNative(this.ref, name, table);
        DwgObjectRef ref = new DwgObjectRef();
        ref.setRef(handle);
        return ref;
    }

    public DwgObjectRef addHandleRef(int code, long value, long obj) {
        long handle = this.addHandleRefNative(this.ref, code, value, obj);
        DwgObjectRef ref = new DwgObjectRef();
        ref.setRef(handle);
        return ref;
    }

    public DwgObjectVport getVport(String portName) {
        long handle = this.getVportNative(this.ref, portName);
        DwgObjectVport vport = new DwgObjectVport();
        vport.setRef(handle);
        return vport;
    }

    private native String getVersionNative();

    private static native long createNative();

    private native int saveNative(long ref, String path);

    private static native long openNative(String path);

    private native long getBlockHeaderNative(long ref);

    private native void setCodePageNative(long ref, String codePage);

    private native long findTableHandleNative(long ref, String name, String table);

    private native long addHandleRefNative(long ref, int code, long value, long obj);

    private native long getVportNative(long ref, String name);
}
