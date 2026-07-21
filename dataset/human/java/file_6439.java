import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int S = sc.nextInt();
        int count = 0;
        for(int x = 0; x <= K; x++){
            for(int y = 0; y <= K; y++){
                int total = x + y;
                if(!(total > S) && (total + K) >= S){
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}
