import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static Tuple[] data;
    static int xt;
    static int yt;
    static int N;

    static class Tuple implements Comparable<Tuple> {
        long x;
        long y;
        long r;
        int index;
        double cost;

        @Override
        public int compareTo(Tuple o) {
            return Double.compare(cost, o.cost);
        }
    }

    static double dist(Tuple a, Tuple b) {
        double p = Math.hypot((a.x - b.x), (a.y - b.y));
        p -= a.r + b.r;
        if (p < 0) {
            p = 0;
        }
        p += a.cost;

        return p;
    }

    public static void setNext(PriorityQueue<Tuple> queue, Tuple a, double[] dp) {
        for (int i = 0; i < data.length; i++) {
            Tuple t = new Tuple();
            t.x = data[i].x;
            t.y = data[i].y;
            t.index = i;
            t.r = data[i].r;
            t.cost = dist(a, data[i]);
            if (dp[i] > t.cost) {
                queue.add(t);
            }
        }
        Tuple end = new Tuple();
        end.x = xt;
        end.y = yt;
        end.r = 0;
        end.cost = dist(a, end);

        end.index = N;
        if (dp[N] > end.cost) {
            queue.add(end);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int xs = sc.nextInt();
        int ys = sc.nextInt();


        xt = sc.nextInt();
        yt = sc.nextInt();
        N = sc.nextInt();
        data = new Tuple[N];
        for (int i = 0; i < N; i++) {
            Tuple t = new Tuple();
            t.x = sc.nextInt();
            t.y = sc.nextInt();
            t.r = sc.nextInt();
            t.index = i;
            data[i] = t;
        }

        Tuple start = new Tuple();
        start.x = xs;
        start.y = ys;

        PriorityQueue<Tuple> queue = new PriorityQueue<>();
        double[] dp = new double[N + 1];

        Arrays.fill(dp, Double.MAX_VALUE);

        setNext(queue, start, dp);

        while (queue.size() > 0) {
            final Tuple poll = queue.poll();
            if (dp[poll.index] > poll.cost) {
                dp[poll.index] = poll.cost;
                setNext(queue, poll, dp);
            }
        }
        System.out.println(dp[N]);
    }
}
