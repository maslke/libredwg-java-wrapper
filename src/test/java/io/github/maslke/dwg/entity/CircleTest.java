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
import static org.junit.Assert.assertFalse;

public class CircleTest extends AbstractEntityTest {


    private Circle circle;

    private Circle createCircle() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        Point3d center = new Point3d(10, 10, 0);
        return hdr.addCircle(center, 10);
    }

    @Test
    public void testCenter() {
        circle = createCircle();
        assertNotNull(circle);
        assertFalse(circle.isEmpty());
        Point3d center = circle.getCenter();
        assertEquals(10, center.getX(), TOLERANCE);
        assertEquals(10, center.getY(), TOLERANCE);
        center = circle.getCenterNative(circle.ref);
        assertNotNull(center);
        assertEquals(10, center.getX(), TOLERANCE);
        assertEquals(10, center.getY(), TOLERANCE);
        circle.setCenter(new Point3d(20, 20, 0));
        center = circle.getCenterNative(circle.ref);
        assertEquals(20, center.getX(), TOLERANCE);
        assertEquals(20, center.getY(), TOLERANCE);
    }

    @Test
    public void testRadius() {
        circle = createCircle();
        assertNotNull(circle);
        assertFalse(circle.isEmpty());
        assertEquals(10, circle.getRadius(), TOLERANCE);
        circle.setRadius(20);
        assertEquals(20, circle.getRadius(), TOLERANCE);
        double r = circle.getRadiusNative(circle.ref);
        assertEquals(20, r, TOLERANCE);
    }

    @Test
    public void testThickness() {
        circle = createCircle();
        assertNotNull(circle);
        assertFalse(circle.isEmpty());
        assertNotEquals(0, circle.getRef());
        double defaultThickness = circle.getThickness();
        assertEquals(0, defaultThickness, TOLERANCE);
        circle.setThickness(1.2);
        double thickness = circle.getThickness();
        assertEquals(1.2, thickness, TOLERANCE);
        thickness = circle.getThicknessNative(circle.ref);
        assertEquals(1.2, thickness, TOLERANCE);
    }


    @Test
    public void testExtrusion() {
        circle = createCircle();
        assertNotNull(circle);
        assertFalse(circle.isEmpty());
        assertNotEquals(0, circle.getRef());
        Vector3d defaultExtrusion = circle.getExtrusionNative(circle.getRef());
        assertNotNull(defaultExtrusion);
        assertEquals(0, defaultExtrusion.getX(), TOLERANCE);
        assertEquals(0, defaultExtrusion.getY(), TOLERANCE);
        assertEquals(1, defaultExtrusion.getZ(), TOLERANCE);
        circle.setExtrusion(new Vector3d(0, 1, 0));
        Vector3d extrusion = circle.getExtrusion();
        assertNotNull(extrusion);
        assertEquals(0, extrusion.getX(), TOLERANCE);
        assertEquals(1, extrusion.getY(), TOLERANCE);
        assertEquals(0, extrusion.getZ(), TOLERANCE);
        Vector3d extrusion2 = circle.getExtrusionNative(circle.ref);
        assertNotNull(extrusion2);
        assertEquals(0, extrusion2.getX(), TOLERANCE);
        assertEquals(1, extrusion2.getY(), TOLERANCE);
        assertEquals(0, extrusion2.getZ(), TOLERANCE);
    }

    @Test
    public void testParent() {
        circle = createCircle();
        assertNotNull(circle);
        assertFalse(circle.isEmpty());
        Parent parent = circle.getParent();
        assertNotNull(parent);
        assertNotEquals(0, parent.getRef());
    }

    @After
    public void release() {
        if (circle != null) {
            releaseDwg(circle);
        }
    }
}
