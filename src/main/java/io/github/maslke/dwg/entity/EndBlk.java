package io.github.maslke.dwg.entity;

public class EndBlk extends Common {

    public EndBlk() {

    }

    public EndBlk(long ref) {
        this();
        this.ref = ref;
    }

    public Parent getParent() {
        return new Parent(this.getParent(this.ref));
    }

    private native long getParent(long ref);
}
