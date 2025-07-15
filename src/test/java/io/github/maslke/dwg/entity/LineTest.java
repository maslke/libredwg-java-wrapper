package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

public class LineTest {

    private static final double TOLERANCE = 1e-3;

    private Line createLine() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        Point3d start = new Point3d(0, 0, 0);
        Point3d end = new Point3d(10, 10, 0);
        return hdr.addLine(start, end);
    }

    @Test
    public void testGetStart() {
        Line line = createLine();
        Point3d start = line.getStart();
        assertNotNull(start);
        assertEquals(0, start.getX(), TOLERANCE);
        assertEquals(0, start.getY(), TOLERANCE);

        start = line.getStartNative(line.getRef());
        assertNotNull(start);
        assertEquals(0, start.getX(), TOLERANCE);
        assertEquals(0, start.getY(), TOLERANCE);

        line.setStart(new Point3d(2, 2, 0));
        start = line.getStart();
        assertNotNull(start);
        assertEquals(2, start.getX(), TOLERANCE);
        assertEquals(2, start.getY(), TOLERANCE);

        start = line.getStartNative(line.ref);
        assertNotNull(start);
        assertEquals(2, start.getX(), TOLERANCE);
        assertEquals(2, start.getY(), TOLERANCE);
    }


    @Test
    public void testGetEnd() {
        Line line = createLine();

        Point3d end = line.getEnd();
        assertNotNull(end);
        assertEquals(10, end.getX(), TOLERANCE);
        assertEquals(10, end.getY(), TOLERANCE);

        end = line.getEndNative(line.getRef());
        assertEquals(10, end.getX(), TOLERANCE);
        assertEquals(10, end.getY(), TOLERANCE);

        line.setEnd(new Point3d(12, 12, 0));
        end = line.getEnd();
        assertNotNull(end);
        assertEquals(12, end.getX(), TOLERANCE);
        assertEquals(12, end.getY(), TOLERANCE);

        end = line.getEndNative(line.getRef());
        assertNotNull(end);
        assertEquals(12, end.getX(), TOLERANCE);
        assertEquals(12, end.getY(), TOLERANCE);
    }

    @Test
    public void testGetExtrusion() {
        Line line = createLine();
        Vector3d extrusion = new Vector3d(1, 0, 0);
        line.setExtrusion(extrusion);

        Vector3d extrusion2 = line.getExtrusionNative(line.ref);
        assertNotNull(extrusion2);
        assertEquals(1, extrusion2.getX(), TOLERANCE);
        assertEquals(0, extrusion2.getY(), TOLERANCE);
        assertEquals(0, extrusion2.getZ(), TOLERANCE);
    }

    @Test
    public void testGetThickness() {
        Line line = createLine();
        line.setThickness(2.5);
        double thickness = line.getThicknessNative(line.ref);
        assertEquals(2.5, thickness, TOLERANCE);
    }

}
