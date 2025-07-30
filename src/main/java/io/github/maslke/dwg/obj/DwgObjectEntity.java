package io.github.maslke.dwg.obj;

import io.github.maslke.dwg.entity.Common;
import io.github.maslke.dwg.Dwg;

public class DwgObjectEntity {
    public long ref;

    public DwgObjectEntity() {
        this.ref = 0;
    }

    public DwgObjectEntity(long ref) {
        this.ref = ref;
    }
    
    public long getRef() {
        return this.ref;
    }

    public long getObjId() {
        return this.getObjId(this.ref);
    }

    public Common getEntity(int entityType) {
        return this.getEntity(this.ref, entityType);
    }

    public void setColor(DwgColor color) {
        this.setColor(this.ref, color);

    }

    public DwgColor getColor() { 
        return this.getColor(this.ref);
    }

    public int getLinewt() {
        return this.getLinewt(this.ref);
    }

    public void setLinewt(int linewt) {
        this.setLinewt(this.ref, linewt);
    }

    public DwgObjectRef getLtype() {
        return this.getLtype(this.ref);
    }

    public void setLtype(DwgObjectRef ltype) {
        this.setLtype(this.ref, ltype);
    }

    public DwgObjectRef getLayer() {
        return this.getLayer(this.ref);
    }

    public void setLayer(DwgObjectRef layer) {
        this.setLayer(this.ref, layer);
    } 

    public Dwg getDwg() {
        return this.getDwg(this.ref);
    }

    private native long getObjId(long ref);
    private native Common getEntity(long ref, int entityType);
    private native void setColor(long ref, DwgColor color);
    private native DwgColor getColor(long ref);
    private native void setLinewt(long ref, int linewt);
    private native int getLinewt(long ref);
    private native void setLtype(long ref, DwgObjectRef ltype);
    private native DwgObjectRef getLtype(long ref);
    private native void setLayer(long ref, DwgObjectRef layer);
    private native DwgObjectRef getLayer(long ref);
    private native Dwg getDwg(long ref);
}
