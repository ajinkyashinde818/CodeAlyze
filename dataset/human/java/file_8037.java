import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

class Main {
    public static void main(String[] args) {
        solve();
        Stdin.flush();
    }

    static void solve() {
        int[] inputs = Stdin.receiveIntArray("space");
        int num1 = inputs[0];
        int num2 = inputs[1];

        BigInteger ans = Calc.lcm(num1, num2);

        Stdin.println(ans);
    }

}

class ModCalc {
    static final BigInteger MOD = BigInteger.valueOf((int) 1e9 + 7);
}

class Calc {
    static BigInteger gcd(BigInteger x, BigInteger y) {
        if (y.subtract(x).signum() > 0) {
            return gcd(y, x);
        }
        if (y.equals(BigInteger.ZERO)) {
            return x;
        }
        return gcd(y, x.remainder(y));
    }

    static BigInteger gcd(int x, int y) {
        return gcd(BigInteger.valueOf(x), BigInteger.valueOf(y));
    }

    static BigInteger gcd(BigInteger[] arr) {
        BigInteger gcd = arr[0];
        for (BigInteger i : arr) {
            gcd = gcd(gcd, i);
        }
        return gcd;
    }

    static BigInteger gcd(int[] arr) {
        BigInteger gcd = BigInteger.valueOf(arr[0]);
        for (int i : arr) {
            gcd = gcd(gcd, BigInteger.valueOf(i));
        }
        return gcd;
    }

    static BigInteger lcm(BigInteger x, BigInteger y) {
        return x.multiply(y).divide(gcd(x, y));
    }

    static BigInteger lcm(int x, int y) {
        return lcm(BigInteger.valueOf(x), BigInteger.valueOf(y));
    }

    static BigInteger lcm(BigInteger[] arr) {
        BigInteger lcm = BigInteger.ONE;
        for (BigInteger i : arr) {
            lcm = lcm(lcm, i);
        }
        return lcm;
    }

    static BigInteger lcm(int[] arr) {
        BigInteger lcm = BigInteger.ONE;
        for (int i : arr) {
            lcm = lcm(lcm, BigInteger.valueOf(i));
        }
        return lcm;
    }

    static int digits(int x) {
        return String.valueOf(x).length();
    }

    static BigInteger arraySum(BigInteger[] arr) {
        BigInteger ret = BigInteger.ZERO;
        for (BigInteger bi : arr) {
            ret = ret.add(bi);
        }
        return ret;
    }

    static BigInteger arraySum(int[] arr) {
        BigInteger ret = BigInteger.ZERO;
        for (int i : arr) {
            ret = ret.add(BigInteger.valueOf(i));
        }
        return ret;
    }
}

class Grid {
    static int width, height;
    private static char[][] grid;
    static char road;

    static void generate(int width, int height, char road) {
        Grid.width = width;
        Grid.height = height;
        Grid.road = road;
        grid = new char[height][width];
        dist = new int[height][width];
    }

    static GridPoint point(int x, int y) {
        return new GridPoint(x, y);
    }

    static char grid(int x, int y) {
        return grid[y][x];
    }

    static void setGrid(int x, int y, char point) {
        Grid.grid[y][x] = point;
    }

    static void setGrid(int y, char[] row) {
        Grid.grid[y] = row;
    }

    static void setGrid(int y, char[][] grid) {
        Grid.grid = grid;
    }

    static boolean isValidPoint(GridPoint gp) {
        return gp.x >= 0 && gp.x < width && gp.y >= 0 && gp.y < height;
    }

    static boolean isRoad(GridPoint gp) {
        return grid(gp.x, gp.y) == road;
    }

    // 最短経路
    private static int[][] dist;

    static int dist(int x, int y) {
        return dist[y][x];
    }

    static void setDist(int x, int y, int dist) {
        Grid.dist[y][x] = dist;
    }

    static int maxDist() {
        int ans = -1;
        for (int[] rowDist : dist) {
            for (int dist : rowDist) {
                ans = ans > dist ? ans : dist;
            }
        }
        return ans;
    }

    static void bfs(GridPoint initialPoint) {
        for (int i = 0; i < height; i++) {
            Arrays.fill(dist[i], -1);
        }

        Deque<GridPoint> que = new ArrayDeque<>();
        que.addLast(initialPoint);
        setDist(initialPoint.x, initialPoint.y, 0);
        while (!que.isEmpty()) {
            GridPoint point = que.remove();
            int beforeDist = dist(point.x, point.y);
            for (GridPoint.Direction dir : GridPoint.Direction.values()) {
                GridPoint next = point.move(dir);
                if (!isValidPoint(next)) {
                    continue;
                }
                if (isRoad(next)) {
                    if (dist(next.x, next.y) == -1) {
                        setDist(next.x, next.y, beforeDist + 1);
                        que.addLast(next);
                    }
                }
            }
        }
    }

    static class GridPoint {
        int x, y;

        GridPoint(int x, int y) {
            this.x = x;
            this.y = y;
        }

        GridPoint move(Direction dir) {
            return new GridPoint(x + dir.dx, y + dir.dy);
        }

        static enum Direction {
            UP(0, -1), DOWN(0, 1), LEFT(-1, 0), RIGHT(1, 0);

            int dx, dy;

            private Direction(int dx, int dy) {
                this.dx = dx;
                this.dy = dy;
            }
        }
    }
}

class Stdin {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final PrintWriter pw = new PrintWriter(System.out);

    public enum Delimiter {
        NONE(""), SPACE(" "), DOT("\\."), COMMA(",");

        private String regex;

        private Delimiter(String regex) {
            this.regex = regex;
        }

        public static Delimiter of(String input) {
            try {
                return Delimiter.valueOf(input.toUpperCase());
            } catch (IllegalArgumentException e) {
                return Arrays.stream(values()).filter(d -> d.getRegex().equals(input)).findFirst().orElse(SPACE);
            }
        }

        public String getRegex() {
            return regex;
        }
    }

    static String nextLine() {
        try {
            return br.readLine();
        } catch (IOException e) {
            throw new IllegalArgumentException(e);
        }
    }

    static int receiveInt() {
        return Integer.parseInt(nextLine());
    }

    static BigInteger receiveBigInteger() {
        return new BigInteger(nextLine());
    }

    static char receiveChar() {
        return nextLine().charAt(0);
    }

    static char[] receiveCharArray() {
        return nextLine().toCharArray();
    }

    static int[] receiveIntArray(Delimiter delimiter) {
        String[] inputs = nextLine().split(delimiter.getRegex());
        int[] ret = new int[inputs.length];
        for (int i = 0; i < inputs.length; i++) {
            ret[i] = Integer.parseInt(inputs[i]);
        }
        return ret;
    }

    static int[] receiveIntArray(String delimiterString) {
        return receiveIntArray(Delimiter.of(delimiterString));
    }

    static BigInteger[] receiveBigIntegerArray(Delimiter delimiter) {
        String[] inputs = nextLine().split(delimiter.getRegex());
        BigInteger[] ret = new BigInteger[inputs.length];
        for (int i = 0; i < inputs.length; i++) {
            ret[i] = new BigInteger(inputs[i]);
        }
        return ret;
    }

    static BigInteger[] receiveBigIntegerArray(String delimiterString) {
        return receiveBigIntegerArray(Delimiter.of(delimiterString));
    }

    static String[] receiveStringArray(Delimiter delimiter) {
        return nextLine().split(delimiter.getRegex());
    }

    static String[] receiveStringArray(String delimiterString) {
        return receiveStringArray(Delimiter.of(delimiterString));
    }

    static void print(Object obj) {
        pw.print(obj);
    }

    static void printf(String str, Object... obj) {
        pw.printf(str, obj);
    }

    static void println(Object obj) {
        pw.println(obj);
    }

    static void println(Object... objs) {
        for (Object obj : objs) {
            println(obj);
        }
    }

    static void flush() {
        pw.flush();
    }
}
