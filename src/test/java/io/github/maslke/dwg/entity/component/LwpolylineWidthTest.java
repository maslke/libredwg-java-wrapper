package io.github.maslke.dwg.entity.component;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class LwpolylineWidthTest {
    @Test
    public void testLwpolylineWidth() {
        LwpolylineWidth width = new LwpolylineWidth();
        assertEquals(0.0, width.getStart(), 0.000001);
        assertEquals(0.0, width.getEnd(), 0.000001);
        width.setStart(1.0);
        width.setEnd(2.0);
        assertEquals(1.0, width.getStart(), 0.000001);
        assertEquals(2.0, width.getEnd(), 0.000001);

        width = new LwpolylineWidth(1.0, 2.0);
        assertEquals(1.0, width.getStart(), 0.000001);
        assertEquals(2.0, width.getEnd(), 0.000001);
    }
}
