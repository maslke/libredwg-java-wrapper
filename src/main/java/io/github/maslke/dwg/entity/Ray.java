package io.github.maslke.dwg.entity;

import lombok.NoArgsConstructor;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import lombok.Getter;
import lombok.NoArgsConstructor;

@Getter
@NoArgsConstructor
public class Ray extends Common {

    private Point3d point;
    private Vector3d vector;

    public Ray(Point3d point, Vector3d vector) {
        this.point = point;
        this.vector = vector;
    }

    public Ray(long ref, Point3d point, Vector3d vector) {
        this(point, vector);
        this.header = ref;
    }


    public void setPoint(Point3d point) {
        this.point = point;
        if (this.ref > 0) {
            this.setPointNative(this.ref, this.point);
        }
    }

    public void setVector(Vector3d vector) {
        this.vector = vector;
        if (this.ref > 0) {
            this.setVectorNative(this.ref, this.vector);
        }
    }

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }

    private native long getParentNative(long ref);

    private native void setPointNative(long ref, Point3d point);
    private native void setVectorNative(long ref, Vector3d vector);

    protected native Point3d getPointNative(long ref);
    protected native Vector3d getVectorNative(long ref);
}
