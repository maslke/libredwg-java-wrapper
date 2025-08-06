package io.github.maslke.dwg.obj;
public class DwgHeader {

    private long ref;

    public DwgHeader() {
        this.ref = 0;
    }

    public DwgHeader(long ref) {
        this.ref = ref;
    }
    
    public int getDwgVersion() {
        return this.getDwgVersion(this.ref);
    }

    public int getMaintVersion() {
        return this.getMaintVersion(this.ref);
    }

    private native int getDwgVersion(long ref);
    private native int getMaintVersion(long ref);
}
