import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        int left = 0;
        int right = s.length-1;
        int ans = 0;
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }else if(s[left] == 'x'){
                left++;
                ans++;
            }else if(s[right] == 'x'){
                right--;
                ans++;
            }else{
                System.out.println(-1);
                return;
            }
        }
        System.out.println(ans);
    }
}
