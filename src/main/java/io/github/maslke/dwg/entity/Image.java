package io.github.maslke.dwg.entity;

import java.util.List;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.common.Vector2d;
import io.github.maslke.dwg.obj.DwgObjectEntity;

public class Image extends AbstractBaseEntity {

    public Image() {
    }

    public Image(long ref) {
        this();
        this.ref = ref;
    }

    public void setClassVersion(long classVersion) {
        this.setClassVersion(this.ref, classVersion);
    }

    public long getClassVersion() {
        return this.getClassVersion(this.ref);
    }

    public void setPt0(Point3d pt0) {
        this.setPt0(this.ref, pt0);
    }

    public Point3d getPt0() {
        return this.getPt0(this.ref);
    }

    public void setUVec(Vector3d uVec) {
        this.setUVec(this.ref, uVec);
    }

    public Vector3d getUVec() {
        return this.getUVec(this.ref);
    }

    public void setVVec(Vector3d vVec) {
        this.setVVec(this.ref, vVec);
    }

    public Vector3d getVVec() {
        return this.getVVec(this.ref);
    }

    public void setSize(Vector2d size) {
        this.setSize(this.ref, size);
    }

    public Vector2d getSize() {
        return this.getSize(this.ref);
    }

    public void setDisplayProps(int displayProps) {
        this.setDisplayProps(this.ref, displayProps);
    }

    public int getDisplayProps() {
        return this.getDisplayProps(this.ref);
    }

    public void setClipping(int clipping) {
        this.setClipping(this.ref, clipping);
    }

    public int getClipping() {
        return this.getClipping(this.ref);
    }

    public void setBrightness(int brightness) {
        this.setBrightness(this.ref, brightness);
    }

    public int getBrightness() {
        return this.getBrightness(this.ref);
    }

    public void setContrast(int contrast) {
        this.setContrast(this.ref, contrast);
    }

    public int getContrast() {
        return this.getContrast(this.ref);
    }

    public void setFade(int fade) {
        this.setFade(this.ref, fade);
    }

    public int getFade() {
        return this.getFade(this.ref);
    }

    public void setClipMode(int clipMode) {
        this.setClipMode(this.ref, clipMode);
    }

    public int getClipMode() {
        return this.getClipMode(this.ref);
    }

    public void setClipBoundaryType(int clipBoundaryType) {
        this.setClipBoundaryType(this.ref, clipBoundaryType);
    }

    public int getClipBoundaryType() {
        return this.getClipBoundaryType(this.ref);
    }

    public void setNumClipVerts(long numClipVerts) {
        this.setNumClipVerts(this.ref, numClipVerts);
    }

    public long getNumClipVerts() {
        return this.getNumClipVerts(this.ref);
    }

    public void setClipVerts(List<Vector2d> clipVerts) {
        this.setClipVerts(this.ref, clipVerts);
    }

    public List<Vector2d> getClipVerts() {
        return this.getClipVerts(this.ref);
    }

    public void setImageDef(DwgObjectRef imageDef) {
        this.setImageDef(this.ref, imageDef);
    }

    public DwgObjectRef getImageDef() {
        return this.getImageDef(this.ref);
    }

    public void setImageDefReactor(DwgObjectRef imageDefReactor) {
        this.setImageDefReactor(this.ref, imageDefReactor);
    }

    public DwgObjectRef getImageDefReactor() {
        return this.getImageDefReactor(this.ref);
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    private native void setClassVersion(long ref, long classVersion);
    private native long getClassVersion(long ref);
    private native void setPt0(long ref, Point3d pt0);
    private native Point3d getPt0(long ref);
    private native void setUVec(long ref, Vector3d uVec);
    private native Vector3d getUVec(long ref);
    private native void setVVec(long ref, Vector3d vVec);
    private native Vector3d getVVec(long ref);
    private native void setSize(long ref, Vector2d size);
    private native Vector2d getSize(long ref);
    private native void setDisplayProps(long ref, int displayProps);
    private native int getDisplayProps(long ref);
    private native void setClipping(long ref, int clipping);
    private native int getClipping(long ref);
    private native void setBrightness(long ref, int brightness);
    private native int getBrightness(long ref);
    private native void setContrast(long ref, int contrast);
    private native int getContrast(long ref);
    private native void setFade(long ref, int fade);
    private native int getFade(long ref);
    private native void setClipMode(long ref, int clipMode);
    private native int getClipMode(long ref);
    private native void setClipBoundaryType(long ref, int clipBoundaryType);
    private native int getClipBoundaryType(long ref);
    private native void setNumClipVerts(long ref, long numClipVerts);
    private native long getNumClipVerts(long ref);
    private native void setClipVerts(long ref, List<Vector2d> clipVerts);
    private native List<Vector2d> getClipVerts(long ref);
    private native void setImageDef(long ref, DwgObjectRef imageDef);
    private native DwgObjectRef getImageDef(long ref);
    private native void setImageDefReactor(long ref, DwgObjectRef imageDefReactor);
    private native DwgObjectRef getImageDefReactor(long ref);
    private native long getParent(long ref);
}
