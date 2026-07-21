import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;

public class Main {
    static ArrayList<Integer> counter = new ArrayList<>();

    static {
        counter.add(1);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String line = bufferedReader.readLine();
        long N = Long.parseLong(line);
        int lim = (int) Math.sqrt(N) + 1;
        ArrayList<Integer> pSet = new ArrayList<>();
        int cnt = 0;
        {
            int i = 2;
            if (isP(i, pSet)) {
                Pair pair = div(N, i);
                if (pair.cnt != 0) {
                    cnt += count(pair.cnt);
                    N = pair.res;
                }
                pSet.add(i);
            }
        }
        for (int i = 3; i < lim; i += 2) {
            int tlim = (int) Math.sqrt(N) + 1;
            if (tlim < i) {
                break;
            }
            if (isP(i, pSet)) {
                Pair pair = div(N, i);
                if (pair.cnt != 0) {
                    cnt += count(pair.cnt);
                    N = pair.res;
                }
                pSet.add(i);
            }
        }
        if (N != 1) {
            cnt++;
        }
        System.out.println(cnt);
    }

    private static int count(int src) {
        int size = counter.size();
        for (int i = 0; i < size; i++) {
            int l = counter.get(i);
            if (src < l) {
                return i;
            }
        }
        int max = counter.get(size - 1);
        for (int i = size; ; i++) {
            max += i + 1;
            counter.add(max);
            if (src < max) {
                return i;
            }
        }
    }

    private static Pair div(long src, int p) {
        int cnt = 0;
        while (true) {
            if (src / p * p == src) {
                src = src / p;
                cnt++;
            } else {
                return new Pair(src, cnt);
            }
        }
    }

    private static boolean isP(int src, ArrayList<Integer> pSet) {
        for (Integer p : pSet) {
            if (src / p * p == src) {
                return false;
            }
            if (p * p > src) {
                break;
            }
        }
        return true;
    }

    static class Pair {
        long res;
        int cnt;

        public Pair(long res, int cnt) {
            this.res = res;
            this.cnt = cnt;
        }
    }
}
