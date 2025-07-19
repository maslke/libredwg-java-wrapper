package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.entity.component.LwpolylineWidth;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.AllArgsConstructor;

import java.util.List;

@Getter
@AllArgsConstructor
@NoArgsConstructor
public class Lwpolyline extends Common {

    private int flag;
    private double constWidth;
    private double elevation;
    private double thickness;
    private Vector3d extrusion = new Vector3d(0, 0, 1);
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
        if (this.ref > 0) {
            this.setFlagNative(this.ref, this.flag);
        }
    }

    public void setConstWidth(double constWidth) {
        this.constWidth = constWidth;
        if (this.ref > 0) {
            this.setConstWidthNative(this.ref, this.constWidth);
        }

    }

    public void setElevation(double elevation) {
        this.elevation = elevation;
        if (this.ref > 0) {
            this.setElevationNative(this.ref, this.elevation);
        }
    }

    public void setThickness(double thickness) {
        this.thickness = thickness;
        if (this.ref > 0) {
            this.setThicknessNative(this.ref, this.thickness);
        }
    }

    public void setExtrusion(Vector3d extrusion) {
        if (extrusion == null) {
            return;
        }
        this.extrusion = extrusion;
        if (this.ref > 0) {
            this.setExtrusionNative(this.ref, this.extrusion.getX(), this.extrusion.getY(), this.extrusion.getZ());
        }
    }

    public void setNumPoints(int numPoints) {
        this.numPoints = numPoints;
        if (this.ref > 0) {
            this.setNumPointsNative(this.ref, this.numPoints);
        }
    }

    public void setPoints(List<Point2d> points) {
        this.points = points;
        if (this.points != null) {
            this.numPoints = this.points.size();
            this.numVertexids = this.points.size();
        }
        if (this.ref > 0) {
            this.setPointsNative(this.ref, this.points);
        }
    }

    public void setNumBulges(int numBulges) {
        this.numBulges = numBulges;
        if (this.ref > 0) {
            this.setNumBulgesNative(this.ref, this.numBulges);
        }
    }

    public void setBulges(List<Integer> bulges) {
        this.bulges = bulges;
        if (this.ref > 0) {
            this.setBulgesNative(this.ref, this.bulges);
        }
    }

    public void setNumVertexids(int numVertexids) {
        this.numVertexids = numVertexids;
        if (this.ref > 0) {
            this.setNumVertexidsNative(this.ref, this.numVertexids);
        }
    }


    public void setVertexids(List<Integer> vertexids) {
        this.vertexids = vertexids;
        if (this.ref > 0) {
            this.setVertexidsNative(this.ref, this.vertexids);
        }
    }

    public void setWidths(List<LwpolylineWidth> widths) {
        this.widths = widths;
        if (this.ref > 0) {
            this.setWidthsNative(this.ref, this.widths);
        }
    }


    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }


    private native void setFlagNative(long ref, int flag);

    protected native int getFlagNative(long ref);
    private native void setConstWidthNative(long ref, double constWidth);

    protected native double getConstWidthNative(long ref);

    private native void setElevationNative(long ref, double elevation);

    protected native double getElevationNative(long ref);

    private native void setThicknessNative(long ref, double thickness);

    protected native double getThicknessNative(long ref);

    private native void setExtrusionNative(long ref, double x, double y, double z);

    protected native Vector3d getExtrusionNative(long ref);

    private native void setNumPointsNative(long ref, int numPoints);

    protected native int getNumPointsNative(long ref);

    private native void setPointsNative(long ref, List<Point2d> points);

    protected native List<Point2d> getPointsNative(long ref);

    private native void setNumBulgesNative(long ref, int numBulges);

    protected native int getNumBulgesNative(long ref);

    private native void setBulgesNative(long ref, List<Integer> bulges);

    protected native List<Integer> getBulgesNative(long ref);

    private native void setNumVertexidsNative(long ref, int numVertexids);


    protected native int getNumVertexidsNative(long ref);

    private native void setVertexidsNative(long ref, List<Integer> vertexids);

    protected native List<Integer> getVertexidsNative(long ref);

    private native void setNumWidthsNative(long ref, int numWidths);

    protected native int getNumWidthsNative(long ref);

    private native void setWidthsNative(long ref, List<LwpolylineWidth> widths);

    protected native List<LwpolylineWidth> getWidthsNative(long ref);

    private native long getParentNative(long ref);
}
