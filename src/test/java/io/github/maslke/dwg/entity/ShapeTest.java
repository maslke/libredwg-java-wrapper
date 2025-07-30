package io.github.maslke.dwg.entity;

import org.junit.After;
import org.junit.Test;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import io.github.maslke.dwg.obj.DwgObjectEntity;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.support.TableType;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class ShapeTest extends AbstractEntityTest {
    private Shape shape;

    private Shape createShape() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        Point3d point = new Point3d(10, 10, 0);
        return hdr.addShape("shape", point, 1.0, 0.0);
    }

    @Test
    public void testInsPt() {
        shape = createShape();
        assertNotNull(shape);
        assertFalse(shape.isEmpty());
        Point3d point = shape.getInsPt();
        assertEquals(10, point.getX(), TOLERANCE);
        assertEquals(10, point.getY(), TOLERANCE);
        assertEquals(0, point.getZ(), TOLERANCE);
        shape.setInsPt(new Point3d(20, 20, 0));
        point = shape.getInsPt();
        assertEquals(20, point.getX(), TOLERANCE);
        assertEquals(20, point.getY(), TOLERANCE);
        assertEquals(0, point.getZ(), TOLERANCE);
    }


    @Test
    public void testRotation() {
        shape = createShape();
        assertNotNull(shape);
        assertFalse(shape.isEmpty());
        assertTrue(shape.getHeader() > 0);
        shape.setRotation(0.5);
        double rotation = shape.getRotation();
        assertEquals(0.5, rotation, TOLERANCE);
    }

    @Test
    public void testThickness() {
        shape = createShape();
        assertNotNull(shape);
        assertFalse(shape.isEmpty());
        assertTrue(shape.getHeader() > 0);
        shape.setThickness(1.2);
        double thickness = shape.getThickness();
        assertEquals(1.2, thickness, TOLERANCE);
    }

    @Test
    public void testExtrusion() {
        shape = createShape();
        assertNotNull(shape);
        assertFalse(shape.isEmpty());
        assertTrue(shape.getHeader() > 0);
        Vector3d defaultExtrusion = shape.getExtrusion();
        assertNotNull(defaultExtrusion);
        assertEquals(0, defaultExtrusion.getX(), TOLERANCE);
        assertEquals(0, defaultExtrusion.getY(), TOLERANCE);
        assertEquals(1, defaultExtrusion.getZ(), TOLERANCE);
        shape.setExtrusion(new Vector3d(1, 0, 0));
        Vector3d extrusion = shape.getExtrusion();
        assertNotNull(extrusion);
        assertEquals(1, extrusion.getX(), TOLERANCE);
        assertEquals(0, extrusion.getY(), TOLERANCE);
        assertEquals(0, extrusion.getZ(), TOLERANCE);
    }

    @Test
    public void testWidthFactor() {
        shape = createShape();
        assertNotNull(shape);
        assertFalse(shape.isEmpty());
        assertTrue(shape.getHeader() > 0);
        shape.setWidthFactor(1.2);
        double widthFactor = shape.getWidthFactor();
        assertEquals(1.2, widthFactor, TOLERANCE);
    }

    @Test
    public void testObliqueAngle() {
        shape = createShape();
        assertNotNull(shape);
        assertFalse(shape.isEmpty());
        assertTrue(shape.getHeader() > 0);
        shape.setObliqueAngle(0.5);
        double angle = shape.getObliqueAngle();
        assertEquals(0.5, angle, TOLERANCE);
    }

    @Test
    public void testStyle() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        Point3d point = new Point3d(10, 10, 0);
        shape = hdr.addShape("shape", point, 1.0, 0.0);
        assertNotNull(shape);
        assertFalse(shape.isEmpty());
        assertTrue(shape.getHeader() > 0);
        DwgObjectRef style = dwg.findTableHandle("Standard", TableType.STYLE);
        assertNotNull(style);
        shape.setStyle(style);
        DwgObjectRef style2 = shape.getStyle();
        assertNotNull(style2);
        assertEquals(style.getRef(), style2.getRef());
    }

    @Test
    public void testStyleId() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        Point3d point = new Point3d(10, 10, 0);
        shape = hdr.addShape("shape", point, 1.0, 0.0);
        assertNotNull(shape);
        assertFalse(shape.isEmpty());
        assertTrue(shape.getHeader() > 0);
        shape.setStyleId(5);
        int styleId = shape.getStyleId();
        assertEquals(5, styleId);
    }

    @Test
    public void testParent() {
        shape = createShape();
        assertNotNull(shape);
        assertFalse(shape.isEmpty());
        assertTrue(shape.getHeader() > 0);
        DwgObjectEntity parent = shape.getParent();
        assertNotNull(parent);
        assertNotEquals(0, parent.ref);
    }

    @After
    public void release() {
        if (shape != null) {
            releaseDwg(shape);
        }
    }
}
