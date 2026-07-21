import java.util.*;


public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        long snack1 = sc.nextLong();
        long snack2 = sc.nextLong();
        long min = Math.min(snack1,snack2);
        long max = Math.max(snack1,snack2);
        
        long num = 1;
        
        long ans = 0;
        
        while(true){
            if((min * num)%max == 0){
                ans = min * num;
                break;
            } 
            num++;
        }
  System.out.println(ans);
    }
}
