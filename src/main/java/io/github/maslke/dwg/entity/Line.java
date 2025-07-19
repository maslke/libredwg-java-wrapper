package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;

public class Line extends Common {

    public Line() {

    }

    public Line(long ref) {
        this();
        this.ref = ref;
    }

    public void setStart(Point3d start) {
        this.setStart(this.ref, start);
    }

    public Point3d getStart() {
        return this.getStart(this.ref);
    }

    public void setEnd(Point3d end) {
        this.setEnd(this.ref, end);
    }

    public Point3d getEnd() {
        return this.getEnd(this.ref);
    }

    public void setExtrusion(Vector3d extrusion) {
        this.setExtrusion(this.ref, extrusion);
    }

    public Vector3d getExtrusion() {
        return this.getExtrusion(this.ref);
    }

    public void setThickness(double thickness) {
        this.setThickness(this.ref, thickness);
    }

    public double getThickness() {
        return this.getThickness(this.ref);
    }

    public Parent getParent() {
        return new Parent(this.getParent(this.ref));
    }

    private native void setStart(long ref, Point3d start);
    private native void setEnd(long ref, Point3d end);
    private native void setExtrusion(long ref, Vector3d extrusion);
    private native void setThickness(long ref, double thickness);
    private native long getParent(long ref);
    private native Point3d getStart(long ref);
    private native Point3d getEnd(long ref);
    private native Vector3d getExtrusion(long ref);
    private native double getThickness(long ref);
}
