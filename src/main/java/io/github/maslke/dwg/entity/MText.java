package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector3d;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class MText extends Common {
    private Point3d insPt;
    private Vector3d extrusion;
    private Point3d thickness;
    private Point3d xAxisDir;
    private double rectHeight;
    private double rectWidth;
    private double textHeight;
    private short attachment;
    private short flowDir;
    private double extentsWidth;
    private double extentsHeight;
    private String text;
    private short linespaceStyle;
    private double linespaceFactor;
    private short unknownB0;
    private int bgFillFlag;
    private int bgFillScale;
    // TODO STYLE


    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }

    private native long getParentNative(long ref);
}
