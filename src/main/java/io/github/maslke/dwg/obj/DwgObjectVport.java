package io.github.maslke.dwg.obj;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector2d;

public class DwgObjectVport {
    private long ref;

    public DwgObjectVport(long ref) {
        this.ref = ref;
    }

    public DwgObjectVport() {
        this.ref = 0;
    }

    public long getRef() {
        return this.ref;
    }

    public void setRef(long ref) {
        this.ref = ref;
    }

    public void setViewCtr(Vector2d viewCtr) {
        this.setViewCtr(this.ref, viewCtr);
    }

    public Vector2d getViewCtr() {
        return this.getViewCtr(this.ref);
    }

    public void setViewSize(double viewSize) {
        this.setViewSize(this.ref, viewSize);
    }

    public double getViewSize() {
        return this.getViewSize(this.ref);
    }

    public void setViewWidth(double viewWidth) {
        this.setViewWidth(this.ref, viewWidth);
    }

    public double getViewWidth() {
        return this.getViewWidth(this.ref);
    }

    public void setAspectRatio(double aspectRatio) {
        this.setAspectRatio(this.ref, aspectRatio);
    }

    public double getAspectRatio() {
        return this.getAspectRatio(this.ref);
    }

    public void setViewTarget(Point3d viewTarget) {
        this.setViewTarget(this.ref, viewTarget);
    }

    public Point3d getViewTarget() {
        return this.getViewTarget(this.ref);
    }

    public void setContrast(double contrast) {
        this.setContrast(this.ref, contrast);
    }

    public double getContrast() {
        return this.getContrast(this.ref);
    }

    public void setBrightness(double brightness) {
        this.setBrightness(this.ref, brightness);
    }

    public double getBrightness() {
        return this.getBrightness(this.ref);
    }

    private native void setViewCtr(long ref, Vector2d viewCtr);
    private native Vector2d getViewCtr(long ref);
    private native double getViewWidth(long ref);
    private native void setViewSize(long ref, double viewSize);
    private native double getViewSize(long ref);
    private native double getAspectRatio(long ref);
    private native void setViewTarget(long ref, Point3d viewTarget);
    private native Point3d getViewTarget(long ref);
    private native void setContrast(long ref, double contrast);
    private native double getContrast(long ref);
    private native void setBrightness(long ref, double brightness);
    private native double getBrightness(long ref);
    private native void setViewWidth(long ref, double viewWidth);
    private native void setAspectRatio(long ref, double aspectRatio);
}
