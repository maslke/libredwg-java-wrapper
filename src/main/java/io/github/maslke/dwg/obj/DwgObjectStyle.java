package io.github.maslke.dwg.obj;

public class DwgObjectStyle extends AbstractBaseTableObject {

    public DwgObjectStyle() {
        this.ref = 0;
    }

    public DwgObjectStyle(long ref) {
        this();
        this.ref = ref;
    }

    public int getIsShape() {
        return this.getIsShape(this.ref);
    }

    public void setIsShape(int isShape) {
        this.setIsShape(this.ref, isShape);
    }

    public int getIsVertical() {
        return this.getIsVertical(this.ref);
    }

    public void setIsVertical(int isVertical) {
        this.setIsVertical(this.ref, isVertical);
    }

    public double getTextSize() {
        return this.getTextSize(this.ref);
    }

    public void setTextSize(double textSize) {
        this.setTextSize(this.ref, textSize);
    }

    public double getWidthFactor() {
        return this.getWidthFactor(this.ref);
    }

    public void setWidthFactor(double widthFactor) {
        this.setWidthFactor(this.ref, widthFactor);
    }

    public double getObliqueAngle() {
        return this.getObliqueAngle(this.ref);
    }

    public void setObliqueAngle(double obliqueAngle) {
        this.setObliqueAngle(this.ref, obliqueAngle);
    }

    public int getGeneration() {
        return this.getGeneration(this.ref);
    }

    public void setGeneration(int generation) {
        this.setGeneration(this.ref, generation);
    }

    public double getLastHeight() {
        return this.getLastHeight(this.ref);
    }

    public void setLastHeight(double lastHeight) {
        this.setLastHeight(this.ref, lastHeight);
    }

    public String getFontFile() {
        return this.getFontFile(this.ref);
    }

    public void setFontFile(String fontFile) {
        this.setFontFile(this.ref, fontFile);
    }

    public String getBigFontFile() {
        return this.getBigFontFile(this.ref);
    }

    public void setBigFontFile(String bigFontFile) {
        this.setBigFontFile(this.ref, bigFontFile);
    }

    
    protected native int getFlag(long ref);
    protected native void setFlag(long ref, int flag);
    protected native String getName(long ref);
    protected native void setName(long ref, String name);
    protected native int getUsed(long ref);
    protected native void setUsed(long ref, int used);
    protected native int getIsXrefRef(long ref);
    protected native void setIsXrefRef(long ref, int isXrefRef);
    protected native int getIsXrefResolved(long ref);
    protected native void setIsXrefResolved(long ref, int isXrefResolved);
    protected native int getIsXrefDep(long ref);
    protected native void setIsXrefDep(long ref, int isXrefDep);
    protected native DwgObjectRef getXref(long ref);
    protected native DwgObjectObject getParent(long ref);    
    protected native void setXref(long ref, DwgObjectRef xref);
    protected native int getIsShape(long ref);
    protected native void setIsShape(long ref, int isShape);
    protected native int getIsVertical(long ref);
    protected native void setIsVertical(long ref, int isVertical);
    protected native double getTextSize(long ref);
    protected native void setTextSize(long ref, double textSize);
    protected native double getWidthFactor(long ref);
    protected native void setWidthFactor(long ref, double widthFactor);
    protected native double getObliqueAngle(long ref);
    protected native void setObliqueAngle(long ref, double obliqueAngle);
    protected native int getGeneration(long ref);
    protected native void setGeneration(long ref, int generation);
    protected native double getLastHeight(long ref);
    protected native void setLastHeight(long ref, double lastHeight);
    protected native String getFontFile(long ref);
    protected native void setFontFile(long ref, String fontFile);
    protected native String getBigFontFile(long ref);
    protected native void setBigFontFile(long ref, String bigFontFile);
}
