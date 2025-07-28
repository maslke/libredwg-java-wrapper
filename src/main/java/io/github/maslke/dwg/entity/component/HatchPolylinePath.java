package io.github.maslke.dwg.entity.component;

import io.github.maslke.dwg.common.Point2d;

public class HatchPolylinePath {

    private long ref;

    public HatchPolylinePath() {
        super();
    }

    public HatchPolylinePath(long ref) {
        this();
        this.ref = ref;
    }

    public void setPoint(Point2d point) {
        this.setPoint(this.ref, point);
    }

    public Point2d getPoint() {
        return this.getPoint(this.ref);
    }

    public void setBulge(double bulge) {
        this.setBulge(this.ref, bulge);
    }
    public double getBulge() {
        return this.getBulge(this.ref);
    }



    public HatchPath getParent() {
        return this.getParent(this.ref);
    }

    private native HatchPath getParent(long ref);
    private native void setPoint(long ref, Point2d point);
    private native Point2d getPoint(long ref);
    private native void setBulge(long ref, double bulge);
    private native double getBulge(long ref);
}
