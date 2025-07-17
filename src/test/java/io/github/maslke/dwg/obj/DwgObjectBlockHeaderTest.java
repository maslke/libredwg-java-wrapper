package io.github.maslke.dwg.obj;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.entity.Line;
import io.github.maslke.dwg.entity.Lwpolyline;
import io.github.maslke.dwg.entity.Text;
import org.junit.After;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

public class DwgObjectBlockHeaderTest {

    private Dwg dwg;

    private Dwg createDwg() {
        return Dwg.create();
    }

    @After
    public void release() {
        if (dwg != null) {
            dwg.release();
        }
    }

    @Test
    public void testAddLine() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());
        Line line = hdr.addLine(new Point3d(0, 0, 0), new Point3d(1, 1, 0));
        assertNotNull(line);
        assertFalse(line.isEmpty());
    }


    @Test
    public void testAddText() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader hdr = dwg.getObjectBlockHeader();
        assertNotNull(hdr);
        assertNotEquals(0, hdr.getRef());
        Text text = hdr.addText("TEXT", new Point3d(10, 10, 0), 2.5);
        assertNotNull(text);
        assertNotEquals(0, text.getRef());
    }

    @Test
    public void testAddLwpolyline() {
        dwg = Dwg.create();
        assertNotNull(dwg);
        assertNotEquals(0, dwg.getRef());
        DwgObjectBlockHeader blockHeader = dwg.getObjectBlockHeader();
        assertNotNull(blockHeader);
        assertNotEquals(0, blockHeader.getRef());
        assertNotEquals(0, blockHeader.getRef());

        List<Point2d> points = Arrays.asList(
                new Point2d(0, 0),
                new Point2d(1, 1)
        );
        Lwpolyline lwpolyline = blockHeader.addLwpolyline(points);
        assertNotNull(lwpolyline);
        assertNotEquals(0, lwpolyline.getRef());
    }
}
