package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.obj.DwgObjectEntity;

public class Shape extends Common {
    public Shape() {
    }

    public Shape(long ref) {
        this();
        this.ref = ref;
    }

    public void setInsPt(Point3d insPt) {
        this.setInsPt(this.ref, insPt);
    }

    public Point3d getInsPt() {
        return this.getInsPt(this.ref);
    }

    public void setScale(double scale) {
        this.setScale(this.ref, scale);
    }

    public double getScale() {
        return this.getScale(this.ref);
    }

    public void setRotation(double rotation) {
        this.setRotation(this.ref, rotation);
    }

    public double getRotation() {
        return this.getRotation(this.ref);
    }

    public void setWidthFactor(double widthFactor) {
        this.setWidthFactor(this.ref, widthFactor);
    }

    public double getWidthFactor() {
        return this.getWidthFactor(this.ref);
    }

    public void setObliqueAngle(double obliqueAngle) {
        this.setObliqueAngle(this.ref, obliqueAngle);
    }

    public double getObliqueAngle() {
        return this.getObliqueAngle(this.ref);
    }

    public void setThickness(double thickness) {
        this.setThickness(this.ref, thickness);
    }

    public double getThickness() {
        return this.getThickness(this.ref);
    }

    public void setStyleId(int styleId) {
        this.setStyleId(this.ref, styleId);
    }

    public int getStyleId() {
        return this.getStyleId(this.ref);
    }

    public void setStyle(DwgObjectRef style) {
        this.setStyle(this.ref, style);
    }

    public DwgObjectRef getStyle() {
        return this.getStyle(this.ref);
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

    private native void setInsPt(long ref, Point3d insPt);

    private native Point3d getInsPt(long ref);

    private native void setScale(long ref, double scale);

    private native double getScale(long ref);

    private native void setRotation(long ref, double rotation);

    private native double getRotation(long ref);

    private native void setWidthFactor(long ref, double widthFactor);

    private native double getWidthFactor(long ref);

    private native void setObliqueAngle(long ref, double obliqueAngle);

    private native double getObliqueAngle(long ref);

    private native void setThickness(long ref, double thickness);

    private native double getThickness(long ref);

    private native void setStyleId(long ref, int styleId);

    private native int getStyleId(long ref);

    private native void setStyle(long ref, DwgObjectRef style);

    private native DwgObjectRef getStyle(long ref);

    private native void setExtrusion(long ref, Vector3d extrusion);

    private native Vector3d getExtrusion(long ref);

    private native long getParent(long ref);
}
