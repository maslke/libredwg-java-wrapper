package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectEntity;

public class Arc extends AbstractBaseEntity {

    public Arc() {

    }

    public Arc(long ref) {
        this();
        this.ref = ref;
    }

    public void setCenter(Point3d center) {
        this.setCenter(this.ref, center);
    }

    public Point3d getCenter() {
        return this.getCenter(this.ref);
    }

    public double getRadius() {
        return this.getRadius(this.ref);
    }


    public void setRadius(double radius) {
        this.setRadius(this.ref, radius);
    }

    public double getThickness() {
        return this.getThickness(this.ref);
    }

    public void setThickness(double thickness) {
        this.setThickness(this.ref, thickness);
    }

    public Vector3d getExtrusion() {
        return this.getExtrusion(this.ref);
    }

    public void setExtrusion(Vector3d extrusion) {
        this.setExtrusion(this.ref, extrusion);
    }

    public double getStartAngle() {
        return this.getStartAngle(this.ref);
    }

    public void setStartAngle(double angle) {
        if (this.ref > 0) {
            this.setStartAngle(this.ref, angle);
        }
    }

    public double getEndAngle() {
        return this.getEndAngle(this.ref);
    }

    public void setEndAngle(double endAngle) {
        this.setEndAngle(this.ref, endAngle);
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }


    private native void setCenter(long ref, Point3d center);
    private native void setRadius(long ref, double radius);
    private native void setThickness(long ref, double thickness);
    private native void setExtrusion(long ref, Vector3d extrusion);
    private native void setStartAngle(long ref, double angle);
    private native void setEndAngle(long ref, double angle);
    private native long getParent(long ref);
    private native Point3d getCenter(long ref);
    private native double getRadius(long ref);
    private native double getThickness(long ref);
    private native Vector3d getExtrusion(long ref);
    private native double getStartAngle(long ref);
    private native double getEndAngle(long ref);
}
