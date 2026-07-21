import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] holeIndices = new int[M];

        for (int i=0; i<M; i++) {
            holeIndices[i] = sc.nextInt() - 1;
        }

        boolean[] holes = new boolean[N];
        for (int i=0; i<N; i++) {
            holes[i] = false;
        }
        for (int index : holeIndices) {
            holes[index] = true;
        }

        if (holes[0] && holes[1]) {
            System.out.println(0);
            return;
        }

        List<Integer> dp = new ArrayList<>();
        dp.add(1);
        if (!holes[0]) {
            dp.add(2);
        } else {
            dp.add(1);
        }

        for (int i=2; i<N; i++) {
            if (holes[i]) {
                if (holes[i-1]) {
                    System.out.println(0);
                    return;
                } else {
                    dp.add(dp.get(i-1));
                }
            } else {
                if (!holes[i-1] && !holes[i-2]) {
                    dp.add((dp.get(i-1) + dp.get(i-2)) % 1000000007);
                } else {
                    dp.add(dp.get(i-1));
                }
            }
        }
        System.out.println(dp.get(N-1));
    }
}
