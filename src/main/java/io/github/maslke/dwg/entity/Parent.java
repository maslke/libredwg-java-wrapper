package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class Parent {
    private long ref;
    private int color;
    private String ltype;
    private int linewt;
    private boolean visible;
    private String layer;

    public Parent(long ref) {
        this.ref = ref;
    }


    public void setColor(int color) {
        this.color = color;
        this.setColorNative(this.ref, this.color);
    }

    public void setLinewt(int linewt) {
        this.linewt = linewt;
        this.setLinewtNative(this.ref, this.linewt);
    }

    public void setLtype(String ltype) {
        this.ltype = ltype;
        this.setLtypeNative(this.ref, this.ltype);
    }

    public Dwg getDwgReference() {
        long reference = this.getDwgNative(this.ref);
        Dwg dwg = new Dwg();
        dwg.setRef(ref);
        return dwg;
    }

    private native long getDwgNative(long ref);

    private native void setColorNative(long ref, int color);

    private native void setLinewtNative(long ref, int linewt);

    private native void setLtypeNative(long ref, String ltype);
}
