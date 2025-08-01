package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.Dwg;

public abstract class AbstractEntityTest {
    protected static final double TOLERANCE = 1e-3;

    protected void releaseDwg(AbstractBaseEntity entity) {
        if (entity != null && entity.getParent() != null) {
            Dwg dwg = entity.getParent().getDwg();
            dwg.release();
        }
    }
}
