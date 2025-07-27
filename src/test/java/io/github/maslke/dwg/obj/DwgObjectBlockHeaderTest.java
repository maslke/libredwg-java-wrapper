package io.github.maslke.dwg.obj;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.entity.Arc;
import io.github.maslke.dwg.entity.Block;
import io.github.maslke.dwg.entity.Circle;
import io.github.maslke.dwg.entity.Ellipse;
import io.github.maslke.dwg.entity.EndBlk;
import io.github.maslke.dwg.entity.Insert;
import io.github.maslke.dwg.entity.Line;
import io.github.maslke.dwg.entity.Lwpolyline;
import io.github.maslke.dwg.entity.Polyline2d;
import io.github.maslke.dwg.entity.Polyline3d;
import io.github.maslke.dwg.entity.Point;
import io.github.maslke.dwg.entity.Text;
import io.github.maslke.dwg.entity.Ray;
import io.github.maslke.dwg.entity.MText;
import io.github.maslke.dwg.common.Vector3d;
import org.junit.After;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertNull;

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
        Insert insert = objectBlockHeader.addInsert(new Point3d(10, 10 ,0), "blk0", 1.0 ,1.0, 1.0, 0);
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
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

}
