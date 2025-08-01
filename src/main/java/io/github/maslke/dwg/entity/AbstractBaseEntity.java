package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.obj.DwgObjectEntity;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public abstract class AbstractBaseEntity {
    protected long ref;
    protected long header;

    protected DwgObjectEntity parent;

    public abstract DwgObjectEntity getParent();

    public boolean isEmpty() {
        return this.ref == 0;
    }
}