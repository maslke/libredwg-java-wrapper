package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Vector3d;
import java.util.List;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.obj.DwgObjectEntity;

public class Spline extends AbstractBaseEntity {
    
    public Spline() {

    }

    public Spline(long ref) {
        this();
        this.ref = ref;
    }

    public int getFlag() {
        return this.getFlag(this.ref);
    }

    public void setFlag(int flag) {
        this.setFlag(this.ref, flag);
    }

    public int getScenario() {
        return this.getScenario(this.ref);
    }

    public void setScenario(int scenario) {
        this.setScenario(this.ref, scenario);
    }

    public int getDegree() {
        return this.getDegree(this.ref);
    }

    public void setDegree(int degree) {
        this.setDegree(this.ref, degree);
    }

    public long getSplineFlags() {
        return this.getSplineFlags(this.ref);
    }

    public void setSplineFlags(long splineFlags) {
        this.setSplineFlags(this.ref, splineFlags);
    }

    public void setKnotParam(long knotParam) {
        this.setKnotParam(this.ref, knotParam);
    }

    public long getKnotParam() {
        return this.getKnotParam(this.ref);
    }

    public void setFitTol(double fitTol) {
        this.setFitTol(this.ref, fitTol);
    }

    public double getFitTol() {
        return this.getFitTol(this.ref);
    }

    public void setBegTanVec(Vector3d begTanVec) {
        this.setBegTanVec(this.ref, begTanVec);
    }

    public Vector3d getBegTanVec() {
        return this.getBegTanVec(this.ref);
    }

    public void setEndTanVec(Vector3d endTanVec) {
        this.setEndTanVec(this.ref, endTanVec);
    }

    public Vector3d getEndTanVec() {
        return this.getEndTanVec(this.ref);
    }

    public void setClosedb(int closedb) {
        this.setClosedb(this.ref, closedb);
    }

    public int getClosedb() {
        return this.getClosedb(this.ref);
    }
    
    public void setPeriodic(int periodic) {
        this.setPeriodic(this.ref, periodic);
    }

    public int getPeriodic() {
        return this.getPeriodic(this.ref);
    }

    public void setRational(int rational) {
        this.setRational(this.ref, rational);
    }

    public int getRational() {
        return this.getRational(this.ref);
    }

    public void setWeighted(int weighted) {
        this.setWeighted(this.ref, weighted);
    }

    public int getWeighted() {
        return this.getWeighted(this.ref);
    }

    public void setKnotTol(double knotTol) {
        this.setKnotTol(this.ref, knotTol);
    }

    public double getKnotTol() {
        return this.getKnotTol(this.ref);
    }

    public void setCtrlTol(double ctrlTol) {
        this.setCtrlTol(this.ref, ctrlTol);
    }

    public double getCtrlTol() {
        return this.getCtrlTol(this.ref);
    }

    public void setNumFitPts(int numFitPts) {
        this.setNumFitPts(this.ref, numFitPts);
    }

    public int getNumFitPts() {
        return this.getNumFitPts(this.ref);
    }

    public void setFitPts(List<Point3d> fitPts) {
        this.setFitPts(this.ref, fitPts);
    }

    public List<Point3d> getFitPts() {
        return this.getFitPts(this.ref);
    }

    public void setNumKnots(long numKnots) {
        this.setNumKnots(this.ref, numKnots);
    }

    public long getNumKnots() {
        return this.getNumKnots(this.ref);
    }

    public void setKnots(List<Double> knots) {
        this.setKnots(this.ref, knots);
    }

    public List<Double> getKnots() {
        return this.getKnots(this.ref);
    }

    public void setNumCtrlPts(long numCtrlPts) {
        this.setNumCtrlPts(this.ref, numCtrlPts);
    }

    public long getNumCtrlPts() {
        return this.getNumCtrlPts(this.ref);
    }

    public void setControlPoints(List<Point3d> ctrlPts) {
        this.setControlPoints(this.ref, ctrlPts);
    }

    public List<Point3d> getControlPoints() {
        return this.getControlPoints(this.ref);
    }



    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    private native int getFlag(long ref);
    private native int getScenario(long ref);
    private native int getDegree(long ref);
    private native long getSplineFlags(long ref);
    private native long getParent(long ref);
    private native long getKnotParam(long ref);
    private native void setKnotParam(long ref, long knotParam);
    private native void setFlag(long ref, int flag);
    private native void setScenario(long ref, int scenario);
    private native void setSplineFlags(long ref, long splineFlags);
    private native void setDegree(long ref, int degree);
    private native void setFitTol(long ref, double fitTol);
    private native double getFitTol(long ref);
    private native void setBegTanVec(long ref, Vector3d begTanVec);
    private native Vector3d getBegTanVec(long ref);
    private native void setEndTanVec(long ref, Vector3d endTanVec);
    private native Vector3d getEndTanVec(long ref);
    private native void setClosedb(long ref, int closedb);
    private native int getClosedb(long ref);
    private native void setPeriodic(long ref, int periodic);
    private native int getPeriodic(long ref);
    private native void setRational(long ref, int rational);
    private native int getRational(long ref);
    private native void setWeighted(long ref, int weighted);
    private native int getWeighted(long ref);
    private native void setKnotTol(long ref, double knotTol);
    private native double getKnotTol(long ref);
    private native void setCtrlTol(long ref, double ctrlTol);
    private native double getCtrlTol(long ref);
    private native void setNumFitPts(long ref, int numFitPts);
    private native int getNumFitPts(long ref);
    private native void setFitPts(long ref, List<Point3d> fitPts);
    private native List<Point3d> getFitPts(long ref);
    private native void setNumKnots(long ref, long numKnots);
    private native long getNumKnots(long ref);
    private native void setKnots(long ref, List<Double> knots);
    private native List<Double> getKnots(long ref);
    private native void setNumCtrlPts(long ref, long numCtrlPts);
    private native long getNumCtrlPts(long ref);
    private native void setControlPoints(long ref, List<Point3d> ctrlPts);
    private native List<Point3d> getControlPoints(long ref);
}
