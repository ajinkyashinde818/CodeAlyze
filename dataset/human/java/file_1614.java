import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc=new Scanner(System.in);
        sc.next();
        int ans[]=new int[26];
        for(char c:sc.next().toCharArray())
             ans[c-'a']++;
        long a=1;
        for(int i=0;i<26;i++)a=(a*(ans[i]+1))%1000000007;
        System.out.println(a-1);
    }
}
