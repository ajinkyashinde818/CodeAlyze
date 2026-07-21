import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] array = new int[n];
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        ArrayList<Integer> loop = new ArrayList<>();
        loop.add(1);
        visited[0] = true;
        int index = 0;
        int to = array[index] - 1;
        while (!visited[to]) {
            visited[to] = true;
            loop.add(to + 1);
            index = to;
            to = array[index] - 1;
        }
        int loopHead = loop.indexOf(to + 1);
        if (k < loopHead) {
            System.out.println(loop.get((int)k));
        } else {
            k -= loopHead;
            int v = (int)(k % (loop.size() - loopHead));
            System.out.println(loop.get(v + loopHead));
        }
    }
}
