import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();
        int[] A = new int[N];
        boolean[] jumped = new boolean[N];

        for(int i = 0 ; i < N ; i++){
            A[i] = sc.nextInt()-1;
            jumped[i] = false;
        }

        jumped[0] = false;
        int now = 0;
        ArrayList<Integer> list = new ArrayList<>(N);
        while(!jumped[now]){
            jumped[now] = true;
            list.add(now);
            now = A[now];
        }

        int loopFirst = 0;
        for(int i = 0 ; i < list.size() ; i++){
            if(list.get(i) == now){
                loopFirst = i;
            }
        }
        int loopLength = list.size() - loopFirst;

        if(K <= loopFirst){
            System.out.println(list.get((int)K)+1);
        }else{
            K -= loopFirst;
            K %= loopLength;
            K += loopFirst;
            System.out.println(list.get((int)K)+1);
        }
    }
}
