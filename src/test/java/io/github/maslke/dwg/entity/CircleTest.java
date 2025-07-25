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
import static org.junit.Assert.assertTrue;

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
        assertTrue(circle.getHeader() > 0);
        Point3d center = circle.getCenter();
        assertEquals(10, center.getX(), TOLERANCE);
        assertEquals(10, center.getY(), TOLERANCE);
        circle.setCenter(new Point3d(20, 20, 0));
        center = circle.getCenter();
        assertEquals(20, center.getX(), TOLERANCE);
        assertEquals(20, center.getY(), TOLERANCE);
    }

    @Test
    public void testRadius() {
        circle = createCircle();
        assertNotNull(circle);
        assertFalse(circle.isEmpty());
        assertTrue(circle.getHeader() > 0);
        assertEquals(10, circle.getRadius(), TOLERANCE);
        circle.setRadius(20);
        assertEquals(20, circle.getRadius(), TOLERANCE);
    }

    @Test
    public void testThickness() {
        circle = createCircle();
        assertNotNull(circle);
        assertFalse(circle.isEmpty());
        assertTrue(circle.getHeader() > 0);
        assertNotEquals(0, circle.getRef());
        double defaultThickness = circle.getThickness();
        assertEquals(0, defaultThickness, TOLERANCE);
        circle.setThickness(1.2);
        double thickness = circle.getThickness();
        assertEquals(1.2, thickness, TOLERANCE);
    }


    @Test
    public void testExtrusion() {
        circle = createCircle();
        assertNotNull(circle);
        assertFalse(circle.isEmpty());
        assertTrue(circle.getHeader() > 0);
        assertNotEquals(0, circle.getRef());
        Vector3d defaultExtrusion = circle.getExtrusion();
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
    }

    @Test
    public void testParent() {
        circle = createCircle();
        assertNotNull(circle);
        assertFalse(circle.isEmpty());
        assertTrue(circle.getHeader() > 0);
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
