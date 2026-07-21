import java.util.*;

class Main {
    public static void main(String[] args) {
        new Solver().run();
    }
}

class Solver {

    public void run() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();
        //int K = sc.nextInt();

        int[] A = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            A[i] = sc.nextInt();
        }

        Set<Integer> set = new HashSet<Integer>();
        int pos = 1;
        set.add(pos);
        ArrayList<Integer> path = new ArrayList<Integer>();
        path.add(pos);
        int loopStart = -1;
        while (true) {
            if (set.contains(A[pos])) {
                loopStart = path.indexOf(A[pos]);
                break;
            }
            set.add(A[pos]);
            path.add(A[pos]);
            pos = A[pos];
        }

        long loopsize = path.size() - loopStart;
        int ans = -1;
        if (loopStart >= K) {
            ans = path.get((int)K);
        } else {
            // loopStart < 
            long tmp = (K - loopStart) % loopsize + loopStart;
            int idx = (int) tmp;
            ans = path.get(idx);
        }

        System.out.println(ans);

        return;
    }

}
