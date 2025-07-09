package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.AllArgsConstructor;
import io.github.maslke.dwg.common.Vector3d;


@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class Line extends Common {
    private Point3d start;
    private Point3d end;
    private Vector3d extrusion;
    private double thickness;

    public Line(Long header, Point3d start, Point3d end) {
        super();
        this.header = header;
        this.start = start;
        this.end = end;
    }


    public void setStart(Point3d start) {
        this.start = start;
        this.setStartNative(this.ref, start);
    }

    public void setEnd(Point3d end) {
        this.end = end;
        this.setEndNative(this.ref, end);
    }

    public void setExtrusion(Vector3d extrusion) {
        if (extrusion == null) {
            return;
        }
        this.extrusion = extrusion;
        this.setExtrusionNative(this.ref, this.extrusion.getX(), this.extrusion.getY(), this.extrusion.getZ());
    }

    public void setThickness(double thickness) {
        this.thickness = thickness;
        this.setThicknessNative(this.ref, this.thickness);
    }

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }



    public native void setStartNative(long ref, Point3d start);
    public native void setEndNative(long ref, Point3d end);
    public native void setExtrusionNative(long ref, double x, double y, double z);
    public native void setThicknessNative(long ref, double thickness);

    public native long getParentNative(long ref);
}
