package io.github.maslke.dwg.obj;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector2d;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
public class DwgObjectVport {
    private long ref;
    private double viewSize;
    private double viewWidth;
    private double aspectRatio;
    private Vector2d viewCtr;
    private Point3d viewTarget;
    private Point3d viewDir;
    private double viewTwist;
    private double lensLength;
    private double frontClipZ;
    private double backClipZ;
    private short viewMode;
    private short renderMode;
    private short useDefaultLights;
    private short defaultLightingType;
    private double brightness;
    private double contrast;

    public DwgObjectVport(Vector2d viewCtr, double viewSize, double viewWidth, double aspectRatio) {
        this.viewCtr = viewCtr;
        this.viewSize = viewSize;
        this.viewWidth = viewWidth;
        this.aspectRatio = aspectRatio;
    }

    public DwgObjectVport(long ref, Vector2d viewCtr, double viewSize, double viewWidth, double aspectRatio) {
        this(viewCtr, viewSize, viewWidth, aspectRatio);
        this.ref = ref;
    }

    public void setViewCtr(Vector2d viewCtr) {
        if (viewCtr == null) {
            return;
        }
        this.viewCtr = viewCtr;
        this.setViewCtrNative(this.ref, this.viewCtr.getX(), this.viewCtr.getY());
    }

    public void setViewSize(double viewSize) {
        this.viewSize = viewSize;
        this.setViewSizeNative(this.ref, this.viewSize);
    }

    public void setViewWidth(double viewWidth) {
        this.viewWidth = viewWidth;
        this.setViewWidthNative(this.ref, this.viewWidth);
    }

    public void setAspectRatio(double aspectRatio) {
        this.aspectRatio = aspectRatio;
        this.setAspectRatioNative(this.ref, this.aspectRatio);
    }

    public void setViewTarget(Point3d viewTarget) {
        if (viewTarget == null) {
            return;
        }
        this.viewTarget = viewTarget;
        this.setViewTargetNative(this.ref, this.viewTarget.getX(), this.viewTarget.getY(), this.viewTarget.getX());
    }

    public void setContrast(double contrast) {
        this.contrast = contrast;
        this.setContrastNative(this.ref, this.contrast);
    }

    public void setBrightness(double brightness) {
        this.brightness = brightness;
        this.setBrightnessNative(this.ref, this.brightness);
    }

    private native void setViewCtrNative(long ref, double x, double y);

    private native void setViewSizeNative(long ref, double viewSize);
    private native void setViewWidthNative(long ref, double viewWidth);

    private native void setAspectRatioNative(long ref, double aspectRatio);

    private native void setViewTargetNative(long ref, double x, double y, double z);

    private native void setContrastNative(long ref, double contrast);

    private native void setBrightnessNative(long ref, double brightness);

}
