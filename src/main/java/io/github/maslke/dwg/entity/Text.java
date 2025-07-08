package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
public class Text extends Common {
    private String textValue;
    private double height;
    private double rotation;
    private double elevation;
    private Point2d insPt;
    private Point2d alignmentPt;
    private Vector3d extrusion;
    private double thickness;
    private double obliqueAngle;
    private double widthFactor;
    private int horizAlignment;
    private int vertAlignment;
    private Parent parent;

    public Text(long header, String textValue, Point3d insertPoint, double height) {
        this.header = header;
        this.textValue = textValue;
        this.insPt = new Point2d(insertPoint.getX(), insertPoint.getY());
        this.elevation = insertPoint.getZ();
        this.height = height;
    }


    public void setTextValue(String textValue) {
        this.textValue = textValue;
        this.setTextValueNative(this.ref, this.textValue);
    }

    public void setRotation(double rotation) {
        this.rotation = rotation;
        this.setRotationNative(this.ref, this.rotation);
    }

    public void setHeight(double height) {
        this.height = height;
        this.setHeightNative(this.ref, this.height);
    }

    public void setInsPt(Point2d insPt) {
        if (insPt == null) {
            return;
        }
        this.insPt = insPt;
        this.setInsPtNative(this.ref, this.insPt.getX(), this.insPt.getY());
    }

    public void setAlignmentPt(Point2d alignmentPt) {
        if (alignmentPt == null) {
            return;
        }
        this.alignmentPt = alignmentPt;
        this.setAlignmentPtNative(this.ref, this.alignmentPt.getX(), this.alignmentPt.getY());
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

    public void setWidthFactor(double widthFactor) {
        this.widthFactor = widthFactor;
        this.setWidthFactorNative(this.ref, this.widthFactor);
    }

    public void setElevation(double elevation) {
        this.elevation = elevation;
        this.setElevationNative(this.ref, this.elevation);
    }

    public void setHorizAlignment(int horizAlignment) {
        this.horizAlignment = horizAlignment;
        this.setHorizAlignmentNative(this.ref, this.horizAlignment);
    }

    public void setVertAlignment(int vertAlignment) {
        this.vertAlignment = vertAlignment;
        this.setVertAlignmentNative(this.ref, this.vertAlignment);
    }

    public void setObliqueAngle(double obliqueAngle) {
        this.obliqueAngle = obliqueAngle;
        this.setObliqueAngleNative(this.ref, this.obliqueAngle);
    }

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }

    private native void setHeightNative(long ref, double height);

    private native void setRotationNative(long ref, double rotation);

    private native void setTextValueNative(long ref, String text);

    private native void setAlignmentPtNative(long ref, double x, double y);

    private native void setInsPtNative(long ref, double x, double y);

    private native void setExtrusionNative(long ref, double x, double y, double z);

    private native void setThicknessNative(long ref, double thickness);

    private native void setWidthFactorNative(long ref, double widthFactor);

    private native void setElevationNative(long ref, double elevation);

    private native void setHorizAlignmentNative(long ref, int horizAlignment);

    private native void setVertAlignmentNative(long ref, int vertAlignment);

    private native void setObliqueAngleNative(long ref, double obliqueAngle);

    private native long getParentNative(long ref);
}
