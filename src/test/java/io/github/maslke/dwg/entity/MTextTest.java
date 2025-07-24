package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.obj.DwgColor;
import io.github.maslke.dwg.support.TableType;
import org.junit.After;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class MTextTest extends AbstractEntityTest {

    private MText mtext;

    @After
    public void release() {
        if (mtext != null) {
            releaseDwg(mtext);
        }
    }

    private MText createMText(String textValue, Point3d insertPt, double rectWidth) {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        return hdr.addMText(textValue, insertPt, rectWidth);
    }

    private MText createMText() {
        return createMText("MTEXT", new Point3d(10, 10, 0), 2.53);
    }

    @Test
    public void testText() {
        mtext = createMText("English MText", new Point3d(10, 10, 0), 2.5);
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        String textValue = mtext.getText();
        assertEquals("English MText", textValue);

        mtext.setText("中文多行文本");
        textValue = mtext.getText();
        assertEquals("中文多行文本", textValue);
    }

    @Test
    public void testTextHeight() {
        mtext = createMText("MText", new Point3d(10, 10, 0), 2.5);
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setTextHeight(2.5);
        double height = mtext.getTextHeight();
        assertEquals(2.5, height, TOLERANCE);
        mtext.setTextHeight(3.0);
        height = mtext.getTextHeight();
        assertEquals(3.0, height, TOLERANCE);
    }

    @Test
    public void testInsPt() {
        mtext = createMText("MText", new Point3d(10, 10, 0), 2.5);
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        Point3d insPt = mtext.getInsPt();
        assertNotNull(insPt);
        assertEquals(10, insPt.getX(), TOLERANCE);
        assertEquals(10, insPt.getY(), TOLERANCE);
        assertEquals(0, insPt.getZ(), TOLERANCE);

        mtext.setInsPt(new Point3d(15, 12, 5));
        insPt = mtext.getInsPt();
        assertNotNull(insPt);
        assertEquals(15, insPt.getX(), TOLERANCE);
        assertEquals(12, insPt.getY(), TOLERANCE);
        assertEquals(5, insPt.getZ(), TOLERANCE);
    }

    @Test
    public void testExtrusion() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        Vector3d defaultExtrusion = mtext.getExtrusion();
        assertNotNull(defaultExtrusion);
        assertEquals(0, defaultExtrusion.getX(), TOLERANCE);
        assertEquals(0, defaultExtrusion.getY(), TOLERANCE);
        assertEquals(1, defaultExtrusion.getZ(), TOLERANCE);
        mtext.setExtrusion(new Vector3d(0, 1, 0));
        Vector3d extrusion = mtext.getExtrusion();
        assertNotNull(extrusion);
        assertEquals(0, extrusion.getX(), TOLERANCE);
        assertEquals(1, extrusion.getY(), TOLERANCE);
        assertEquals(0, extrusion.getZ(), TOLERANCE);
    }

    @Test
    public void testXAxisDir() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setXAxisDir(new Point3d(1, 0, 0));
        Point3d xAxisDir = mtext.getXAxisDir();
        assertNotNull(xAxisDir);
        assertEquals(1, xAxisDir.getX(), TOLERANCE);
        assertEquals(0, xAxisDir.getY(), TOLERANCE);
        assertEquals(0, xAxisDir.getZ(), TOLERANCE);
    }

    @Test
    public void testRectWidth() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setRectWidth(100.0);
        double rectWidth = mtext.getRectWidth();
        assertEquals(100.0, rectWidth, TOLERANCE);
    }

    @Test
    public void testRectHeight() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setRectHeight(50.0);
        double rectHeight = mtext.getRectHeight();
        assertEquals(50.0, rectHeight, TOLERANCE);
    }

    @Test
    public void testAttachment() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setAttachment(1);
        int attachment = mtext.getAttachment();
        assertEquals(1, attachment);
    }

    @Test
    public void testFlowDir() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setFlowDir(5);
        int flowDir = mtext.getFlowDir();
        assertEquals(5, flowDir);
    }

    @Test
    public void testExtentsWidth() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setExtentsWidth(80.0);
        double extentsWidth = mtext.getExtentsWidth();
        assertEquals(80.0, extentsWidth, TOLERANCE);
    }

    @Test
    public void testExtentsHeight() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setExtentsHeight(40.0);
        double extentsHeight = mtext.getExtentsHeight();
        assertEquals(40.0, extentsHeight, TOLERANCE);
    }

    @Test
    public void testLinespaceStyle() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setLinespaceStyle(2);
        int linespaceStyle = mtext.getLinespaceStyle();
        assertEquals(2, linespaceStyle);
    }

    @Test
    public void testLinespaceFactor() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setLinespaceFactor(1.5);
        double linespaceFactor = mtext.getLinespaceFactor();
        assertEquals(1.5, linespaceFactor, TOLERANCE);
    }

    @Test
    public void testUnknownB0() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setUnknownB0(123);
        int unknownB0 = mtext.getUnknownB0();
        assertEquals(123, unknownB0);
    }

    @Test
    public void testBgFillFlag() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setBgFillFlag(1);
        int bgFillFlag = mtext.getBgFillFlag();
        assertEquals(1, bgFillFlag);
    }

    @Test
    public void testBgFillScale() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setBgFillScale(150);
        int bgFillScale = mtext.getBgFillScale();
        assertEquals(150, bgFillScale);
    }

    @Test
    public void testBgFillTrans() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setBgFillTrans(75);
        int bgFillTrans = mtext.getBgFillTrans();
        assertEquals(75, bgFillTrans);
    }

    @Test
    public void testBgFillColor() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        mtext = hdr.addMText("MText", new Point3d(10, 10, 0), 1.2);
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        
        DwgColor color = mtext.getBgFillColor();
        if (color != null) {
            color.setIndex(5);
            mtext.setBgFillColor(color);
            DwgColor retrievedColor = mtext.getBgFillColor();
            assertNotNull(retrievedColor);
            assertEquals(5, retrievedColor.getIndex());
        }
    }

    @Test
    public void testIsNotAnnotative() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setIsNotAnnotative(1);
        int isNotAnnotative = mtext.getIsNotAnnotative();
        assertEquals(1, isNotAnnotative);
    }

    @Test
    public void testClassVersion() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setClassVersion(2);
        int classVersion = mtext.getClassVersion();
        assertEquals(2, classVersion);
    }

    @Test
    public void testDefaultFlag() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setDefaultFlag(1);
        int defaultFlag = mtext.getDefaultFlag();
        assertEquals(1, defaultFlag);
    }

    @Test
    public void testIgnoreAttachment() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setIgnoreAttachment(999L);
        long ignoreAttachment = mtext.getIgnoreAttachment();
        assertEquals(999L, ignoreAttachment);
    }

    @Test
    public void testColumnType() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setColumnType(3);
        int columnType = mtext.getColumnType();
        assertEquals(3, columnType);
    }

    @Test
    public void testNumFragments() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setNumFragments(5L);
        long numFragments = mtext.getNumFragments();
        assertEquals(5L, numFragments);
    }

    @Test
    public void testColumnWidth() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setColumnWidth(120.0);
        double columnWidth = mtext.getColumnWidth();
        assertEquals(120.0, columnWidth, TOLERANCE);
    }

    @Test
    public void testGutter() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setGutter(10.0);
        double gutter = mtext.getGutter();
        assertEquals(10.0, gutter, TOLERANCE);
    }

    @Test
    public void testAutoHeight() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setAutoHeight(1);
        int autoHeight = mtext.getAutoHeight();
        assertEquals(1, autoHeight);
    }

    @Test
    public void testFlowReversed() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setFlowReversed(1);
        int flowReversed = mtext.getFlowReversed();
        assertEquals(1, flowReversed);
    }

    @Test
    public void testNumColumnHeights() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        mtext.setNumColumnHeights(3L);
        long numColumnHeights = mtext.getNumColumnHeights();
        assertEquals(3L, numColumnHeights);
    }

    @Test
    public void testColumnHeights() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        List<Double> heights = Arrays.asList(10.0, 20.0, 30.0);
        mtext.setColumnHeights(heights);
        List<Double> retrievedHeights = mtext.getColumnHeights();
        assertNotNull(retrievedHeights);
        assertEquals(3, retrievedHeights.size());
        assertEquals(10.0, retrievedHeights.get(0), TOLERANCE);
        assertEquals(20.0, retrievedHeights.get(1), TOLERANCE);
        assertEquals(30.0, retrievedHeights.get(2), TOLERANCE);
    }

    @Test
    public void testStyle() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        mtext = hdr.addMText("MText", new Point3d(10, 10, 0), 1.2);
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        DwgObjectRef objectRef = dwg.findTableHandle("CONTINUOUS", TableType.LTYPE);
        assertNotNull(objectRef);
        mtext.setStyle(objectRef);

        DwgObjectRef style = mtext.getStyle();
        assertNotNull(style);
        assertEquals(objectRef.getRef(), style.getRef());
        assertEquals(objectRef.getAbsoluteRef(), style.getAbsoluteRef());
        assertEquals(objectRef.getR11Idx(), style.getR11Idx());
    }

    @Test
    public void testAppid() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        mtext = hdr.addMText("MText", new Point3d(10, 10, 0), 1.2);
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        assertTrue(mtext.getHeader() > 0);
        DwgObjectRef appidRef = dwg.findTableHandle("ACAD", TableType.APPID);
        if (appidRef != null) {
            mtext.setAppid(appidRef);
            DwgObjectRef retrievedAppid = mtext.getAppid();
            assertNotNull(retrievedAppid);
            assertEquals(appidRef.getRef(), retrievedAppid.getRef());
        }
    }

    @Test
    public void testParent() {
        mtext = createMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
        Parent parent = mtext.getParent();
        assertNotNull(parent);
        assertTrue(parent.getRef() > 0);
        assertNotEquals(0, parent.getRef());
    }
}
