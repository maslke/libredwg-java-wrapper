package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.obj.DwgObjectRef;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class Parent {
    // TODO: more attrs
    private long ref;
    private int color;
    private DwgObjectRef ltype;
    private int linewt;
    private DwgObjectRef layer;

    public Parent(long ref) {
        this.ref = ref;
    }


    public void setColor(int color) {
        this.color = color;
        if (this.ref > 0) {
            this.setColorNative(this.ref, this.color);
        }
    }

    public void setLinewt(int linewt) {
        this.linewt = linewt;
        if (this.ref > 0) {
            this.setLinewtNative(this.ref, this.linewt);
        }
    }

    public void setLtype(DwgObjectRef ltype) {
        this.ltype = ltype;
        if (this.ref > 0) {
            this.setLtypeNative(this.ref, this.ltype.getRef());
        }
    }

    public void setLayer(DwgObjectRef layer) {
        this.layer = layer;
        if (this.ref > 0) {
            this.setLayerNative(this.ref, this.layer.getRef());
        }
    }

    public Dwg getDwg() {
        long reference = this.getDwgNative(this.ref);
        Dwg dwg = new Dwg();
        dwg.setRef(reference);
        return dwg;
    }

    private native long getDwgNative(long ref);

    private native void setColorNative(long ref, int color);

    private native void setLinewtNative(long ref, int linewt);

    private native void setLtypeNative(long ref, long ltype);

    private native void setLayerNative(long ref, long layer);

    protected native int getColorNative(long ref);

    protected native DwgObjectRef getLayerNative(long ref);

    protected native DwgObjectRef getLtypeNative(long ref);

    protected native int getLinewtNative(long ref);
}
