import java.util.*;
public class Main {
  public static void main(String... args) {
    Scanner input = new Scanner(System.in);
    char[] s = input.next().toCharArray();
    Deque<Character> deque = new LinkedList<>();
    for (char c : s) {
      deque.addLast(c);
    }
    
    int q = input.nextInt();
    int rev = 0;
    for (int i = 0; i < q; i++) {
      int op = input.nextInt();
      if (op == 1) {
        rev++;
      } else {
        int f = input.nextInt();
        char c = input.next().charAt(0);
        if (rev % 2 == 0) {
     		if (f == 1) {
              deque.addFirst(c);
            } else {
              deque.addLast(c);
            }
        } else {
          if (f == 1) {
            deque.addLast(c);
          } else {
            deque.addFirst(c);
          }
        }
      }
    }
    
    StringBuilder sb = new StringBuilder();
    while (!deque.isEmpty()) {
      sb.append(deque.pollFirst());
    }
    
    System.out.println(rev % 2 == 0 ? sb.toString() : sb.reverse().toString());
  }
}
