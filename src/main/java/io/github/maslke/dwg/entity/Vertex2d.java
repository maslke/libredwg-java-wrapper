package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.obj.DwgObjectEntity;

public class Vertex2d extends Common {
    public Vertex2d() {
        super();
    }

    public Vertex2d(long ref) {
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

    public void setStartWidth(double startWidth) {
        this.setStartWidth(this.ref, startWidth);
    }

    public double getStartWidth() {
        return this.getStartWidth(this.ref);
    }

    public void setEndWidth(double endWidth) {
        this.setEndWidth(this.ref, endWidth);
    }

    public double getEndWidth() {
        return this.getEndWidth(this.ref);
    }

    public void setId(long id) {
        this.setId(this.ref, id);
    }

    public long getId() {
        return this.getId(this.ref);
    }

    public void setBulge(double bulge) {
        this.setBulge(this.ref, bulge);
    }

    public double getBulge() {
        return this.getBulge(this.ref);
    }

    public void setTangentDir(double tangentDir) {
        this.setTangentDir(this.ref, tangentDir);
    }

    public double getTangentDir() {
        return this.getTangentDir(this.ref);
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    private native long getParent(long ref);
    private native void setFlag(long ref, int flag);
    private native int getFlag(long ref);
    private native void setPoint(long ref, Point3d point);
    private native Point3d getPoint(long ref);
    private native void setStartWidth(long ref, double startWidth);
    private native double getStartWidth(long ref);
    private native void setEndWidth(long ref, double endWidth);
    private native double getEndWidth(long ref);
    private native void setId(long ref, long id);
    private native long getId(long ref);
    private native void setBulge(long ref, double bulge);
    private native double getBulge(long ref);
    private native void setTangentDir(long ref, double tangentDir);
    private native double getTangentDir(long ref);
}