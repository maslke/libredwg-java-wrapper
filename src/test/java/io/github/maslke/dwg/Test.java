package io.github.maslke.dwg;

public class Test {
    public static void main(String[] args) {
        Dwg dwg = Dwg.createDocument();
        System.out.println(dwg.getVersion());
    }
}
