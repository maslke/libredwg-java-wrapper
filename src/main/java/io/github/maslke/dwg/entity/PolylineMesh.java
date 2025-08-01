package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.obj.DwgObjectEntity;
import java.util.List;

public class PolylineMesh extends AbstractBaseEntity {
    public PolylineMesh() {
        super();
    }

    public PolylineMesh(long ref) {
        this();
        this.ref = ref;
    }

    public void setHasVertex(int hasVertex) {
        this.setHasVertex(this.ref, hasVertex);
    }

    public int getHasVertex() {
        return this.getHasVertex(this.ref);
    }

    public void setNumVertex(long numVertex) {
        this.setNumVertex(this.ref, numVertex);
    }

    public long getNumVertex() {
        return this.getNumVertex(this.ref);
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

    public void setMDensity(int mDensity) {
        this.setMDensity(this.ref, mDensity);
    }

    public int getMDensity() {
        return this.getMDensity(this.ref);
    }

    public void setNDensity(int nDensity) {
        this.setNDensity(this.ref, nDensity);
    }

    public int getNDensity() {
        return this.getNDensity(this.ref);
    }

    private native long getParent(long ref);
    private native void setHasVertex(long ref, int hasVertex);
    private native int getHasVertex(long ref);
    private native void setNumVertex(long ref, long numVertex);
    private native long getNumVertex(long ref);
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
    private native void setNumMVerts(long ref, int numMVerts);
    private native int getNumMVerts(long ref);
    private native void setNumNVerts(long ref, int numNVerts);
    private native int getNumNVerts(long ref);
    private native void setMDensity(long ref, int mDensity);
    private native int getMDensity(long ref);
    private native void setNDensity(long ref, int nDensity);
    private native int getNDensity(long ref);
}
