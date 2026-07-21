import java.util.*;
import java.io.*;
import static java.lang.System.in;

public class Main {
    static int n,m;
    static long mod = 1000000000+7;
    // static ArrayList<Integer>[] graph,tree;
    public static void main(String[] args)throws IOException {
        //BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        Scanner sc = new Scanner(System.in);
        //String[] buf = reader.readLine().split(" ");
        n = sc.nextInt();
        char[] s = sc.next().toCharArray();
        int[] cnt = new int[26];
        for(char w:s){
            cnt[w-'a']++;
        }
        long ans = 1;
        for(int i=0;i<26;i++){
            ans = ans*(cnt[i]+1)%mod;
        }
        ans = (ans-1+mod)%mod;
        System.out.println(ans);
    }
    static long pow(long base, long p){
        long ans = 1;
        while(p>0){
            if(p%2==1) ans = ans*base%mod;
            base = base*base%mod;
            p /= 2;
        }
        return ans;
    }
}
