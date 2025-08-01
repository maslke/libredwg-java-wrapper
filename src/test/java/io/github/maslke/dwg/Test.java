package io.github.maslke.dwg;

import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.common.Vector2d;
import io.github.maslke.dwg.entity.Arc;
import io.github.maslke.dwg.entity.Circle;
import io.github.maslke.dwg.entity.Line;
import io.github.maslke.dwg.entity.Text;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import io.github.maslke.dwg.obj.DwgObjectEntity;
import io.github.maslke.dwg.obj.DwgObjectRef;
import io.github.maslke.dwg.obj.DwgObjectVport;
import io.github.maslke.dwg.support.HorizAlignment;
import io.github.maslke.dwg.support.TableType;
import io.github.maslke.dwg.support.VertAlignment;
import io.github.maslke.dwg.obj.DwgColor;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Test {
    public static void main(String[] args) {
        Dwg dwg = Dwg.open("/home/maslke/Documents/seed_0704.dwg");
        System.out.println(dwg.getVersion());
        dwg.setCodePage("ANSI_936");
        String path2 = "/mnt/c/Users/maslke/Desktop/seed_2025.dwg";
        deleteFile(path2);

        DwgObjectRef style = dwg.findTableHandle("1", TableType.STYLE);

        DwgObjectBlockHeader dwgBlockHeader = dwg.getObjectBlockHeader();
        Point3d start = new Point3d(100, 100, 0);
        Point3d end = new Point3d(200, 200, 0);
        Line line = dwgBlockHeader.addLine(start, end);
        DwgObjectEntity parent = line.getParent();
        DwgColor color = parent.getColor();
        color.setIndex(3);
        parent.setColor(color);
        parent.setLinewt(50);


        Text text = dwgBlockHeader.addText("This is libredwg", new Point3d(150, 150, 0), 2.5);
//        text.setRotation(90);
        text.setAlignmentPt(new Point2d(150, 150));
        text.setHorizAlignment(HorizAlignment.CENTER);
        text.setVertAlignment(VertAlignment.BOTTOM);
        text.setStyle(dwg.addHandleRef(5, style.getAbsoluteRef(), 0));
//        text.setWidthFactor(1);
        text.setTextValue("汉字测试");

        Circle circle = dwgBlockHeader.addCircle(new Point3d(150, 150, 0), 30);
        dwgBlockHeader.addArc(new Point3d(300, 300, 0), 100, 0, 1.57);
        circle.getParent().setLinewt(30);
        DwgColor color2 = circle.getParent().getColor();
        color2.setIndex(2);
        circle.getParent().setColor(color2);

        dwgBlockHeader.addEllipse(new Point3d(120, 120, 0), 100, 0.8);

        DwgObjectVport vport = dwg.getVport("*Active");
        if (vport.getRef() != 0) {
            vport.setViewCtr(new Vector2d(200, 200));
            vport.setViewTarget(new Point3d(200, 200, 0));
            vport.setViewSize(400);
            vport.setAspectRatio(16.0 / 9);
            vport.setViewWidth(vport.getAspectRatio() * vport.getViewSize());
        }

        if (dwg.save(path2)) {
            System.out.println("save successfully.");
        }
    }

    private static void deleteFile(String name) {
        Path path = Paths.get(name);
        try {
            if (Files.exists(path)) {
                Files.delete(path);
                System.out.println("file deleted: " + path);
            }
        }
        catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
    }
}
