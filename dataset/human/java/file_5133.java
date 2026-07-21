import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        ArrayDeque<String> deq = new ArrayDeque<>();
        for (int i = 0; i < str.length(); i++) {
            String s = String.valueOf(str.charAt(i));
            deq.offerLast(s);
        }
        int q = sc.nextInt();
        
        int reverse = 0;
        while (q-- > 0) {
            int type = sc.nextInt();
            if (type == 1) {
                reverse ^= 1;
            } else {
                int index = sc.nextInt()-1;
                String s = sc.next();
                if (reverse == 1) {
                    index ^= 1;
                }
                
                if (index == 0) {
                    deq.offerFirst(s);
                } else {
                    deq.offerLast(s);
                }
            }
        }
        
        if (reverse == 0) {
            while (!deq.isEmpty()) {
                System.out.print(deq.pollFirst());
            }
        } else {
            while (!deq.isEmpty()) {
                System.out.print(deq.pollLast());
            }
        }
        System.out.println();
    }
}
