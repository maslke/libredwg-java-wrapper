package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.entity.component.HatchColor;
import io.github.maslke.dwg.common.Vector3d;
import java.util.List;
import io.github.maslke.dwg.obj.DwgObjectEntity;

public class Hatch extends Common {

    public Hatch() {
        super();
    }

    public Hatch(long ref) {
        this();
        this.ref = ref;
    }

    public void setIsGradientFill(long isGradientFill) {
        this.setIsGradientFill(this.ref, isGradientFill);
    }

    public long getIsGradientFill() {
        return this.getIsGradientFill(this.ref);
    }

    public void setReserved(long reserved) {
        this.setReserved(this.ref, reserved);
    }

    public long getReserved() {
        return this.getReserved(this.ref);
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    public void setGradientAngle(double gradientAngle) {
        this.setGradientAngle(this.ref, gradientAngle);
    }

    public double getGradientAngle() {
        return this.getGradientAngle(this.ref);
    }

    public void setGradientShift(double gradientShift) {
        this.setGradientShift(this.ref, gradientShift);
    }


    public double getGradientShift() {
        return this.getGradientShift(this.ref);
    }

    public void setSingleColorGradient(long singleColorGradient) {
        this.setSingleColorGradient(this.ref, singleColorGradient);
    }

    public long getSingleColorGradient() {
        return this.getSingleColorGradient(this.ref);
    }

    public void setGradientTint(double gradientTint) {
        this.setGradientTint(this.ref, gradientTint);
    }

    public double getGradientTint() {
        return this.getGradientTint(this.ref);
    }

    public void setNumColors(long numColors) {
        this.setNumColors(this.ref, numColors);
    }

    public long getNumColors() {
        return this.getNumColors(this.ref);
    }

    public void setColors(List<HatchColor> colors) {
        this.setColors(this.ref, colors);
    }

    public List<HatchColor> getColors() {
        return this.getColors(this.ref);
    }

    public void setGradientName(String gradientName) {
        this.setGradientName(this.ref, gradientName);
    }

    public String getGradientName() {
        return this.getGradientName(this.ref);
    }

    public void setElevation(double elevation) {
        this.setElevation(this.ref, elevation);
    }

    public double getElevation() {
        return this.getElevation(this.ref);
    }

    public void setExtrusion(Vector3d extrusion) {
        this.setExtrusion(this.ref, extrusion);
    }

    public Vector3d getExtrusion() {
        return this.getExtrusion(this.ref);
    }

    public void setName(String name) {
        this.setName(this.ref, name);
    }

    public String getName() {
        return this.getName(this.ref);
    }

    public void setIsSolidFill(int isSolidFill) {
        this.setIsSolidFill(this.ref, isSolidFill);
    }

    public int getIsSolidFill() {
        return this.getIsSolidFill(this.ref);
    }

    public void setIsAssociative(int isAssociative) {
        this.setIsAssociative(this.ref, isAssociative);
    }

    public int getIsAssociative() {
        return this.getIsAssociative(this.ref);
    }

    public void setNumPaths(long numPaths) {
        this.setNumPaths(this.ref, numPaths);
    }

    public long getNumPaths() {
        return this.getNumPaths(this.ref);
    }
    



    private native long getParent(long ref);
    private native void setIsGradientFill(long ref, long isGradientFill);
    private native long getIsGradientFill(long ref);
    private native void setReserved(long ref, long reserved);
    private native long getReserved(long ref);
    private native void setGradientAngle(long ref, double gradientAngle);
    private native double getGradientAngle(long ref);
    private native void setGradientShift(long ref, double gradientShift);
    private native double getGradientShift(long ref);
    private native void setSingleColorGradient(long ref, long singleColorGradient);
    private native long getSingleColorGradient(long ref);
    private native void setGradientTint(long ref, double gradientTint);
    private native double getGradientTint(long ref);
    private native void setNumColors(long ref, long numColors);
    private native long getNumColors(long ref);
    private native void setColors(long ref, List<HatchColor> colors);
    private native List<HatchColor> getColors(long ref);
    private native void setGradientName(long ref, String gradientName);
    private native String getGradientName(long ref);
    
    private native void setElevation(long ref, double elevation);
    private native double getElevation(long ref);
    private native void setExtrusion(long ref, Vector3d extrusion);
    private native Vector3d getExtrusion(long ref);
    private native void setName(long ref, String name);
    private native String getName(long ref);
    private native void setIsSolidFill(long ref, int isSolidFill);
    private native int getIsSolidFill(long ref);
    private native void setIsAssociative(long ref, int isAssociative);
    private native int getIsAssociative(long ref);
    private native void setNumPaths(long ref, long numPaths);
    private native long getNumPaths(long ref);
}
