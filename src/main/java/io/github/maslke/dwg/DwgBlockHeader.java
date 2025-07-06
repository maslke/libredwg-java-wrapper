package io.github.maslke.dwg;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.entity.Line;
import io.github.maslke.dwg.entity.Point;
import io.github.maslke.dwg.entity.Text;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class DwgBlockHeader {
    private Dwg dwg;
    private long ref;


    public Point addPoint(Point3d point) {
        if (point == null) {
            return null;
        }
        Point pointEntity = new Point(this.ref, point.getX(), point.getY(), point.getZ());
        long reference = this.addPointNative(this.ref, point.getX(), point.getY(), point.getZ());
        pointEntity.setRef(reference);
        return pointEntity;
    }

    public Text addText(String text, Point3d point) {
        return null;
    }

    public Line addLine(Point3d start, Point3d end) {
        if (start == null || end == null) {
            return null;
        }
        Line lineEntity = new Line(this.ref, start, end);
        long reference = this.addLineNative(this.ref, start, end);
        lineEntity.setRef(reference);
        return lineEntity;
    }

    public native long addPointNative(long ref, double x, double y, double z);
    public native long addLineNative(long ref, Point3d start, Point3d end);
}
