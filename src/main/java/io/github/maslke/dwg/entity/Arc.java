package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class Arc extends Common {
    private Point3d center;
    private double radius;
    private double thickness;
    private Vector3d extrusion;
    private double startAngle;
    private double endAngle;

    public Arc(Point3d center, double radius, double startAngle, double endAngle) {
        this.center = center;
        this.radius = radius;
        this.startAngle = startAngle;
        this.endAngle = endAngle;
    }


    public Arc(long ref, Point3d center, double radius, double startAngle, double endAngle) {
        this(center, radius, startAngle, endAngle);
        this.header =ref;
    }

    public void setCenter(Point3d center) {
        this.center = center;
        this.setCenterNative(this.ref, center.getX(), center.getY(), center.getZ());
    }

    public void setRadius(double radius) {
        this.radius =radius;
        this.setRadiusNative(this.ref, this.radius);
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


    private native void setCenterNative(long ref, double x, double y, double z);
    private native void setRadiusNative(long ref, double radius);

    private native void setThicknessNative(long ref, double thickness);

    private native void setExtrusionNative(long ref, double x, double y, double z);
    private native void setStartAngleNative(long ref, double angle);

    private native void setEndAngleNative(long ref, double angle);

    private native long getParentNative(long ref);

    public native Point3d getCenterNative(long ref);
    public native double getRadiusNative(long ref);
    public native double getThicknessNative(long ref);
    public native Vector3d getExtrusionNative(long ref);
    public native double getStartAngleNative(long ref);
    public native double getEndAngleNative(long ref);
}
