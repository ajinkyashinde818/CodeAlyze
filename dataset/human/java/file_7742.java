import java.util.Scanner;

public class Main {
    static int n = 0;
    static long k = 0;
    static int[] a = null;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        k = in.nextLong();
        a = new int[n+1];
        for(int i=1; i<=n; i++) {
            a[i] = in.nextInt();
        }
        int[] visited = new int[n+1];
        for(int i=1; i<=n; i++) {
            visited[i] = -1;
        }
        
        int count = 0;
        int offset = 0;
        int loopTerm = 0;
        int current = 1;
        visited[current] = 0;
        while(true) {
            int next = a[current];
            count++;
            if(visited[next] >= 0) {
                offset = visited[next];
                loopTerm = count - offset;
                break;
            }
            visited[next] = count;
            current = next;
        }
        if(k>offset) {
            k -= offset;
            k %= loopTerm;
            k += offset;
        }
        current = 1;
        for(int i=0; i<k; i++) {
            current = a[current];
        }
        System.out.println(current);
    }
}
