package io.github.maslke.dwg.entity.component;

import io.github.maslke.dwg.entity.Hatch;
import io.github.maslke.dwg.obj.DwgObjectRef;
import java.util.List;

public class HatchPath {

    private long ref;

    public HatchPath() {
        super();
    }

    public HatchPath(long ref) {
        this();
        this.ref = ref;
    }

    public void setFlag(long flag) {
        this.setFlag(this.ref, flag);
    }

    public long getFlag() {
        return this.getFlag(this.ref);
    }


    public void setNumSegsOrPaths(int numSegsOrPaths) {
        this.setNumSegsOrPaths(this.ref, numSegsOrPaths);
    }

    public int getNumSegsOrPaths() {
        return this.getNumSegsOrPaths(this.ref);
    }

    // Dwg_HATCH_PathSeg*

    public void setSegs(List<HatchPathSeg> segs) {
        this.setSegs(this.ref, segs);
    }
    public List<HatchPathSeg> getSegs() {
        return this.getSegs(this.ref);
    }


    public void setBulgesPresent(int bulgesPresent) {
        this.setBulgesPresent(this.ref, bulgesPresent);
    }

    public int getBulgesPresent() {
        return this.getBulgesPresent(this.ref);
    }

    public void setClosed(int closed) {
        this.setClosed(this.ref, closed);
    }

    public int getClosed() {
        return this.getClosed(this.ref);
    }

    public void setPolylinePaths(List<HatchPolylinePath> polylinePaths) {
        this.setPolylinePaths(this.ref, polylinePaths);
    }

    public List<HatchPolylinePath> getPolylinePaths() {
        return this.getPolylinePaths(this.ref);
    }


    public void setNumBoundaryHandles(long numBoundaryHandles) {
        this.setNumBoundaryHandles(this.ref, numBoundaryHandles);
    }

    public long getNumBoundaryHandles() {
        return this.getNumBoundaryHandles(this.ref);
    }

    public void setBoundaryHandles(List<DwgObjectRef> boundaryHandles) {
        this.setBoundaryHandles(this.ref, boundaryHandles);
    }

    public List<DwgObjectRef> getBoundaryHandles() {
        return this.getBoundaryHandles(this.ref);
    }


    public Hatch getParent() {
        return this.getParent(this.ref);
    }

    private native Hatch getParent(long ref);
    private native void setFlag(long ref, long flag);
    private native long getFlag(long ref);
    private native void setNumSegsOrPaths(long ref, int numSegsOrPaths);
    private native int getNumSegsOrPaths(long ref);
    private native void setBulgesPresent(long ref, int bulgesPresent);
    private native int getBulgesPresent(long ref);
    private native void setClosed(long ref, int closed);
    private native int getClosed(long ref);
    private native void setNumBoundaryHandles(long ref, long numBoundaryHandles);
    private native long getNumBoundaryHandles(long ref);
    private native void setBoundaryHandles(long ref, List<DwgObjectRef> boundaryHandles);
    private native List<DwgObjectRef> getBoundaryHandles(long ref);
    private native void setPolylinePaths(long ref, List<HatchPolylinePath> polylinePaths);
    private native List<HatchPolylinePath> getPolylinePaths(long ref);
    private native void setSegs(long ref, List<HatchPathSeg> segs);
    private native List<HatchPathSeg> getSegs(long ref);
}
