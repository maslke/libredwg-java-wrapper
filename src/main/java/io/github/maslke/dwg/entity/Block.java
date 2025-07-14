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

    public void setBasePt(Point2d basePt) {
        if (basePt == null) {
            return;
        }
        this.basePt = basePt;
        this.setBasePtNative(this.ref, this.basePt.getX(), this.basePt.getY());
    }

    private native long getParentNative(long ref);

    private native void setNameNative(long ref, String name);
    private native void setXrefPnameNative(long ref, String xrefPname);

    private native void setBasePtNative(long ref, double x, double y);
}
