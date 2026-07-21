import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] cs = sc.next().toCharArray();
        long[] ls = new long[26];
        long t = 1;
        for(int i = 0 ;i < ls.length;++i){
            ls[i] = 1;
        }
        for(int i = 0;i < cs.length;++i){
            ++ls[cs[i] - 'a'];
        }
        for(int i = 0 ;i < ls.length;++i){
            t *= ls[i];
            t %= 1000000007;
        }
        --t;
        System.out.println(t);
    }

}
