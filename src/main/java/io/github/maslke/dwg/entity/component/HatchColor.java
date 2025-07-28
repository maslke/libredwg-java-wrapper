package io.github.maslke.dwg.entity.component;

import io.github.maslke.dwg.entity.Hatch;
import io.github.maslke.dwg.obj.DwgColor;

public class HatchColor {

    private long ref;

    public HatchColor() {
        super();
    }

    public HatchColor(long ref) {
        this();
        this.ref = ref;
    }

    public void setRef(long ref) {
        this.ref = ref;
    }

    public long getRef() {
        return this.ref;
    }

    public void setShiftValue(double shiftValue) {
        this.setShiftValue(this.ref, shiftValue);
    }

    public double getShiftValue() {
        return this.getShiftValue(this.ref);
    }

    public void setColor(DwgColor color)  {
        this.setColor(this.ref, color);
    }

    public DwgColor getColor() {
        return this.getColor(this.ref);
    }

    public Hatch getParent() {
        return this.getParent(this.ref);
    }

    
    private native Hatch getParent(long ref);
    private native void setShiftValue(long ref, double shiftValue);
    private native double getShiftValue(long ref);
    private native void setColor(long ref, DwgColor color);
    private native DwgColor getColor(long ref);

}