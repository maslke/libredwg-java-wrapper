package io.github.maslke.dwg;

import io.github.maslke.dwg.common.Point2d;
import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.entity.Arc;
import io.github.maslke.dwg.entity.Circle;
import io.github.maslke.dwg.entity.Line;
import io.github.maslke.dwg.entity.Parent;
import io.github.maslke.dwg.entity.Text;
import io.github.maslke.dwg.obj.DwgObjectBlockHeader;
import io.github.maslke.dwg.support.HorizAlignment;
import io.github.maslke.dwg.support.VertAlignment;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Test {
    public static void main(String[] args) {
        Dwg dwg = Dwg.open("/home/maslke/Documents/seed_0704.dwg");
        System.out.println(dwg.getVersion());
        dwg.setCodePage("ANSI_936");
        String path2 = "/mnt/c/Users/maslke/Desktop/seed_2.dwg";
        deleteFile(path2);

        DwgObjectBlockHeader dwgBlockHeader = dwg.getObjectBlockHeader();
        Point3d start = new Point3d(100, 100, 0);
        Point3d end = new Point3d(200, 200, 0);
        Line line = dwgBlockHeader.addLine(start, end);
        Parent parent = line.getParent();
        parent.setColor(3);
        parent.setLinewt(50);

        Text text = dwgBlockHeader.addText("test", new Point3d(150, 150, 0), 2.5);
//        text.setRotation(90);
        text.setAlignmentPt(new Point2d(150, 150));
        text.setHorizAlignment(HorizAlignment.CENTER);
        text.setVertAlignment(VertAlignment.BOTTOM);
//        text.setWidthFactor(1);
        text.setTextValue("This is libredwg java wrapper");

        Circle circle = dwgBlockHeader.addCircle(new Point3d(150, 150, 0), 30);
        Arc arc = dwgBlockHeader.addArc(new Point3d(300, 300, 0), 100, 0, 1.57);
        circle.getParent().setLinewt(30);
        circle.getParent().setColor(2);
        arc.getParent().setColor(4);

        dwgBlockHeader.addEllipse(new Point3d(120, 120, 0), 100, 0.8);

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
