package io.github.maslke.dwg.obj;

import io.github.maslke.dwg.Dwg;

public class DwgObjectObject {
    public long ref;

    public DwgObjectObject() {
        this.ref = 0;
    }

    public DwgObjectObject(long ref) {
        this.ref = ref;
    }
    
    public long getRef() {
        return this.ref;
    }

    public long getObjId() {
        return this.getObjId(this.ref);
    }

    public Dwg getDwg() {
        return this.getDwg(this.ref);
    }

    public DwgObjectBlockHeader getObjectBlockHeader() {
        return this.getObjectBlockHeader(this.ref);
    }

    public DwgObjectStyle getObjectStyle() {
        return this.getObjectStyle(this.ref);
    }

    public DwgObjectVport getObjectVport() {
        return this.getObjectVport(this.ref);
    }

    public DwgObjectLtype getObjectLtype() {
        return this.getObjectLtype(this.ref);
    }

    public DwgObjectLayer getObjectLayer() {
        return this.getObjectLayer(this.ref);
    }

    private native long getObjId(long ref);
    private native Dwg getDwg(long ref);
    private native DwgObjectBlockHeader getObjectBlockHeader(long ref);
    private native DwgObjectStyle getObjectStyle(long ref);
    private native DwgObjectVport getObjectVport(long ref);
    private native DwgObjectLtype getObjectLtype(long ref);
    private native DwgObjectLayer getObjectLayer(long ref);
} 