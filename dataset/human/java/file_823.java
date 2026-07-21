import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int R = sc.nextInt();
        
        int rate;
        
        if(N>=10){
            rate = R;
        } else {
            rate = R + 100 * (10-N);
        }
        
        System.out.println(rate);
    }
}
