package io.github.maslke.dwg.entity;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class ParentEntity {
    private long ref;
    private int color;
    private String ltype;
    private int linewt;
    private boolean visible;
    private String layer;

    public ParentEntity(long ref) {
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

    private native void setColorNative(long ref, int color);

    private native void setLinewtNative(long ref, int linewt);
}
