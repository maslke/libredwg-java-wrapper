package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Vector3d;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class Point extends Common {
    private double x;
    private double y;
    private double z;
    private Vector3d extrusion;
    private double thickness;

    public Point(long header, double x, double y, double z) {
        this.header = header;
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public void setX(double x) {
        this.x = x;
        if (this.ref > 0) {
            setXNative(this.ref, this.x);
        }
    }

    public void setY(double y) {
        this.y = y;
        if (this.ref > 0) {
            setYNative(this.ref, this.y);
        }
    }

    public void setZ(double z) {
        this.z = z;
        if (this.ref > 0) {
            setZNative(this.ref, this.z);
        }
    }

    public void setThickness(double thickness) {
        this.thickness = thickness;
        if (this.ref > 0) {
            setThicknessNative(this.ref, this.thickness);
        }
    }

    public void setExtrusion(Vector3d extrusion) {
        if (extrusion == null) {
            return;
        }
        this.extrusion = extrusion;
        if (this.ref > 0) {
            setExtrusionNative(this.ref, this.extrusion.getX(), this.extrusion.getY(), this.extrusion.getZ());
        }
    }

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }

    public native void setXNative(long ref, double x);

    public native void setYNative(long ref, double y);

    public native void setZNative(long ref, double z);

    public native void setThicknessNative(long ref, double thickness);

    public native void setExtrusionNative(long ref, double x, double y, double z);

    private native long getParentNative(long ref);

    protected native double getXNative(long ref);

    protected native double getYNative(long ref);

    protected native double getZNative(long ref);

    protected native Vector3d getExtrusionNative(long ref);

    protected native double getThicknessNative(long ref);
}
