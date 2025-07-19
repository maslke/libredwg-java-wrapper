package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.entity.component.LwpolylineWidth;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import org.junit.After;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

public class LwpolylineTest extends AbstractEntityTest {
    private Lwpolyline lwpolyline;

    private Lwpolyline createLwpolyline() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        return hdr.addLwpolyline(Arrays.asList(new Point2d(0, 0), new Point2d(1, 1)));
    }

    @After
    public void release() {
        if (lwpolyline != null) {
            releaseDwg(lwpolyline);
        }
    }

    @Test
    public void testFlag() {
        lwpolyline = createLwpolyline();
        assertNotNull(lwpolyline);
        assertFalse(lwpolyline.isEmpty());
        assertTrue(lwpolyline.getHeader() > 0);
        int flag = lwpolyline.getFlag();
        assertEquals(0, flag);
        flag = lwpolyline.getFlagNative(lwpolyline.getRef());
        assertEquals(0, flag);
        lwpolyline.setFlag(1);
        flag = lwpolyline.getFlag();
        assertEquals(1, flag);
        flag = lwpolyline.getFlagNative(lwpolyline.getRef());
        assertEquals(1, flag);
    }

    @Test
    public void testElevation() {
        lwpolyline = createLwpolyline();
        assertNotNull(lwpolyline);
        assertFalse(lwpolyline.isEmpty());
        assertTrue(lwpolyline.getHeader() > 0);
        double elevation = lwpolyline.getElevation();
        assertEquals(0, elevation, TOLERANCE);
        elevation = lwpolyline.getElevationNative(lwpolyline.getRef());
        assertEquals(0, elevation, TOLERANCE);
        lwpolyline.setElevation(2.0);
        elevation = lwpolyline.getElevation();
        assertEquals(2.0, elevation, TOLERANCE);
        elevation = lwpolyline.getElevationNative(lwpolyline.getRef());
        assertEquals(2.0, elevation, TOLERANCE);
    }

    @Test
    public void testConstWidth() {
        lwpolyline = createLwpolyline();
        assertNotNull(lwpolyline);
        assertFalse(lwpolyline.isEmpty());
        assertTrue(lwpolyline.getHeader() > 0);
        double constWidth = lwpolyline.getConstWidth();
        assertEquals(0, constWidth, TOLERANCE);
        constWidth = lwpolyline.getConstWidthNative(lwpolyline.getRef());
        assertEquals(0, constWidth, TOLERANCE);
        lwpolyline.setConstWidth(2);
        constWidth = lwpolyline.getConstWidthNative(lwpolyline.getRef());
        assertEquals(2, constWidth, TOLERANCE);
        constWidth = lwpolyline.getConstWidth();
        assertEquals(2, constWidth, TOLERANCE);
    }

    @Test
    public void testThickness() {
        lwpolyline = createLwpolyline();
        assertNotNull(lwpolyline);
        assertFalse(lwpolyline.isEmpty());
        assertTrue(lwpolyline.getHeader() > 0);
        double thickness = lwpolyline.getThickness();
        assertEquals(0, thickness, TOLERANCE);
        thickness = lwpolyline.getThicknessNative(lwpolyline.getRef());
        assertEquals(0, thickness, TOLERANCE);
        lwpolyline.setThickness(1.0);
        thickness = lwpolyline.getThickness();
        assertEquals(1, thickness, TOLERANCE);
        thickness = lwpolyline.getThicknessNative(lwpolyline.getRef());
        assertEquals(1, thickness, TOLERANCE);
    }

    @Test
    public void testExtrusion() {
        lwpolyline = createLwpolyline();
        assertNotNull(lwpolyline);
        assertFalse(lwpolyline.isEmpty());
        assertTrue(lwpolyline.getHeader() > 0);
        Vector3d extrusion = lwpolyline.getExtrusionNative(lwpolyline.getRef());
        assertNotNull(extrusion);
        assertEquals(0, extrusion.getX(), TOLERANCE);
        assertEquals(0, extrusion.getY(), TOLERANCE);
        assertEquals(1, extrusion.getZ(), TOLERANCE);
        extrusion = lwpolyline.getExtrusionNative(lwpolyline.getRef());
        assertNotNull(extrusion);
        assertEquals(0, extrusion.getX(), TOLERANCE);
        assertEquals(0, extrusion.getY(), TOLERANCE);
        assertEquals(1, extrusion.getZ(), TOLERANCE);
        lwpolyline.setExtrusion(new Vector3d(1, 0, 0));
        extrusion = lwpolyline.getExtrusion();
        assertNotNull(extrusion);
        assertEquals(1, extrusion.getX(), TOLERANCE);
        assertEquals(0, extrusion.getY(), TOLERANCE);
        assertEquals(0, extrusion.getZ(), TOLERANCE);
        extrusion = lwpolyline.getExtrusionNative(lwpolyline.getRef());
        assertNotNull(extrusion);
        assertEquals(1, extrusion.getX(), TOLERANCE);
        assertEquals(0, extrusion.getY(), TOLERANCE);
        assertEquals(0, extrusion.getZ(), TOLERANCE);
    }

    @Test
    public void testPoints() {
        lwpolyline = createLwpolyline();
        assertNotNull(lwpolyline);
        assertFalse(lwpolyline.isEmpty());
        assertTrue(lwpolyline.getHeader() > 0);
        int numPoints = lwpolyline.getNumPointsNative(lwpolyline.getRef());
        assertEquals(2, numPoints);
        numPoints = lwpolyline.getNumPointsNative(lwpolyline.getRef());
        assertEquals(2, numPoints);
        List<Point2d> point2ds = lwpolyline.getPointsNative(lwpolyline.getRef());
        assertNotNull(point2ds);
        assertEquals(2, point2ds.size());
        assertEquals(0, point2ds.get(0).getX(), TOLERANCE);
        assertEquals(0, point2ds.get(0).getY(), TOLERANCE);
        assertEquals(1, point2ds.get(1).getX(), TOLERANCE);
        assertEquals(1, point2ds.get(1).getY(), TOLERANCE);
        point2ds = lwpolyline.getPointsNative(lwpolyline.getRef());
        assertNotNull(point2ds);
        assertEquals(2, point2ds.size());
        assertEquals(0, point2ds.get(0).getX(), TOLERANCE);
        assertEquals(0, point2ds.get(0).getY(), TOLERANCE);
        assertEquals(1, point2ds.get(1).getX(), TOLERANCE);
        assertEquals(1, point2ds.get(1).getY(), TOLERANCE);
        lwpolyline.setPoints(Arrays.asList(new Point2d(0, 0), new Point2d(1, 1), new Point2d(2, 2)));
        point2ds = lwpolyline.getPoints();
        assertNotNull(point2ds);
        assertEquals(3, point2ds.size());
        assertEquals(0, point2ds.get(0).getX(), TOLERANCE);
        assertEquals(0, point2ds.get(0).getY(), TOLERANCE);
        assertEquals(1, point2ds.get(1).getX(), TOLERANCE);
        assertEquals(1, point2ds.get(1).getY(), TOLERANCE);
        assertEquals(2, point2ds.get(2).getX(), TOLERANCE);
        assertEquals(2, point2ds.get(2).getY(), TOLERANCE);
        point2ds = lwpolyline.getPointsNative(lwpolyline.getRef());
        assertNotNull(point2ds);
        assertEquals(3, point2ds.size());
        assertEquals(0, point2ds.get(0).getX(), TOLERANCE);
        assertEquals(0, point2ds.get(0).getY(), TOLERANCE);
        assertEquals(1, point2ds.get(1).getX(), TOLERANCE);
        assertEquals(1, point2ds.get(1).getY(), TOLERANCE);
        assertEquals(2, point2ds.get(2).getX(), TOLERANCE);
        assertEquals(2, point2ds.get(2).getY(), TOLERANCE);
    }

    @Test
    public void testVertexids() {
        lwpolyline = createLwpolyline();
        assertNotNull(lwpolyline);
        assertFalse(lwpolyline.isEmpty());
        assertTrue(lwpolyline.getHeader() > 0);
        int vertexids = lwpolyline.getNumVertexids();
        assertEquals(2, vertexids);
        vertexids = lwpolyline.getNumVertexidsNative(lwpolyline.getRef());
        assertEquals(2, vertexids);
        lwpolyline.setPoints(Arrays.asList(new Point2d(0, 0), new Point2d(1, 1), new Point2d(2, 2)));
        vertexids = lwpolyline.getNumVertexidsNative(lwpolyline.getRef());
        assertEquals(3, vertexids);
        vertexids = lwpolyline.getNumVertexids();
        assertEquals(3, vertexids);
    }

    @Test
    public void testBulges() {
        lwpolyline = createLwpolyline();
        assertNotNull(lwpolyline);
        assertFalse(lwpolyline.isEmpty());
        assertTrue(lwpolyline.getHeader() > 0);
        int numBulges = lwpolyline.getNumBulgesNative(lwpolyline.getRef());
        assertEquals(0, numBulges);
        lwpolyline.setNumBulges(1);
        lwpolyline.setBulges(new ArrayList<>(Collections.singletonList(1)));
        numBulges = lwpolyline.getNumBulges();
        assertEquals(1, numBulges);
        numBulges = lwpolyline.getNumBulgesNative(lwpolyline.getRef());
        assertEquals(1, numBulges);
        List<Integer> bulges = lwpolyline.getBulges();
        assertNotNull(bulges);
        assertEquals(1, bulges.size());
        assertEquals(1, bulges. get(0).intValue());
    }

    @Test
    public void testWidths() {
        lwpolyline = createLwpolyline();
        assertNotNull(lwpolyline);
        assertFalse(lwpolyline.isEmpty());
        assertTrue(lwpolyline.getHeader() > 0);
        int numWidths = lwpolyline.getNumWidthsNative(lwpolyline.getRef());
        assertEquals(0, numWidths);
        lwpolyline.setWidths(Arrays.asList(new LwpolylineWidth(1, 2), new LwpolylineWidth(1, 1)));

        List<LwpolylineWidth> widths = lwpolyline.getWidths();
        assertNotNull(widths);
        assertEquals(2, widths.size());
        assertEquals(1, widths.get(0).getStart(), TOLERANCE);
        assertEquals(2, widths.get(0).getEnd(), TOLERANCE);
        assertEquals(1, widths.get(1).getStart(), TOLERANCE);
        assertEquals(1, widths.get(1).getEnd(), TOLERANCE);

        widths = lwpolyline.getWidthsNative(lwpolyline.getRef());
        assertNotNull(widths);
        assertEquals(2, widths.size());
        assertEquals(1, widths.get(0).getStart(), TOLERANCE);
        assertEquals(2, widths.get(0).getEnd(), TOLERANCE);
        assertEquals(1, widths.get(1).getStart(), TOLERANCE);
        assertEquals(1, widths.get(1).getEnd(), TOLERANCE);

    }


}
