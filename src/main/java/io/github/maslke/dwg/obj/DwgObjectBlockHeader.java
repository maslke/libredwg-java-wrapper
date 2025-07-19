package io.github.maslke.dwg.obj;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.entity.Arc;
import io.github.maslke.dwg.entity.Block;
import io.github.maslke.dwg.entity.Circle;
import io.github.maslke.dwg.entity.Ellipse;
import io.github.maslke.dwg.entity.EndBlk;
import io.github.maslke.dwg.entity.Insert;
import io.github.maslke.dwg.entity.Line;
import io.github.maslke.dwg.entity.Lwpolyline;
import io.github.maslke.dwg.entity.Point;
import io.github.maslke.dwg.entity.Ray;
import io.github.maslke.dwg.entity.Text;
import lombok.Getter;
import lombok.Setter;

import java.util.List;

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
        Circle circle = this.addCircle(this.ref, center, radius);
        circle.setHeader(this.ref);
        return circle;
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

    public Block addBlock(String name) {
        Block block = new Block();
        block.setRef(this.addBlockNative(this.ref, name));
        return block;
    }

    public Block addBlock(String name, Point2d basePoint) {
        Block block = this.addBlock(name);
        if (basePoint != null) {
            block.setBasePt(basePoint);
        }
        return block;
    }

    public EndBlk addEndBlk() {
        EndBlk endBlk = new EndBlk();
        endBlk.setHeader(this.ref);
        endBlk.setRef(this.addEndBlkNative(this.ref));
        return endBlk;
    }

    public Lwpolyline addLwpolyline(List<Point2d> points) {
        if (points == null || points.isEmpty()) {
            return null;
        }
        Lwpolyline lwpolyline = new Lwpolyline();
        long reference = this.addLwpolylineNative(this.ref, points.size(), points);
        lwpolyline.setRef(reference);
        lwpolyline.setPoints(points);
        lwpolyline.setNumPoints(points.size());
        lwpolyline.setFlag(0);
        lwpolyline.setNumVertexids(points.size());
        lwpolyline.setHeader(this.ref);
        return lwpolyline;
    }

    public Ray addRay(Point3d point, Vector3d vector) {
        Ray ray = new Ray(this.ref, point, vector);
        long reference = this.addRayNative(this.ref, point, vector);
        ray.setRef(reference);
        return ray;
    }

    public Arc addArc(Point3d center, double radius, double startAngle, double endAngle) {
        Arc arc = this.addArc(this.ref, center, radius, startAngle, endAngle);
        arc.setHeader(this.ref);
        return arc;
    }


    private native long addPointNative(long ref, double x, double y, double z);
    private native long addLineNative(long ref, Point3d start, Point3d end);

    private native long addTextNative(long ref, String textValue, Point3d insPt, double height);

    private native Circle addCircle(long ref, Point3d center, double radius);

    private native Arc addArc(long ref, Point3d center, double radius, double startAngle, double endAngle);

    private native long addEllipseNative(long ref, Point3d center, double majorAxis, double axisRatio);

    private native long addInsertNative(long ref, Point3d insPt, String blockName, double scaleX, double scaleY, double scaleZ, double rotation);

    private native long addBlockNative(long ref, String name);

    private native long addEndBlkNative(long ref);

    private native long addLwpolylineNative(long ref, int num, List<Point2d> points);

    private native long addRayNative(long ref, Point3d point, Vector3d vector);
}
