import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main{
    
 
    public static void main(String[] args)  {
        new Main().solve();
    }

    void solve(){
        Scanner sc = new Scanner(System.in);
        int K = Integer.parseInt(sc.next());
        int N = Integer.parseInt(sc.next());

        int[] a = new int[N];
        for(int i=0; i<N; i++){
            a[i] = Integer.parseInt(sc.next());
        }

        sc.close();

        int[] b = new int[N];
        b[0] = a[1] - a[0];
        for(int i=1; i<N-1; i++){
            b[i] = a[i+1] - a[i];
        }
        b[N-1] = K - a[N-1] + a[0];

        // System.out.println(Arrays.toString(b));

        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0; i< N; i++){
            list.add(b[i]);
        }

        Arrays.sort(b);
        int result=0;
        for(int i=0; i<N-1; i++){
            result += b[i];
        }

        System.out.println(result);

    }
}
