package io.github.maslke.dwg.obj;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
public class DwgHandle {
    private long ref;
    private short code;
    private short size;
    private long value;
    private short isGlobal;
}
