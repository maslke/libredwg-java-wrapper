package io.github.maslke.dwg.entity.component;

import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Vector2d;
import java.util.List;

public class HatchPathSeg {
    private long ref;
    
    public HatchPathSeg() {
        super();
    }

    public HatchPathSeg(long ref) {
        this();
        this.ref = ref;
    }

    public void setCurveType(int curveType) {
        this.setCurveType(this.ref, curveType);
    }

    public int getCurveType() {
        return this.getCurveType(this.ref);
    }

    public void setFirstEndPoint(Point2d firstEndPoint) {
        this.setFirstEndPoint(this.ref, firstEndPoint);
    }

    public Point2d getFirstEndPoint() {
        return this.getFirstEndPoint(this.ref);
    }

    public void setSecondEndPoint(Point2d secondEndPoint) {
        this.setSecondEndPoint(this.ref, secondEndPoint);
    }

    public Point2d getSecondEndPoint() {
        return this.getSecondEndPoint(this.ref);
    }

    public void setCenterPoint(Point2d centerPoint) {
        this.setCenterPoint(this.ref, centerPoint);
    }

    public Point2d getCenterPoint() {
        return this.getCenterPoint(this.ref);
    }

    public void setRadius(double radius) {
        this.setRadius(this.ref, radius);
    }

    public double getRadius() {
        return this.getRadius(this.ref);
    }

    public void setStartAngle(double startAngle) {
        this.setStartAngle(this.ref, startAngle);
    }

    public double getStartAngle() {
        return this.getStartAngle(this.ref);
    }

    public void setEndAngle(double endAngle) {
        this.setEndAngle(this.ref, endAngle);
    }

    public double getEndAngle() {
        return this.getEndAngle(this.ref);
    }

    public void setIsCcw(int isCcw) {
        this.setIsCcw(this.ref, isCcw);
    }

    public int getIsCcw() {
        return this.getIsCcw(this.ref);
    }

    public void setEndPoint(Point2d endPoint) {
        this.setEndPoint(this.ref, endPoint);
    }

    public Point2d getEndPoint() {
        return this.getEndPoint(this.ref);
    }

    public void setMinorMajorRatio(double minorMajorRatio) {
        this.setMinorMajorRatio(this.ref, minorMajorRatio);
    }

    public double getMinorMajorRatio() {
        return this.getMinorMajorRatio(this.ref);
    }

    public void setDegree(long degree) {
        this.setDegree(this.ref, degree);
    }

    public long getDegree() {
        return this.getDegree(this.ref);
    }

    public void setIsRational(int isRational) {
        this.setIsRational(this.ref, isRational);
    }

    public int getIsRational() {
        return this.getIsRational(this.ref);
    }

    public void setIsPeriodic(int isPeriodic) {
        this.setIsPeriodic(this.ref, isPeriodic);
    }

    public int getIsPeriodic() {
        return this.getIsPeriodic(this.ref);
    }

    public void setNumKnots(long numKnots) {
        this.setNumKnots(this.ref, numKnots);
    }

    public long getNumKnots() {
        return this.getNumKnots(this.ref);
    }

    public void setNumControlPoints(long numControlPoints) {
        this.setNumControlPoints(this.ref, numControlPoints);
    }

    public long getNumControlPoints() {
        return this.getNumControlPoints(this.ref);
    }

    public void setKnots(List<Double> knots) {
        this.setKnots(this.ref, knots);
    }

    public List<Double> getKnots() {
        return this.getKnots(this.ref);
    }

    //Dwg_HATCH_ControlPoint*


    public void setNumFitPts(long numFitPts) {
        this.setNumFitPts(this.ref, numFitPts);
    }

    public long getNumFitPts() {
        return this.getNumFitPts(this.ref);
    }

    public void setFitPts(List<Point2d> fitPts) {
        this.setFitPts(this.ref, fitPts);
    }
    public List<Point2d> getFitPts() {
        return this.getFitPts(this.ref);
    }

    public void setStartTangent(Vector2d startTangent) {
        this.setStartTangent(this.ref, startTangent);
    }

    public Vector2d getStartTangent() {
        return this.getStartTangent(this.ref);
    }

    public void setEndTangent(Vector2d endTangent) {
        this.setEndTangent(this.ref, endTangent);
    }

    public Vector2d getEndTangent() {
        return this.getEndTangent(this.ref);
    }

    public HatchPath getParent() {
        return this.getParent(this.ref);
    }

    private native HatchPath getParent(long ref);
    private native void setCurveType(long ref, int curveType);
    private native int getCurveType(long ref);
    private native void setFirstEndPoint(long ref, Point2d firstEndPoint);
    private native Point2d getFirstEndPoint(long ref);
    private native void setSecondEndPoint(long ref, Point2d secondEndPoint);
    private native Point2d getSecondEndPoint(long ref);
    private native void setCenterPoint(long ref, Point2d centerPoint);
    private native Point2d getCenterPoint(long ref);
    private native void setRadius(long ref, double radius);
    private native double getRadius(long ref);
    private native void setStartAngle(long ref, double startAngle);
    private native double getStartAngle(long ref);
    private native void setEndAngle(long ref, double endAngle);
    private native double getEndAngle(long ref);
    private native void setIsCcw(long ref, int isCcw);
    private native int getIsCcw(long ref);
    private native void setEndPoint(long ref, Point2d endPoint);
    private native Point2d getEndPoint(long ref);
    private native void setMinorMajorRatio(long ref, double minorMajorRatio);
    private native double getMinorMajorRatio(long ref);
    private native void setDegree(long ref, long degree);
    private native long getDegree(long ref);
    private native void setIsRational(long ref, int isRational);
    private native int getIsRational(long ref);
    private native void setIsPeriodic(long ref, int isPeriodic);
    private native int getIsPeriodic(long ref);
    private native void setNumKnots(long ref, long numKnots);
    private native long getNumKnots(long ref);
    private native void setNumControlPoints(long ref, long numControlPoints);
    private native long getNumControlPoints(long ref);
    private native void setKnots(long ref, List<Double> knots);
    private native List<Double> getKnots(long ref);
    private native void setNumFitPts(long ref, long numFitPts);
    private native long getNumFitPts(long ref);
    private native void setFitPts(long ref, List<Point2d> fitPts);
    private native List<Point2d> getFitPts(long ref);
    private native void setStartTangent(long ref, Vector2d startTangent);
    private native Vector2d getStartTangent(long ref);
    private native void setEndTangent(long ref, Vector2d endTangent);
    private native Vector2d getEndTangent(long ref);
}