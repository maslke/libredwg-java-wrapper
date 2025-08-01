package io.github.maslke.dwg.obj;

import io.github.maslke.dwg.Dwg;
import io.github.maslke.dwg.entity.Point;
import io.github.maslke.dwg.entity.Arc;
import io.github.maslke.dwg.entity.Circle;
import io.github.maslke.dwg.entity.Ellipse;
import io.github.maslke.dwg.entity.Hatch;
import io.github.maslke.dwg.entity.Lwpolyline;
import io.github.maslke.dwg.entity.Insert;
import io.github.maslke.dwg.entity.Line;
import io.github.maslke.dwg.entity.MLine;
import io.github.maslke.dwg.entity.Spline;
import io.github.maslke.dwg.entity.Text;
import io.github.maslke.dwg.entity.Block;
import io.github.maslke.dwg.entity.EndBlk;
import io.github.maslke.dwg.entity.Image;
import io.github.maslke.dwg.entity.MInsert;
import io.github.maslke.dwg.entity.Polyline2d;
import io.github.maslke.dwg.entity.Polyline3d;
import io.github.maslke.dwg.entity.OleFrame;
import io.github.maslke.dwg.entity.Ray;
import io.github.maslke.dwg.entity.MText;

public class DwgObjectEntity {
    public long ref;

    public DwgObjectEntity() {
        this.ref = 0;
    }

    public DwgObjectEntity(long ref) {
        this.ref = ref;
    }
    
    public long getRef() {
        return this.ref;
    }

    public long getObjId() {
        return this.getObjId(this.ref);
    }

    public Point getEntityPoint() {
        return this.getEntityPoint(this.ref);
    }

    public Line getEntityLine() {
        return this.getEntityLine(this.ref);
    }

    public Arc getEntityArc() {
        return this.getEntityArc(this.ref);
    }

    public Circle getEntityCircle() {
        return this.getEntityCircle(this.ref);
    }

    public Text getEntityText() {
        return this.getEntityText(this.ref);
    }

    public Ellipse getEntityEllipse() {
        return this.getEntityEllipse(this.ref);
    }

    public Spline getEntitySpline() {
        return this.getEntitySpline(this.ref);
    }

    public Insert getEntityInsert() {
        return this.getEntityInsert(this.ref);
    }

    public MLine getEntityMLine() {
        return this.getEntityMLine(this.ref);
    }

    public Hatch getEntityHatch() {
        return this.getEntityHatch(this.ref);
    }

    public Lwpolyline getEntityLwPolyline() {
        return this.getEntityLwpolyline(this.ref);
    }

    public Block getEntityBlock() {
        return this.getEntityBlock(this.ref);
    }

    public EndBlk getEntityEndBlk() {
        return this.getEntityEndBlk(this.ref);
    }

    public Image getEntityImage() {
        return this.getEntityImage(this.ref);
    }

    public MInsert getEntityMInsert() {
        return this.getEntityMInsert(this.ref);
    }

    public Polyline2d getEntityPolyline2d() {
        return this.getEntityPolyline2d(this.ref);
    }

    public Polyline3d getEntityPolyline3d() {
        return this.getEntityPolyline3d(this.ref);
    }

    public OleFrame getEntityOleFrame() {
        return this.getEntityOleFrame(this.ref);
    }

    public Ray getEntityRay() {
        return this.getEntityRay(this.ref);
    }

    public MText getEntityMText() {
        return this.getEntityMText(this.ref);
    }

    public void setColor(DwgColor color) {
        this.setColor(this.ref, color);

    }

    public DwgColor getColor() { 
        return this.getColor(this.ref);
    }

    public int getLinewt() {
        return this.getLinewt(this.ref);
    }

    public void setLinewt(int linewt) {
        this.setLinewt(this.ref, linewt);
    }

    public DwgObjectRef getLtype() {
        return this.getLtype(this.ref);
    }

    public void setLtype(DwgObjectRef ltype) {
        this.setLtype(this.ref, ltype);
    }

    public DwgObjectRef getLayer() {
        return this.getLayer(this.ref);
    }

    public void setLayer(DwgObjectRef layer) {
        this.setLayer(this.ref, layer);
    } 

    public Dwg getDwg() {
        return this.getDwg(this.ref);
    }

    public int getEntMode() {
        return this.getEntMode(this.ref);
    }

    public boolean isInModalSpace() {
        return this.getEntMode() == 2;
    }

    public boolean isInPaperSpace() {
        return this.getEntMode() == 1;
    }

    private native long getObjId(long ref);
    private native void setColor(long ref, DwgColor color);
    private native DwgColor getColor(long ref);
    private native void setLinewt(long ref, int linewt);
    private native int getLinewt(long ref);
    private native void setLtype(long ref, DwgObjectRef ltype);
    private native DwgObjectRef getLtype(long ref);
    private native void setLayer(long ref, DwgObjectRef layer);
    private native DwgObjectRef getLayer(long ref);
    private native Dwg getDwg(long ref);
    private native int getEntMode(long ref);
    private native Point getEntityPoint(long ref);
    private native Line getEntityLine(long ref);
    private native Arc getEntityArc(long ref);
    private native Circle getEntityCircle(long ref);
    private native Text getEntityText(long ref);
    private native Ellipse getEntityEllipse(long ref);
    private native Spline getEntitySpline(long ref);
    private native Insert getEntityInsert(long ref);
    private native MLine getEntityMLine(long ref);
    private native Hatch getEntityHatch(long ref);
    private native Lwpolyline getEntityLwpolyline(long ref);
    private native Block getEntityBlock(long ref);
    private native EndBlk getEntityEndBlk(long ref);
    private native Image getEntityImage(long ref);
    private native MInsert getEntityMInsert(long ref);
    private native Polyline2d getEntityPolyline2d(long ref);
    private native Polyline3d getEntityPolyline3d(long ref);
    private native OleFrame getEntityOleFrame(long ref);
    private native Ray getEntityRay(long ref);
    private native MText getEntityMText(long ref);
}
