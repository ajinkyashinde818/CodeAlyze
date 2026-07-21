import java.io.*;
import java.util.*;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static Scanner sc = new Scanner(System.in);
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    long mod = 1000000000+7;
    int cnt2 = 0;
    ArrayList<Integer>[] tree;
    public static void main(String[] args) throws IOException {
        Main main = new Main();
//        main.solve();
        out.println(main.solve());
        out.flush();
    }
    long solve() throws IOException {
        int n = sc.nextInt();
        char[] s = sc.next().toCharArray();
        long ans = 1, left = 0;
        int cntPair = 0;
        for(char c:s){
            if(c=='W'){
                // this is 'W' plus self gives black
                if(left%2==1){
                    // then this is '('
                    left ++;
                } else{
                    // left%2==0, this should be ')'
                    if(left==0) return 0;
                    ans = ans*left%mod;
                    left--;
                    cntPair++;
                }
            } else{ // c = 'B'
                if(left%2==1){
                    // then this is ')'
                    ans = ans*left%mod;
                    left--;
                    cntPair++;
                } else{
                    // then this is '('
                    left ++;
                }
            }
        }
        if(left!=0) return 0;
        for(int i=1;i<=cntPair;i++){
            ans = ans*i%mod;
        }
        return ans;
    }
}
