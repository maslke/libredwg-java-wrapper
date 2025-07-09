package io.github.maslke.dwg.obj;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
public class DwgColor {
    private long ref;
    private int index;
    private int flag;
    private int raw;
    private int rgb;
    private int method;
    private String name;
    private String bookName;
    private DwgObjectRef handle;
    private int alphaRaw;
    private short alphaType;
    private int alpha;
}
