package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectRef;

public class Text extends Common {

    public Text() {

    }

    public Text(long ref) {
        this();
        this.ref = ref;
    }

    public void setTextValue(String textValue) {
        this.setTextValue(this.ref, textValue);
    }

    public String getTextValue() {
        return this.getTextValue(this.ref);
    }

    public void setRotation(double rotation) {
        this.setRotation(this.ref, rotation);
    }

    public double getRotation() {
        return this.getRotation(this.ref);
    }

    public void setHeight(double height) {
        this.setHeight(this.ref, height);
    }

    public double getHeight() {
        return this.getHeight(this.ref);
    }

    public void setInsPt(Point2d insPt) {
        this.setInsPt(this.ref, insPt);
    }

    public Point2d getInsPt() {
        return this.getInsPt(this.ref);
    }

    public void setAlignmentPt(Point2d alignmentPt) {
        this.setAlignmentPt(this.ref, alignmentPt);
    }

    public Point2d getAlignmentPt() {
        return this.getAlignmentPt(this.ref);
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

    public void setWidthFactor(double widthFactor) {
        this.setWidthFactor(this.ref, widthFactor);
    }

    public double getWidthFactor() {
        return this.getWidthFactor(this.ref);
    }

    public void setElevation(double elevation) {
        this.setElevation(this.ref, elevation);
    }

    public double getElevation() {
        return this.getElevation(this.ref);
    }

    public void setHorizAlignment(int horizAlignment) {
        this.setHorizAlignment(this.ref, horizAlignment);
    }

    public int getHorizAlignment() {
        return this.getHorizAlignment(this.ref);
    }

    public void setVertAlignment(int vertAlignment) {
        this.setVertAlignment(this.ref, vertAlignment);
    }

    public int getVertAlignment() {
        return this.getVertAlignment(this.ref);
    }

    public void setObliqueAngle(double obliqueAngle) {
        this.setObliqueAngle(this.ref, obliqueAngle);
    }

    public double getObliqueAngle() {
        return this.getObliqueAngle(this.ref);
    }

    public void setStyle(DwgObjectRef style) {
        this.setStyle(this.ref, style);
    }

    public DwgObjectRef getStyle() {
        return this.getStyle(this.ref);
    }

    public Parent getParent() {
        return new Parent(this.getParent(this.ref));
    }

    private native void setTextValue(long ref, String textValue);
    private native void setRotation(long ref, double rotation);
    private native void setHeight(long ref, double height);
    private native void setInsPt(long ref, Point2d insPt);
    private native void setAlignmentPt(long ref, Point2d alignmentPt);
    private native void setExtrusion(long ref, Vector3d extrusion);
    private native void setThickness(long ref, double thickness);
    private native void setWidthFactor(long ref, double widthFactor);
    private native void setElevation(long ref, double elevation);
    private native void setHorizAlignment(long ref, int horizAlignment);
    private native void setVertAlignment(long ref, int vertAlignment);
    private native void setObliqueAngle(long ref, double obliqueAngle);
    private native void setStyle(long ref, DwgObjectRef style);
    private native long getParent(long ref);
    private native String getTextValue(long ref);
    private native double getRotation(long ref);
    private native double getHeight(long ref);
    private native double getElevation(long ref);
    private native Point2d getInsPt(long ref);
    private native Point2d getAlignmentPt(long ref);
    private native Vector3d getExtrusion(long ref);
    private native double getObliqueAngle(long ref);
    private native double getThickness(long ref);
    private native double getWidthFactor(long ref);
    private native int getHorizAlignment(long ref);
    private native int getVertAlignment(long ref);
    private native DwgObjectRef getStyle(long ref);
}
