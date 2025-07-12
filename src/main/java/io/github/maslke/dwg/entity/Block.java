package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point2d;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
public class Block extends Common {
    private String name;
    private String xrefPname;
    private Point2d basePt;


    public Parent getParent() {
        long reference = this.getParentNative(this.ref);
        return new Parent(reference);
    }

    public void setName(String name) {
        this.name = name;
        this.setNameNative(this.ref, this.name);
    }

    public void setXrefPname(String xrefPname) {
        this.xrefPname = xrefPname;
        this.setXrefPnameNative(this.ref, this.xrefPname);
    }


    private native long getParentNative(long ref);

    private native void setNameNative(long ref, String name);
    private native void setXrefPnameNative(long ref, String xrefPname);
}
