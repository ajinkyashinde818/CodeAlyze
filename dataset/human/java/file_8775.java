import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();
        

        int ans = 1;
        int count = 0;
        int i = 101;
        while(count < K){
            i--; 
            if( A % i == 0 && B % i == 0){
                ans = i;
                count++;
            }
        }
        System.out.println(ans);
    }
}
