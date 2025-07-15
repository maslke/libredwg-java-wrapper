package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
public class CircleTest {

    private static final double TOLERANCE = 1e-3;

    private Circle createCircle() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        Point3d center = new Point3d(10, 10, 0);
        return hdr.addCircle(center, 10);
    }

    @Test
    public void testGetCenter() {
        Circle circle = createCircle();
        assertNotNull(circle);
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
    public void testGetRadius() {
        Circle circle = createCircle();
        assertNotNull(circle);
        assertEquals(10, circle.getRadius(), TOLERANCE);
        circle.setRadius(20);
        assertEquals(20, circle.getRadius(), TOLERANCE);
        double r = circle.getRadiusNative(circle.ref);
        assertEquals(20, r, TOLERANCE);
    }

    @Test
    public void testGetThickness() {
        Circle circle = createCircle();
        assertNotNull(circle);
        circle.setThickness(1.2);
        double thickness = circle.getThicknessNative(circle.ref);
        assertEquals(1.2, thickness, TOLERANCE);
    }


    @Test
    public void testGetExtrusion() {
        Circle circle = createCircle();
        assertNotNull(circle);
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


}
