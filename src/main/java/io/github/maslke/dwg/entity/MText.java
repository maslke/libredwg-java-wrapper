package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.obj.DwgColor;
import io.github.maslke.dwg.obj.DwgObjectEntity;
import java.util.List;

public class MText extends Common {
    
    public MText() {

    }

    public MText(long ref) {
        this();
        this.ref = ref;
    }

    public void setInsPt(Point3d insPt) {
        this.setInsPt(this.ref, insPt);
    }

    public Point3d getInsPt() {
        return this.getInsPt(this.ref);
    }

    public void setExtrusion(Vector3d extrusion) {
        this.setExtrusion(this.ref, extrusion);
    }

    public Vector3d getExtrusion() {
        return this.getExtrusion(this.ref);
    }

    public void setXAxisDir(Point3d xAxisDir) {
        this.setXAxisDir(this.ref, xAxisDir);
    }

    public Point3d getXAxisDir() {
        return this.getXAxisDir(this.ref);
    }

    public void setRectHeight(double rectHeight) {
        this.setRectHeight(this.ref, rectHeight);
    }

    public double getRectHeight() {
        return this.getRectHeight(this.ref);
    }

    public void setRectWidth(double rectWidth) {
        this.setRectWidth(this.ref, rectWidth);
    }

    public double getRectWidth() {
        return this.getRectWidth(this.ref);
    }

    public void setTextHeight(double textHeight) {
        this.setTextHeight(this.ref, textHeight);
    }

    public double getTextHeight() {
        return this.getTextHeight(this.ref);
    }

    public void setAttachment(int attachment) {
        this.setAttachment(this.ref, attachment);
    }

    public int getAttachment() {
        return this.getAttachment(this.ref);
    }

    public void setFlowDir(int flowDir) {
        this.setFlowDir(this.ref, flowDir);
    }

    public int getFlowDir() {
        return this.getFlowDir(this.ref);
    }

    public void setExtentsWidth(double extentsWidth) {
        this.setExtentsWidth(this.ref, extentsWidth);
    }

    public double getExtentsWidth() {
        return this.getExtentsWidth(this.ref);
    }

    public void setExtentsHeight(double extentsHeight) {
        this.setExtentsHeight(this.ref, extentsHeight);
    }

    public double getExtentsHeight() {
        return this.getExtentsHeight(this.ref);
    }

    public void setText(String text) {
        this.setText(this.ref, text);
    }

    public String getText() {
        return this.getText(this.ref);
    }

    public DwgObjectRef getStyle() {
        return this.getStyle(this.ref);
    }
    
    public void setStyle(DwgObjectRef style) {
        this.setStyle(this.ref, style);
    }

    public void setLinespaceStyle(int linespaceStyle) {
        this.setLinespaceStyle(this.ref, linespaceStyle);
    }

    public int getLinespaceStyle() {
        return this.getLinespaceStyle(this.ref);
    }

    public void setLinespaceFactor(double linespaceFactor) {
        this.setLinespaceFactor(this.ref, linespaceFactor);
    }

    public double getLinespaceFactor() {
        return this.getLinespaceFactor(this.ref);
    }

    public void setUnknownB0(int unknownB0) {
        this.setUnknownB0(this.ref, unknownB0);
    }

    public int getUnknownB0() {
        return this.getUnknownB0(this.ref);
    }

    public void setBgFillFlag(int bgFillFlag) {
        this.setBgFillFlag(this.ref, bgFillFlag);
    }

    public int getBgFillFlag() {
        return this.getBgFillFlag(this.ref);
    }

    public void setBgFillScale(int bgFillScale) {
        this.setBgFillScale(this.ref, bgFillScale);
    }

    public int getBgFillScale() {
        return this.getBgFillScale(this.ref);
    }


    public DwgColor getBgFillColor() {
        return this.getBgFillColor(this.ref);
    }

    public void setBgFillColor(DwgColor bgFillColor) {
        this.setBgFillColor(this.ref, bgFillColor);
    }

    public void setBgFillTrans(int bgFillTrans) {
        this.setBgFillTrans(this.ref, bgFillTrans);
    }

    public int getBgFillTrans() {
        return this.getBgFillTrans(this.ref);
    }

    public void setIsNotAnnotative(int isNotAnnotative) {
        this.setIsNotAnnotative(this.ref, isNotAnnotative);
    }

    public int getIsNotAnnotative() {
        return this.getIsNotAnnotative(this.ref);
    }

    public void setClassVersion(int classVersion) {
        this.setClassVersion(this.ref, classVersion);
    }

    public int getClassVersion() {
        return this.getClassVersion(this.ref);
    }

    public void setDefaultFlag(int defaultFlag) {
        this.setDefaultFlag(this.ref, defaultFlag);
    }

    public int getDefaultFlag() {
        return this.getDefaultFlag(this.ref);
    }

    public void setAppid(DwgObjectRef appid) {
        this.setAppid(this.ref, appid);
    }

    public DwgObjectRef getAppid() {
        return this.getAppid(this.ref);
    }

    public void setIgnoreAttachment(long ignoreAttachment) {
        this.setIgnoreAttachment(this.ref, ignoreAttachment);
    }

    public long getIgnoreAttachment() {
        return this.getIgnoreAttachment(this.ref);
    }

    public void setColumnType(int columnType) {
        this.setColumnType(this.ref, columnType);
    }

    public int getColumnType() {
        return this.getColumnType(this.ref);
    }

    public void setNumFragments(long numFragments) {
        this.setNumFragments(this.ref, numFragments);
    }

    public long getNumFragments() {
        return this.getNumFragments(this.ref);
    }

    public void setColumnWidth(double columnWidth) {
        this.setColumnWidth(this.ref, columnWidth);
    }

    public double getColumnWidth() {
        return this.getColumnWidth(this.ref);
    }

    public void setGutter(double gutter) {
        this.setGutter(this.ref, gutter);
    }

    public double getGutter() {
        return this.getGutter(this.ref);
    }

    public void setAutoHeight(int autoHeight) {
        this.setAutoHeight(this.ref, autoHeight);
    }

    public int getAutoHeight() {
        return this.getAutoHeight(this.ref);
    }

    public void setFlowReversed(int flowReversed) {
        this.setFlowReversed(this.ref, flowReversed);
    }

    public int getFlowReversed() {
        return this.getFlowReversed(this.ref);
    }

    public void setNumColumnHeights(long numColumnHeights) {
        this.setNumColumnHeights(this.ref, numColumnHeights);
    }

    public long getNumColumnHeights() {
        return this.getNumColumnHeights(this.ref);
    }

    public void setColumnHeights(List<Double> columnHeights) {
        this.setColumnHeights(this.ref, columnHeights);
    }

    public List<Double> getColumnHeights() {
        return this.getColumnHeights(this.ref);
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    private native void setInsPt(long ref, Point3d insPt);
    private native void setExtrusion(long ref, Vector3d extrusion);
    private native void setXAxisDir(long ref, Point3d xAxisDir);
    private native void setRectHeight(long ref, double rectHeight);
    private native void setRectWidth(long ref, double rectWidth);
    private native void setTextHeight(long ref, double textHeight);
    private native void setAttachment(long ref, int attachment);
    private native void setFlowDir(long ref, int flowDir);
    private native void setExtentsWidth(long ref, double extentsWidth);
    private native void setExtentsHeight(long ref, double extentsHeight);
    private native void setText(long ref, String text);
    private native void setStyle(long ref, DwgObjectRef style);
    private native void setLinespaceStyle(long ref, int linespaceStyle);
    private native void setLinespaceFactor(long ref, double linespaceFactor);
    private native void setUnknownB0(long ref, int unknownB0);
    private native void setBgFillFlag(long ref, int bgFillFlag);
    private native void setBgFillScale(long ref, int bgFillScale);
    private native void setBgFillTrans(long ref, int bgFillTrans);
    private native void setBgFillColor(long ref, DwgColor bgFillColor);
    private native void setIsNotAnnotative(long ref, int isNotAnnotative);
    private native void setClassVersion(long ref, int classVersion);
    private native void setDefaultFlag(long ref, int defaultFlag);
    private native void setAppid(long ref, DwgObjectRef appid);
    private native void setIgnoreAttachment(long ref, long ignoreAttachment);
    private native void setColumnType(long ref, int columnType);
    private native void setNumFragments(long ref, long numFragments);
    private native void setColumnWidth(long ref, double columnWidth);
    private native void setGutter(long ref, double gutter);
    private native void setAutoHeight(long ref, int autoHeight);
    private native void setFlowReversed(long ref, int flowReversed);
    private native void setNumColumnHeights(long ref, long numColumnHeights);
    private native void setColumnHeights(long ref, List<Double> columnHeights);
    private native long getParent(long ref);
    private native Point3d getInsPt(long ref);
    private native Vector3d getExtrusion(long ref);
    private native Point3d getXAxisDir(long ref);
    private native double getRectHeight(long ref);
    private native double getRectWidth(long ref);
    private native double getTextHeight(long ref);
    private native int getAttachment(long ref);
    private native int getFlowDir(long ref);
    private native double getExtentsWidth(long ref);
    private native double getExtentsHeight(long ref);
    private native String getText(long ref);
    private native DwgObjectRef getStyle(long ref);
    private native int getLinespaceStyle(long ref);
    private native double getLinespaceFactor(long ref);
    private native int getUnknownB0(long ref);
    private native int getBgFillFlag(long ref);
    private native int getBgFillScale(long ref);
    private native int getBgFillTrans(long ref);
    private native DwgColor getBgFillColor(long ref);
    private native int getIsNotAnnotative(long ref);
    private native int getClassVersion(long ref);
    private native int getDefaultFlag(long ref);
    private native DwgObjectRef getAppid(long ref);
    private native long getIgnoreAttachment(long ref);
    private native int getColumnType(long ref);
    private native long getNumFragments(long ref);
    private native double getColumnWidth(long ref);
    private native double getGutter(long ref);
    private native int getAutoHeight(long ref);
    private native int getFlowReversed(long ref);
    private native long getNumColumnHeights(long ref);
    private native List<Double> getColumnHeights(long ref);
}
