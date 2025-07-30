package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectEntity;


public class Solid extends Common {
    
    public Solid() {
    }
    public Solid(long ref) {
        this();
        this.ref = ref;
    }

    public void setThickness(double thickness) {
        this.setThickness(this.ref, thickness);
    }
    public double getThickness() {
        return this.getThickness(this.ref);
    }
    
    public void setElevation(double elevation) {
        this.setElevation(this.ref, elevation);
    }
    public double getElevation() {
        return this.getElevation(this.ref);
    }
    

    public void setCorner1(Point2d corner1) {
        this.setCorner1(this.ref, corner1);
    }
    public Point2d getCorner1() {
        return this.getCorner1(this.ref);
    }

    public void setCorner2(Point2d corner2) {
        this.setCorner2(this.ref, corner2);
    }
    public Point2d getCorner2() {
        return this.getCorner2(this.ref);
    }

    public void setCorner3(Point2d corner3) {
        this.setCorner3(this.ref, corner3);
    }
    public Point2d getCorner3() {
        return this.getCorner3(this.ref);
    }
    
    public void setCorner4(Point2d corner4) {
        this.setCorner4(this.ref, corner4);
    }
    public Point2d getCorner4() {
        return this.getCorner4(this.ref);
    }
    
    public void setExtrusion(Vector3d extrusion) {
        this.setExtrusion(this.ref, extrusion);
    }
    public Vector3d getExtrusion() {
        return this.getExtrusion(this.ref);
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    private native void setThickness(long ref, double thickness);
    private native double getThickness(long ref);
    private native void setElevation(long ref, double elevation);
    private native double getElevation(long ref);
    private native void setCorner1(long ref, Point2d corner1);
    private native Point2d getCorner1(long ref);
    private native void setCorner2(long ref, Point2d corner2);
    private native Point2d getCorner2(long ref);
    private native void setCorner3(long ref, Point2d corner3);
    private native Point2d getCorner3(long ref);
    private native void setCorner4(long ref, Point2d corner4);
    private native Point2d getCorner4(long ref);
    private native void setExtrusion(long ref, Vector3d extrusion);
    private native Vector3d getExtrusion(long ref);
    private native long getParent(long ref);
}
