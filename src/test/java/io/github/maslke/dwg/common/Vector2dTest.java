package io.github.maslke.dwg.common;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Vector2dTest {
    @Test
    public void testVector2d() {
        Vector2d vector = new Vector2d();
        assertEquals(0.0, vector.getX(), 0.000001);
        assertEquals(0.0, vector.getY(), 0.000001);
        vector.setX(1.0);
        vector.setY(2.0);
        assertEquals(1.0, vector.getX(), 0.000001);
        assertEquals(2.0, vector.getY(), 0.000001);

        vector = new Vector2d(1.0, 2.0);
        assertEquals(1.0, vector.getX(), 0.000001);
        assertEquals(2.0, vector.getY(), 0.000001);
    }
}
