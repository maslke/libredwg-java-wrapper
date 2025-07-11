package io.github.maslke.dwg.entity;

import lombok.Getter;
import lombok.Setter;
import lombok.AllArgsConstructor;

@Getter
@Setter
@AllArgsConstructor
public class Lwpolyline extends Common {

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }

    private native long getParentNative(long ref);
}
