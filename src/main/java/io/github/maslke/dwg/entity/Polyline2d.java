package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.obj.DwgObjectEntity;
import io.github.maslke.dwg.common.Vector3d;
import java.util.List;

public class Polyline2d extends Common {
    public Polyline2d() {
        super();
    }

    public Polyline2d(long ref) {
        this();
        this.ref = ref;
    }

    public void setHasVertex(int hasVertex) {
        this.setHasVertex(this.ref, hasVertex);
    }

    public int getHasVertex() {
        return this.getHasVertex(this.ref);
    }

    public void setNumOwned(long numOwned) {
        this.setNumOwned(this.ref, numOwned);
    }

    public long getNumOwned() {
        return this.getNumOwned(this.ref);
    }

    public void setFirstVertex(DwgObjectRef firstVertex) {
        this.setFirstVertex(this.ref, firstVertex);
    }

    public DwgObjectRef getFirstVertex() {
        return this.getFirstVertex(this.ref);
    }

    public void setLastVertex(DwgObjectRef lastVertex) {
        this.setLastVertex(this.ref, lastVertex);
    }

    public DwgObjectRef getLastVertex() {
        return this.getLastVertex(this.ref);
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    public void setVertex(List<DwgObjectRef> vertex) {
        this.setVertex(this.ref, vertex);
    }

    public List<DwgObjectRef> getVertex() {
        return this.getVertex(this.ref);
    }

    public void setSeqend(DwgObjectRef seqend) {
        this.setSeqend(this.ref, seqend);
    }

    public DwgObjectRef getSeqend() {
        return this.getSeqend(this.ref);
    }

    public void setFlag(int flag) {
        this.setFlag(this.ref, flag);
    }

    public int getFlag() {
        return this.getFlag(this.ref);
    }

    public void setCurveType(int curveType) {
        this.setCurveType(this.ref, curveType);
    }

    public int getCurveType() {
        return this.getCurveType(this.ref);
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

    public void setExtrusion(Vector3d extrusion) {
        this.setExtrusion(this.ref, extrusion);
    }

    public Vector3d getExtrusion() {
        return this.getExtrusion(this.ref);
    }

    public void setExtraR11Size(long extraR11Size) {
        this.setExtraR11Size(this.ref, extraR11Size);
    }

    public long getExtraR11Size() {
        return this.getExtraR11Size(this.ref);
    }

    public void setExtraR11Text(String extraR11Text) {
        this.setExtraR11Text(this.ref, extraR11Text);
    }

    public String getExtraR11Text() {
        return this.getExtraR11Text(this.ref);
    }

    public void setNumMVerts(int numMVerts) {
        this.setNumMVerts(this.ref, numMVerts);
    }

    public int getNumMVerts() {
        return this.getNumMVerts(this.ref);
    }

    public void setNumNVerts(int numNVerts) {
        this.setNumNVerts(this.ref, numNVerts);
    }

    public int getNumNVerts() {
        return this.getNumNVerts(this.ref);
    }


    public boolean isClosed() {
        return this.getFlag() == 1;
    }

    private native long getParent(long ref);
    private native void setHasVertex(long ref, int hasVertex);
    private native int getHasVertex(long ref);
    private native void setNumOwned(long ref, long numOwned);
    private native long getNumOwned(long ref);
    private native void setFirstVertex(long ref, DwgObjectRef firstVertex);
    private native DwgObjectRef getFirstVertex(long ref);
    private native void setLastVertex(long ref, DwgObjectRef lastVertex);
    private native DwgObjectRef getLastVertex(long ref);
    private native void setVertex(long ref, List<DwgObjectRef> vertex);
    private native List<DwgObjectRef> getVertex(long ref);
    private native void setSeqend(long ref, DwgObjectRef seqend);
    private native DwgObjectRef getSeqend(long ref);
    private native void setFlag(long ref, int flag);
    private native int getFlag(long ref);
    private native void setCurveType(long ref, int curveType);
    private native int getCurveType(long ref);
    private native void setStartWidth(long ref, double startWidth);
    private native double getStartWidth(long ref);
    private native void setEndWidth(long ref, double endWidth);
    private native double getEndWidth(long ref);
    private native void setThickness(long ref, double thickness);
    private native double getThickness(long ref);
    private native void setElevation(long ref, double elevation);
    private native double getElevation(long ref);
    private native void setExtrusion(long ref, Vector3d extrusion);
    private native Vector3d getExtrusion(long ref);
    private native void setExtraR11Size(long ref, long extraR11Size);
    private native long getExtraR11Size(long ref);
    private native void setExtraR11Text(long ref, String extraR11Text);
    private native String getExtraR11Text(long ref);
    private native void setNumMVerts(long ref, int numMVerts);
    private native int getNumMVerts(long ref);
    private native void setNumNVerts(long ref, int numNVerts);
    private native int getNumNVerts(long ref);
}
