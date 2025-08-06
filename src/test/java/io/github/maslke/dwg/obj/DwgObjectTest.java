package io.github.maslke.dwg.obj;

import org.junit.Test;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertNotNull;

import org.junit.After;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.support.DwgObjectType;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.entity.Line;
import io.github.maslke.dwg.entity.Point;
import io.github.maslke.dwg.entity.Circle;

import java.util.List;
import java.util.stream.Collectors;

public class DwgObjectTest {


    Dwg dwg;

    private Dwg createDwg() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader header = dwg.getObjectBlockHeader();
        header.addPoint(new Point3d(0, 0, 0));
        header.addLine(new Point3d(0, 0, 0), new Point3d(1, 1, 0));
        return dwg;
    }

    @After
    public void release() {
        if (dwg != null) {
            dwg.release();
        }
    }

    @Test
    public void testGetObject() {
        dwg = createDwg();
        assertNotNull(dwg);
        assertTrue(dwg.getRef() > 0);
        long numObjects = dwg.getNumObjects();
        assertTrue(numObjects >= 2);

        List<DwgObject> objects = dwg.getObject();
        assertNotNull(objects);
        assertTrue(objects.size() >= 2);

        objects = objects.stream().filter(r -> r.getTioEntity() != null && r.getFixedType() != DwgObjectType.DWG_TYPE_BLOCK && r.getFixedType() != DwgObjectType.DWG_TYPE_ENDBLK && r.getTioEntity().isInModalSpace()).collect(Collectors.toList());
        assertEquals(2, objects.size());

        List<Integer> fixedTypes = objects.stream().map(DwgObject::getFixedType).collect(Collectors.toList());
        assertTrue(fixedTypes.contains(DwgObjectType.DWG_TYPE_POINT));
        assertTrue(fixedTypes.contains(DwgObjectType.DWG_TYPE_LINE));

        DwgObjectEntity pointEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_POINT).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNotNull(pointEntity);
        assertTrue(pointEntity.getRef() > 0);
        assertTrue(pointEntity.isInModalSpace());
        Point point = pointEntity.getEntityPoint();
        assertNotNull(point);
        assertFalse(point.isEmpty());


        DwgObjectEntity lineEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_LINE).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNotNull(lineEntity);
        assertTrue(lineEntity.getRef() > 0);
        assertTrue(lineEntity.isInModalSpace());
        Line line = lineEntity.getEntityLine();
        assertNotNull(line);
        assertFalse(line.isEmpty());

        DwgObjectEntity circleEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_CIRCLE).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNull(circleEntity);

        DwgObjectBlockHeader header = dwg.getObjectBlockHeader();
        header.addCircle(new Point3d(0, 0, 0), 10);

        numObjects = dwg.getNumObjects();
        assertTrue(numObjects >= 3);

        objects = dwg.getObject();
        assertNotNull(objects);
        assertTrue(objects.size() >= 3);

        objects = objects.stream().filter(r -> r.getTioEntity() != null && r.getFixedType() != DwgObjectType.DWG_TYPE_BLOCK && r.getFixedType() != DwgObjectType.DWG_TYPE_ENDBLK && r.getTioEntity().isInModalSpace()).collect(Collectors.toList());
        assertEquals(3, objects.size());

        fixedTypes = objects.stream().map(DwgObject::getFixedType).collect(Collectors.toList());
        assertTrue(fixedTypes.contains(DwgObjectType.DWG_TYPE_CIRCLE));

        circleEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_CIRCLE).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNotNull(circleEntity);
        assertTrue(circleEntity.getRef() > 0);
        assertTrue(circleEntity.isInModalSpace());
        Circle circle = circleEntity.getEntityCircle();
        assertNotNull(circle);
        assertFalse(circle.isEmpty());
    }
}
