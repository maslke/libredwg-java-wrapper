package io.github.maslke.dwg.common;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Point2dTest {
    @Test
    public void testPoint2d() {
        Point2d point = new Point2d();
        assertEquals(0.0, point.getX(), 0.000001);
        assertEquals(0.0, point.getY(), 0.000001);
        point.setX(1.0);
        point.setY(2.0);
        assertEquals(1.0, point.getX(), 0.000001);
        assertEquals(2.0, point.getY(), 0.000001);

        point = new Point2d(1.0, 2.0);
        assertEquals(1.0, point.getX(), 0.000001);
        assertEquals(2.0, point.getY(), 0.000001);
    }
}
