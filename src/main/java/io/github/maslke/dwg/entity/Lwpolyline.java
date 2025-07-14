package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.entity.component.LwpolylineWidth;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;

import java.util.List;

@Getter
@Setter
@AllArgsConstructor
public class Lwpolyline extends Common {

    private int flag;
    private double constWidth;
    private double elevation;
    private double thickness;
    private Vector3d extrusion;
    private int numPoints;
    private List<Point2d> points;
    private int numBulges;
    private List<Integer> bulges;
    private int numVertexids;
    private List<Integer> vertexids;
    private int numWidths;
    private List<LwpolylineWidth> widths;


    public void setFlag(int flag) {
        this.flag = flag;
        this.setFlagNative(this.ref, this.flag);
    }

    public void setConstWidth(double constWidth) {
        this.constWidth = constWidth;
        this.setConstWidthNative(this.ref, this.constWidth);
    }

    public void setElevation(double elevation) {
        this.elevation = elevation;
        this.setElevationNative(this.ref, this.elevation);
    }

    public void setThickness(double thickness) {
        this.thickness = thickness;
        this.setThicknessNative(this.ref, this.thickness);
    }

    public void setExtrusion(Vector3d extrusion) {
        if (extrusion == null) {
            return;
        }
        this.extrusion = extrusion;
        this.setExtrusionNative(this.ref, this.extrusion.getX(), this.extrusion.getY(), this.extrusion.getZ());
    }

    public void setNumPoints(int numPoints) {
        this.numPoints = numPoints;
        this.setNumPointsNative(this.ref, this.numPoints);
    }

    public void setPoints(List<Point2d> points) {
        this.points = points;
        this.setPointsNative(this.ref, this.points);
    }

    public void setNumbulges(int numBulges) {
        this.numBulges = numBulges;
        this.setNumBulgesNative(this.ref, this.numBulges);
    }

    public void setBulges(List<Integer> bulges) {
        this.bulges = bulges;
        this.setBulgesNative(this.ref, this.bulges);
    }

    public void setNumVertexids(int numVertexids) {
        this.numVertexids = numVertexids;
        this.setNumVertexidsNative(this.ref, this.numVertexids);
    }

    public void setVertexids(List<Integer> vertexids) {
        this.vertexids = vertexids;
        this.setVertexidsNative(this.ref, this.vertexids);
    }

    public void setNumWidths(int numWidths) {
        this.numWidths = numWidths;
        this.setNumWidthsNative(this.ref, this.numWidths);
    }

    public void setWidths(List<LwpolylineWidth> widths) {
        this.widths = widths;
        this.setWidthsNative(this.ref, this.widths);
    }


    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }


    private native void setFlagNative(long ref, int flag);
    private native void setConstWidthNative(long ref, double constWidth);

    private native void setElevationNative(long ref, double elevation);
    private native void setThicknessNative(long ref, double thickness);

    private native void setExtrusionNative(long ref, double x, double y, double z);

    private native void setNumPointsNative(long ref, int numPoints);

    private native void setPointsNative(long ref, List<Point2d> points);

    private native void setNumBulgesNative(long ref, int numBulges);

    private native void setBulgesNative(long ref, List<Integer> bulges);

    private native void setNumVertexidsNative(long ref, int numVertexids);

    private native void setVertexidsNative(long ref, List<Integer> vertexids);

    private native void setNumWidthsNative(long ref, int numWidths);

    private native void setWidthsNative(long ref, List<LwpolylineWidth> widths);

    private native long getParentNative(long ref);
}
