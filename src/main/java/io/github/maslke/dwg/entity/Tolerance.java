package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.obj.DwgObjectEntity;

public class Tolerance extends Common {
    public Tolerance() {
        super();
    }

    public Tolerance(long ref) {
        this();
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    public void setUnknownShort(int unknownShort) {
        this.setUnknownShort(this.ref, unknownShort);
    }

    public int getUnknownShort() {
        return this.getUnknownShort(this.ref);
    }

    public void setHeight(double height) {
        this.setHeight(this.ref, height);
    }

    public double getHeight() {
        return this.getHeight(this.ref);
    }

    public void setDimgap(double dimgap) {
        this.setDimgap(this.ref, dimgap);
    }

    public double getDimgap() {
        return this.getDimgap(this.ref);
    }

    public void setInsPt(Point3d insPt) {
        this.setInsPt(this.ref, insPt);
    }

    public Point3d getInsPt() {
        return this.getInsPt(this.ref);
    }

    public void setXDirection(Point3d xDirection) {
        this.setXDirection(this.ref, xDirection);
    }

    public Point3d getXDirection() {
        return this.getXDirection(this.ref);
    }

    public void setExtrusion(Vector3d extrusion) {
        this.setExtrusion(this.ref, extrusion);
    }

    public Vector3d getExtrusion() {
        return this.getExtrusion(this.ref);
    }

    public void setTextValue(String textValue) {
        this.setTextValue(this.ref, textValue);
    }

    public String getTextValue() {
        return this.getTextValue(this.ref);
    }

    public void setDimStyle(DwgObjectRef dimStyle) {
        this.setDimStyle(this.ref, dimStyle);
    }

    public DwgObjectRef getDimStyle() {
        return this.getDimStyle(this.ref);
    }

    public void setText(String text) {}

    private native long getParent(long ref);  
    private native void setUnknownShort(long ref, int unknownShort);
    private native int getUnknownShort(long ref);
    private native void setHeight(long ref, double height);
    private native double getHeight(long ref);
    private native void setDimgap(long ref, double dimgap);
    private native double getDimgap(long ref);
    private native void setInsPt(long ref, Point3d insPt);
    private native Point3d getInsPt(long ref);
    private native void setXDirection(long ref, Point3d xDirection);
    private native Point3d getXDirection(long ref);
    private native void setExtrusion(long ref, Vector3d extrusion);
    private native Vector3d getExtrusion(long ref);
    private native void setTextValue(long ref, String textValue);
    private native String getTextValue(long ref);
    private native void setDimStyle(long ref, DwgObjectRef dimStyle);
    private native DwgObjectRef getDimStyle(long ref);
}
