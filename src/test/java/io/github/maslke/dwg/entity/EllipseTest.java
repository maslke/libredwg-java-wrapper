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

public class EllipseTest extends AbstractEntityTest {
    private Ellipse ellipse;

    private Ellipse createEllipse(Point3d center, double majorAxis, double axisRatio) {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        return hdr.addEllipse(center, majorAxis, axisRatio);
    }

    private Ellipse createEllipse() {
        return createEllipse(new Point3d(0, 0, 0), 1.0, 0.8);
    }

    @After
    public void release() {
        if (ellipse != null) {
            releaseDwg(ellipse);
        }
    }

    @Test
    public void testCenter() {
        ellipse = createEllipse();
        assertNotNull(ellipse);
        assertFalse(ellipse.isEmpty());
        assertNotEquals(0, ellipse.getRef());
        Point3d center = ellipse.getCenter();
        assertNotNull(center);
        assertEquals(0, center.getX(), TOLERANCE);
        assertEquals(0, center.getY(), TOLERANCE);
        assertEquals(0, center.getZ(), TOLERANCE);
        center = ellipse.getCenterNative(ellipse.getRef());
        assertNotNull(center);
        assertEquals(0, center.getX(), TOLERANCE);
        assertEquals(0, center.getY(), TOLERANCE);
        assertEquals(0, center.getZ(), TOLERANCE);
        ellipse.setCenter(new Point3d(1, 1, 1));
        center = ellipse.getCenter();
        assertNotNull(center);
        assertEquals(1, center.getX(), TOLERANCE);
        assertEquals(1, center.getY(), TOLERANCE);
        assertEquals(1, center.getZ(), TOLERANCE);
        center = ellipse.getCenterNative(ellipse.getRef());
        assertNotNull(center);
        assertEquals(1, center.getX(), TOLERANCE);
        assertEquals(1, center.getY(), TOLERANCE);
        assertEquals(1, center.getZ(), TOLERANCE);
    }

    @Test
    public void testMajorAxis() {
        ellipse = createEllipse();
        assertNotNull(ellipse);
        assertFalse(ellipse.isEmpty());
        assertNotEquals(0, ellipse.getRef());
        double majorAxis = ellipse.getMajorAxis();
        assertEquals(1.0, majorAxis, TOLERANCE);
        majorAxis = ellipse.getMajorAxisNative(ellipse.getRef());
        assertEquals(1.0, majorAxis, TOLERANCE);
        ellipse.setMajorAxis(1.2);
        majorAxis = ellipse.getMajorAxisNative(ellipse.getRef());
        assertEquals(1.2, majorAxis, TOLERANCE);
        majorAxis = ellipse.getMajorAxis();
        assertEquals(1.2, majorAxis, TOLERANCE);
    }

    @Test
    public void testAxisRatio() {
        ellipse = createEllipse();
        assertNotNull(ellipse);
        assertFalse(ellipse.isEmpty());
        assertNotEquals(0, ellipse.getRef());
        double ratio = ellipse.getAxisRatio();
        assertEquals(0.8, ratio, TOLERANCE);
        ratio = ellipse.getAxisRatioNative(ellipse.getRef());
        assertEquals(0.8, ratio, TOLERANCE);
        ellipse.setAxisRatio(0.5);
        ratio = ellipse.getAxisRatio();
        assertEquals(0.5, ratio, TOLERANCE);
        ratio = ellipse.getAxisRatioNative(ellipse.getRef());
        assertEquals(0.5, ratio, TOLERANCE);
    }

    @Test
    public void testStartAngle() {
        ellipse = createEllipse();
        assertNotNull(ellipse);
        assertFalse(ellipse.isEmpty());
        assertNotEquals(0, ellipse.getRef());
        ellipse.setStartAngle(0.2);
        double startAngle = ellipse.getStartAngle();
        assertEquals(0.2, startAngle, TOLERANCE);
        startAngle = ellipse.getStartAngleNative(ellipse.getRef());
        assertEquals(0.2, startAngle, TOLERANCE);
    }

    @Test
    public void testEndAngle() {
        ellipse = createEllipse();
        assertNotNull(ellipse);
        assertFalse(ellipse.isEmpty());
        assertNotEquals(0, ellipse.getRef());
        ellipse.setEndAngle(1.5);
        double endAngle = ellipse.getEndAngle();
        assertEquals(1.5, endAngle, TOLERANCE);
        endAngle = ellipse.getEndAngleNative(ellipse.getRef());
        assertEquals(1.5, endAngle, TOLERANCE);
    }

    @Test
    public void testExtrusion() {
        ellipse = createEllipse();
        assertNotNull(ellipse);
        assertFalse(ellipse.isEmpty());
        assertNotEquals(0, ellipse.getRef());
        Vector3d defaultExtrusion = ellipse.getExtrusionNative(ellipse.getRef());
        assertNotNull(defaultExtrusion);
        assertEquals(0, defaultExtrusion.getX(), TOLERANCE);
        assertEquals(0, defaultExtrusion.getY(), TOLERANCE);
        assertEquals(1, defaultExtrusion.getZ(), TOLERANCE);
        Vector3d extrusion = new Vector3d(1, 0, 0);
        ellipse.setExtrusion(extrusion);
        extrusion = ellipse.getExtrusion();
        assertNotNull(extrusion);
        assertEquals(1, extrusion.getX(), TOLERANCE);
        assertEquals(0, extrusion.getY(), TOLERANCE);
        assertEquals(0, extrusion.getZ(), TOLERANCE);
        extrusion = ellipse.getExtrusionNative(ellipse.getRef());
        assertNotNull(extrusion);
        assertEquals(1, extrusion.getX(), TOLERANCE);
        assertEquals(0, extrusion.getY(), TOLERANCE);
        assertEquals(0, extrusion.getZ(), TOLERANCE);
    }
}
