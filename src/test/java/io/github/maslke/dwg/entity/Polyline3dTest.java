package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import io.github.maslke.dwg.obj.DwgObjectRef;
import org.junit.After;
import org.junit.Ignore;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class Polyline3dTest extends AbstractEntityTest {

    private Polyline3d polyline3d;

    private Polyline3d createPolyline3d() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        List<Point3d> points = Arrays.asList(
                new Point3d(0, 0, 0),
                new Point3d(10, 10, 5),
                new Point3d(20, 0, 10)
        );
        return hdr.addPolyline3d(points);
    }

    @After
    public void release() {
        if (polyline3d != null) {
            releaseDwg(polyline3d);
        }
    }

    @Test
    public void testHasVertex() {
        polyline3d = createPolyline3d();
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());
        assertTrue(polyline3d.getHeader() > 0);

        int hasVertex = polyline3d.getHasVertex();
        assertEquals(1, hasVertex);

        polyline3d.setHasVertex(0);
        hasVertex = polyline3d.getHasVertex();
        assertEquals(0, hasVertex);
    }

    @Test
    @Ignore
    public void testNumVertex() {
        polyline3d = createPolyline3d();
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());
        assertTrue(polyline3d.getHeader() > 0);

        long numVertex = polyline3d.getNumVertex();
        assertTrue(numVertex >= 0);

        polyline3d.setNumVertex((long)5);
        numVertex = polyline3d.getNumVertex();
        assertEquals(5, numVertex);
    }

    @Test
    public void testFirstVertex() {
        polyline3d = createPolyline3d();
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());
        assertTrue(polyline3d.getHeader() > 0);

        DwgObjectRef firstVertex = polyline3d.getFirstVertex();
        if (firstVertex != null) {
            assertNotEquals(0, firstVertex.getRef());
        }
    }

    @Test
    public void testLastVertex() {
        polyline3d = createPolyline3d();
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());
        assertTrue(polyline3d.getHeader() > 0);

        DwgObjectRef lastVertex = polyline3d.getLastVertex();
        if (lastVertex != null) {
            assertNotEquals(0, lastVertex.getRef());
        }
    }

    @Test
    public void testParent() {
        polyline3d = createPolyline3d();
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());
        assertTrue(polyline3d.getHeader() > 0);
        assertNotEquals(0, polyline3d.getRef());

        Parent parent = polyline3d.getParent();
        assertNotNull(parent);
        assertNotEquals(0, parent.getRef());
    }

    @Test
    public void testVertex() {
        polyline3d = createPolyline3d();
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());
        assertTrue(polyline3d.getHeader() > 0);

        List<DwgObjectRef> vertex = polyline3d.getVertex();
        if (vertex != null) {
            assertTrue(vertex.size() >= 0);
        }
    }

    @Test
    public void testSeqend() {
        polyline3d = createPolyline3d();
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());
        assertTrue(polyline3d.getHeader() > 0);

        DwgObjectRef seqend = polyline3d.getSeqend();
        if (seqend != null) {
            assertNotEquals(0, seqend.getRef());
        }
    }

    @Test
    public void testFlag() {
        polyline3d = createPolyline3d();
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());
        assertTrue(polyline3d.getHeader() > 0);

        int flag = polyline3d.getFlag();
        assertEquals(8, flag);

        polyline3d.setFlag(1);
        flag = polyline3d.getFlag();
        assertEquals(1, flag);
    }

    @Test
    public void testCurveType() {
        polyline3d = createPolyline3d();
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());
        assertTrue(polyline3d.getHeader() > 0);

        int curveType = polyline3d.getCurveType();
        assertEquals(0, curveType);

        polyline3d.setCurveType(2);
        curveType = polyline3d.getCurveType();
        assertEquals(2, curveType);
    }

    @Test
    public void testStartWidth() {
        polyline3d = createPolyline3d();
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());
        assertTrue(polyline3d.getHeader() > 0);

        double startWidth = polyline3d.getStartWidth();
        assertEquals(0.0, startWidth, TOLERANCE);

        polyline3d.setStartWidth(2.5);
        startWidth = polyline3d.getStartWidth();
        assertEquals(2.5, startWidth, TOLERANCE);
    }

    @Test
    public void testEndWidth() {
        polyline3d = createPolyline3d();
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());
        assertTrue(polyline3d.getHeader() > 0);

        double endWidth = polyline3d.getEndWidth();
        assertEquals(0.0, endWidth, TOLERANCE);

        polyline3d.setEndWidth(3.0);
        endWidth = polyline3d.getEndWidth();
        assertEquals(3.0, endWidth, TOLERANCE);
    }

    @Test
    public void testExtrusion() {
        polyline3d = createPolyline3d();
        assertNotNull(polyline3d);
        assertFalse(polyline3d.isEmpty());
        assertTrue(polyline3d.getHeader() > 0);
        assertNotEquals(0, polyline3d.getRef());

        Vector3d defaultExtrusion = polyline3d.getExtrusion();
        assertNotNull(defaultExtrusion);
        assertEquals(0, defaultExtrusion.getX(), TOLERANCE);
        assertEquals(0, defaultExtrusion.getY(), TOLERANCE);
        assertEquals(1, defaultExtrusion.getZ(), TOLERANCE);

        Vector3d extrusion = new Vector3d(1, 0, 0);
        polyline3d.setExtrusion(extrusion);
        Vector3d extrusion2 = polyline3d.getExtrusion();
        assertNotNull(extrusion2);
        assertEquals(1, extrusion2.getX(), TOLERANCE);
        assertEquals(0, extrusion2.getY(), TOLERANCE);
        assertEquals(0, extrusion2.getZ(), TOLERANCE);
    }
}