package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.obj.DwgObjectEntity;
import org.junit.After;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class Polyline2dTest extends AbstractEntityTest {

    private Polyline2d polyline2d;

    private Polyline2d createPolyline2d() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        List<Point2d> points = Arrays.asList(
                new Point2d(0, 0),
                new Point2d(10, 10),
                new Point2d(20, 0)
        );
        return hdr.addPolyline2d(points);
    }

    @After
    public void release() {
        if (polyline2d != null) {
            releaseDwg(polyline2d);
        }
    }

    @Test
    public void testHasVertex() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        int hasVertex = polyline2d.getHasVertex();
        assertEquals(1, hasVertex);

        polyline2d.setHasVertex(0);
        hasVertex = polyline2d.getHasVertex();
        assertEquals(0, hasVertex);
    }

    @Test
    public void testNumOwned() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        long numOwned = polyline2d.getNumOwned();
        assertEquals(3, numOwned);
    }

    @Test
    public void testFirstVertex() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        DwgObjectRef firstVertex = polyline2d.getFirstVertex();
        assertNotNull(firstVertex);
        assertNotEquals(0, firstVertex.getRef());
    }

    @Test
    public void testLastVertex() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        DwgObjectRef lastVertex = polyline2d.getLastVertex();
        assertNotNull(lastVertex);
        assertNotEquals(0, lastVertex.getRef());
    }

    @Test
    public void tstGetVertex() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        List<DwgObjectRef> vertex = polyline2d.getVertex();
        assertNotNull(vertex);
        assertEquals(3, vertex.size());
    }

    @Test
    public void testParent() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);
        assertNotEquals(0, polyline2d.getRef());

        DwgObjectEntity parent = polyline2d.getParent();
        assertNotNull(parent);
        assertNotEquals(0, parent.ref);
    }

    @Test
    public void testVertex() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        List<DwgObjectRef> vertex = polyline2d.getVertex();
        assertNotNull(vertex);
        assertEquals(3, vertex.size());
    }

    @Test
    public void testSeqend() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        DwgObjectRef seqend = polyline2d.getSeqend();
        assertNotNull(seqend);
        assertNotEquals(0, seqend.getRef());
    }

    @Test
    public void testFlag() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        int flag = polyline2d.getFlag();
        assertEquals(0, flag);

        polyline2d.setFlag(1);
        flag = polyline2d.getFlag();
        assertEquals(1, flag);
    }

    @Test
    public void testCurveType() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        int curveType = polyline2d.getCurveType();
        assertEquals(0, curveType);

        polyline2d.setCurveType(2);
        curveType = polyline2d.getCurveType();
        assertEquals(2, curveType);
    }

    @Test
    public void testStartWidth() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        double startWidth = polyline2d.getStartWidth();
        assertEquals(0.0, startWidth, TOLERANCE);

        polyline2d.setStartWidth(2.5);
        startWidth = polyline2d.getStartWidth();
        assertEquals(2.5, startWidth, TOLERANCE);
    }

    @Test
    public void testEndWidth() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        double endWidth = polyline2d.getEndWidth();
        assertEquals(0.0, endWidth, TOLERANCE);

        polyline2d.setEndWidth(3.0);
        endWidth = polyline2d.getEndWidth();
        assertEquals(3.0, endWidth, TOLERANCE);
    }

    @Test
    public void testThickness() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        double thickness = polyline2d.getThickness();
        assertEquals(0.0, thickness, TOLERANCE);

        polyline2d.setThickness(1.5);
        thickness = polyline2d.getThickness();
        assertEquals(1.5, thickness, TOLERANCE);
    }

    @Test
    public void testElevation() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        double elevation = polyline2d.getElevation();
        assertEquals(0.0, elevation, TOLERANCE);

        polyline2d.setElevation(10.0);
        elevation = polyline2d.getElevation();
        assertEquals(10.0, elevation, TOLERANCE);
    }

    @Test
    public void testExtrusion() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);
        assertNotEquals(0, polyline2d.getRef());

        Vector3d defaultExtrusion = polyline2d.getExtrusion();
        assertNotNull(defaultExtrusion);
        assertEquals(0, defaultExtrusion.getX(), TOLERANCE);
        assertEquals(0, defaultExtrusion.getY(), TOLERANCE);
        assertEquals(1, defaultExtrusion.getZ(), TOLERANCE);

        Vector3d extrusion = new Vector3d(1, 0, 0);
        polyline2d.setExtrusion(extrusion);
        Vector3d extrusion2 = polyline2d.getExtrusion();
        assertNotNull(extrusion2);
        assertEquals(1, extrusion2.getX(), TOLERANCE);
        assertEquals(0, extrusion2.getY(), TOLERANCE);
        assertEquals(0, extrusion2.getZ(), TOLERANCE);
    }

    @Test
    public void testExtraR11Size() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        long extraR11Size = polyline2d.getExtraR11Size();
        assertEquals(0, extraR11Size);

        polyline2d.setExtraR11Size(100);
        extraR11Size = polyline2d.getExtraR11Size();
        assertEquals(100, extraR11Size);
    }

    @Test
    public void testExtraR11Text() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        String extraR11Text = polyline2d.getExtraR11Text();
        // 可能为null或空字符串

        polyline2d.setExtraR11Text("测试文本");
        extraR11Text = polyline2d.getExtraR11Text();
        assertEquals("测试文本", extraR11Text);
    }

    @Test
    public void testNumMVerts() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        int numMVerts = polyline2d.getNumMVerts();
        assertEquals(0, numMVerts);

        polyline2d.setNumMVerts(5);
        numMVerts = polyline2d.getNumMVerts();
        assertEquals(5, numMVerts);
    }

    @Test
    public void testNumNVerts() {
        polyline2d = createPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
        assertTrue(polyline2d.getHeader() > 0);

        int numNVerts = polyline2d.getNumNVerts();
        assertEquals(0, numNVerts);

        polyline2d.setNumNVerts(3);
        numNVerts = polyline2d.getNumNVerts();
        assertEquals(3, numNVerts);
    }
}
