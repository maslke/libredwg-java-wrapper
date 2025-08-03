package io.github.maslke.dwg.obj;

public class DwgObjectLtype {
    public long ref;

    public DwgObjectLtype() {
        this.ref = 0;
    }
    
    public DwgObjectLtype(long ref) {
        this.ref = ref;
    }

    public long getRef() {
        return this.ref;
    }

    public void setRef(long ref) {
        this.ref = ref;
    }
}
