//package src.com.jetman.atcoder;

import java.util.*;

/**
 * @description:
 * @author: Jetman
 * @create: 2020-08-29 14:39
 **/
public class Main {

    Scanner sc = new Scanner(System.in);

    long MOD = 1000000000 + 7;

    long dp[][];

    private void slove() {

        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }

        boolean ans = false;
        for (int i = 2; i < n; i++) {
            if (a[i] != b[i]) continue;
            if (a[i-1] == b[i-1] && a[i-2] == b[i-2]) {
                ans = true;
                break;
            }
        }

        System.out.println(ans?"Yes":"No");



    }

    private void build(Map<Integer, List<Integer>> edge, int l, int r) {
        List<Integer> list = edge.getOrDefault(l, new ArrayList<>());
        list.add(r);
        edge.put(l,list);
    }


    public static void main(String[] args) {
        new Main().slove();
    }
}
