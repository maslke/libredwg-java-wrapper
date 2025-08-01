package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.obj.DwgObjectEntity;

public class MLine extends AbstractBaseEntity {
    public MLine() {
        super();
    }

    public MLine(long ref) {
        this();
        this.ref = ref;
    }


    

    public void setScale(double scale) {
        this.setScale(this.ref, scale);
    }

    public double getScale() {
        return this.getScale(this.ref);
    }

    public void setJustification(int justification) {
        this.setJustification(this.ref, justification);
    }
    
    public int getJustification() {
        return this.getJustification(this.ref);
    }

    public void setBasePoint(Point3d basePoint) {
        this.setBasePoint(this.ref, basePoint);
    }

    public Point3d getBasePoint() {
        return this.getBasePoint(this.ref);
    }

    public void setExtrusion(Vector3d extrusion) {
        this.setExtrusion(this.ref, extrusion);
    }

    public Vector3d getExtrusion() {
        return this.getExtrusion(this.ref);
    }

    public void setFlags(int flags) {
        this.setFlags(this.ref, flags);
    }

    public int getFlags() {
        return this.getFlags(this.ref);
    }

    public void setNumLines(int numLines) {
        this.setNumLines(this.ref, numLines);
    }

    public int getNumLines() {
        return this.getNumLines(this.ref);
    }

    public void setNumVerts(long numVerts) {
        this.setNumVerts(this.ref, numVerts);
    }

    public long getNumVerts() {
        return this.getNumVerts(this.ref);
    }

    public void setMlineStyle(DwgObjectRef mlineStyle) {
        this.setMlineStyle(this.ref, mlineStyle);
    }

    public DwgObjectRef getMlineStyle() {
        return this.getMlineStyle(this.ref);
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }





    private native void setScale(long ref, double scale);
    private native double getScale(long ref);
    private native void setJustification(long ref, int justification);
    private native int getJustification(long ref);
    private native void setBasePoint(long ref, Point3d basePoint);
    private native Point3d getBasePoint(long ref);
    private native void setExtrusion(long ref, Vector3d extrusion);
    private native Vector3d getExtrusion(long ref);
    private native void setFlags(long ref, int flags);
    private native int getFlags(long ref);
    private native void setNumLines(long ref, int numLines);
    private native int getNumLines(long ref);
    private native void setNumVerts(long ref, long numVerts);
    private native long getNumVerts(long ref);
    private native void setMlineStyle(long ref, DwgObjectRef mlineStyle);
    private native DwgObjectRef getMlineStyle(long ref);
    private native long getParent(long ref);

    
}