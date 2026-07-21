import java.util.*;
import java.util.ArrayList;

class Main{
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] A = new int[N];
        int m = 0;
        int min = 1000000001;
        long sum = 0;

        for(int i=0; i<N; i++){
            A[i] = sc.nextInt();
            sum += Math.abs(A[i]);
            min = Math.min(min, Math.abs(A[i]));
            if(A[i]<0){
                m += 1;
            }
        }
        if(m%2==0){
            System.out.println(sum);
        }
        else{
            System.out.println(sum - 2 * min);
        }
    }
}
