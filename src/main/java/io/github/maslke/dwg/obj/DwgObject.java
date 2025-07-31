package io.github.maslke.dwg.obj;

import io.github.maslke.dwg.Dwg;

public class DwgObject {
    private long ref;

    public DwgObject() {
        this.ref = 0;
    }

    public DwgObject(long ref) {
        this();
        this.ref = ref;
    }

    public long getRef() {
        return this.ref;
    }

    public long getSize() {
        return this.getSize(this.ref);
    }

    public void setSize(long size) {
        this.setSize(this.ref, size);
    }

    public String getAddress() {
        return this.getAddress(this.ref);
    }

    public void setAddress(String address) {
        this.setAddress(this.ref, address);
    }

    public int getType() {
        return this.getType(this.ref);
    }

    public void setType(int type) {
        this.setType(this.ref, type);
    }

    public long getIndex() {
        return this.getIndex(this.ref);
    }

    public void setIndex(long index) {
        this.setIndex(this.ref, index);
    }

    // #TODO: DWG_OBJECT_TYPE

    public DwgHandle getHandle() {
        return this.getHandle(this.ref);
    }

    public Dwg getParent() {
        return this.getParent(this.ref);
    }

    public void setParent(Dwg parent) {
        this.setParent(this.ref, parent);
    }

    public void setName(String name) {
        this.setName(this.ref, name);
    }

    public String getName() {
        return this.getName(this.ref);
    }

    public void setDxfName(String dxfName) {
        this.setDxfName(this.ref, dxfName);
    }

    public String getDxfName() {
        return this.getDxfName(this.ref);
    }

    public DwgObjectEntity getTioEntity() {
        return this.getTioEntity(this.ref);
    }

    public DwgObjectObject getTioObject() {
        return this.getTioObject(this.ref);
    }

    public void setBitSize(long bitsize) {
        this.setBitSize(this.ref, bitsize);
    }

    public long getBitSize() {
        return this.getBitSize(this.ref);
    }

    public void setBitSizePos(long bitSizePos) {
        this.setBitSizePos(this.ref, bitSizePos);
    }

    public long getBitSizePos() {
        return this.getBitSizePos(this.ref);
    }

    public void setHdlPos(long hdlPos) {
        this.setHdlPos(this.ref, hdlPos);
    }

    public long getHdlPos() {
        return this.getHdlPos(this.ref);
    }

    public void setWasBitSizeSet(int wasBitSizeSet) {
        this.setWasBitSizeSet(this.ref, wasBitSizeSet);
    }

    public int getWasBitSizeSet() {
        return this.getWasBitSizeSet(this.ref);
    }

    public void setHasStrings(int hasStrings) {
        this.setHasStrings(this.ref, hasStrings);
    }

    public int getHasStrings() {
        return this.getHasStrings(this.ref);
    }

    public void setStringStreamSize(long stringStreamSize) {
        this.setStringStreamSize(this.ref, stringStreamSize);
    }

    public long getStringStreamSize() {
        return this.getStringStreamSize(this.ref);
    }

    public void setHandleStreamSize(long handleStreamSize) {
        this.setHandleStreamSize(this.ref, handleStreamSize);
    }

    public long getHandleStreamSize() {
        return this.getHandleStreamSize(this.ref);
    }

    public void setCommonSize(long commonSize) {
        this.setCommonSize(this.ref, commonSize);
    }

    public long getCommonSize() {
        return this.getCommonSize(this.ref);
    }

    public void setNumUnknownBits(long numUnknownBits) {
        this.setNumUnknownBits(this.ref, numUnknownBits);
    }

    public long getNumUnknownBits() {
        return this.getNumUnknownBits(this.ref);
    }

    public void setUnknownBits(String unknownBits) {
        this.setUnknownBits(this.ref, unknownBits);
    }

    public String getUnknownBits() {
        return this.getUnknownBits(this.ref);
    }

    public void setNumUnknownRest(long numUnknownRest) {
        this.setNumUnknownRest(this.ref, numUnknownRest);
    }

    public long getNumUnknownRest() {
        return this.getNumUnknownRest(this.ref);
    }

    public void setUnknownRest(String unknownRest) {
        this.setUnknownRest(this.ref, unknownRest);
    }

    public String getUnknownRest() {
        return this.getUnknownRest(this.ref);
    }

    private native long getSize(long ref);
    private native String getAddress(long ref);
    private native int getType(long ref);
    private native long getIndex(long ref);
    private native void setSize(long ref, long size);
    private native void setAddress(long ref, String address);
    private native void setType(long ref, int type);
    private native void setIndex(long ref, long index);
    private native void setName(long ref, String name);
    private native String getName(long ref);
    private native void setDxfName(long ref, String dxfName);
    private native String getDxfName(long ref);
    private native void setBitSize(long ref, long bitsize);
    private native long getBitSize(long ref);
    private native void setBitSizePos(long ref, long bitSizePos);
    private native long getBitSizePos(long ref);
    private native void setHdlPos(long ref, long hdlPos);
    private native long getHdlPos(long ref);
    private native void setWasBitSizeSet(long ref, int wasBitSizeSet);
    private native int getWasBitSizeSet(long ref);
    private native void setHasStrings(long ref, int hasStrings);
    private native int getHasStrings(long ref);
    private native void setStringStreamSize(long ref, long stringStreamSize);
    private native long getStringStreamSize(long ref);
    private native void setHandleStreamSize(long ref, long handleStreamSize);
    private native long getHandleStreamSize(long ref);
    private native void setCommonSize(long ref, long commonSize);
    private native long getCommonSize(long ref);
    private native void setNumUnknownBits(long ref, long numUnknownBits);
    private native long getNumUnknownBits(long ref);
    private native void setUnknownBits(long ref, String unknownBits);
    private native String getUnknownBits(long ref);
    private native void setNumUnknownRest(long ref, long numUnknownRest);
    private native long getNumUnknownRest(long ref);
    private native void setUnknownRest(long ref, String unknownRest);
    private native String getUnknownRest(long ref);
    private native Dwg getParent(long ref);
    private native void setParent(long ref, Dwg parent);
    private native DwgObjectEntity getTioEntity(long ref);
    private native DwgObjectObject getTioObject(long ref);
    private native DwgHandle getHandle(long ref);
}
