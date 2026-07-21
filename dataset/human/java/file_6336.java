import java.util.*;
import java.util.Collections;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = Integer.parseInt(sc.next());
        int S = Integer.parseInt(sc.next());
        
        long count = 0;
        
        for(int x = 0; x <= K; x++) {
            if(x == S) {
                count++;
                break;
            }
            if(x > S) {
                break;
            }
            if(x+K+K < S) {
                continue;
            }
            for(int y = 0; y <= K; y++) {
                if(x + y == S) {
                    count++;
                    break;
                }
                if(x + y > S) {
                    break;
                }
                if(x+y+K < S) {
                    continue;
                }
                count++;
            }
            
        }
        
        System.out.println(count);
        
    }
}
