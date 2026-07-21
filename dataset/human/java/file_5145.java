import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Deque<Character> dq = new ArrayDeque<>();
        char[] s = sc.next().toCharArray();
        int cnt = 0;
        for(char c : s){
            dq.addLast(c);
            cnt++;
        }
        int n = sc.nextInt();
        boolean ret = false;
        for(int i = 0; i < n; i++){
            int q = sc.nextInt();
            if(q == 1){
                if(ret){
                    ret = false;
                }else{
                    ret = true;
                }
            }else{
                int q2 = sc.nextInt();
                if(q2 == 1 && !ret || q2 == 2 && ret){
                    dq.addFirst(sc.next().charAt(0));
                }else{
                    dq.addLast(sc.next().charAt(0));
                }
                cnt++;
            }
        }
        if(ret){
            for(int i = 0; i < cnt; i++){
                System.out.print(dq.removeLast());
            }
        }else{
            for(int i = 0; i < cnt; i++){
                System.out.print(dq.removeFirst());
            }
        }
        
    }
}
