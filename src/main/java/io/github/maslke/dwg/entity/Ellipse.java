package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class Ellipse extends Common {

    private Point3d center;
    private double majorAxis;
    private Vector3d extrusion;
    private double axisRatio;
    private double startAngle;
    private double endAngle;


    public Ellipse(Point3d center, double majorAxis, double axisRatio) {
        this.center = center;
        this.majorAxis = majorAxis;
        this.axisRatio = axisRatio;
    }

    public Ellipse(long header, Point3d center, double majorAxis, double axisRatio) {
        this(center, majorAxis, axisRatio);
        this.header = header;
    }


    public void setCenter(Point3d center) {
        if (center == null) {
            return;
        }
        this.center = center;
        this.setCenterNative(this.ref, this.center.getX(), this.center.getY(), this.center.getZ());
    }

    public void setMajorAxis(double majorAxis) {
        this.majorAxis = majorAxis;
        this.setMajorAxisNative(this.ref, this.majorAxis);
    }

    public void setExtrusion(Vector3d extrusion) {
        if (extrusion == null) {
            return;
        }
        this.extrusion = extrusion;
        this.setExtrusionNative(this.ref, this.extrusion.getX(), this.extrusion.getY(), this.extrusion.getZ());
    }

    public void setAxisRatio(double axisRatio) {
        this.axisRatio = axisRatio;
        this.setAxisRatioNative(this.ref, this.axisRatio);
    }

    public void setStartAngle(double angle) {
        this.startAngle = angle;
        this.setStartAngleNative(this.ref, this.startAngle);
    }

    public void setEndAngle(double angle) {
        this.endAngle = angle;
        this.setEndAngleNative(this.ref, this.endAngle);
    }

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }

    private native long getParentNative(long ref);

    private native void setCenterNative(long ref, double x, double y, double z);
    private native void setMajorAxisNative(long ref, double majorAxis);
    private native void setExtrusionNative(long ref, double x, double y, double z);
    private native void setAxisRatioNative(long ref, double ratio);
    private native void setStartAngleNative(long ref, double angle);
    private native void setEndAngleNative(long ref, double angle);
}
