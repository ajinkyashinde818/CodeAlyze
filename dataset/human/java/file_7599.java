import java.util.*;
public class Main {

  public static void main(String[] args) { 
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      long k = sc.nextLong();
      int[] arr = new int[n+1];
      for(int i = 1; i <= n; i++)
        arr[i] = sc.nextInt();

      int fast = 1;
      int slow = 1;
      long moves = 0;
      while(true) {
        fast = arr[arr[fast]];
        slow = arr[slow];
        moves++;
        if(fast == slow) break;
      }

      fast = 1;
      while(fast != slow && k > 0) {
        fast = arr[fast];
        slow = arr[slow];
        k--;
      }

      if(k > 0) {
        int res = fast;
        long step = k % moves;
        for(long i = 0; i < step; i++)
          res = arr[res];
        System.out.println(res);
      } else {
        System.out.println(fast);
      }
  }
}
