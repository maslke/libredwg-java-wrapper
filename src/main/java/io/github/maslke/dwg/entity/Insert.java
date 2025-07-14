package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectRef;
import lombok.Getter;
import lombok.Setter;
import io.github.maslke.dwg.common.Point3d;

import java.util.List;

@Getter
@Setter
public class Insert extends Common {
    private Point3d insPt;
    private int scaleFlag;
    private Point3d scale;
    private double rotation;
    private Vector3d extrusion;
    private short hasAttribs;
    private int numOwned;

    private DwgObjectRef blockHeader;
    private DwgObjectRef firstAttrib;
    private DwgObjectRef lastAttrib;
    private DwgObjectRef seqend;
    private List<DwgObjectRef> attribs;

    private int numCols;
    private int numRows;
    private double colSpacing;
    private double rowSpacing;
    private String blockName;


    public void setInsPt(Point3d insPt) {
        if (insPt == null) {
            return;
        }
        this.insPt = insPt;
        this.setInsPtNative(this.ref, this.insPt.getX(), this.insPt.getY(), this.insPt.getZ());
    }

    public void setScaleFlag(int scaleFlag) {
        this.scaleFlag = scaleFlag;
        this.setScaleFlagNative(this.ref, this.scaleFlag);
    }

    public void setScale(Point3d scale) {
        if (scale == null) {
            return;
        }
        this.scale = scale;
        this.setScaleNative(this.ref, this.scale.getX(), this.scale.getY(), this.scale.getZ());
    }

    public void setRotation(double rotation) {
        this.rotation = rotation;
        this.setRotationNative(this.ref, this.rotation);
    }

    public void setExtrusion(Vector3d extrusion) {
        if (extrusion == null) {
            return;
        }
        this.extrusion = extrusion;
        this.setExtrusionNative(this.ref, this.extrusion.getX(), this.extrusion.getY(), this.extrusion.getZ());
    }

    public void setHasAttribs(short hasAttribs) {
        this.hasAttribs = hasAttribs;
        this.setHasAttribsNative(this.ref, this.hasAttribs);
    }

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }


    private native void setInsPtNative(long ref, double x, double y, double z);

    private native void setScaleFlagNative(long ref, int scaleFlag);
    private native void setScaleNative(long ref, double scaleX, double scaleY, double scaleZ);
    private native void setRotationNative(long ref, double rotation);
    private native void setExtrusionNative(long ref, double x, double y, double z);
    private native void setHasAttribsNative(long ref, short hasAttribs);
    private native long getParentNative(long ref);
}
