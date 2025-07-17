package io.github.maslke.dwg.obj;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
public class DwgObjectRef {
    private long ref;
    private DwgHandle handleRef;
    private long absoluteRef;
    private short r11Idx;


    public void initAbsoluteRef() {
        this.absoluteRef = this.getAbsoluteRefNative(this.ref);
    }

    public void initR11Idx() {
        this.r11Idx = this.getR11IdxNative(this.ref);
    }

    public void setAbsoluteRef(long absoluteRef) {
        this.absoluteRef = absoluteRef;
        this.setAbsoluteRefNative(this.ref, this.absoluteRef);
    }

    public void setR11Idx(short r11Idx) {
        this.r11Idx = r11Idx;
        this.setR11IdxNative(this.ref, this.r11Idx);
    }


    private native void setAbsoluteRefNative(long ref, long absoluteRef);

    private native void setR11IdxNative(long ref, short r11Idx);

    private native long getAbsoluteRefNative(long ref);
    private native short getR11IdxNative(long ref);
}
