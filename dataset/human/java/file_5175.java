import java.io.*;
import java.util.*;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);
    static Scanner sc = new Scanner(System.in);
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    int k;
    long[] d;
    public static void main(String[] args) throws IOException {
        Main main = new Main();
//        main.solve();
        System.out.println(main.solve());
    }
    String solve() throws IOException{
        LinkedList<Character> res = new LinkedList<>();
        String s = sc.next();
        for(char c:s.toCharArray()) res.addLast(c);
        int q = sc.nextInt();
        int normalOrder = 1;
        while(q-->0){
            int t = sc.nextInt();
            if(t==1){
                normalOrder ^= 1;
            } else{
                int f = sc.nextInt()-1;
                char c = sc.next().charAt(0);
                if((f^normalOrder)==1){
                    res.addFirst(c);
                } else{
                    res.addLast(c);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        while(res.size()>0){
            if(normalOrder==1) sb.append(res.pollFirst());
            else sb.append(res.pollLast());
        }
        return sb.toString();
    }
}
