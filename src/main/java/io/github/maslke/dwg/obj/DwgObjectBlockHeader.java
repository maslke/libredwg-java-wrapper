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
import io.github.maslke.dwg.entity.MText;
import io.github.maslke.dwg.entity.Solid;
import io.github.maslke.dwg.entity.Shape;
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
        Point pnt = this.addPoint(this.ref, point);
        if (pnt != null) {
            pnt.setHeader(this.ref);
        }
        return pnt;
    }

    public Text addText(String textValue, Point3d point, double height)
    {
        Text text = this.addText(this.ref, textValue, point, height);
        if (text != null) {
            text.setHeader(this.ref);
        }
        return text;
    }

    public MText addMText(String textValue, Point3d point, double height) {
        MText mtext = this.addMText(this.ref, textValue, point, height);
        if (mtext != null) {
            mtext.setHeader(this.ref);
        }
        return mtext;
    }

    public Line addLine(Point3d start, Point3d end) {
        Line line = this.addLine(this.ref, start, end);
        if (line != null) {
            line.setHeader(this.ref);
        }
        return line;
    }

    public Circle addCircle(Point3d center, double radius) {
        Circle circle = this.addCircle(this.ref, center, radius);
        if (circle != null) {
            circle.setHeader(this.ref);
        }
        return circle;
    }


    public Ellipse addEllipse(Point3d center, double majorAxis, double axisRatio) {
        Ellipse ellipse = this.addEllipse(this.ref, center, majorAxis, axisRatio);
        if (ellipse != null) {
            ellipse.setHeader(this.ref);
        }
        return ellipse;
    }

    public Insert addInsert(Point3d point3d, String blockName, double scaleX, double scaleY, double scaleZ, double rotation) {
        Insert insert = this.addInsert(this.ref, point3d, blockName, scaleX, scaleY, scaleZ, rotation);
        if (insert != null) {
            insert.setHeader(this.ref);
            insert.setBlockName(blockName);
        }
        return insert;
    }

    public Block addBlock(String name) {
        Block block = this.addBlock(this.ref, name);
        if (block != null) {
            block.setHeader(this.ref);
        }
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
        EndBlk endBlk = this.addEndBlk(this.ref);
        if (endBlk != null) {
            endBlk.setHeader(this.ref);
        }
        return endBlk;
    }

    public Lwpolyline addLwpolyline(List<Point2d> points) {
        Lwpolyline lwpolyline = this.addLwpolyline(this.ref, points);
        if (lwpolyline != null) {
            lwpolyline.setHeader(this.ref);
        }
        return lwpolyline;
    }

    public Ray addRay(Point3d point, Vector3d vector) {
        Ray ray = this.addRay(this.ref, point, vector);
        if (ray != null) {
            ray.setHeader(this.ref);
        }
        return ray;
    }

    public Arc addArc(Point3d center, double radius, double startAngle, double endAngle) {
        Arc arc = this.addArc(this.ref, center, radius, startAngle, endAngle);
        if (arc != null) {
            arc.setHeader(this.ref);
        }
        return arc;
    }

    public Solid addSolid(Point3d corner1, Point2d corner2, Point2d corner3, Point2d corner4) {
        Solid solid = this.addSolid(this.ref, corner1, corner2, corner3, corner4);
        if (solid != null) {
            solid.setHeader(this.ref);
        }
        return solid;
    }

    public Solid addSolid(Point2d corner1, Point2d corner2, Point2d corner3, Point2d corner4, double thickness) {
        if (corner1 == null) {
            return null;
        }
        Point3d corner = new Point3d(corner1.getX(), corner1.getY(), thickness);
        return this.addSolid(corner, corner2, corner3, corner4);
    }

    public Shape addShape(String name, Point3d point, double scale, double obliqueAngle) {
        Shape shape = this.addShape(this.ref, name, point, scale, obliqueAngle);
        if (shape != null) {
            shape.setHeader(this.ref);
        }
        return shape;
    }


    private native Point addPoint(long ref, Point3d point);
    private native Line addLine(long ref, Point3d start, Point3d end);

    private native Text addText(long ref, String textValue, Point3d insPt, double height);

    private native MText addMText(long ref, String textValue, Point3d insPt, double height);

    private native Circle addCircle(long ref, Point3d center, double radius);

    private native Arc addArc(long ref, Point3d center, double radius, double startAngle, double endAngle);

    private native Ellipse addEllipse(long ref, Point3d center, double majorAxis, double axisRatio);

    private native Insert addInsert(long ref, Point3d insPt, String blockName, double scaleX, double scaleY, double scaleZ, double rotation);

    private native Block addBlock(long ref, String name);

    private native EndBlk addEndBlk(long ref);

    private native Lwpolyline addLwpolyline(long ref, List<Point2d> points);

    private native Ray addRay(long ref, Point3d point, Vector3d vector);

    private native Solid addSolid(long ref, Point3d corner1, Point2d corner2, Point2d corner3, Point2d corner4);

    private native Shape addShape(long ref, String name, Point3d point, double scale, double obliqueAngle);
}
