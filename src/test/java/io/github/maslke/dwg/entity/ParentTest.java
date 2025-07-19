package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.support.TableType;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

public class ParentTest extends AbstractEntityTest {

    private Parent parent;

    public Parent getParent() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        Line line = hdr.addLine(new Point3d(0, 0, 0), new Point3d(10, 10, 0));
        return line.getParent();
    }



    @Test
    public void testColor() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        parent.setColor(3);
        assertNotEquals(0, parent.getRef());
        int color = parent.getColor();
        assertEquals(3, color);
    }

    @Test
    public void testLinewt() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        parent.setLinewt(50);
        int linewt = parent.getLinewt();
        assertEquals(50, linewt);
    }

    @Test
    public void testLtype() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        Dwg dwg = parent.getDwg();
        DwgObjectRef ltypeRef = dwg.findTableHandle("CONTINUOUS", TableType.LTYPE);
        assertNotNull(ltypeRef);
        parent.setLtype(ltypeRef);
        DwgObjectRef ltype = parent.getLtype();
        assertNotNull(ltype);
        assertEquals(ltypeRef.getAbsoluteRef(), ltype.getAbsoluteRef());
        assertEquals(ltypeRef.getR11Idx(), ltype.getR11Idx());
        assertEquals(ltypeRef.getRef(), ltype.getRef());
    }

    @Test
    public void testLayer() {
        parent = getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        Dwg dwg = parent.getDwg();
        DwgObjectRef layerRef = dwg.findTableHandle("0", TableType.LAYER);
        assertNotNull(layerRef);
        parent.setLayer(layerRef);
        DwgObjectRef layer = parent.getLayer();
        assertNotNull(layer);
        assertEquals(layer.getRef(), layerRef.getRef());
        assertEquals(layer.getAbsoluteRef(), layerRef.getAbsoluteRef());
        assertEquals(layer.getR11Idx(), layerRef.getR11Idx());
    }
}
