package io.github.maslke.dwg.obj;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.entity.Arc;
import io.github.maslke.dwg.entity.Circle;
import io.github.maslke.dwg.entity.Ellipse;
import io.github.maslke.dwg.entity.Insert;
import io.github.maslke.dwg.entity.Line;
import io.github.maslke.dwg.entity.Point;
import io.github.maslke.dwg.entity.Text;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class DwgObjectBlockHeader {
    private Dwg dwg;
    private String name;
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

    public Text addText(String textValue, Point3d point, double height)
    {
        if (point == null || textValue == null) {
            return null;
        }
        Text text = new Text(this.ref, textValue, point, height);
        long reference = this.addTextNative(this.ref, textValue, point, height);
        text.setRef(reference);
        return text;
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

    public Circle addCircle(Point3d center, double radius) {
        Circle circle = new Circle(this.ref, center, radius);
        long reference = this.addCircleNative(this.ref, center, radius);
        circle.setRef(reference);
        return circle;
    }

    public Arc addArc(Point3d center, double radius, double startAngle, double endAngle) {
        Arc arc = new Arc(this.ref, center, radius, startAngle, endAngle);
        long reference = this.addArcNative(this.ref, center, radius, startAngle, endAngle);
        arc.setRef(reference);
        return arc;
    }

    public Ellipse addEllipse(Point3d center, double majorAxis, double axisRatio) {
        Ellipse ellipse = new Ellipse(this.ref, center, majorAxis, axisRatio);
        long reference = this.addEllipseNative(this.ref, center, majorAxis, axisRatio);
        ellipse.setRef(reference);
        return ellipse;
    }

    public Insert addInsert(Point3d point3d, String blockName, double scaleX, double scaleY, double scaleZ, double rotation) {
        Insert insert = new Insert();
        long reference = this.addInsertNative(this.ref, point3d, blockName, scaleX, scaleY, scaleZ, rotation);
        insert.setRef(reference);
        insert.setBlockName(blockName);
        return insert;
    }

    private native long addPointNative(long ref, double x, double y, double z);
    private native long addLineNative(long ref, Point3d start, Point3d end);

    private native long addTextNative(long ref, String textValue, Point3d insPt, double height);

    private native long addCircleNative(long ref, Point3d center, double radius);

    private native long addArcNative(long ref, Point3d center, double radius, double startAngle, double endAngle);

    private native long addEllipseNative(long ref, Point3d center, double majorAxis, double axisRatio);

    private native long addInsertNative(long ref, Point3d insPt, String blockName, double scaleX, double scaleY, double scaleZ, double rotation);
}
