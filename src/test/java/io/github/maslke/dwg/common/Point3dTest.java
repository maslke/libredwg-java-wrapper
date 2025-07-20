package io.github.maslke.dwg.common;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Point3dTest {
    @Test
    public void testPoint3d() {
        Point3d point = new Point3d();
        assertEquals(0.0, point.getX(), 0.000001);
        assertEquals(0.0, point.getY(), 0.000001);
        assertEquals(0.0, point.getZ(), 0.000001);
        point.setX(1.0);
        point.setY(2.0);
        point.setZ(3.0);
        assertEquals(1.0, point.getX(), 0.000001);
        assertEquals(2.0, point.getY(), 0.000001);
        assertEquals(3.0, point.getZ(), 0.000001);
        point = new Point3d(1.0, 2.0, 3.0);
        assertEquals(1.0, point.getX(), 0.000001);
        assertEquals(2.0, point.getY(), 0.000001);
        assertEquals(3.0, point.getZ(), 0.000001);
    }
}
