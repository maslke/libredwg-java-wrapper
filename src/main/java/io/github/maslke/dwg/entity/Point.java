package io.github.maslke.dwg.entity;

import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import io.github.maslke.dwg.common.Vector3d;

@Getter
@Setter
@AllArgsConstructor
public class Point extends BaseEntity {
    private Double x;
    private Double y;
    private Double z;
    private Vector3d extrusion;
    private Double thickness;
}