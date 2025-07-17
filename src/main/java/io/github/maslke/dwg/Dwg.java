package io.github.maslke.dwg;

import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.obj.DwgObjectVport;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
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

    public Dwg() {

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

    public boolean release() {
        return releaseNative(this.ref) == 0;
    }

    public DwgObjectBlockHeader getObjectBlockHeader() {
        DwgObjectBlockHeader header = new DwgObjectBlockHeader();
        header.setRef(this.getObjectBlockHeaderNative(this.ref));
        header.setDwg(this);
        return header;
    }

    public DwgObjectBlockHeader createObjectBlockHeader(String name) {
        DwgObjectBlockHeader header = new DwgObjectBlockHeader();
        header.setRef(this.createObjectBlockHeaderNative(this.ref, name));
        header.setName(name);
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
        ref.initAbsoluteRef();
        return ref;
    }

    public DwgObjectRef addHandleRef(int code, long value, long obj) {
        long handle = this.addHandleRefNative(this.ref, code, value, obj);
        DwgObjectRef ref = new DwgObjectRef();
        ref.setRef(handle);
        ref.initAbsoluteRef();
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

    private native long getObjectBlockHeaderNative(long ref);

    private native long createObjectBlockHeaderNative(long ref, String name);

    private native void setCodePageNative(long ref, String codePage);

    private native long findTableHandleNative(long ref, String name, String table);

    private native long addHandleRefNative(long ref, int code, long value, long obj);

    private native long getVportNative(long ref, String name);

    private native int releaseNative(long ref);
}
