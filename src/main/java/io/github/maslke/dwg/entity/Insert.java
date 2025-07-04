package io.github.maslke.dwg.entity;

import lombok.Getter;
import lombok.Setter;
import io.github.maslke.dwg.common.Point3d;

@Getter
@Setter
public class Insert extends BaseEntity {
    private String blockName;
    private Point3d insertPoint;
    private Double rotation;
}