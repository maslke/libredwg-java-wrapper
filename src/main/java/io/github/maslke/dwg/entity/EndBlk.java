package io.github.maslke.dwg.entity;

import io.github.maslke.dwg.obj.DwgObjectEntity;

public class EndBlk extends AbstractBaseEntity {

    public EndBlk() {

    }

    public EndBlk(long ref) {
        this();
        this.ref = ref;
    }

    public DwgObjectEntity getParent() {
        return new DwgObjectEntity(this.getParent(this.ref));
    }

    private native long getParent(long ref);
}
