import java.util.*;

public class Main{
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        String s = sc.next();
        sc.close();

        int n = s.length();
        int r = 0; 
        int l = n-1;
        int ans = 0;

        while(r <= l){
            int cntr = 0;
            int cntl = 0;
            while(s.charAt(r) == 'x' && r < n-1){
                r++;
                cntr++;
            }
            while(s.charAt(l) == 'x' && l > 0){
                l--;
                cntl++;
            }
            if(s.charAt(r) != s.charAt(l)){
                System.out.println(-1);
                return;
            } else {
                ans += Math.abs(cntr-cntl);
                r++;
                l--;
            }
        }
        System.out.println(ans);
   }
}
