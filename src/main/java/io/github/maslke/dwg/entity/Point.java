package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Vector3d;

public class Point extends Common {
    
    public Point() {

    }

    public Point(long ref) {
        this();
        this.ref = ref;
    }


    public void setX(double x) {
        this.setX(this.ref, x);
    }

    public double getX() {
        return this.getX(this.ref);
    }

    public void setY(double y) {
        this.setY(this.ref, y);
    }

    public double getY() {
        return this.getY(this.ref);
    }

    public void setZ(double z) {
        this.setZ(this.ref, z);
    }

    public double getZ() {
        return this.getZ(this.ref);
    }

    public void setThickness(double thickness) {
        this.setThickness(this.ref, thickness);
    }

    public double getThickness() {
        return this.getThickness(this.ref);
    }

    public void setExtrusion(Vector3d extrusion) {
        this.setExtrusion(this.ref, extrusion);
    }

    public Vector3d getExtrusion() {
        return this.getExtrusion(this.ref);
    }

    public Parent getParent() {
        return new Parent(this.getParent(this.ref));
    }

    public native void setX(long ref, double x);
    public native void setY(long ref, double y);
    public native void setZ(long ref, double z);
    public native void setThickness(long ref, double thickness);
    public native void setExtrusion(long ref, Vector3d extrusion);
    private native long getParent(long ref);
    protected native double getX(long ref);
    protected native double getY(long ref);
    protected native double getZ(long ref);
    protected native Vector3d getExtrusion(long ref);
    protected native double getThickness(long ref);
}
