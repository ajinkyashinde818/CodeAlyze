import java.io.*;

public class Main {

    class Node {
        int parent = -1;
        int left = -1;
        int right = -1;
    }

    Node[] nodes;

    int getHeight(int id) {
        int r = nodes[id].right;
        int l = nodes[id].left;
        if (r != -1 && l != -1) {
            return Math.max(getHeight(r), getHeight(l)) + 1;
        } else if (r != -1) {
            return getHeight(r) + 1;
        } else if (l != -1) {
            return getHeight(l) + 1;
        } else {
            return 0;
        }
    }

    int getDepth(int id) {
        int p = nodes[id].parent;
        if (p != -1) {
            return getDepth(p) + 1;
        } else {
            return 0;
        }
    }

    int getDegree(int id) {
        int l = nodes[id].left != -1 ? 1 : 0;
        int r = nodes[id].right != -1 ? 1 : 0;
        return l + r;
    }

    enum Type {
        Root,
        InternalNode,
        Leaf;

        @Override
        public String toString() {
            switch (this) {
                case Root:
                    return "root";
                case InternalNode:
                    return "internal node";
                case Leaf:
                    return "leaf";
                default:
                    throw new IllegalArgumentException("");
            }
        }
    }

    Type getType(int id) {
        int d = getDepth(id);
        int h = getHeight(id);
        if (d == 0) {
            return Type.Root;
        }
        if (h == 0) {
            return Type.Leaf;
        }
        return Type.InternalNode;
    }

    int getSibling(int id) {
        int p = nodes[id].parent;
        if (p == -1) {
            return -1;
        } else {
            int l = nodes[p].left;
            int r = nodes[p].right;
            if (id == l) {
                return r;
            } else {
                return l;
            }
        }
    }

    void show(int id) {
        System.out.println(String.format("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s",
                id,
                nodes[id].parent,
                getSibling(id),
                getDegree(id),
                getDepth(id),
                getHeight(id),
                getType(id).toString()
        ));
    }

    void solve() {
        int n = io.nextInt();
        nodes = new Node[n];
        for (int i = 0; i < n; i++) nodes[i] = new Node();
        for (int i = 0; i < n; i++) {
            int id = io.nextInt();
            int left = io.nextInt();
            int right = io.nextInt();
            nodes[id].left = left;
            nodes[id].right = right;
            if (left != -1)
                nodes[left].parent = id;
            if (right != -1)
                nodes[right].parent = id;
        }

        for (int i = 0; i < n; i++) {
            show(i);
        }

    }

    public static void main(final String[] args) {
        new Main().solve();
    }

    IO io = new IO();

    class IO {
        private final int SIZE = 1 << 12;
        private final InputStream stream = System.in;
        private final byte[] buffer = new byte[SIZE];
        private int ptr = 0, buffLen = 0;

        private boolean hasNextByte() {
            if (ptr < buffLen) return true;
            ptr = 0;
            try {
                buffLen = stream.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return buffLen > 0;
        }

        private byte readByte() {
            if (hasNextByte()) return buffer[ptr++];
            return -1;
        }

        private boolean isAscii(byte i) {
            return '!' <= i && i <= '~';
        }

        public char nextChar() {
            byte b = readByte();
            while (!isAscii(b)) b = readByte();
            return (char) b;
        }

        public String next() {
            StringBuilder sb = new StringBuilder();
            byte b = readByte();
            while (isAscii(b)) {
                sb.append((char) b);
                b = readByte();
            }
            return sb.toString();
        }

        public int nextInt() {
            return Integer.valueOf(next());
        }

        public long nextLong() {
            return Long.valueOf(next());
        }

        public double nextDouble() {
            return Double.valueOf(next());
        }
    }
}
