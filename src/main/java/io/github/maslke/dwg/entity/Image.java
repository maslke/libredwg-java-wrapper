package io.github.maslke.dwg.entity;

import java.util.List;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.common.Vector2d;
import lombok.Getter;
import lombok.Setter;
import lombok.NoArgsConstructor;


@Getter
@Setter
@NoArgsConstructor
public class Image extends Common {

    private long classVersion;
    private Point3d pt0;
    private Vector3d uVec;
    private Vector3d vVec;
    private Vector2d size;
    private int displayProps;
    private int clipping;
    private int brightness;
    private int contrast;
    private int fade;
    private int clipMode;
    private int clipBoundaryType;
    private long numClipVerts;
    private List<Vector2d> clipVerts;
    private DwgObjectRef imageDef;
    private DwgObjectRef imageDefReactor;

    public Image(long header) {
        this.header = header;
    }

    public void setClassVersion(long classVersion) {
        this.classVersion = classVersion;
        if (this.ref > 0) {
            this.setClassVersionNative(this.ref, this.classVersion);
        }
    }

    public void setPt0(Point3d pt0) {
        if (pt0 == null) {
            return;
        }
        this.pt0 = pt0;
        if (this.ref > 0) {
            this.setPt0Native(this.ref, this.pt0.getX(), this.pt0.getY(), this.pt0.getZ());
        }
    }

    public void setVVec(Vector3d vVec) {
        if (vVec == null) {
            return;
        }
        this.vVec = vVec;
        if (this.ref > 0) {
            this.setVVecNative(this.ref, this.vVec.getX(), this.vVec.getY(), this.vVec.getZ());
        }
    }

    public void setSize(Vector2d size) {
        if (size == null) {
            return;
        }
        this.size = size;
        if (this.ref > 0) {
            this.setSizeNative(this.ref, this.size.getX(), this.size.getY());
        }
    }

    public void setDisplayProps(int displayProps) {
        this.displayProps = displayProps;
        if (this.ref > 0) {
            this.setDisplayPropsNative(this.ref, this.displayProps);
        }
    }

    public void setClipping(int clipping) {
        this.clipping = clipping;
        if (this.ref > 0) {
            this.setClippingNative(this.ref, this.clipping);
        }
    }

    public void setBrightness(int brightness) {
        this.brightness = brightness;
        if (this.ref > 0) {
            this.setBrightnessNative(this.ref, this.brightness);
        }
    }

    public void setContrast(int contrast) {
        this.contrast = contrast;
        if (this.ref > 0) {
            this.setContrastNative(this.ref, this.contrast);
        }
    }

    public void setFade(int fade) {
        this.fade = fade;
        if (this.ref > 0) {
            this.setFadeNative(this.ref, this.fade);
        }
    }

    public void setClipMode(int clipMode) {
        this.clipMode = clipMode;
        if (this.ref > 0) {
            this.setClipModeNative(this.ref, this.clipMode);
        }
    }

    public void setClipBoundaryType(int clipBoundaryType) {
        this.clipBoundaryType = clipBoundaryType;
        if (this.ref > 0) {
            this.setClipBoundaryTypeNative(this.ref, this.clipBoundaryType);
        }
    }

    public void setNumClipVerts(long numClipVerts) {
        this.numClipVerts = numClipVerts;
        if (this.ref > 0) {
            this.setNumClipVertsNative(this.ref, this.numClipVerts);
        }
    }

    public void setClipVerts(List<Vector2d> clipVerts) {
        this.clipVerts = clipVerts;
        if (this.ref > 0) {
            this.setClipVertsNative(this.ref, this.clipVerts);
        }
    }

    public void setImageDef(DwgObjectRef imageDef) {
        if (imageDef == null) {
            return;
        }
        this.imageDef = imageDef;
        if (this.ref > 0) {
            this.setImageDefNative(this.ref, this.imageDef);
        }
    }

    public void setImageDefReactor(DwgObjectRef imageDefReactor) {
        if (imageDefReactor == null) {
            return;
        }
        this.imageDefReactor = imageDefReactor;
        if (this.ref > 0) {
            this.setImageDefReactorNative(this.ref, this.imageDefReactor);
        }
    }

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }


    private native void setClassVersionNative(long ref, long classVersion);
    private native void setPt0Native(long ref, double x, double y, double z);
    private native void setUVecNative(long ref, double x, double y, double z);
    private native void setVVecNative(long ref, double x, double y, double z);
    private native void setSizeNative(long ref, double width, double height);
    private native void setDisplayPropsNative(long ref, int displayProps);
    private native void setClippingNative(long ref, int clipping);
    private native void setBrightnessNative(long ref, int brightness);
    private native void setContrastNative(long ref, int contrast);
    private native void setFadeNative(long ref, int fade);
    private native void setClipModeNative(long ref, int clipMode);
    private native void setClipBoundaryTypeNative(long ref, int clipBoundaryType);
    private native void setNumClipVertsNative(long ref, long numClipVerts);
    private native void setClipVertsNative(long ref, List<Vector2d> clipVerts);
    private native void setImageDefNative(long ref, DwgObjectRef imageDef);
    private native void setImageDefReactorNative(long ref, DwgObjectRef imageDefReactor);

    private native long getClassVersionNative(long ref);
    private native Point3d getPt0Native(long ref);
    private native Vector3d getUVecNative(long ref);
    private native Vector3d getVVecNative(long ref);
    private native Vector2d getSizeNative(long ref);
    private native int getDisplayPropsNative(long ref);
    private native int getClippingNative(long ref);
    private native int getBrightnessNative(long ref);
    private native int getContrastNative(long ref);
    private native int getFadeNative(long ref);
    private native int getClipModeNative(long ref);
    private native int getClipBoundaryTypeNative(long ref);
    private native long getParentNative(long ref);
}
