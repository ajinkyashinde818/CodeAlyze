import java.util.Arrays;

import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

 class FS {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }

    private int readByte() {
        return hasNextByte() ? buffer[ptr++] : -1;
    }

    private boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    public boolean hasNext() {
        skipUnprintable();
        return hasNextByte();
    }

    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public int nextInt() {
        return (int) nextLong();
    }

    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
}

public class Main {
    static BinTree bt[];
    static int par[];

    public static void main(String[] args) {
        FS fs = new FS();
        int n = fs.nextInt();
        bt = new BinTree[n];
        par = new int[n];
        for (int i = 0; i < n; i++) {
            int id = fs.nextInt();
            int left = fs.nextInt();
            int right = fs.nextInt();
            if (left!=-1)par[left] = id + 1;
            if (right!=-1) par[right] = id + 1;
            bt[i] = new BinTree(id, left, right);
        }
        Arrays.sort(bt);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            BinTree binTree = bt[i];
            int sibling = -1;
            if (par[binTree.id] - 1 >= 0) {
                if (bt[par[binTree.id] - 1].left == binTree.id) sibling = bt[par[binTree.id] - 1].right;
                else sibling = bt[par[binTree.id] - 1].left;
            }
            int degree = 0;
            if (binTree.left != -1) degree++;
            if (binTree.right != -1) degree++;

            int depth = 0;
            int x = binTree.id;
            while (par[x] - 1 != -1) {
                depth++;
                x = par[x] - 1;
            }
            int height = getHeight(binTree);
            String type = "internal node";
            if (par[binTree.id]-1 == -1) type = "root";
            else if (binTree.left == -1 && binTree.right == -1) type = "leaf";
            sb.append("node ").append(binTree.id).append(": parent = ").append(par[binTree.id] - 1).append(", sibling = ")
                    .append(sibling).append(", degree = ").append(degree).append(", depth = ")
                    .append(depth).append(", height = ").append(height).append(", ").append(type).append("\n");
        }
        System.out.print(sb);
    }

    private static int getHeight(BinTree binTree) {
        if (binTree.left == -1 && binTree.right == -1) {
            return 0;
        }
        if (binTree.left == -1) return getHeight(bt[binTree.right]) + 1;
        else if (binTree.right == -1) return getHeight(bt[binTree.left]) + 1;
        else return Math.max(getHeight(bt[binTree.right]) + 1, getHeight(bt[binTree.left]) + 1);
    }

    static class BinTree implements Comparable<BinTree> {
        int id;
        int left;
        int right;

        public BinTree(int id, int left, int right) {
            this.id = id;
            this.left = left;
            this.right = right;
        }

        @Override
        public int compareTo(BinTree o) {
            if (this.id > o.id) return 1;
            else return -1;
        }
    }
}
