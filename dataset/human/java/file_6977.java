import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        
        int array[] = new int[N];
        int gap = 0;
        
        for(int i=0;i<N;i++){
            array[i] = sc.nextInt();
        }
        
        int tmp;
        
        for(int i=0;i<N-1;i++){
            tmp = array[i+1] - array[i];
            gap = Math.max(gap, tmp);
        }
        
        tmp = (array[0] + K) - array[N-1];
        gap = Math.max(gap, tmp);
        
        System.out.println(K-gap);
    }
}
