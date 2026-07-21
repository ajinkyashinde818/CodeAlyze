import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        int ans = 0;
        int l = 0, r = s.length-1;
        while(0 < r - l){
            int fx = 0, bx = 0;
            while(l < r && s[l] == 'x'){
                fx++; l++;
            }
            while(l < r && s[r] == 'x'){
                bx++; r--;
            }
            if(s[l] != s[r]){
                ans = -1; break;
            }
            if(s[l] == 'x')break;
            ans += Math.abs(fx - bx);
            l++; r--;
            if(s.length-1 < l || r < 0)break;
        }
        System.out.println(ans);
        sc.close();

    }

}
