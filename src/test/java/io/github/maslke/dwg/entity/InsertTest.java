package io.github.maslke.dwg.entity;

import org.junit.After;
import org.junit.Ignore;
import org.junit.Test;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNull;

import java.util.List;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;

public class InsertTest extends AbstractEntityTest {

    private Insert insert;

    
    @After
    public void release() {
        if (insert != null) { 
            releaseDwg(insert);
        }
    }

    private Insert createInsert(double x, double y, double z, String blockName) {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader objectBlockHeader = dwg.getObjectBlockHeader();
        DwgObjectBlockHeader hdr = dwg.createObjectBlockHeader(blockName);
        hdr.addBlock(blockName);
        hdr.addLine(new Point3d(0, 0, 0), new Point3d(1, 1, 0));
        hdr.addPoint(new Point3d(1, 1, 0));
        hdr.addCircle(new Point3d(2, 2, 0), 5);
        hdr.addEndBlk();
        return objectBlockHeader.addInsert(new Point3d(x, y, z), blockName, 0, 0, 0, 0);
    }

    @Test
    public void testInsPt() {
        insert = createInsert(10, 10, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        Point3d insPt = insert.getInsPt();
        assertNotNull(insPt);
        assertEquals(10, insPt.getX(), TOLERANCE);
        assertEquals(10, insPt.getY(), TOLERANCE);
        assertEquals(0, insPt.getZ(), TOLERANCE);

        Point3d newInsPt = new Point3d(15, 15, 5);
        insert.setInsPt(newInsPt);
        Point3d updatedInsPt = insert.getInsPt();
        assertEquals(15, updatedInsPt.getX(), TOLERANCE);
        assertEquals(15, updatedInsPt.getY(), TOLERANCE);
        assertEquals(5, updatedInsPt.getZ(), TOLERANCE);
    }

    @Test
    public void testScaleFlag() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        int defaultScaleFlag = insert.getScaleFlag();
        assertEquals(0, defaultScaleFlag);

        insert.setScaleFlag(1);
        int updatedScaleFlag = insert.getScaleFlag();
        assertEquals(1, updatedScaleFlag);
    }

    @Test
    public void testScale() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        Point3d defaultScale = insert.getScale();
        assertNotNull(defaultScale);
        assertEquals(0, defaultScale.getX(), TOLERANCE);
        assertEquals(0, defaultScale.getY(), TOLERANCE);
        assertEquals(0, defaultScale.getZ(), TOLERANCE);

        Point3d newScale = new Point3d(2, 2, 2);
        insert.setScale(newScale);
        Point3d updatedScale = insert.getScale();
        assertEquals(2, updatedScale.getX(), TOLERANCE);
        assertEquals(2, updatedScale.getY(), TOLERANCE);
        assertEquals(2, updatedScale.getZ(), TOLERANCE);
    }

    @Test
    public void testRotation() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        double defaultRotation = insert.getRotation();
        assertEquals(0, defaultRotation, TOLERANCE);

        insert.setRotation(45.5);
        double updatedRotation = insert.getRotation();
        assertEquals(45.5, updatedRotation, TOLERANCE);
    }

    @Test
    public void testExtrusion() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        Vector3d defaultExtrusion = insert.getExtrusion();
        assertNotNull(defaultExtrusion);
        assertEquals(0, defaultExtrusion.getX(), TOLERANCE);
        assertEquals(0, defaultExtrusion.getY(), TOLERANCE);
        assertEquals(1, defaultExtrusion.getZ(), TOLERANCE);

        Vector3d newExtrusion = new Vector3d(1, 0, 0);
        insert.setExtrusion(newExtrusion);
        Vector3d updatedExtrusion = insert.getExtrusion();
        assertEquals(1, updatedExtrusion.getX(), TOLERANCE);
        assertEquals(0, updatedExtrusion.getY(), TOLERANCE);
        assertEquals(0, updatedExtrusion.getZ(), TOLERANCE);
    }

    @Test
    public void testHasAttribs() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        short defaultHasAttribs = insert.getHasAttribs();
        assertEquals(0, defaultHasAttribs);

        insert.setHasAttribs((short) 1);
        short updatedHasAttribs = insert.getHasAttribs();
        assertEquals(1, updatedHasAttribs);
    }

    @Test
    public void testNumOwned() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        int defaultNumOwned = insert.getNumOwned();
        assertEquals(0, defaultNumOwned);

        insert.setNumOwned(5);
        int updatedNumOwned = insert.getNumOwned();
        assertEquals(5, updatedNumOwned);
    }


    @Test
    public void testBlockHeader() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        DwgObjectRef blockHeader = insert.getBlockHeader();
        assertNotNull(blockHeader);
        assertNotEquals(0, blockHeader.getRef());
    }

    @Test
    public void testFirstAttrib() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        DwgObjectRef firstAttrib = insert.getFirstAttrib();
        assertNull(firstAttrib);
    }

    @Test
    public void testLastAttrib() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        DwgObjectRef lastAttrib = insert.getLastAttrib();
        assertNull(lastAttrib);
    }

    @Test
    @Ignore
    public void testSeqend() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        DwgObjectRef seqend = insert.getSeqend();
        assertNull(seqend);
    }

    @Test
    public void testAttribs() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        List<DwgObjectRef> attribs = insert.getAttribs();
        assertNull(attribs);
    }

    @Test
    public void testBlockName() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        String defaultBlockName = insert.getBlockName();
        assertEquals("TestBlock", defaultBlockName);
        insert.setBlockName("NewBlock");
        String updatedBlockName = insert.getBlockName();
        assertEquals("NewBlock", updatedBlockName); 
    }

    @Test
    public void testNumCols() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        int defaultNumCols = insert.getNumCols();
        assertEquals(0, defaultNumCols);

        insert.setNumCols(3);
        int updatedNumCols = insert.getNumCols();
        assertEquals(3, updatedNumCols);
    }

    @Test
    public void testNumRows() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        int defaultNumRows = insert.getNumRows();
        assertEquals(0, defaultNumRows);

        insert.setNumRows(4);
        int updatedNumRows = insert.getNumRows();
        assertEquals(4, updatedNumRows);
    }

    @Test
    public void testColSpacing() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        double defaultColSpacing = insert.getColSpacing();
        assertEquals(0, defaultColSpacing, TOLERANCE);

        insert.setColSpacing(10.5);
        double updatedColSpacing = insert.getColSpacing();
        assertEquals(10.5, updatedColSpacing, TOLERANCE);
    }

    @Test
    public void testRowSpacing() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        double defaultRowSpacing = insert.getRowSpacing();
        assertEquals(0, defaultRowSpacing, TOLERANCE);

        insert.setRowSpacing(15.5);
        double updatedRowSpacing = insert.getRowSpacing();
        assertEquals(15.5, updatedRowSpacing, TOLERANCE);
    }

    

    @Test
    public void testParent() {
        insert = createInsert(0, 0, 0, "TestBlock");
        assertNotNull(insert);
        assertFalse(insert.isEmpty());
        assertTrue(insert.getHeader() > 0);
        assertNotEquals(0, insert.getRef());
        Parent parent = insert.getParent();
        assertNotNull(parent);
        assertNotEquals(0, parent.getRef());
    }
}
