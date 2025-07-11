package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
public class Circle extends Common {
    private Point3d center;
    private double radius;
    private double thickness;
    private Vector3d extrusion;

    public Circle(Point3d center, double radius) {
        this.center = center;
        this.radius = radius;
    }

    public Circle(long ref, Point3d center, double radius) {
        this(center, radius);
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

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }


    private native void setCenterNative(long ref, double x, double y, double z);
    private native void setRadiusNative(long ref, double radius);

    private native void setThicknessNative(long ref, double thickness);

    private native void setExtrusionNative(long ref, double x, double y, double z);

    private native long getParentNative(long ref);

}
