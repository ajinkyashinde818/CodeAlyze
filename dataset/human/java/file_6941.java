import java.util.*;
import java.util.ArrayList;
import java.util.Collections;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
 
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];

        for(int i=0; i<N; i++){
            A[i] = sc.nextInt();
        }
        ArrayList<Integer> list = new ArrayList<Integer>();
        int[] B = new int[N];
        for(int i=0; i<N-1; i++){
            B[i] = A[i + 1] - A[i];
            list.add(B[i]);
        }
        B[N - 1] = K - A[N - 1] + A[0];
        list.add(B[N - 1]);

        Collections.sort(list);

        int ans = 0;
        for(int i=0; i<N-1; i++){
            ans += list.get(i);
        }
        System.out.println(ans);
    }
}
