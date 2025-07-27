package io.github.maslke.dwg.entity;

public class OleFrame extends Common {
    public OleFrame() {
        super();
    }

    public OleFrame(long ref) {
        this();
        this.ref = ref;
    }

    public void setFlag(int flag) {
        this.setFlag(this.ref, flag);
    }

    public int getFlag() {
        return this.getFlag(this.ref);
    }

    public void setMode(int mode) {
        this.setMode(this.ref, mode);
    }

    public int getMode() {
        return this.getMode(this.ref);
    }

    public void setDataSize(int dataSize) {
        this.setDataSize(this.ref, dataSize);
    }

    public long getDataSize() {
        return this.getDataSize(this.ref);
    }

    public void setData(String data) {
        this.setData(this.ref, data);
    }

    public String getData() {
        return this.getData(this.ref);
    }

    public Parent getParent() {
        return new Parent(this.getParent(this.ref));
    }

    private native long getParent(long ref);
    private native void setFlag(long ref, int flag);
    private native int getFlag(long ref);
    private native void setMode(long ref, int mode);
    private native int getMode(long ref);
    private native void setDataSize(long ref, long dataSize);
    private native long getDataSize(long ref);
    private native void setData(long ref, String data);
    private native String getData(long ref);
}
