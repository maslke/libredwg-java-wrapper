package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.obj.DwgObjectEntity;

import java.util.List;

public class Insert extends AbstractBaseEntity {

    public Insert() {

    }

    public Insert(long ref) {
        this();
        this.ref = ref;
    }

    public void setInsPt(Point3d insPt) {
        this.setInsPt(this.ref, insPt);
    }

    public Point3d getInsPt() {
        return this.getInsPt(this.ref);
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

    public void setRotation(double rotation) {
        this.setRotation(this.ref, rotation);
    }

    public double getRotation() {
        return this.getRotation(this.ref);
    }

    public void setExtrusion(Vector3d extrusion) {
        this.setExtrusion(this.ref, extrusion);
    }

    public Vector3d getExtrusion() {
        return this.getExtrusion(this.ref);
    }

    public void setHasAttribs(short hasAttribs) {
        this.setHasAttribs(this.ref, hasAttribs);
    }

    public short getHasAttribs() {
        return this.getHasAttribs(this.ref);
    }

    public void setNumOwned(int numOwned) {
        this.setNumOwned(this.ref, numOwned);
    }

    public int getNumOwned() {
        return this.getNumOwned(this.ref);
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

    public void setSeqend(DwgObjectRef seqend) {
        this.setSeqend(this.ref, seqend);
    }

    public DwgObjectRef getSeqend() {
        return this.getSeqend(this.ref);
    }

    public void setAttribs(List<DwgObjectRef> attribs) {
        this.setAttribs(this.ref, attribs);
    }

    public List<DwgObjectRef> getAttribs() {
        return this.getAttribs(this.ref);
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

    public void setBlockName(String blockName) {
        this.setBlockName(this.ref, blockName);
    }

    public String getBlockName() {
        return this.getBlockName(this.ref);
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    private native void setInsPt(long ref, Point3d insPt);
    private native void setScaleFlag(long ref, int scaleFlag);
    private native void setScale(long ref, Point3d scale);
    private native void setRotation(long ref, double rotation);
    private native void setExtrusion(long ref, Vector3d extrusion);
    private native void setHasAttribs(long ref, short hasAttribs);
    private native void setNumOwned(long ref, int numOwned);
    private native void setBlockHeader(long ref, DwgObjectRef blockHeader);
    private native void setFirstAttrib(long ref, DwgObjectRef firstAttrib);
    private native void setLastAttrib(long ref, DwgObjectRef lastAttrib);
    private native void setSeqend(long ref, DwgObjectRef seqend);
    private native void setAttribs(long ref, List<DwgObjectRef> attribs);
    private native void setNumCols(long ref, int numCols);
    private native void setNumRows(long ref, int numRows);
    private native void setColSpacing(long ref, double colSpacing);
    private native void setRowSpacing(long ref, double rowSpacing);
    private native void setBlockName(long ref, String blockName);
    private native long getParent(long ref);
    private native Point3d getInsPt(long ref);
    private native int getScaleFlag(long ref);
    private native Point3d getScale(long ref);
    private native double getRotation(long ref);
    private native Vector3d getExtrusion(long ref);
    private native short getHasAttribs(long ref);
    private native int getNumOwned(long ref);
    private native DwgObjectRef getBlockHeader(long ref);
    private native DwgObjectRef getFirstAttrib(long ref);
    private native DwgObjectRef getLastAttrib(long ref);
    private native DwgObjectRef getSeqend(long ref);
    private native List<DwgObjectRef> getAttribs(long ref);
    private native int getNumCols(long ref);
    private native int getNumRows(long ref);
    private native double getColSpacing(long ref);
    private native double getRowSpacing(long ref);
    private native String getBlockName(long ref);
}
