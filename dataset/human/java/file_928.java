import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int r = sc.nextInt();
        int ans = 0;
        if(num < 10){
            ans = 100 * (10 - num);
            ans = ans + r;
        }else{
            ans = r;
        }
       
        System.out.println(ans);
    }
}
