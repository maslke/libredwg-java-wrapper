package io.github.maslke.dwg.entity;

import lombok.NoArgsConstructor;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;

public class Ray extends Common {

    public Ray() {
    }

    public Ray(long ref) {
        this();
        this.ref = ref;
    }


    public void setPoint(Point3d point) {
        this.setPoint(this.ref, point);
    }

    public Point3d getPoint() {
        return this.getPoint(this.ref);
    }

    public void setVector(Vector3d vector) {
        this.setVector(this.ref, vector);
    }

    public Vector3d getVector() {
        return this.getVector(this.ref);
    }


    public Parent getParent() {
        return new Parent(this.getParent(this.ref));
    }

    private native void setPoint(long ref, Point3d point);
    private native void setVector(long ref, Vector3d vector);
    private native long getParent(long ref);
    private native Point3d getPoint(long ref);
    private native Vector3d getVector(long ref);
}
