import java.util.*;
public class Main {
    
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long K = scanner.nextLong();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt()-1;
        }
        int count = 0;
        int current = 0;
        int[] visited = new int[N];
        for (int i = 0; i < visited.length; i++) {
            visited[i] = -1;
        }
        visited[0] = 0;
        while(true){
            count ++;
            current = A[current];
            if(count == K) break;
            if(visited[current] != -1) break;
            visited[current] = count;
        }
        if(visited[current] == -1){
            System.out.println(current+1);
            return;
        }
        // for (int i = 0; i < N; i++) {
        //     System.out.print(visited[i]);
        // }
        int roopsize = count - visited[current];
        if(roopsize == 0){
            System.out.println(current+1);
            return;
        }
        // System.out.println(roopsize);
        int beforeroop = visited[current];
        // System.out.println(beforeroop);
        long res = (K-(long)beforeroop) % (long)roopsize;
        // System.out.println(res);
        for (long i = 0; i < res; i++) {
            current = A[current];
        }
        System.out.println(current +1);
    }
}
