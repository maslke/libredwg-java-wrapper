package io.github.maslke.dwg;

import io.github.maslke.dwg.entity.Text;
import io.github.maslke.dwg.entity.Point;
import io.github.maslke.dwg.entity.Line;
import io.github.maslke.dwg.common.Point3d;

public class Dwg {
    public Dwg() {

    }

    public static Dwg createDocument() {
        return new Dwg();
    }

    public static Dwg openDocument(String path) {
        return new Dwg();
    } 

    public boolean save(String path) {
        return true;
    }

    public Text createText(String text, Point3d insertPoint) {
        return null;
    }

    public Point createPoint(Point3d point) {
        return null;
    }

    public Line createLine(Point3d startPoint, Point3d endPoint) {
        return null;
    }

    public native int getVersion();

}