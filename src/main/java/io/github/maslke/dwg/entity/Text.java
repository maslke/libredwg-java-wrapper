package io.github.maslke.dwg.entity;

import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
public class Text {
    private long ref;
    private long header;
    private String text;
    private double height;
    private int color;
    private double rotation;
}
