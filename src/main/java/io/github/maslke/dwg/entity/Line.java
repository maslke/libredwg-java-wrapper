package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.common.Point3d;
import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;
import io.github.maslke.dwg.common.Vector3d;


@Getter
@Setter
@AllArgsConstructor
public class Line extends BaseEntity {
    private Point3d startPoint;
    private Point3d endPoint;
    private Vector3d extrusion;
    private Double thickness;
}