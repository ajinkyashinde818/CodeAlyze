import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String n = sc.next();
        int digit = n.length();
        long ans = 0;
        char[] a = n.toCharArray();
        int[] ai = new int[digit+1];
        for(int i = 0; i < digit; i++){
            ai[i] = a[digit-1-i] -48;
        }
        for(int i = 0; i < digit; i++){
            if(ai[i] < 5){
                ans += ai[i];
            }else if(ai[i] == 5){
                if(ai[i+1] < 5) {
					ans += ai[i];
				} else {
					ans += 10 - ai[i];
					ai[i+1]++;
				}
            }else{
                ans += 10-ai[i];
                ai[i+1]++;
            }
        }
        System.out.println(ans+ai[digit]);
    }
}
