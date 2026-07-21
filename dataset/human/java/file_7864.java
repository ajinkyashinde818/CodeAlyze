import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();
        int A[] = new int[N+1];
        for(int n=1; n<=N; n++) {
            A[n] = sc.nextInt();
        }

        int mymap[] = new int[N+1];
        boolean visited[] = new boolean[N+1];
        int now = 1;
        int count = 0;
        int maxIndex = -1;
        mymap[count] = now;
        visited[now] = true;
        while(true) {
            int next = A[now];
            if(visited[next]) {
                // todo
                // ++count 回目にnextにループする
                // 持つべきマイマップのサイズは ++count
                maxIndex = ++count;
                mymap[maxIndex] = next;
                break;
            } else {
                mymap[++count] = next;
                visited[next] = true;
                now = next;
            }
        }
        // search loop start
        int loopStart = -1;
        for(int i=0; i<=maxIndex; i++) {
            if(mymap[i]==mymap[maxIndex]) {
                loopStart = i;
                break;
            }
        }
        int loopSize = maxIndex - loopStart;
//        System.out.println(String.format("maxIndex: %d, loopStart:%d, loopSize;%d", maxIndex, loopStart, loopSize));
        if(maxIndex>=K) {
            System.out.println(mymap[(int) K]);
        } else {
            long amari = (K - maxIndex) % loopSize;
            int amari_i = (int)amari;
            System.out.println(mymap[loopStart + amari_i]);
        }
    }
}
