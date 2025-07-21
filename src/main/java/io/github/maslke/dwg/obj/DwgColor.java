package io.github.maslke.dwg.obj;

public class DwgColor {
    private long ref;

    public DwgColor() {
    }

    public DwgColor(long ref) {
        this();
        this.ref = ref;
    }

    public void setIndex(int index) {
        this.setIndex(this.ref, index);
    }

    public int getIndex() {
        return this.getIndex(this.ref);
    }

    public void setFlag(int flag) {
        this.setFlag(this.ref, flag);
    }

    public int getFlag() {
        return this.getFlag(this.ref);
    }

    public void setRaw(int raw) {
        this.setRaw(this.ref, raw);
    }

    public int getRaw() {
        return this.getRaw(this.ref);
    }

    public void setRgb(int rgb) {
        this.setRgb(this.ref, rgb);
    }

    public int getRgb() {
        return this.getRgb(this.ref);
    }

    public void setMethod(int method) {
        this.setMethod(this.ref, method);
    }

    public int getMethod() {
        return this.getMethod(this.ref);
    }

    public void setName(String name) {
        this.setName(this.ref, name);
    }

    public String getName() {
        return this.getName(this.ref);
    }

    public void setBookName(String bookName) {
        this.setBookName(this.ref, bookName);
    }

    public String getBookName() {
        return this.getBookName(this.ref);
    }

    public void setHandle(DwgObjectRef handle) {
        this.setHandle(this.ref, handle);
    }

    public DwgObjectRef getHandle() {
        return this.getHandle(this.ref);
    }

    public void setAlphaRaw(int alphaRaw) {
        this.setAlphaRaw(this.ref, alphaRaw);
    }

    public int getAlphaRaw() {
        return this.getAlphaRaw(this.ref);
    }

    public void setAlphaType(short alphaType) {
        this.setAlphaType(this.ref, alphaType);
    }

    public short getAlphaType() {
        return this.getAlphaType(this.ref);
    }

    public void setAlpha(int alpha) {
        this.setAlpha(this.ref, alpha);
    }

    public int getAlpha() {
        return this.getAlpha(this.ref);
    }

    public long getRef() {
        return this.ref;
    }

    public void setRef(long ref) {
        this.ref = ref;
    }

    private native void setIndex(long ref, int index);

    private native void setFlag(long ref, int flag);

    private native void setRaw(long ref, int raw);

    private native void setRgb(long ref, int rgb);

    private native void setMethod(long ref, int method);

    private native void setName(long ref, String name);

    private native void setBookName(long ref, String bookName);

    private native void setHandle(long ref, DwgObjectRef handle);

    private native void setAlphaRaw(long ref, int alphaRaw);

    private native void setAlphaType(long ref, short alphaType);

    private native void setAlpha(long ref, int alpha);

    private native int getIndex(long ref);

    private native int getFlag(long ref);

    private native int getRaw(long ref);

    private native int getRgb(long ref);

    private native int getMethod(long ref);

    private native String getName(long ref);

    private native String getBookName(long ref);

    private native DwgObjectRef getHandle(long ref);

    private native int getAlphaRaw(long ref);

    private native short getAlphaType(long ref);

    private native int getAlpha(long ref);
}
