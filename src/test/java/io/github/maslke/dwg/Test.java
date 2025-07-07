package io.github.maslke.dwg;

import io.github.maslke.dwg.common.Point3d;
import io.github.maslke.dwg.entity.Line;
import io.github.maslke.dwg.entity.ParentEntity;

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

        DwgBlockHeader dwgBlockHeader = dwg.getBlockHeader();
        Point3d start = new Point3d(100, 100, 0);
        Point3d end = new Point3d(200, 200, 0);
        Line line = dwgBlockHeader.addLine(start, end);
        ParentEntity parent = line.getParentEntity();
        parent.setColor(3);
        parent.setLinewt(50);
        if (dwg.save(path2)) {
            System.out.println("save successfully.");
        }
    }

    private static void deleteFile(String name) {
        Path path = Paths.get(name);
        try {
            if (Files.exists(path)) {
                Files.delete(path);
                Files.delete(path);
                System.out.println("file deleted: " + path);
            }
        }
        catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
    }
}
