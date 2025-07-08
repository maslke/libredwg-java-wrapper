package io.github.maslke.dwg.entity;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class MText extends Common {

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }

    private native long getParentNative(long ref);
}
