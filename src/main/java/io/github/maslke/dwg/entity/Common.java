package io.github.maslke.dwg.entity;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public abstract class Common {
    protected long ref;
    protected long header;

    protected Parent parent;

    public abstract Parent getParent();

    public boolean isEmpty() {
        return this.ref == 0;
    }
}
