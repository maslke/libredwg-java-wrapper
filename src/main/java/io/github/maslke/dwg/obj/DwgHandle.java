package io.github.maslke.dwg.obj;


public class DwgHandle {
    private long ref;
    
    public long getRef() {
        return this.ref;
    }

    public void setRef(long ref) {
        this.ref = ref;
    }

    public DwgHandle(long ref) {
        this.ref = ref;
    }

    public DwgHandle() {
        this.ref = 0;
    }

    public int getCode() {
        return this.getCode(this.ref);
    }

    public void setCode(int code) {
        this.setCode(this.ref, code);
    }

    public int getSize() {
        return this.getSize(this.ref);
    }

    public void setSize(int size) {
        this.setSize(this.ref, size);
    }

    public long getValue() {
        return this.getValue(this.ref);
    }

    public void setValue(long value) {
        this.setValue(this.ref, value);
    }

    public int getIsGlobal() {
        return this.getIsGlobal(this.ref);
    }

    public void setIsGlobal(int isGlobal) {
        this.setIsGlobal(this.ref, isGlobal);
    }
    
    private native int getCode(long ref);
    private native void setCode(long ref, int code);
    private native int getSize(long ref);
    private native void setSize(long ref, int size);
    private native long getValue(long ref);
    private native void setValue(long ref, long value);
    private native int getIsGlobal(long ref);
    private native void setIsGlobal(long ref, int isGlobal);
}
