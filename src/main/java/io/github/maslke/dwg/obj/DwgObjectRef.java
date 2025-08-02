package io.github.maslke.dwg.obj;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;


public class DwgObjectRef {
    private long ref;

    public DwgObjectRef(long ref) {
        this.ref = ref;
    }

    public DwgObjectRef() {
        this.ref = ref;
    }


    public long getRef() {
        return this.ref;
    }

    public void setRef(long ref) {
        this.ref = ref;
    }

    public DwgHandle getHandleRef() {
        return this.getHandleRef(this.ref);
    }

    public void setHandleRef(DwgHandle handleRef) {
        this.setHandleRef(this.ref, handleRef);
    }

    public long getAbsoluteRef() {
        return this.getAbsoluteRef(this.ref);
    }

    public void setAbsoluteRef(long absoluteRef) {
        this.setAbsoluteRef(this.ref, absoluteRef);
    }

    public int getR11Idx() {
        return this.getR11Idx(this.ref);
    }

    public void setR11Idx(int r11Idx) {
        this.setR11Idx(this.ref, r11Idx);
    }

    public DwgObject getObject() {
        return this.getObject(this.ref);
    }

    public void setObject(DwgObject object) {
        this.setObject(this.ref, object);
    }


    private native DwgHandle getHandleRef(long ref);
    private native void setHandleRef(long ref, DwgHandle handleRef);
    private native long getAbsoluteRef(long ref);
    private native void setAbsoluteRef(long ref, long absoluteRef);
    private native int getR11Idx(long ref);
    private native void setR11Idx(long ref, int r11Idx);
    private native DwgObject getObject(long ref);
    private native void setObject(long ref, DwgObject object);
}
