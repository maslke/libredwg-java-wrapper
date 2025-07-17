package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectRef;
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
    private DwgObjectRef style;
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
        if (this.ref > 0) {
            this.setRotationNative(this.ref, this.rotation);
        }
    }

    public void setHeight(double height) {
        this.height = height;
        if (this.ref > 0) {
            this.setHeightNative(this.ref, this.height);
        }
    }

    public void setInsPt(Point2d insPt) {
        if (insPt == null) {
            return;
        }
        this.insPt = insPt;
        if (this.ref > 0) {
            this.setInsPtNative(this.ref, this.insPt.getX(), this.insPt.getY());
        }
    }

    public void setAlignmentPt(Point2d alignmentPt) {
        if (alignmentPt == null) {
            return;
        }
        this.alignmentPt = alignmentPt;
        if (this.ref > 0) {
            this.setAlignmentPtNative(this.ref, this.alignmentPt.getX(), this.alignmentPt.getY());
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

    public void setThickness(double thickness) {
        this.thickness = thickness;
        if (this.ref > 0) {
            this.setThicknessNative(this.ref, this.thickness);
        }
    }

    public void setWidthFactor(double widthFactor) {
        this.widthFactor = widthFactor;
        if (this.ref > 0) {
            this.setWidthFactorNative(this.ref, this.widthFactor);
        }
    }

    public void setElevation(double elevation) {
        this.elevation = elevation;
        if (this.ref > 0) {
            this.setElevationNative(this.ref, this.elevation);
        }
    }

    public void setHorizAlignment(int horizAlignment) {
        this.horizAlignment = horizAlignment;
        if (this.ref > 0) {
            this.setHorizAlignmentNative(this.ref, this.horizAlignment);
        }
    }

    public void setVertAlignment(int vertAlignment) {
        this.vertAlignment = vertAlignment;
        if (this.ref > 0) {
            this.setVertAlignmentNative(this.ref, this.vertAlignment);
        }
    }

    public void setObliqueAngle(double obliqueAngle) {
        this.obliqueAngle = obliqueAngle;
        if (this.ref > 0) {
            this.setObliqueAngleNative(this.ref, this.obliqueAngle);
        }
    }

    public void setStyle(DwgObjectRef style) {
        if (style == null || style.getRef() == 0) {
            return;
        }
        this.style = style;
        if (this.ref > 0) {
            this.setStyleNative(this.ref, this.style.getRef());
        }
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

    private native void setStyleNative(long ref, long style);

    protected native String getTextValueNative(long ref);

    protected native double getRotationNative(long ref);

    protected native double getHeightNative(long ref);

    protected native double getElevationNative(long ref);

    protected native Point2d getInsPtNative(long ref);

    protected native Point2d getAlignmentPtNative(long ref);

    protected native Vector3d getExtrusionNative(long ref);

    protected native double getObliqueAngleNative(long ref);

    protected native double getThicknessNative(long ref);

    protected native double getWidthFactorNative(long ref);

    protected native int getHorizAlignmentNative(long ref);

    protected native int getVertAlignmentNative(long ref);

    protected native DwgObjectRef getStyleNative(long ref);

}
