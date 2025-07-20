package io.github.maslke.dwg.common;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class Vector3dTest {
    @Test
    public void testVector3d() {
        Vector3d vector = new Vector3d();
        assertEquals(0.0, vector.getX(), 0.000001);
        assertEquals(0.0, vector.getY(), 0.000001);
        assertEquals(0.0, vector.getZ(), 0.000001);
        vector.setX(1.0);
        vector.setY(2.0);
        vector.setZ(3.0);
        assertEquals(1.0, vector.getX(), 0.000001);
        assertEquals(2.0, vector.getY(), 0.000001);
        assertEquals(3.0, vector.getZ(), 0.000001);

        vector = new Vector3d(1.0, 2.0, 3.0);
        assertEquals(1.0, vector.getX(), 0.000001);
        assertEquals(2.0, vector.getY(), 0.000001);
        assertEquals(3.0, vector.getZ(), 0.000001);
    }
}
