package io.github.maslke.dwg.obj;

public class DwgObjectLayer extends AbstractBaseTableObject {
    public long ref;

    public DwgObjectLayer() {
        this.ref = 0;
    }
    
    public DwgObjectLayer(long ref) {
        this.ref = ref;
    }

    public long getRef() {
        return this.ref;
    }
    
    public void setRef(long ref) {
        this.ref = ref;
    }

    public int getFlag0() {
        return this.getFlag0(this.ref);
    }

    public void setFlag0(int flag) {
        this.setFlag0(this.ref, flag);
    }

    public int getFrozen(int frozen) {
        return this.getFrozen(this.ref);
    }

    public void setFrozen(int frozen) {
        this.setFrozen(this.ref, frozen);
    }

    public void setOn(int on) {
        this.setOn(this.ref, on);
    }

    public int getOn() {
        return this.getOn(this.ref);
    }

    public int getFrozenInNew() {
        return this.getFrozenInNew(this.ref);
    }

    public void setFrozenInNew(int frozenInNew) {
        this.setFrozenInNew(this.ref, frozenInNew);
    }

    public int getLocked() {
        return this.getLocked(this.ref);
    }

    public void setLocked(int locked) {
        this.setLocked(this.ref, locked);
    }

    public int getPlotFlag() {
        return this.getPlotFlag(this.ref);
    }

    public void setPlotFlag(int plotFlag) {
        this.setPlotFlag(this.ref, plotFlag);
    }

    public double getLinewt() {
        return this.getLinewt(this.ref);
    }

    public void setLinewt(double linewt) {
        this.setLinewt(this.ref, linewt);
    }

    public DwgColor getColor() {
        return this.getColor(this.ref);
    }

    public void setColor(DwgColor color) {
        this.setColor(this.ref, color);
    }

    public DwgObjectRef getPlotStyle() {
        return this.getPlotStyle(this.ref);
    }

    public void setPlotStyle(DwgObjectRef plotStyle) {
        this.setPlotStyle(this.ref, plotStyle);
    }

    public DwgObjectRef getMaterial() {
        return this.getMaterial(this.ref);
    }

    public void setMaterial(DwgObjectRef material) {
        this.setMaterial(this.ref, material);
    }

    public DwgObjectRef getLtype() {
        return this.getLtype(this.ref);
    }

    public void setLtype(DwgObjectRef ltype) {
        this.setLtype(this.ref, ltype);
    }

    public DwgObjectRef getVisualStyle() {
        return this.getVisualStyle(this.ref);
    }

    public void setVisualStyle(DwgObjectRef visualStyle) {
        this.setVisualStyle(this.ref, visualStyle);
    }
    
    protected native int getFlag(long ref);
    protected native void setFlag(long ref, int flag);
    protected native String getName(long ref);
    protected native void setName(long ref, String name);
    protected native void setUsed(long ref, int used);
    protected native int getUsed(long ref);
    protected native void setIsXrefRef(long ref, int isXrefRef);
    protected native int getIsXrefRef(long ref);
    protected native void setIsXrefResolved(long ref, int isXrefResolved);
    protected native int getIsXrefResolved(long ref);
    protected native void setIsXrefDep(long ref, int isXrefDep);
    protected native int getIsXrefDep(long ref);
    protected native void setXref(long ref, DwgObjectRef xref);
    protected native DwgObjectRef getXref(long ref);
    protected native DwgObjectObject getParent(long ref);
    protected native int getFlag0(long ref);
    protected native void setFlag0(long ref, int flag);
    protected native int getFrozen(long ref);
    protected native void setFrozen(long ref, int frozen);
    protected native void setOn(long ref, int on);
    protected native int getOn(long ref);
    protected native int getFrozenInNew(long ref);
    protected native void setFrozenInNew(long ref, int frozenInNew);
    protected native int getLocked(long ref);
    protected native void setLocked(long ref, int locked);
    protected native int getPlotFlag(long ref);
    protected native void setPlotFlag(long ref, int plotFlag);
    protected native double getLinewt(long ref);
    protected native void setLinewt(long ref, double linewt);
    protected native DwgColor getColor(long ref);
    protected native void setColor(long ref, DwgColor color);
    protected native DwgObjectRef getPlotStyle(long ref);
    protected native void setPlotStyle(long ref, DwgObjectRef plotStyle);
    protected native DwgObjectRef getMaterial(long ref);
    protected native void setMaterial(long ref, DwgObjectRef material);
    protected native DwgObjectRef getLtype(long ref);
    protected native void setLtype(long ref, DwgObjectRef ltype);
    protected native DwgObjectRef getVisualStyle(long ref);
    protected native void setVisualStyle(long ref, DwgObjectRef visualStyle);
}
