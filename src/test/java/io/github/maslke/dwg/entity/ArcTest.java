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

public class ArcTest extends AbstractEntityTest {

    private Arc arc;


    private Arc createArc() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        Point3d center = new Point3d(10, 10, 0);
        return hdr.addArc(center, 10, 0, 1.2);
    }

    @Test
    public void testGetCenter() {
        arc = createArc();
        assertNotNull(arc);
        Point3d center = arc.getCenter();
        assertEquals(10, center.getX(), TOLERANCE);
        assertEquals(10, center.getY(), TOLERANCE);
        center = arc.getCenterNative(arc.ref);
        assertNotNull(center);
        assertEquals(10, center.getX(), TOLERANCE);
        assertEquals(10, center.getY(), TOLERANCE);
        arc.setCenter(new Point3d(20, 20, 0));
        center = arc.getCenterNative(arc.ref);
        assertEquals(20, center.getX(), TOLERANCE);
        assertEquals(20, center.getY(), TOLERANCE);
    }

    @After
    public void release() {
        if (arc != null) {
            releaseDwg(arc);
        }
    }

    @Test
    public void testRadius() {
        arc = createArc();
        assertNotNull(arc);
        assertFalse(arc.isEmpty());
        assertEquals(10, arc.getRadius(), TOLERANCE);
        arc.setRadius(20);
        assertEquals(20, arc.getRadius(), TOLERANCE);
        double r = arc.getRadiusNative(arc.ref);
        assertEquals(20, r, TOLERANCE);
    }

    @Test
    public void testThickness() {
        arc = createArc();
        assertNotNull(arc);
        assertFalse(arc.isEmpty());
        double defaultThickness = arc.getThickness();
        assertEquals(0, defaultThickness, TOLERANCE);
        arc.setThickness(1.2);
        double thickness = arc.getThicknessNative(arc.ref);
        assertEquals(1.2, thickness, TOLERANCE);
        thickness = arc.getThickness();
        assertEquals(1.2, thickness, TOLERANCE);
    }


    @Test
    public void testExtrusion() {
        arc = createArc();
        assertNotNull(arc);
        assertFalse(arc.isEmpty());
        Vector3d defaultExtrusion = arc.getExtrusionNative(arc.getRef());
        assertNotNull(defaultExtrusion);
        assertEquals(0, defaultExtrusion.getX(), TOLERANCE);
        assertEquals(0, defaultExtrusion.getY(), TOLERANCE);
        assertEquals(1, defaultExtrusion.getZ(), TOLERANCE);
        arc.setExtrusion(new Vector3d(0, 1, 0));
        Vector3d extrusion = arc.getExtrusion();
        assertNotNull(extrusion);
        assertEquals(0, extrusion.getX(), TOLERANCE);
        assertEquals(1, extrusion.getY(), TOLERANCE);
        assertEquals(0, extrusion.getZ(), TOLERANCE);
        Vector3d extrusion2 = arc.getExtrusionNative(arc.ref);
        assertNotNull(extrusion2);
        assertEquals(0, extrusion2.getX(), TOLERANCE);
        assertEquals(1, extrusion2.getY(), TOLERANCE);
        assertEquals(0, extrusion2.getZ(), TOLERANCE);
    }

    @Test
    public void testStartAngle() {
        arc = createArc();
        assertNotNull(arc);
        assertFalse(arc.isEmpty());
        double start = arc.getStartAngle();
        assertEquals(0, start, TOLERANCE);
        arc.setStartAngle(1.0);
        start = arc.getStartAngle();
        assertEquals(1.0, start, TOLERANCE);
        start = arc.getStartAngleNative(arc.ref);
        assertEquals(1.0, start, TOLERANCE);
    }

    @Test
    public void testEndAngle() {
        arc = createArc();
        assertNotNull(arc);
        assertFalse(arc.isEmpty());
        double end = arc.getEndAngle();
        assertEquals(1.2, end, TOLERANCE);
        arc.setEndAngle(1.5);
        end = arc.getEndAngle();
        assertEquals(1.5, end, TOLERANCE);
        end = arc.getEndAngleNative(arc.ref);
        assertEquals(1.5, end, TOLERANCE);
    }

    @Test
    public void testParent() {
        arc = createArc();
        assertNotNull(arc);
        Parent parent = arc.getParent();
        assertNotNull(parent);
        assertNotEquals(0, parent.getRef());
    }
}
