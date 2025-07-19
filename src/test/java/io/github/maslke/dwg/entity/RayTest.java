package io.github.maslke.dwg.entity;

import org.junit.Test;
import org.junit.After;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

public class RayTest extends AbstractEntityTest {

    private Ray ray;

    @After
    public void release() {
        if (ray != null) {
            releaseDwg(ray);
        }
    }

    private Ray createRay() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        return hdr.addRay(new Point3d(0, 0, 0), new Vector3d(1, 0, 0));
    }

    @Test
    public void testPoint() {
        ray = createRay();
        assertNotNull(ray);
        assertFalse(ray.isEmpty());
        assertTrue(ray.getHeader() > 0);
        Point3d point = ray.getPoint();
        assertEquals(0, point.getX(), TOLERANCE);
        assertEquals(0, point.getY(), TOLERANCE);
        assertEquals(0, point.getZ(), TOLERANCE);
        ray.setPoint(new Point3d(1, 1, 0));
        point = ray.getPoint();
        assertEquals(1, point.getX(), TOLERANCE);
        assertEquals(1, point.getY(), TOLERANCE);
        assertEquals(0, point.getZ(), TOLERANCE);
    }

    @Test
    public void testVector() {
        ray = createRay();
        assertNotNull(ray);
        assertFalse(ray.isEmpty());
        assertTrue(ray.getHeader() > 0);
        Vector3d vector = ray.getVector();
        assertEquals(1, vector.getX(), TOLERANCE);
        assertEquals(0, vector.getY(), TOLERANCE);
        assertEquals(0, vector.getZ(), TOLERANCE);
        ray.setVector(new Vector3d(0, 1, 0));
        vector = ray.getVector();
        assertEquals(0, vector.getX(), TOLERANCE);
        assertEquals(1, vector.getY(), TOLERANCE);
        assertEquals(0, vector.getZ(), TOLERANCE);
    }
}
