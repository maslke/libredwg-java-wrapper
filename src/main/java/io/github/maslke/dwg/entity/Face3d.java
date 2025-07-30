package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.obj.DwgObjectEntity;

public class Face3d extends Common {
    public Face3d() {
        super();
    }

    public Face3d(long ref) {
        this();
        this.ref = ref;
    }

    public void setHasNoFlags(int hasNoFlags) {
        this.setHasNoFlags(this.ref, hasNoFlags);
    }

    public int getHasNoFlags() {
        return this.getHasNoFlags(this.ref);
    }

    public void setZIsZero(int zIsZero) {
        this.setZIsZero(this.ref, zIsZero);
    }

    public int getZIsZero() {
        return this.getZIsZero(this.ref);
    }

    public void setCorner1(Point3d corner1) {
        this.setCorner1(this.ref, corner1);
    }

    public Point3d getCorner1() {
        return this.getCorner1(this.ref);
    }

    public void setCorner2(Point3d corner2) {
        this.setCorner2(this.ref, corner2);
    }

    public Point3d getCorner2() {
        return this.getCorner2(this.ref);
    }

    public void setCorner3(Point3d corner3) {
        this.setCorner3(this.ref, corner3);
    }

    public Point3d getCorner3() {
        return this.getCorner3(this.ref);
    }

    public void setInvisFlags(int invisFlags) {
        this.setInvisFlags(this.ref, invisFlags);
    }

    public int getInvisFlags() {
        return this.getInvisFlags(this.ref);
    }


    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    private native long getParent(long ref);
    private native void setHasNoFlags(long ref, int hasNoFlags);
    private native int getHasNoFlags(long ref);
    private native void setZIsZero(long ref, int zIsZero);
    private native int getZIsZero(long ref);
    private native void setCorner1(long ref, Point3d corner1);
    private native Point3d getCorner1(long ref);
    private native void setCorner2(long ref, Point3d corner2);
    private native Point3d getCorner2(long ref);
    private native void setCorner3(long ref, Point3d corner3);
    private native Point3d getCorner3(long ref);
    private native void setCorner4(long ref, Point3d corner4);
    private native Point3d getCorner4(long ref);
    private native void setInvisFlags(long ref, int invisFlags);
    private native int getInvisFlags(long ref);
}
