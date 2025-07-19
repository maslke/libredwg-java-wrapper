package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.entity.component.LwpolylineWidth;

import java.util.List;

public class Lwpolyline extends Common {

    public Lwpolyline() {

    }

    public Lwpolyline(long ref) {
        this();
        this.ref = ref;
    }

    public void setFlag(int flag) {
        this.setFlag(this.ref, flag);
    }

    public int getFlag() {
        return this.getFlag(this.ref);
    }

    public void setConstWidth(double constWidth) {
        this.setConstWidth(this.ref, constWidth);
    }

    public double getConstWidth() {
        return this.getConstWidth(this.ref);
    }

    public void setElevation(double elevation) {
        this.setElevation(this.ref, elevation);
    }

    public double getElevation() {
        return this.getElevation(this.ref);
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

    public void setNumPoints(int numPoints) {
        this.setNumPoints(this.ref, numPoints);
    }

    public int getNumPoints() {
        return this.getNumPoints(this.ref);
    }

    public void setPoints(List<Point2d> points) {
        this.setPoints(this.ref, points);
    }

    public List<Point2d> getPoints() {
        return this.getPoints(this.ref);
    }

    public void setNumBulges(int numBulges) {
        this.setNumBulges(this.ref, numBulges);
    }

    public int getNumBulges() {
        return this.getNumBulges(this.ref);
    }

    public void setBulges(List<Double> bulges) {
        this.setBulges(this.ref, bulges);
    }

    public List<Double> getBulges() {
        return this.getBulges(this.ref);
    }

    public void setNumVertexids(int numVertexids) {
        this.setNumVertexids(this.ref, numVertexids);
    }

    public int getNumVertexids() {
        return this.getNumVertexids(this.ref);
    }

    public void setVertexids(List<Integer> vertexids) {
        this.setVertexids(this.ref, vertexids);
    }

    public List<Integer> getVertexids() {
        return this.getVertexids(this.ref);
    }

    public void setNumWidths(int numWidths) {
        this.setNumWidths(this.ref, numWidths);
    }

    public int getNumWidths() {
        return this.getNumWidths(this.ref);
    }

    public void setWidths(List<LwpolylineWidth> widths) {
        this.setWidths(this.ref, widths);
    }

    public List<LwpolylineWidth> getWidths() {
        return this.getWidths(this.ref);
    }

    public Parent getParent() {
        return new Parent(this.getParent(this.ref));
    }

    private native void setFlag(long ref, int flag);
    private native void setConstWidth(long ref, double constWidth);
    private native void setElevation(long ref, double elevation);
    private native void setThickness(long ref, double thickness);
    private native void setExtrusion(long ref, Vector3d extrusion);
    private native void setNumPoints(long ref, int numPoints);
    private native void setPoints(long ref, List<Point2d> points);
    private native void setNumBulges(long ref, int numBulges);
    private native void setBulges(long ref, List<Double> bulges);
    private native void setNumVertexids(long ref, int numVertexids);
    private native void setVertexids(long ref, List<Integer> vertexids);
    private native void setNumWidths(long ref, int numWidths);
    private native void setWidths(long ref, List<LwpolylineWidth> widths);
    private native long getParent(long ref);
    private native int getFlag(long ref);
    private native double getConstWidth(long ref);
    private native double getElevation(long ref);
    private native double getThickness(long ref);
    private native Vector3d getExtrusion(long ref);
    private native int getNumPoints(long ref);
    private native List<Point2d> getPoints(long ref);
    private native int getNumBulges(long ref);
    private native List<Double> getBulges(long ref);
    private native int getNumVertexids(long ref);
    private native List<Integer> getVertexids(long ref);
    private native int getNumWidths(long ref);
    private native List<LwpolylineWidth> getWidths(long ref);
}
