package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.obj.DwgObjectEntity;

public class Vertex3d extends AbstractBaseEntity {
    public Vertex3d() {
        super();
    }

    public Vertex3d(long ref) {
        this();
        this.ref = ref;
    }

    public void setFlag(int flag) {
        this.setFlag(this.ref, flag);
    }

    public int getFlag() {
        return this.getFlag(this.ref);
    }
    

    public void setPoint(Point3d point) {
        this.setPoint(this.ref, point);
    }

    public Point3d getPoint() {
        return this.getPoint(this.ref);
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    private native long getParent(long ref);
    private native void setFlag(long ref, int flag);
    private native int getFlag(long ref);
    private native void setPoint(long ref, Point3d point);
    private native Point3d getPoint(long ref);
}
