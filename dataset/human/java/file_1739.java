import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        long mod = 1000000007;
        int[] c = new int[26];
        Arrays.fill(c, 1);
        for(int i = 0; i < n; i++){
            char x = s.charAt(i);
            c[x - 'a']++;
        }
        long ans = 1;
        for(int i = 0; i < 26; i++){
            ans *= c[i];
            ans %= mod;
        }
        ans--;
        System.out.println(ans);
    }
}
