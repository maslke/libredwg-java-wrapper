package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
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

public class SplineTest extends AbstractEntityTest {

    private Spline spline;

    @After
    public void release() {
        if (spline != null) {
            releaseDwg(spline);
        }
    }

    private Spline createSpline(List<Point3d> fitPoints, Vector3d begTanVec, Vector3d endTanVec) {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        return hdr.addSpline(fitPoints, begTanVec, endTanVec);
    }

    private Spline createSpline() {
        List<Point3d> fitPoints = Arrays.asList(
            new Point3d(0, 0, 0),
            new Point3d(10, 5, 0),
            new Point3d(20, 0, 0),
            new Point3d(30, -5, 0)
        );
        Vector3d begTanVec = new Vector3d(1, 0, 0);
        Vector3d endTanVec = new Vector3d(1, 0, 0);
        return createSpline(fitPoints, begTanVec, endTanVec);
    }

    @Test
    public void testBasicCreation() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
    }

    @Test
    public void testFlag() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setFlag(5);
        int flag = spline.getFlag();
        assertEquals(5, flag);
    }

    @Test
    public void testScenario() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setScenario(2);
        int scenario = spline.getScenario();
        assertEquals(2, scenario);
    }

    @Test
    public void testDegree() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setDegree(3);
        int degree = spline.getDegree();
        assertEquals(3, degree);
    }

    @Test
    public void testSplineFlags() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setSplineFlags(7L);
        long splineFlags = spline.getSplineFlags();
        assertEquals(7L, splineFlags);
    }

    @Test
    public void testKnotParam() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setKnotParam(1L);
        long knotParam = spline.getKnotParam();
        assertEquals(1L, knotParam);
    }

    @Test
    public void testFitTol() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setFitTol(0.001);
        double fitTol = spline.getFitTol();
        assertEquals(0.001, fitTol, TOLERANCE);
    }

    @Test
    public void testBegTanVec() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        Vector3d newBegTanVec = new Vector3d(0, 1, 0);
        spline.setBegTanVec(newBegTanVec);
        Vector3d begTanVec = spline.getBegTanVec();
        assertNotNull(begTanVec);
        assertEquals(0, begTanVec.getX(), TOLERANCE);
        assertEquals(1, begTanVec.getY(), TOLERANCE);
        assertEquals(0, begTanVec.getZ(), TOLERANCE);
    }

    @Test
    public void testEndTanVec() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        Vector3d newEndTanVec = new Vector3d(0, 0, 1);
        spline.setEndTanVec(newEndTanVec);
        Vector3d endTanVec = spline.getEndTanVec();
        assertNotNull(endTanVec);
        assertEquals(0, endTanVec.getX(), TOLERANCE);
        assertEquals(0, endTanVec.getY(), TOLERANCE);
        assertEquals(1, endTanVec.getZ(), TOLERANCE);
    }

    @Test
    public void testClosedb() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setClosedb(1);
        int closedb = spline.getClosedb();
        assertEquals(1, closedb);
    }

    @Test
    public void testPeriodic() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setPeriodic(1);
        int periodic = spline.getPeriodic();
        assertEquals(1, periodic);
    }

    @Test
    public void testRational() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setRational(1);
        int rational = spline.getRational();
        assertEquals(1, rational);
    }

    @Test
    public void testWeighted() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setWeighted(1);
        int weighted = spline.getWeighted();
        assertEquals(1, weighted);
    }

    @Test
    public void testKnotTol() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setKnotTol(0.0001);
        double knotTol = spline.getKnotTol();
        assertEquals(0.0001, knotTol, TOLERANCE);
    }

    @Test
    public void testCtrlTol() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setCtrlTol(0.0001);
        double ctrlTol = spline.getCtrlTol();
        assertEquals(0.0001, ctrlTol, TOLERANCE);
    }

    @Test
    public void testNumFitPts() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setNumFitPts(5);
        int numFitPts = spline.getNumFitPts();
        assertEquals(5, numFitPts);
    }

    @Test
    public void testFitPts() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        
        List<Point3d> newFitPts = Arrays.asList(
            new Point3d(0, 0, 0),
            new Point3d(5, 5, 0),
            new Point3d(10, 0, 0)
        );
        spline.setFitPts(newFitPts);
        List<Point3d> fitPts = spline.getFitPts();
        assertNotNull(fitPts);
        assertEquals(3, fitPts.size());
        assertEquals(0, fitPts.get(0).getX(), TOLERANCE);
        assertEquals(0, fitPts.get(0).getY(), TOLERANCE);
        assertEquals(5, fitPts.get(1).getX(), TOLERANCE);
        assertEquals(5, fitPts.get(1).getY(), TOLERANCE);
        assertEquals(10, fitPts.get(2).getX(), TOLERANCE);
        assertEquals(0, fitPts.get(2).getY(), TOLERANCE);
    }

    @Test
    public void testNumKnots() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setNumKnots(8L);
        long numKnots = spline.getNumKnots();
        assertEquals(8L, numKnots);
    }

    @Test
    public void testKnots() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        
        List<Double> newKnots = Arrays.asList(0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0);
        spline.setKnots(newKnots);
        List<Double> knots = spline.getKnots();
        assertNotNull(knots);
        assertEquals(8, knots.size());
        assertEquals(0.0, knots.get(0), TOLERANCE);
        assertEquals(0.0, knots.get(1), TOLERANCE);
        assertEquals(1.0, knots.get(4), TOLERANCE);
        assertEquals(1.0, knots.get(7), TOLERANCE);
    }

    @Test
    public void testNumCtrlPts() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        spline.setNumCtrlPts(4L);
        long numCtrlPts = spline.getNumCtrlPts();
        assertEquals(4L, numCtrlPts);
    }

    @Test
    public void testControlPoints() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        
        List<Point3d> newCtrlPts = Arrays.asList(
            new Point3d(0, 0, 0),
            new Point3d(3.33, 1.67, 0),
            new Point3d(6.67, -1.67, 0),
            new Point3d(10, 0, 0)
        );
        spline.setControlPoints(newCtrlPts);
        List<Point3d> ctrlPts = spline.getControlPoints();
        assertNotNull(ctrlPts);
        assertEquals(4, ctrlPts.size());
        assertEquals(0, ctrlPts.get(0).getX(), TOLERANCE);
        assertEquals(0, ctrlPts.get(0).getY(), TOLERANCE);
        assertEquals(3.33, ctrlPts.get(1).getX(), TOLERANCE);
        assertEquals(1.67, ctrlPts.get(1).getY(), TOLERANCE);
        assertEquals(10, ctrlPts.get(3).getX(), TOLERANCE);
        assertEquals(0, ctrlPts.get(3).getY(), TOLERANCE);
    }

    @Test
    public void testComplexSpline() {
        List<Point3d> fitPoints = Arrays.asList(
            new Point3d(0, 0, 0),
            new Point3d(10, 10, 0),
            new Point3d(20, 5, 0),
            new Point3d(30, 15, 0),
            new Point3d(40, 0, 0)
        );
        Vector3d begTanVec = new Vector3d(1, 1, 0);
        Vector3d endTanVec = new Vector3d(1, -1, 0);
        
        spline = createSpline(fitPoints, begTanVec, endTanVec);
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        assertTrue(spline.getHeader() > 0);
        
        spline.setDegree(3);
        spline.setSplineFlags(4L);
        spline.setRational(1);
        spline.setWeighted(1);
        spline.setFitTol(0.01);
        spline.setKnotTol(0.0001);
        spline.setCtrlTol(0.0001);
        
        assertEquals(3, spline.getDegree());
        assertEquals(4L, spline.getSplineFlags());
        assertEquals(1, spline.getRational());
        assertEquals(1, spline.getWeighted());
        assertEquals(0.01, spline.getFitTol(), TOLERANCE);
        assertEquals(0.0001, spline.getKnotTol(), TOLERANCE);
        assertEquals(0.0001, spline.getCtrlTol(), TOLERANCE);
    }

    @Test
    public void testParent() {
        spline = createSpline();
        assertNotNull(spline);
        assertFalse(spline.isEmpty());
        DwgObjectEntity parent = spline.getParent();
        assertNotNull(parent);
        assertTrue(parent.ref > 0);
        assertNotEquals(0, parent.ref);
    }
}
