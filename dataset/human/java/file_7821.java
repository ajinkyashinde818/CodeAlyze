import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        long res = 0;
        boolean[] seen = new boolean[n];
        int[] A = new int[n];
        for(int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(sc.next())-1;
        }
        int next = A[0];
        List<Integer> list = new ArrayList<>();
        list.add(0);
        int idx = -1;
        seen[0] = true;
        while(true) {
            if(seen[next]) {
                idx = next;
                break;
            }
            seen[next] = true;
            list.add(next);
            next = A[next];
        }

        int c = 0;
        next = A[idx];
        while(true) {
            c++;
            if(next == idx) break;
            next = A[next];
        }

        if(k < list.size()) {
        	res = list.get((int)k) + 1;
        } else {
        	res = list.get((int)((k - list.size() + c) % c + list.size() - c)) + 1;
        }

        System.out.println(res);
    }
}
