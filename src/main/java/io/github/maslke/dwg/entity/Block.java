package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.obj.DwgObjectEntity;

public class Block extends Common {
    
    public Block() {

    }

    public Block(long ref) {
        this();
        this.ref = ref;
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    public void setName(String name) {
        this.setName(this.ref, name);
    }

    public void setXrefPname(String xrefPname) {
        this.setXrefPname(this.ref, xrefPname);
    }

    public void setBasePt(Point2d basePt) {
        this.setBasePt(this.ref, basePt);
    }

    private native long getParent(long ref);
    private native void setName(long ref, String name);
    private native void setXrefPname(long ref, String xrefPname);
    private native void setBasePt(long ref, Point2d basePt);
}
