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
}
