package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.support.HorizAlignment;
import io.github.maslke.dwg.support.TableType;
import io.github.maslke.dwg.support.VertAlignment;
import org.junit.After;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertFalse;

public class TextTest extends AbstractEntityTest {

    private Text text;

    @After
    public void release() {
        if (text != null) {
            releaseDwg(text);
        }
    }

    private Text createText(String textValue, Point3d insertPt, double height) {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        return hdr.addText(textValue, insertPt, height);
    }

    private Text createText() {
        return createText("TEXT", new Point3d(10, 10, 0), 2.53);
    }

    @Test
    public void testTextValue() {
        text = createText("English Text", new Point3d(10, 10, 0), 2.5);
        assertNotNull(text);
        assertFalse(text.isEmpty());
        String textValue = text.getTextValue();
        assertEquals("English Text", textValue);
        textValue = text.getTextValueNative(text.ref);
        assertEquals("English Text", textValue);

        text.setTextValue("中文文本");
        textValue = text.getTextValue();
        assertEquals("中文文本", textValue);
        textValue = text.getTextValueNative(text.getRef());
        assertEquals("中文文本", textValue);
    }

    @Test
    public void testRotation() {
        text = createText();
        assertNotNull(text);
        assertFalse(text.isEmpty());
        text.setRotation(1.50);
        double rotation = text.getRotation();
        assertEquals(1.5, rotation, TOLERANCE);
        rotation = text.getRotationNative(text.getRef());
        assertEquals(1.5, rotation, TOLERANCE);
    }

    @Test
    public void testHeight() {
        text = createText("Text", new Point3d(10, 10, 0), 2.5);
        assertNotNull(text);
        assertFalse(text.isEmpty());
        double height = text.getHeight();
        assertEquals(2.5, height, TOLERANCE);
        height = text.getHeightNative(text.getRef());
        assertEquals(2.5, height, TOLERANCE);
        text.setHeight(3.0);
        height = text.getHeight();
        assertEquals(3.0, height, TOLERANCE);
        height = text.getHeightNative(text.getRef());
        assertEquals(3.0, height, TOLERANCE);
    }

    @Test
    public void testElevation() {
        text = createText("Text", new Point3d(10, 10, 0), 2.5);
        assertNotNull(text);
        assertFalse(text.isEmpty());
        text.setElevation(1.0);
        double elevation = text.getElevation();
        assertEquals(1.0, elevation, TOLERANCE);
        elevation = text.getElevationNative(text.getRef());
        assertEquals(1.0, elevation, TOLERANCE);
    }

    @Test
    public void testWidthFactor() {
        text = createText();
        assertNotNull(text);
        assertFalse(text.isEmpty());
        text.setWidthFactor(0.8);
        double factor = text.getWidthFactor();
        assertEquals(0.8, factor, TOLERANCE);
        factor = text.getWidthFactorNative(text.getRef());
        assertEquals(0.8, factor, TOLERANCE);
    }

    @Test
    public void testInsPt() {
        text = createText("Text", new Point3d(10, 10, 0), 2.5);
        assertNotNull(text);
        assertFalse(text.isEmpty());
        Point2d insPt = text.getInsPt();
        assertNotNull(insPt);
        assertEquals(10, insPt.getX(), TOLERANCE);
        assertEquals(10, insPt.getY(), TOLERANCE);
        insPt = text.getInsPtNative(text.getRef());
        assertNotNull(insPt);
        assertEquals(10, insPt.getX(), TOLERANCE);
        assertEquals(10, insPt.getY(), TOLERANCE);

        text.setInsPt(new Point2d(15, 12));
        insPt = text.getInsPt();
        assertNotNull(insPt);
        assertEquals(15, insPt.getX(), TOLERANCE);
        assertEquals(12, insPt.getY(), TOLERANCE);
        insPt = text.getInsPtNative(text.getRef());
        assertNotNull(insPt);
        assertEquals(15, insPt.getX(), TOLERANCE);
        assertEquals(12, insPt.getY(), TOLERANCE);
    }

    @Test
    public void testAlignmentPt() {
        text = createText("Text", new Point3d(10, 10, 0), 2.5);
        assertNotNull(text);
        assertFalse(text.isEmpty());
        text.setAlignmentPt(new Point2d(10, 10));
        Point2d alignmentPt = text.getAlignmentPt();
        assertNotNull(alignmentPt);
        assertEquals(10, alignmentPt.getX(), TOLERANCE);
        assertEquals(10, alignmentPt.getY(), TOLERANCE);
        alignmentPt = text.getInsPtNative(text.getRef());
        assertNotNull(alignmentPt);
        assertEquals(10, alignmentPt.getX(), TOLERANCE);
        assertEquals(10, alignmentPt.getY(), TOLERANCE);

        text.setAlignmentPt(new Point2d(15, 12));
        alignmentPt = text.getAlignmentPt();
        assertNotNull(alignmentPt);
        assertEquals(15, alignmentPt.getX(), TOLERANCE);
        assertEquals(12, alignmentPt.getY(), TOLERANCE);
        alignmentPt = text.getAlignmentPtNative(text.getRef());
        assertNotNull(alignmentPt);
        assertEquals(15, alignmentPt.getX(), TOLERANCE);
        assertEquals(12, alignmentPt.getY(), TOLERANCE);
    }

    @Test
    public void testVertAlignment() {
        text = createText();
        assertNotNull(text);
        assertFalse(text.isEmpty());
        text.setVertAlignment(VertAlignment.TOP);
        int vertAlign = text.getVertAlignment();
        assertEquals(VertAlignment.TOP, vertAlign);
        vertAlign = text.getVertAlignmentNative(text.getRef());
        assertEquals(VertAlignment.TOP, vertAlign);
    }

    @Test
    public void testHorizAlignment() {
        text = createText();
        assertNotNull(text);
        assertFalse(text.isEmpty());
        text.setHorizAlignment(HorizAlignment.CENTER);
        int horizAlign = text.getHorizAlignment();
        assertEquals(HorizAlignment.CENTER, horizAlign);
        horizAlign = text.getHorizAlignmentNative(text.getRef());
        assertEquals(HorizAlignment.CENTER, horizAlign);
    }

    @Test
    public void testExtrusion() {
        text = createText();
        assertNotNull(text);
        assertFalse(text.isEmpty());
        Vector3d defaultExtrusion = text.getExtrusionNative(text.getRef());
        assertNotNull(defaultExtrusion);
        assertEquals(0, defaultExtrusion.getX(), TOLERANCE);
        assertEquals(0, defaultExtrusion.getY(), TOLERANCE);
        assertEquals(1, defaultExtrusion.getZ(), TOLERANCE);
        text.setExtrusion(new Vector3d(0, 0, 1));
        Vector3d extrusion = text.getExtrusion();
        assertNotNull(extrusion);
        assertEquals(0, extrusion.getX(), TOLERANCE);
        assertEquals(0, extrusion.getY(), TOLERANCE);
        assertEquals(1, extrusion.getZ(), TOLERANCE);
        extrusion = text.getExtrusionNative(text.getRef());
        assertEquals(0, extrusion.getX(), TOLERANCE);
        assertEquals(0, extrusion.getY(), TOLERANCE);
        assertEquals(1, extrusion.getZ(), TOLERANCE);
    }

    @Test
    public void testThickness() {
        text = createText();
        assertNotNull(text);
        assertFalse(text.isEmpty());
        text.setThickness(1.0);
        double thickness = text.getThickness();
        assertEquals(1.0, thickness, TOLERANCE);
        thickness = text.getThicknessNative(text.getRef());
        assertEquals(1.0, thickness, TOLERANCE);
    }

    @Test
    public void testObliqueAngle() {
        text = createText();
        assertNotNull(text);
        assertFalse(text.isEmpty());
        text.setObliqueAngle(0.5);
        double obliqueAngle = text.getObliqueAngle();
        assertEquals(0.5, obliqueAngle, TOLERANCE);
        obliqueAngle = text.getObliqueAngleNative(text.getRef());
        assertEquals(0.5, obliqueAngle, TOLERANCE);
    }

    @Test
    public void testStyle() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        text = hdr.addText("Text", new Point3d(10, 10, 0), 1.2);
        assertNotNull(text);
        assertFalse(text.isEmpty());

        DwgObjectRef objectRef = dwg.findTableHandle("CONTINUOUS", TableType.LTYPE);
        assertNotNull(objectRef);
        text.setStyle(objectRef);

        DwgObjectRef style = text.getStyle();
        assertNotNull(style);
        assertEquals(objectRef.getRef(), style.getRef());
        assertEquals(objectRef.getAbsoluteRef(), style.getAbsoluteRef());
        assertEquals(objectRef.getR11Idx(), style.getR11Idx());

        style = text.getStyleNative(text.getRef());
        assertNotNull(style);
        assertNotNull(style);
        assertEquals(objectRef.getRef(), style.getRef());
        assertEquals(objectRef.getAbsoluteRef(), style.getAbsoluteRef());
        assertEquals(objectRef.getR11Idx(), style.getR11Idx());
    }

    @Test
    public void parent() {
        text = createText();
        assertNotNull(text);
        assertFalse(text.isEmpty());
        Parent parent = text.getParent();
        assertNotNull(parent);
        assertNotEquals(0, parent.getRef());
    }
}
