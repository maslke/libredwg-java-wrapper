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
    private Vector2d imageSize;
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
    

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }


    private native void setClassVersionNative(long ref, long classVersion);
    private native void setPt0Native(long ref, double x, double y, double z);
    private native void setUVecNative(long ref, double x, double y, double z);
    private native void setVVecNative(long ref, double x, double y, double z);
    private native void setImageSizeNative(long ref, double width, double height);
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
    private native Vector2d getImageSizeNative(long ref);
    private native int getDisplayPropsNative(long ref);
    private native int getClippingNative(long ref);
    private native int getBrightnessNative(long ref);
    private native int getContrastNative(long ref);
    private native int getFadeNative(long ref);
    private native int getClipModeNative(long ref);
    private native int getClipBoundaryTypeNative(long ref);
    private native long getParentNative(long ref);
}
