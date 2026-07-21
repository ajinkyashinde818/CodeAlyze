import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();
        int[] A = new int[N];
        for (int i = 0; i < A.length; i++) {
            A[i] = sc.nextInt() - 1;
        }
        int index = 0;
        Set<Integer> index_memory = new HashSet<>();        
        while (!index_memory.contains(index)) {
            index_memory.add(index);
            index = A[index];
        }
        Set<Integer> loop_memory = new HashSet<>();
        while (!loop_memory.contains(index)) {
            loop_memory.add(index);
            index = A[index];
        }
        int toLoop = index_memory.size() - loop_memory.size();
        long r;
        if (K <= toLoop) {
            r = K;
            index = 0;
        } else {
            r = (K - toLoop) % loop_memory.size();
        }
        for (int i = 0; i < r; i++) {
            index = A[index];
        }
        System.out.println(index + 1);
        sc.close();
    }
}
