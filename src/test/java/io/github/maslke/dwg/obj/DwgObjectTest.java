package io.github.maslke.dwg.obj;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.entity.Circle;
import io.github.maslke.dwg.entity.Insert;
import io.github.maslke.dwg.entity.Line;
import io.github.maslke.dwg.entity.Point;
import io.github.maslke.dwg.entity.Text;
import io.github.maslke.dwg.entity.MText;
import io.github.maslke.dwg.entity.MInsert;
import io.github.maslke.dwg.entity.Polyline2d;
import io.github.maslke.dwg.entity.Polyline3d;
import io.github.maslke.dwg.support.DwgObjectType;
import org.junit.After;
import org.junit.Test;

import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

public class DwgObjectTest {


    Dwg dwg;

    private Dwg createDwg() {
        Dwg dwg = Dwg.create();
        DwgObjectBlockHeader header = dwg.getObjectBlockHeader();
        header.addPoint(new Point3d(0, 0, 0));
        header.addLine(new Point3d(0, 0, 0), new Point3d(1, 1, 0));
        return dwg;
    }

    private Dwg creatEmptyDwg() {
        return Dwg.create();
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
    }
    

    @Test
    public void testGetCircleObject() {
        
        dwg = creatEmptyDwg();
        DwgObjectBlockHeader header = dwg.getObjectBlockHeader();
        header.addCircle(new Point3d(0, 0, 0), 10);

        List<DwgObject> objects = dwg.getObject();
        assertNotNull(objects);
        assertFalse(objects.isEmpty());
        List<Integer> fixedTypes = objects.stream().map(DwgObject::getFixedType).collect(Collectors.toList());
        assertTrue(fixedTypes.contains(DwgObjectType.DWG_TYPE_CIRCLE));

        DwgObjectEntity circleEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_CIRCLE).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNotNull(circleEntity);
        assertTrue(circleEntity.getRef() > 0);
        assertTrue(circleEntity.isInModalSpace());
        Circle circle = circleEntity.getEntityCircle();
        assertNotNull(circle);
        assertFalse(circle.isEmpty());
    }


    @Test
    public void testGetLineObject() {
        dwg = creatEmptyDwg();
        DwgObjectBlockHeader header = dwg.getObjectBlockHeader();
        header.addLine(new Point3d(0, 0, 0), new Point3d(1, 1, 0));

        List<DwgObject> objects = dwg.getObject();
        assertNotNull(objects);
        assertFalse(objects.isEmpty());
        List<Integer> fixedTypes = objects.stream().map(DwgObject::getFixedType).collect(Collectors.toList());
        assertTrue(fixedTypes.contains(DwgObjectType.DWG_TYPE_LINE));

        DwgObjectEntity lineEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_LINE).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNotNull(lineEntity);
        assertTrue(lineEntity.getRef() > 0);
        assertTrue(lineEntity.isInModalSpace());
        Line line = lineEntity.getEntityLine();
        assertNotNull(line);
        assertFalse(line.isEmpty());
    }

    @Test
    public void testGetPointObject() {
        dwg = creatEmptyDwg();
        DwgObjectBlockHeader header = dwg.getObjectBlockHeader();
        header.addPoint(new Point3d(0, 0, 0));

        List<DwgObject> objects = dwg.getObject();
        assertNotNull(objects);
        assertFalse(objects.isEmpty());
        List<Integer> fixedTypes = objects.stream().map(DwgObject::getFixedType).collect(Collectors.toList());
        assertTrue(fixedTypes.contains(DwgObjectType.DWG_TYPE_POINT));

        DwgObjectEntity pointEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_POINT).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNotNull(pointEntity);
        assertTrue(pointEntity.getRef() > 0);
        assertTrue(pointEntity.isInModalSpace());
        Point point = pointEntity.getEntityPoint();
        assertNotNull(point);
        assertFalse(point.isEmpty());
    }

    @Test
    public void testGetTextObject() {
        dwg = creatEmptyDwg();
        DwgObjectBlockHeader header = dwg.getObjectBlockHeader();
        header.addText("TEXT", new Point3d(0, 0, 0), 1.2);

        List<DwgObject> objects = dwg.getObject();
        assertNotNull(objects);
        assertFalse(objects.isEmpty());
        List<Integer> fixedTypes = objects.stream().map(DwgObject::getFixedType).collect(Collectors.toList());
        assertTrue(fixedTypes.contains(DwgObjectType.DWG_TYPE_TEXT));

        DwgObjectEntity textEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_TEXT).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNotNull(textEntity);
        assertTrue(textEntity.getRef() > 0);
        assertTrue(textEntity.isInModalSpace());
        Text text = textEntity.getEntityText();
        assertNotNull(text);
        assertFalse(text.isEmpty());
    }

    @Test
    public void testGetMTextObject() {
        dwg = creatEmptyDwg();
        DwgObjectBlockHeader header = dwg.getObjectBlockHeader();
        header.addMText("MTEXT", new Point3d(0, 0, 0), 1.2);

        List<DwgObject> objects = dwg.getObject();
        assertNotNull(objects);
        assertFalse(objects.isEmpty());
        List<Integer> fixedTypes = objects.stream().map(DwgObject::getFixedType).collect(Collectors.toList());
        assertTrue(fixedTypes.contains(DwgObjectType.DWG_TYPE_MTEXT));

        DwgObjectEntity mtextEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_MTEXT).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNotNull(mtextEntity);
        assertTrue(mtextEntity.getRef() > 0);
        assertTrue(mtextEntity.isInModalSpace());
        MText mtext = mtextEntity.getEntityMText();
        assertNotNull(mtext);
        assertFalse(mtext.isEmpty());
    }

    @Test
    public void testGetPolyline2dObject() {
        dwg = creatEmptyDwg();
        DwgObjectBlockHeader header = dwg.getObjectBlockHeader();
        header.addPolyline2d(Arrays.asList(new Point2d(0, 0), new Point2d(1, 1)));

        List<DwgObject> objects = dwg.getObject();
        assertNotNull(objects);
        assertFalse(objects.isEmpty());
        List<Integer> fixedTypes = objects.stream().map(DwgObject::getFixedType).collect(Collectors.toList());
        assertTrue(fixedTypes.contains(DwgObjectType.DWG_TYPE_POLYLINE_2D));

        DwgObjectEntity polyline2dEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_POLYLINE_2D).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNotNull(polyline2dEntity);
        assertTrue(polyline2dEntity.getRef() > 0);
        assertTrue(polyline2dEntity.isInModalSpace());
        Polyline2d polyline2d = polyline2dEntity.getEntityPolyline2d();
        assertNotNull(polyline2d);
        assertFalse(polyline2d.isEmpty());
    }

    @Test
    public void testGetPolyline3dObject() {
        dwg = creatEmptyDwg();
        DwgObjectBlockHeader header = dwg.getObjectBlockHeader();
        header.addPolyline3d(Arrays.asList(new Point3d(0, 0, 0), new Point3d(1, 1, 0)));

        List<DwgObject> objects = dwg.getObject();
        assertNotNull(objects);
        assertFalse(objects.isEmpty());
        List<Integer> fixedTypes = objects.stream().map(DwgObject::getFixedType).collect(Collectors.toList());
        assertTrue(fixedTypes.contains(DwgObjectType.DWG_TYPE_POLYLINE_3D));

        DwgObjectEntity polyline3dEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_POLYLINE_3D).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNotNull(polyline3dEntity);
        assertTrue(polyline3dEntity.getRef() > 0);
        assertTrue(polyline3dEntity.isInModalSpace());
        Polyline3d polyline3d = polyline3dEntity.getEntityPolyline3d();
        assertNotNull(polyline3d);
    }

    @Test
    public void testGetMInsertObject() {
        dwg = creatEmptyDwg();
        DwgObjectBlockHeader header = dwg.getObjectBlockHeader();
        header.addMInsert(new Point3d(0, 0, 0), "blk0", new Vector3d(1, 1, 1), 0, 1, 1, 1.2, 1.2);

        List<DwgObject> objects = dwg.getObject();
        assertNotNull(objects);
        assertFalse(objects.isEmpty());
        List<Integer> fixedTypes = objects.stream().map(DwgObject::getFixedType).collect(Collectors.toList());
        assertTrue(fixedTypes.contains(DwgObjectType.DWG_TYPE_MINSERT));
        DwgObjectEntity minsertEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_MINSERT).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNotNull(minsertEntity);
        assertTrue(minsertEntity.getRef() > 0);
        assertTrue(minsertEntity.isInModalSpace());
        MInsert minsert = minsertEntity.getEntityMInsert();
        assertNotNull(minsert);
        assertFalse(minsert.isEmpty());
    }

    @Test
    public void testGetInsert() {
        dwg = createDwg();
        assertNotNull(dwg);
        assertTrue(dwg.getRef() > 0);
        DwgObjectBlockHeader header = dwg.getObjectBlockHeader();
        DwgObjectBlockHeader hdr = dwg.createObjectBlockHeader("blk0");
        hdr.addBlock("blk0");
        hdr.addLine(new Point3d(0, 0, 0), new Point3d(1, 1, 0));
        hdr.addEndBlk();
        header.addInsert(new Point3d(10, 10, 0), "blk0", 1.0, 1.0, 1.0, 0);
        List<DwgObject> objects = dwg.getObject();
        DwgObjectEntity insertEntity = objects.stream().filter(r -> r.getFixedType() == DwgObjectType.DWG_TYPE_INSERT).map(DwgObject::getTioEntity).findFirst().orElse(null);
        assertNotNull(insertEntity);
        assertTrue(insertEntity.getRef() > 0);
        assertTrue(insertEntity.isInModalSpace());
        Insert insert = insertEntity.getEntityInsert();
        assertNotNull(insert);
        assertFalse(insert.isEmpty());

        DwgObjectRef ref = insert.getBlockHeader();
        DwgObject blockObj = ref.getObject();
        if (blockObj == null) {
            blockObj = dwg.resolveHandle(ref.getAbsoluteRef());
        }

        DwgObjectBlockHeader hdr2 = blockObj.getTioObject().getObjectBlockHeader();
        List<DwgObject> ownedObjects = hdr2.getOwnObjects(blockObj);
        assertNotNull(ownedObjects);
    }
}
