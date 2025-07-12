package io.github.maslke.dwg.entity;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
public class EndBlk extends Common {

    public Parent getParent() {
        return new Parent(this.getParentNative(this.ref));
    }

    private native long getParentNative(long ref);
}

