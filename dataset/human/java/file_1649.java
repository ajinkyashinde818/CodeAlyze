import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        long mod = (long)Math.pow(10,9) + 7;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] s = sc.next().toCharArray();
        int[] cl = new int[26];
        for(char c : s){
            cl[c - 'a']++;
        }
        long ans = 1;
        for(int i : cl){
            ans *= i+1;
            ans %= mod;
        }
        System.out.println(ans-1);
    }
}
