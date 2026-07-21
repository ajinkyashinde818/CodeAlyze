import java.util.HashSet;
    import java.util.Iterator;
    import java.util.Scanner;
     
    public class Main {
     
    static Scanner sc = new Scanner(System.in);
    static int N;
    static int R;
    static long[] x, y;
     
    static int solve() {
    HashSet<Grid> set = new HashSet<Grid>();
    for (int i = 0; i < N; ++i) {
    Grid grid = new Grid(x[i], y[i]);
    set.add(grid);
    }
    int ans = 0;
    Iterator<Grid> itr = set.iterator();
    HashSet<Grid> visited = new HashSet<Grid>();
    while (itr.hasNext()) {
    Grid cur = itr.next();
    if (visited.contains(cur)) continue;
    ++ans;
    for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
    Grid grid = new Grid();
    grid.xl = cur.xl + i;
    grid.yl = cur.yl + j;
    if (set.contains(grid)) {
    visited.add(grid);
    }
    }
    }
    }
    return ans;
    }
     
    static class Grid {
    long xl, yl;
    boolean visited = false;
     
    Grid(long x, long y) {
    this.xl = x / R;
    this.yl = y / R;
    }
     
    Grid() {}
     
    public int hashCode() {
    final int prime = 31;
    int result = 1;
    result = prime * result + (int) (xl ^ (xl >>> 32));
    result = prime * result + (int) (yl ^ (yl >>> 32));
    return result;
    }
     
    public boolean equals(Object obj) {
    Grid other = (Grid) obj;
    if (xl != other.xl) return false;
    if (yl != other.yl) return false;
    return true;
    }
     
    }
     
    public static void main(String[] args) {
    N = sc.nextInt();
    R = toInt(sc.next());
    x = new long[N];
    y = new long[N];
    for (int i = 0; i < N; ++i) {
    x[i] = toInt(sc.next()) + (long) 1e9;
    y[i] = toInt(sc.next()) + (long) 1e9;
    }
    System.out.println(solve());
    }
     
    static int toInt(String ds) {
    return Integer.parseInt(ds.replaceAll("\\.", ""));
    }
     
    }
