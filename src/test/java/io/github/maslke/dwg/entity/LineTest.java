package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import io.github.maslke.dwg.obj.DwgObjectEntity;
import org.junit.After;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

public class LineTest extends AbstractEntityTest {


    private Line line;

    private Line createLine() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        Point3d start = new Point3d(0, 0, 0);
        Point3d end = new Point3d(10, 10, 0);
        return hdr.addLine(start, end);
    }

    @After
    public void release() {
        if (line != null) {
            releaseDwg(line);
        }
    }

    @Test
    public void testStart() {
        Line line = createLine();
        assertNotNull(line);
        assertFalse(line.isEmpty());
        assertTrue(line.getHeader() > 0);
        Point3d start = line.getStart();
        assertNotNull(start);
        assertEquals(0, start.getX(), TOLERANCE);
        assertEquals(0, start.getY(), TOLERANCE);
        line.setStart(new Point3d(2, 2, 0));
        start = line.getStart();
        assertNotNull(start);
        assertEquals(2, start.getX(), TOLERANCE);
        assertEquals(2, start.getY(), TOLERANCE);

    }


    @Test
    public void testEnd() {
        line = createLine();
        assertNotNull(line);
        assertFalse(line.isEmpty());
        assertTrue(line.getHeader() > 0);
        Point3d end = line.getEnd();
        assertNotNull(end);
        assertEquals(10, end.getX(), TOLERANCE);
        assertEquals(10, end.getY(), TOLERANCE);
        line.setEnd(new Point3d(12, 12, 0));
        end = line.getEnd();
        assertNotNull(end);
        assertEquals(12, end.getX(), TOLERANCE);
        assertEquals(12, end.getY(), TOLERANCE);
    }

    @Test
    public void testExtrusion() {
        line = createLine();
        assertNotNull(line);
        assertFalse(line.isEmpty());
        assertTrue(line.getHeader() > 0);
        assertNotEquals(0, line.getRef());
        Vector3d defaultExtrusion = line.getExtrusion();
        assertNotNull(defaultExtrusion);
        assertEquals(0, defaultExtrusion.getX(), TOLERANCE);
        assertEquals(0, defaultExtrusion.getY(), TOLERANCE);
        assertEquals(1, defaultExtrusion.getZ(), TOLERANCE);
        Vector3d extrusion = new Vector3d(1, 0, 0);
        line.setExtrusion(extrusion);
        Vector3d extrusion2 = line.getExtrusion();
        assertNotNull(extrusion2);
        assertEquals(1, extrusion2.getX(), TOLERANCE);
        assertEquals(0, extrusion2.getY(), TOLERANCE);
        assertEquals(0, extrusion2.getZ(), TOLERANCE);
    }

    @Test
    public void testThickness() {
        line = createLine();
        assertNotNull(line);
        assertFalse(line.isEmpty());
        assertTrue(line.getHeader() > 0);
        line.setThickness(2.5);
        double thickness = line.getThickness();
        assertEquals(2.5, thickness, TOLERANCE);
    }

    @Test
    public void testParent() {
        line = createLine();
        assertNotNull(line);
        assertFalse(line.isEmpty());
        assertTrue(line.getHeader() > 0);
        assertNotEquals(0, line.getRef());
        DwgObjectEntity parent = line.getParent();
        assertNotNull(parent);
        assertNotEquals(0, parent.ref);
    }
}
