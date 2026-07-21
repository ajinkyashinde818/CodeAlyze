import java.awt.Point;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class Main {
    Scanner sc = new Scanner(System.in);

    void run() {
        Map<Integer, Character> dir = new HashMap<Integer, Character>();
        dir.put(0, 'W');
        dir.put(2, 'E');
        dir.put(1, 'S');
        dir.put(3, 'N');
        while (true) {
            // 1 行目 迷路の大きさ横 W 縦 H (整数 整数 ; 半角空白区切り)
            // 2 行目 迷路の 1 行目の情報 (半角英文字列)
            // :
            // H+1 行目 迷路の H 行目の情報
            int w = sc.nextInt();
            int h = sc.nextInt();
            if ((h | w) == 0)
                break;
            char[][] map = new char[h][w];
            for (int i = 0; i < h; i++) {
                map[i] = sc.next().toCharArray();
            }
            Queue<Man> q = new LinkedList<Man>();
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (map[i][j] == 'X' || map[i][j] == '.'
                            || map[i][j] == '#')
                        continue;
                    switch (map[i][j]) {
                    case 'W':
                        q.add(new Man(j, i, 0));
                        break;
                    case 'N':
                        q.add(new Man(j, i, 3));
                        break;
                    case 'E':
                        q.add(new Man(j, i, 2));
                        break;
                    case 'S':
                        q.add(new Man(j, i, 1));
                        break;
                    }
                }
            }
            for (int t = 1; t <= 180; t++) {
                Queue<Man> pq = new PriorityQueue<Man>();
                while (!q.isEmpty()) {
                    Man m = q.poll();
                    int x = m.x;
                    int y = m.y;
                    int d = m.d;
                    int dx[] = { 0, -1, 0, 1 };
                    int dy[] = { -1, 0, 1, 0 };
                    boolean imp = true;
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[(i + d) % 4];
                        int ny = y + dy[(i + d) % 4];
                        if (nx >= 0 && ny >= 0 && nx < w && ny < h
                                && (map[ny][nx] == '.' || map[ny][nx] == 'X')) {
                            pq.add(new Man(x, y, (d + i + 3) % 4));
                            imp = false;
                            break;
                        }
                    }
                    if (imp) {
                        pq.add(new Man(x, y, d));
                    }
                }
                char[][] nmap = new char[h][w];
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        nmap[i][j] = map[i][j];
                    }
                }
                int dx[] = { -1, 0, 1, 0 };
                int dy[] = { 0, 1, 0, -1 };
                Set<Point> set = new HashSet<Point>();
                while (!pq.isEmpty()) {
                    Man m = pq.poll();
                    int x = m.x;
                    int y = m.y;
                    int d = m.d;
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= w || ny >= h) {
                        q.add(m);
                        continue;
                    }
                    if (map[ny][nx] == '.') {
                        if (nmap[ny][nx] == '.') {
                            nmap[ny][nx] = dir.get(d);
                            nmap[y][x] = '.';
                            q.add(new Man(nx, ny, d));
                        } else {
                            q.add(m);
                        }
                    } else if (map[ny][nx] == 'X') {
                        Point p = new Point(nx, ny);
                        if (set.contains(p)) {
                            q.add(m);
                            continue;
                        }
                        set.add(p);
                        nmap[y][x] = '.';
                    } else {
                        q.add(m);
                    }
                }
                if (q.isEmpty()) {
                    System.out.println(t);
                    break;
                }
                if (t == 180) {
                    System.out.println("NA");
                }
                map = nmap;
            }
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}

class Man implements Comparable<Man> {
    int x;
    int y;
    int d; // E:2 N:3 W:0 S:1

    Man(int x, int y, int d) {
        this.x = x;
        this.y = y;
        this.d = d;
    }

    public String toString() {
        return "<x,y> = " + "<" + x + "," + y + "> " + "d = " + d;
    }

    @Override
    public int compareTo(Man o) {
        // TODO 自動生成されたメソッド・スタブ
        return d - o.d;
    }

}
