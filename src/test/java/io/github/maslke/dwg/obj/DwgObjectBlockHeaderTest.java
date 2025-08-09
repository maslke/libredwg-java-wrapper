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
import io.github.maslke.dwg.entity.MInsert;
import io.github.maslke.dwg.entity.MText;
import io.github.maslke.dwg.entity.Point;
import io.github.maslke.dwg.entity.Polyline2d;
import io.github.maslke.dwg.entity.Polyline3d;
import io.github.maslke.dwg.entity.Ray;
import io.github.maslke.dwg.entity.Shape;
import io.github.maslke.dwg.entity.Solid;
import io.github.maslke.dwg.entity.Spline;
import io.github.maslke.dwg.entity.Text;
import org.junit.After;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

public class DwgObjectBlockHeaderTest {

    private Dwg dwg;

    @After
    public void release() {
        if (dwg != null) {
            dwg.release();
        }
    }

    @Test
    public void testAddLine() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());
        Line line = hdr.addLine(new Point3d(0, 0, 0), new Point3d(1, 1, 0));
        assertNotNull(line);
        assertFalse(line.isEmpty());
    }


    @Test
    public void testAddText() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());
        Text text = hdr.addText("TEXT", new Point3d(10, 10, 0), 2.5);
        assertNotNull(text);
        assertNotEquals(0, text.getRef());
    }

    @Test
    public void testAddMText() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());
        MText mtext = hdr.addMText("MTEXT", new Point3d(10, 10, 0), 2.5);
        assertNotNull(mtext);
        assertNotEquals(0, mtext.getRef());
    }

    @Test
    public void testAddLwpolyline() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader blockHeader = dwg.getObjectBlockHeader();
        assertNotNull(blockHeader);
        assertNotEquals(0, blockHeader.getRef());
        assertNotEquals(0, blockHeader.getRef());

        List<Point2d> points = Arrays.asList(
                new Point2d(0, 0),
                new Point2d(1, 1)
        );
        Lwpolyline lwpolyline = blockHeader.addLwpolyline(points);
        assertNotNull(lwpolyline);
        assertNotEquals(0, lwpolyline.getRef());
    }

    @Test
    public void testAddCircle() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());
        Circle circle = hdr.addCircle(new Point3d(0, 0, 0), 14);
        assertNotNull(circle);
        assertFalse(circle.isEmpty());
    }

    @Test
    public void testAddArc() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());
        Arc arc = hdr.addArc(new Point3d(0, 0, 0), 1.5, 0, 1.5);
        assertNotNull(arc);
        assertFalse(arc.isEmpty());
    }

    @Test
    public void testAddEllipse() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());
        Ellipse ellipse = hdr.addEllipse(new Point3d(0, 0, 0), 1, 0.8);
        assertNotNull(ellipse);
        assertFalse(ellipse.isEmpty());
    }

    @Test
    public void testAddPoint() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());
        Point point = hdr.addPoint(new Point3d(1, 1, 1));
        assertNotNull(point);
        assertFalse(point.isEmpty());
    }

    @Test
    public void testAddBlock() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader objectBlockHeader = dwg.getObjectBlockHeader();
        assertNotNull(objectBlockHeader);
        assertNotEquals(0, objectBlockHeader.getRef());
        DwgObjectBlockHeader hdr = dwg.createObjectBlockHeader("blk0");
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());
        Block block = hdr.addBlock("blk0");
        assertNotNull(block);
        assertFalse(block.isEmpty());
        hdr.addLine(new Point3d(0, 0, 0), new Point3d(1, 1, 0));
        EndBlk endBlk = hdr.addEndBlk();
        assertNotNull(endBlk);
        assertFalse(endBlk.isEmpty());
        Insert insert = objectBlockHeader.addInsert(new Point3d(10, 10, 0), "blk0", 1.0, 1.0, 1.0, 0);
        assertNotNull(insert);
        assertFalse(insert.isEmpty());

        DwgObjectRef objectHeaderRef = insert.getBlockHeader();
        assertNotNull(objectHeaderRef);
        assertTrue(objectHeaderRef.getRef() > 0);

        long absoluteRef = objectHeaderRef.getAbsoluteRef();
        assertTrue(absoluteRef > 0);

        if (objectHeaderRef.getObject() == null) {
            objectHeaderRef.setObject(dwg.resolveHandle(absoluteRef));
        }

        DwgObject block_obj = objectHeaderRef.getObject();
        assertNotNull(block_obj);
        assertTrue(block_obj.getRef() > 0);
        DwgObjectObject tioObject = block_obj.getTioObject();
        assertNotNull(tioObject);
        assertTrue(tioObject.getRef() > 0);
        DwgObjectBlockHeader blockHeader = tioObject.getObjectBlockHeader();
        assertNotNull(blockHeader);
        assertTrue(blockHeader.getRef() > 0);
        assertNotNull(blockHeader);
    }

    @Test
    public void testName() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader objectBlockHeader = dwg.getObjectBlockHeader();
        assertNotNull(objectBlockHeader);
        assertNotEquals(0, objectBlockHeader.getRef());
        DwgObjectBlockHeader hdr = dwg.createObjectBlockHeader("blk0");
        assertNotNull(hdr);
        assertEquals("blk0", hdr.getName());
        assertNotEquals(0, hdr.getRef());

        DwgObjectObject parent = hdr.getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        assertNotNull(parent.getDwg());
        Block block = hdr.addBlock("blk0");
        assertNotNull(block);
        assertFalse(block.isEmpty());
        hdr.addLine(new Point3d(0, 0, 0), new Point3d(1, 1, 0));
        EndBlk endBlk = hdr.addEndBlk();
        assertNotNull(endBlk);
        assertFalse(endBlk.isEmpty());
        Insert insert = objectBlockHeader.addInsert(new Point3d(10, 10, 0), "blk0", 1.0, 1.0, 1.0, 0);
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
    }

    @Test
    public void testAddBlockWithBasePoint() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.createObjectBlockHeader("blk1");
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());

        Point2d basePoint = new Point2d(5, 5);
        Block block = hdr.addBlock("blk1", basePoint);
        assertNotNull(block);
        assertFalse(block.isEmpty());
        assertNotEquals(0, block.getRef());

        hdr.addCircle(new Point3d(0, 0, 0), 3);
        EndBlk endBlk = hdr.addEndBlk();
        assertNotNull(endBlk);
        assertFalse(endBlk.isEmpty());
    }

    @Test
    public void testAddRay() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        Ray ray = hdr.addRay(new Point3d(0, 0, 0), new Vector3d(1, 1, 0));
        assertNotNull(ray);
        assertFalse(ray.isEmpty());
    }

    @Test
    public void testAddPolyline3d() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertTrue(hdr.getRef() > 0);
        List<Point3d> points = Arrays.asList(
                new Point3d(0, 0, 0),
                new Point3d(1, 1, 0)
        );
        Polyline3d polyline3d = hdr.addPolyline3d(points);
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());

        polyline3d = hdr.addPolyline3d(null);
        assertNull(polyline3d);

        polyline3d = hdr.addPolyline3d(new ArrayList<>());
        assertNull(polyline3d);
    }

    @Test
    public void testAddPolyline2d() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertTrue(hdr.getRef() > 0);
        List<Point2d> points = Arrays.asList(
                new Point2d(0, 0),
                new Point2d(1, 1)
        );
        Polyline2d polyline2d = hdr.addPolyline2d(points);
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());

        polyline2d = hdr.addPolyline2d(null);
        assertNull(polyline2d);

        polyline2d = hdr.addPolyline2d(new ArrayList<>());
        assertNull(polyline2d);
    }

    @Test
    public void testAddSolid() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());

        Point3d corner1 = new Point3d(0, 0, 0);
        Point2d corner2 = new Point2d(10, 0);
        Point2d corner3 = new Point2d(10, 10);
        Point2d corner4 = new Point2d(0, 10);

        Solid solid = hdr.addSolid(corner1, corner2, corner3, corner4);
        assertNotNull(solid);
        assertFalse(solid.isEmpty());
        assertNotEquals(0, solid.getRef());
    }

    @Test
    public void testAddSolidWithThickness() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());

        Point2d corner1 = new Point2d(0, 0);
        Point2d corner2 = new Point2d(5, 0);
        Point2d corner3 = new Point2d(5, 5);
        Point2d corner4 = new Point2d(0, 5);
        double thickness = 2.5;

        Solid solid = hdr.addSolid(corner1, corner2, corner3, corner4, thickness);
        assertNotNull(solid);
        assertFalse(solid.isEmpty());
        assertNotEquals(0, solid.getRef());
    }

    @Test
    public void testAddShape() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());

        String shapeName = "LTYPESHP.SHX";
        Point3d insertPoint = new Point3d(5, 5, 0);
        double scale = 1.0;
        double obliqueAngle = 0.0;

        Shape shape = hdr.addShape(shapeName, insertPoint, scale, obliqueAngle);
        assertNotNull(shape);
        assertFalse(shape.isEmpty());
        assertNotEquals(0, shape.getRef());
    }

    @Test
    public void testAddSpline() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());

        List<Point3d> fitPoints = Arrays.asList(
                new Point3d(0, 0, 0),
                new Point3d(10, 5, 0),
                new Point3d(20, 0, 0),
                new Point3d(30, -5, 0)
        );
        Vector3d begTanVec = new Vector3d(1, 0, 0);
        Vector3d endTanVec = new Vector3d(1, 0, 0);

        Spline spline = hdr.addSpline(fitPoints, begTanVec, endTanVec);
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertNotEquals(0, spline.getRef());
    }

    @Test
    public void testAddSplineWithComplexCurve() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());

        List<Point3d> fitPoints = Arrays.asList(
                new Point3d(0, 0, 0),
                new Point3d(5, 10, 0),
                new Point3d(15, 8, 0),
                new Point3d(25, 12, 0),
                new Point3d(30, 0, 0)
        );
        Vector3d begTanVec = new Vector3d(1, 2, 0);
        Vector3d endTanVec = new Vector3d(1, -2, 0);

        Spline spline = hdr.addSpline(fitPoints, begTanVec, endTanVec);
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertNotEquals(0, spline.getRef());
    }

    @Test
    public void testAddMInsert() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        MInsert minsert = hdr.addMInsert(new Point3d(0, 0, 0), "blk0", new Vector3d(1, 1, 1), 0, 1, 1, 1, 1);
        assertNotNull(minsert);
        assertFalse(minsert.isEmpty());
        assertNotEquals(0, minsert.getRef());
    }

    @Test
    public void testAddMultipleEntities() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());

        Point point = hdr.addPoint(new Point3d(0, 0, 0));
        assertNotNull(point);
        assertFalse(point.isEmpty());

        Line line = hdr.addLine(new Point3d(0, 0, 0), new Point3d(10, 10, 0));
        assertNotNull(line);
        assertFalse(line.isEmpty());

        Circle circle = hdr.addCircle(new Point3d(5, 5, 0), 2.5);
        assertNotNull(circle);
        assertFalse(circle.isEmpty());

        Arc arc = hdr.addArc(new Point3d(15, 5, 0), 3.0, 0, Math.PI / 2);
        assertNotNull(arc);
        assertFalse(arc.isEmpty());

        Ellipse ellipse = hdr.addEllipse(new Point3d(25, 5, 0), 4.0, 0.6);
        assertNotNull(ellipse);
        assertFalse(ellipse.isEmpty());

        Text text = hdr.addText("测试文本", new Point3d(0, 15, 0), 2.0);
        assertNotNull(text);
        assertFalse(text.isEmpty());

        MText mtext = hdr.addMText("多行文本测试", new Point3d(15, 15, 0), 3.0);
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());

        List<Point2d> polyPoints = Arrays.asList(
                new Point2d(30, 0),
                new Point2d(35, 0),
                new Point2d(35, 5),
                new Point2d(30, 5),
                new Point2d(30, 0)
        );
        Lwpolyline lwpolyline = hdr.addLwpolyline(polyPoints);
        assertNotNull(lwpolyline);
        assertFalse(lwpolyline.isEmpty());

        Ray ray = hdr.addRay(new Point3d(40, 0, 0), new Vector3d(1, 1, 0));
        assertNotNull(ray);
        assertFalse(ray.isEmpty());

        Solid solid = hdr.addSolid(
                new Point3d(45, 0, 0),
                new Point2d(50, 0),
                new Point2d(50, 5),
                new Point2d(45, 5)
        );
        assertNotNull(solid);
        assertFalse(solid.isEmpty());

        Shape shape = hdr.addShape("LTYPESHP.SHX", new Point3d(55, 2.5, 0), 1.0, 0.0);
        assertNotNull(shape);
        assertFalse(shape.isEmpty());

        List<Point3d> splinePoints = Arrays.asList(
                new Point3d(60, 0, 0),
                new Point3d(65, 3, 0),
                new Point3d(70, 1, 0),
                new Point3d(75, 4, 0)
        );
        Spline spline = hdr.addSpline(splinePoints, new Vector3d(1, 0, 0), new Vector3d(1, 0, 0));
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
    }

}
