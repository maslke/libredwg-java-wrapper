package io.github.maslke.dwg.entity.component;

import java.util.List;

import io.github.maslke.dwg.entity.Common;


public class MLineLine {

    private long ref;

    public MLineLine() {
        this.ref = 0;
    }

    public MLineLine(long ref) {
        this();
        this.ref = ref;
    }

    public long getRef() {
        return this.ref;
    }

    
    public void setNumSegparms(int numSegparms) {
        this.setNumSegparms(this.ref, numSegparms);
    }

    public int getNumSegparms() {
        return this.getNumSegparms(this.ref);
    }

    public void setSegparms(List<Double> segparms) {
        this.setSegparms(this.ref, segparms);
    }

    public List<Double> getSegparms() {
        return this.getSegparms(this.ref);
    }

    public void setNumAreaFillparms(int numAreaFillparms) {
        this.setNumAreaFillparms(this.ref, numAreaFillparms);
    }

    public int getNumAreaFillparms() {
        return this.getNumAreaFillparms(this.ref);
    }

    public void setAreaFillparms(List<Double> areaFillparms) {
        this.setAreaFillparms(this.ref, areaFillparms);
    }

    public List<Double> getAreaFillparms() {
        return this.getAreaFillparms(this.ref);
    }

    public MLineVertex getParent() {
        return new MLineVertex(this.getParent(this.ref));
    }

    private native void setNumSegparms(long ref, int numSegparms);
    private native int getNumSegparms(long ref);
    private native void setSegparms(long ref, List<Double> segparms);
    private native List<Double> getSegparms(long ref);
    private native void setNumAreaFillparms(long ref, int numAreaFillparms);
    private native int getNumAreaFillparms(long ref);
    private native void setAreaFillparms(long ref, List<Double> areaFillparms);
    private native List<Double> getAreaFillparms(long ref);
    private native long getParent(long ref);
}
