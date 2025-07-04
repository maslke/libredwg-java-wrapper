package io.github.maslke.dwg.entity;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public abstract class BaseEntity {
    private int color;
    private String lltype;
    private String linewt;
    private Boolean visible;
    private String layer;
}