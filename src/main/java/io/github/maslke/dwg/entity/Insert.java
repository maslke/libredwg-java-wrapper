package io.github.maslke.dwg.entity;

import lombok.Getter;
import lombok.Setter;
import io.github.maslke.dwg.common.Point3d;

@Getter
@Setter
public class Insert extends Common {
    private String blockName;
    private Point3d insertPoint;
    private double rotation;

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }

    private native long getParentNative(long ref);
}
