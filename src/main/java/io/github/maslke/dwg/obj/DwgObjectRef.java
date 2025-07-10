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


    public void setRef(long ref) {
        this.ref = ref;
        this.absoluteRef = this.getAbsoluteRefNative(ref);
    }

    private native long getAbsoluteRefNative(long ref);

}
