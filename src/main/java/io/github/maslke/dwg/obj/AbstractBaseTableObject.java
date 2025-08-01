package io.github.maslke.dwg.obj;

public abstract class AbstractBaseTableObject {
    protected long ref;

    
    public long getRef() {
        return this.ref;
    }

    public void setRef(long ref) {
        this.ref = ref;
    }

    public DwgObjectObject getParent() {
        return this.getParent(this.ref);
    }

    public int getFlag() {
        return this.getFlag(ref);
    }

    public void setFlag(int flag) {
        this.setFlag(this.ref, flag);
    }

    public String getName() {
        return this.getName(ref);
    }

    public void setName(String name) {
        this.setName(this.ref, name);
    }

    public int getUsed() {
        return this.getUsed(ref);
    }

    public void setUsed(int used) {
        this.setUsed(this.ref, used);
    }

    public int getIsXrefRef() {
        return this.getIsXrefRef(ref);
    }

    public void setIsXrefRef(int isXrefRef) {
        this.setIsXrefRef(this.ref, isXrefRef);
    }

    public int getIsXrefResolved() {
        return this.getIsXrefResolved(ref);
    }

    public void setIsXrefResolved(int isXrefResolved) {
        this.setIsXrefResolved(this.ref, isXrefResolved);
    }

    public void setIsXrefDep(int isXrefDep) {
        this.setIsXrefDep(this.ref, isXrefDep);
    }

    public void getIsXrefDep() {
        this.getIsXrefDep(ref);
    }

    
    public DwgObjectRef getXref() {
        return this.getXref(ref);
    }

    public void setXref(DwgObjectRef xref) {
        this.setXref(this.ref, xref);
    }

    protected abstract int getFlag(long ref);
    protected abstract void setFlag(long ref, int flag);
    protected abstract String getName(long ref);
    protected abstract void setName(long ref, String name);
    protected abstract void setUsed(long ref, int used);
    protected abstract int getUsed(long ref);
    protected abstract void setIsXrefRef(long ref, int isXrefRef);
    protected abstract int getIsXrefRef(long ref);
    protected abstract void setIsXrefResolved(long ref, int isXrefResolved);
    protected abstract int getIsXrefResolved(long ref);
    protected abstract void setIsXrefDep(long ref, int isXrefDep);
    protected abstract int getIsXrefDep(long ref);
    protected abstract void setXref(long ref, DwgObjectRef xref);
    protected abstract DwgObjectRef getXref(long ref);
    protected abstract DwgObjectObject getParent(long ref);
}
