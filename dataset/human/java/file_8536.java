import java.util.*;
import java.lang.*;

public class Main{
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
  
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int ans = 0;
        
        int i = Math.min(a, b);
        int count = 0;
        
        while(true) {
            if (i <= 0) {
                break;
            }
            if (a % i == 0 && b % i == 0) {
                //System.out.println(i);
                count++;
            }
            if (count == k) {
                ans = i;
                break;
            }
            i--;
        }
        
        //System.out.println("---");
        System.out.println(ans);
    }

}
