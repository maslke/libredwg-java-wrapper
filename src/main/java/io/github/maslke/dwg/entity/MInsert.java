package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.obj.DwgObjectEntity;

public class MInsert extends Common {
    public MInsert() {
    }

    public MInsert(long ref) {
        this();
    }

    public void setInsPt(Point3d insPt) {
        this.setInsPt(this.ref, insPt);
    }

    public Point3d getInsPt() {
        return this.getInsPt(this.ref);
    }

    public void setRotation(double rotation) {
        this.setRotation(this.ref, rotation);
    }

    public double getRotation() {
        return this.getRotation(this.ref);
    }

    public void setScaleFlag(int scaleFlag) {
        this.setScaleFlag(this.ref, scaleFlag);
    }

    public int getScaleFlag() {
        return this.getScaleFlag(this.ref);
    }

    public void setScale(Point3d scale) {
        this.setScale(this.ref, scale);
    }

    public Point3d getScale() {
        return this.getScale(this.ref);
    }


    public void setExtrusion(Vector3d extrusion) {
        this.setExtrusion(this.ref, extrusion);
    }

    public Vector3d getExtrusion() {
        return this.getExtrusion(this.ref);
    }

    public void setHasAttribs(int hasAttribs) {
        this.setHasAttribs(this.ref, hasAttribs);
    }

    public int getHasAttribs() {
        return this.getHasAttribs(this.ref);
    }

    public void setNumOwned(long numOwned) {
        this.setNumOwned(this.ref, numOwned);
    }

    public long getNumOwned() {
        return this.getNumOwned(this.ref);
    }

    public void setNumCols(int numCols) {
        this.setNumCols(this.ref, numCols);
    }

    public int getNumCols() {
        return this.getNumCols(this.ref);
    }

    public void setNumRows(int numRows) {
        this.setNumRows(this.ref, numRows);
    }

    public int getNumRows() {
        return this.getNumRows(this.ref);
    }

    public void setColSpacing(double colSpacing) {
        this.setColSpacing(this.ref, colSpacing);
    }

    public double getColSpacing() {
        return this.getColSpacing(this.ref);
    }

    public void setRowSpacing(double rowSpacing) {
        this.setRowSpacing(this.ref, rowSpacing);
    }

    public double getRowSpacing() {
        return this.getRowSpacing(this.ref);
    }

    public void setBlockHeader(DwgObjectRef blockHeader) {
        this.setBlockHeader(this.ref, blockHeader);
    }

    public DwgObjectRef getBlockHeader() {
        return this.getBlockHeader(this.ref);
    }

    public void setFirstAttrib(DwgObjectRef firstAttrib) {
        this.setFirstAttrib(this.ref, firstAttrib);
    }

    public DwgObjectRef getFirstAttrib() {
        return this.getFirstAttrib(this.ref);
    }

    public void setLastAttrib(DwgObjectRef lastAttrib) {
        this.setLastAttrib(this.ref, lastAttrib);
    }

    public DwgObjectRef getLastAttrib() {
        return this.getLastAttrib(this.ref);
    }

    public void setSegs(DwgObjectRef segs) {
        this.setSegs(this.ref, segs);
    }

    public DwgObjectRef getSegs() {
        return this.getSegs(this.ref);
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    private native void setInsPt(long ref, Point3d insPt);

    private native Point3d getInsPt(long ref);

    private native void setRotation(long ref, double rotation);

    private native double getRotation(long ref);

    private native void setScaleFlag(long ref, int scaleFlag);

    private native int getScaleFlag(long ref);

    private native void setScale(long ref, Point3d scale);

    private native Point3d getScale(long ref);

    private native void setExtrusion(long ref, Vector3d extrusion);

    private native Vector3d getExtrusion(long ref);

    private native void setHasAttribs(long ref, int hasAttribs);

    private native int getHasAttribs(long ref);

    private native void setNumOwned(long ref, long numOwned);

    private native long getNumOwned(long ref);

    private native void setNumCols(long ref, int numCols);

    private native int getNumCols(long ref);

    private native void setNumRows(long ref, int numRows);

    private native int getNumRows(long ref);

    private native void setColSpacing(long ref, double colSpacing);

    private native double getColSpacing(long ref);

    private native void setRowSpacing(long ref, double rowSpacing);

    private native double getRowSpacing(long ref);

    private native void setBlockHeader(long ref, DwgObjectRef blockHeader);

    private native DwgObjectRef getBlockHeader(long ref);

    private native void setFirstAttrib(long ref, DwgObjectRef firstAttrib);

    private native DwgObjectRef getFirstAttrib(long ref);

    private native void setLastAttrib(long ref, DwgObjectRef lastAttrib);

    private native DwgObjectRef getLastAttrib(long ref);

    private native void setSegs(long ref, DwgObjectRef segs);

    private native DwgObjectRef getSegs(long ref);

    private native long getParent(long ref);
}
