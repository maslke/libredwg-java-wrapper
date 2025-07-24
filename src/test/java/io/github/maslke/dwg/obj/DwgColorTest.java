package io.github.maslke.dwg.obj;

import org.junit.Test;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.entity.Parent;
import io.github.maslke.dwg.entity.Line;
import org.junit.After;

public class DwgColorTest {

    private Parent parent;

    public Parent getParent() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        Line line = hdr.addLine(new Point3d(0, 0, 0), new Point3d(10, 10, 0));
        return line.getParent();
    }

    @After
    public void release() {
        if (parent != null) {
            parent.getDwg().release();
        }
    }

    @Test
    public void testIndex() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        DwgColor color = parent.getColor();
        assertNotNull(color);
        assertTrue(color.getRef() > 0);
        color.setIndex(3);
        int index = color.getIndex();
        assertEquals(3, index);
        color.setIndex(-1);
        index = color.getIndex();
        assertEquals(-1, index);
        color.setIndex(0);
        index = color.getIndex();
        assertEquals(0, index);
        color.setIndex(256);
        index = color.getIndex();
        assertEquals(256, index);
    }

    @Test
    public void testName() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        DwgColor color = parent.getColor();
        assertNotNull(color);
        assertTrue(color.getRef() > 0);
        color.setName("Red");
        String name = color.getName();
        assertEquals("Red", name);
    }

    @Test
    public void testBookName() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        DwgColor color = parent.getColor();
        assertNotNull(color);
        assertTrue(color.getRef() > 0);
        color.setBookName("Book$Test");
        String bookName = color.getBookName();
        assertEquals("Book$Test", bookName);
    }
    @Test
    public void testFlag() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        DwgColor color = parent.getColor();
        assertNotNull(color);
        assertTrue(color.getRef() > 0);
        color.setFlag(1);
        int flag = color.getFlag();
        assertEquals(1, flag);
    }

    @Test
    public void testRgb() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        DwgColor color = parent.getColor();
        assertNotNull(color);
        assertTrue(color.getRef() > 0);
        color.setRgb(Integer.parseInt("FF", 16));
        int rgb = color.getRgb();
        assertEquals(255, rgb);
        color.setRgb(Integer.parseInt("FF00", 16));
        rgb = color.getRgb();
        assertEquals(65280, rgb);
    }

    @Test
    public void testMethod() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        DwgColor color = parent.getColor();
        assertNotNull(color);
        assertTrue(color.getRef() > 0);
        color.setMethod(Integer.parseInt("C0", 16));
        int method = color.getMethod();
        assertEquals(192, method);
        color.setMethod(Integer.parseInt("C1", 16));
        method = color.getMethod();
        assertEquals(193, method);
        color.setMethod(Integer.parseInt("C2", 16));
        method = color.getMethod();
        assertEquals(194, method);
        color.setMethod(Integer.parseInt("C3", 16));
        method = color.getMethod();
        assertEquals(195, method);
        color.setMethod(Integer.parseInt("C5", 16));
        method = color.getMethod();
        assertEquals(197, method);
    }

    @Test
    public void testAlpha() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        DwgColor color = parent.getColor();
        assertNotNull(color);
        assertTrue(color.getRef() > 0);
        color.setAlpha(1);
        int alpha = color.getAlpha();
        assertEquals(1, alpha);
        color.setAlpha(0);
        alpha = color.getAlpha();
        assertEquals(0, alpha);
        color.setAlpha(255);
        alpha = color.getAlpha();
        assertEquals(255, alpha);
    }

    @Test
    public void testAlphaRaw() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        DwgColor color = parent.getColor();
        assertNotNull(color);
        assertTrue(color.getRef() > 0);
        color.setAlphaRaw(1);
        int alphaRaw = color.getAlphaRaw();
        assertEquals(1, alphaRaw);
        color.setAlphaRaw(0);
        alphaRaw = color.getAlphaRaw();
        assertEquals(0, alphaRaw);
        color.setAlphaRaw(255);
    }

    @Test
    public void testAlphaType() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        DwgColor color = parent.getColor();
        assertNotNull(color);
        assertTrue(color.getRef() > 0);
        color.setAlphaType((short) 1);
        short alphaType = color.getAlphaType();
        assertEquals((short) 1, alphaType);
        color.setAlphaType((short) 0);
        alphaType = color.getAlphaType();
        assertEquals((short) 0, alphaType);
        color.setAlphaType((short) 3);
        alphaType = color.getAlphaType();
        assertEquals((short) 3, alphaType);
    }   
}
