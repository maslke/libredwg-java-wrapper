package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import org.junit.After;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;

public class PointTest extends AbstractEntityTest {

    private Point point;

    private Point createPoint(double x, double y, double z) {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        return hdr.addPoint(new Point3d(x, y, z));
    }

    @After
    public void release() {
        if (point != null) {
            releaseDwg(point);
        }
    }

    @Test
    public void testX() {
        point = createPoint(10, 10, 0);
        assertNotNull(point);
        double x = point.getX();
        assertEquals(10, x, TOLERANCE);

        x = point.getXNative(point.ref);
        assertEquals(10, x, TOLERANCE);

        point.setX(12);
        x = point.getXNative(point.ref);
        assertEquals(12, x, TOLERANCE);
    }

    @Test
    public void testY() {
        point = createPoint(10, 10, 10);
        assertNotNull(point);
        double y = point.getY();
        assertEquals(10, y, TOLERANCE);
        y = point.getYNative(point.ref);
        assertEquals(10, y, TOLERANCE);
        point.setY(15);
        y = point.getYNative(point.ref);
        assertEquals(15, y, TOLERANCE);
    }

    @Test
    public void testZ() {
        point = createPoint(0, 0, 12);
        assertNotNull(point);
        double z = point.getZ();
        assertEquals(12, z, TOLERANCE);
        z = point.getZNative(point.ref);
        assertEquals(12, z, TOLERANCE);
        point.setZ(15);
        z = point.getZNative(point.ref);
        assertEquals(15, z, TOLERANCE);
    }

    @Test
    public void testThickness() {
        point = createPoint(0, 0, 0);
        assertNotNull(point);
        point.setThickness(2.5);
        double thickness = point.getThickness();
        assertEquals(2.5, thickness, TOLERANCE);
        thickness = point.getThicknessNative(point.ref);
        assertEquals(2.5, thickness, TOLERANCE);
    }

    @Test
    public void testExtrusion() {
        point = createPoint(0, 0, 0);
        assertNotNull(point);
        assertNotEquals(0, point.getRef());
        Vector3d defaultExtrusion = point.getExtrusionNative(point.getRef());
        assertNotNull(defaultExtrusion);
        assertEquals(0, defaultExtrusion.getX(), TOLERANCE);
        assertEquals(0, defaultExtrusion.getY(), TOLERANCE);
        assertEquals(1, defaultExtrusion.getZ(), TOLERANCE);
        Vector3d extrusion = new Vector3d(1, 0, 0);
        point.setExtrusion(extrusion);
        Vector3d extrusion2 = point.getExtrusion();
        assertNotNull(extrusion2);
        assertEquals(1, extrusion2.getX(), TOLERANCE);
        assertEquals(0, extrusion2.getY(), TOLERANCE);
        assertEquals(0, extrusion2.getZ(), TOLERANCE);
        Vector3d extrusion3 = point.getExtrusionNative(point.ref);
        assertNotNull(extrusion3);
        assertEquals(1, extrusion3.getX(), TOLERANCE);
        assertEquals(0, extrusion3.getY(), TOLERANCE);
        assertEquals(0, extrusion3.getZ(), TOLERANCE);
    }

    @Test
    public void testParent() {
        point = createPoint(0, 0, 0);
        assertNotNull(point);
        assertNotEquals(0, point.getRef());
        Parent parent = point.getParent();
        assertNotNull(parent);
        assertNotEquals(0, parent.getRef());
    }
}
