package io.github.maslke.dwg.entity.component;

import java.util.List;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.entity.MLine;
import io.github.maslke.dwg.common.Vector3d;

public class MLineVertex {
    private long ref;

    public MLineVertex() {
        this.ref = 0;
    }

    public MLineVertex(long ref) {
        this();
        this.ref = ref;
    }

    public void setVertex(Point3d vertex) {
        this.setVertex(this.ref, vertex);
    }

    public Point3d getVertex() {
        return this.getVertex(this.ref);
    }

    public void setVertexDirection(Vector3d vertexDirection) {
        this.setVertexDirection(this.ref, vertexDirection);
    }

    public Vector3d getVertexDirection() {
        return this.getVertexDirection(this.ref);
    }

    public void setMiterDirection(Vector3d miterDirection) {
        this.setMiterDirection(this.ref, miterDirection);
    }

    public Vector3d getMiterDirection() {
        return this.getMiterDirection(this.ref);
    }

    public void setNumLines(long numLines) {
        this.setNumLines(this.ref, numLines);
    }

    public long getNumLines() {
        return this.getNumLines(this.ref);
    }

    public void setLines(List<MLineLine> lines) {
        this.setLines(this.ref, lines);
    }

    public List<MLineLine> getLines() {
        return this.getLines(this.ref);
    }

    public MLine getParent() {
        return new MLine(this.getParent(this.ref));
    }

    private native void setVertex(long ref, Point3d vertex);
    private native Point3d getVertex(long ref);
    private native void setVertexDirection(long ref, Vector3d vertexDirection);
    private native Vector3d getVertexDirection(long ref);
    private native void setMiterDirection(long ref, Vector3d miterDirection);
    private native Vector3d getMiterDirection(long ref);
    private native void setNumLines(long ref, long numLines);
    private native long getNumLines(long ref);
    private native void setLines(long ref, List<MLineLine> lines);
    private native List<MLineLine> getLines(long ref);
    private native long getParent(long ref);
}
