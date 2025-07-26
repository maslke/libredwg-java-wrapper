package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.common.Vector3d;
import java.util.List;

public class PolylinePface extends Common {
    public PolylinePface() {
        super();
    }

    public PolylinePface(long ref) {
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

    public Parent getParent() {
        return new Parent(this.getParent(this.ref));
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

   public void setNumVerts(int numVerts) {
    this.setNumVerts(this.ref, numVerts);
   }
   public int getNumVerts() {
    return this.getNumVerts(this.ref);
   }
   
   public void setNumFaces(int numFaces) {
    this.setNumFaces(this.ref, numFaces);
   }
   public int getNumFaces() {
    return this.getNumFaces(this.ref);
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
    private native void setNumVerts(long ref, int numVerts);
    private native int getNumVerts(long ref);
    private native void setNumFaces(long ref, int numFaces);
    private native int getNumFaces(long ref);
}
