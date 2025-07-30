package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectEntity;


public class Ellipse extends Common {

    public Ellipse() {

    }

    public Ellipse(long ref) {
        this();
        this.ref = ref;
    }

    public void setCenter(Point3d center) {
        this.setCenter(this.ref, center);
    }

    public Point3d getCenter() {
        return this.getCenter(this.ref);
    }

    public void setMajorAxis(double majorAxis) {
        this.setMajorAxis(this.ref, majorAxis);
    }

    public double getMajorAxis() {
        return this.getMajorAxis(this.ref);
    }

    public void setExtrusion(Vector3d extrusion) {
        this.setExtrusion(this.ref, extrusion);
    }

    public Vector3d getExtrusion() {
        return this.getExtrusion(this.ref);
    }

    public void setAxisRatio(double axisRatio) {
        this.setAxisRatio(this.ref, axisRatio);
    }

    public double getAxisRatio() {
        return this.getAxisRatio(this.ref);
    }

    public void setStartAngle(double angle) {
        this.setStartAngle(this.ref, angle);
    }

    public double getStartAngle() {
        return this.getStartAngle(this.ref);
    }

    public void setEndAngle(double angle) {
        this.setEndAngle(this.ref, angle);
    }

    public double getEndAngle() {
        return this.getEndAngle(this.ref);
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    private native void setCenter(long ref, Point3d center);
    private native void setMajorAxis(long ref, double majorAxis);
    private native void setExtrusion(long ref, Vector3d extrusion);
    private native void setAxisRatio(long ref, double ratio);
    private native void setStartAngle(long ref, double angle);
    private native void setEndAngle(long ref, double angle);
    private native long getParent(long ref);
    private native Point3d getCenter(long ref);
    private native double getMajorAxis(long ref);
    private native Vector3d getExtrusion(long ref);
    private native double getAxisRatio(long ref);
    private native double getStartAngle(long ref);
    private native double getEndAngle(long ref);
}
