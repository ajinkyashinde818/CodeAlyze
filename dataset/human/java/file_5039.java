import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        int n = sc.nextInt();
        Deque<Character> deq = new ArrayDeque<>();
        for (int i = 0; i < s.length; i++) {
            deq.addFirst(s[i]);
        }
        boolean flg = false;
        for (int i = 0; i < n; i++) {
            int t = sc.nextInt();
            if(t == 1) {
                if(flg) {
                    flg = false;
                } else {
                    flg = true;
                }
            } else if(t == 2) {
                int f = sc.nextInt();
                char c = sc.next().charAt(0);
                if(flg && f == 1) {
                    deq.addFirst(c);
                } else if(!flg && f == 1) {
                    deq.addLast(c);
                } else if(flg && f == 2) {
                    deq.addLast(c);
                } else if(!flg && f == 2) {
                    deq.addFirst(c);
                }
            }
        }
        if(!flg) {
            while(!deq.isEmpty()) {
                System.out.print(deq.pollLast());
            }
        } else {
            while(!deq.isEmpty()) {
                System.out.print(deq.pollFirst());
            }
        }
    }
}
