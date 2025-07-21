package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.obj.DwgColor;

public class Parent {
    // TODO MORE ATTRIBUTES
    private long ref;

    public Parent() {

    }

    public Parent(long ref) {
        this();
        this.ref = ref;
    }

    public long getRef() {
        return this.ref;
    }

    public void setRef(long ref) {
        this.ref = ref;
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

    private native Dwg getDwg(long ref);
    private native void setColor(long ref, DwgColor color);
    private native void setLinewt(long ref, int linewt);
    private native void setLtype(long ref, DwgObjectRef ltype);
    private native void setLayer(long ref, DwgObjectRef layer);
    protected native DwgColor getColor(long ref);
    protected native DwgObjectRef getLayer(long ref);
    protected native DwgObjectRef getLtype(long ref);
    protected native int getLinewt(long ref);
}
