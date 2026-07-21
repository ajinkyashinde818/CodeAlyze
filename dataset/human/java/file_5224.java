import java.util.*;
public class Main {

  public static void main(String[] args) { 
      Scanner sc = new Scanner(System.in);
      String s = sc.next();
      int q = sc.nextInt();

      int reverseCnt = 0;
      int headFlag = 1;
      int tailFlag = 2;
      StringBuilder S = new StringBuilder(s);
      StringBuilder sb = new StringBuilder();
      
      while(q-- > 0) {
        int oper = sc.nextInt();
        if(oper == 1) {
          reverseCnt++;
          headFlag = headFlag ^ tailFlag;
          tailFlag = headFlag ^ tailFlag;
          headFlag = headFlag ^ tailFlag;
        } else {
          int f = sc.nextInt();
          char c = sc.next().charAt(0);
          if(f == headFlag)
            sb.append(c);
          else
            S.append(c);
        }
      }
      StringBuilder res = new StringBuilder(sb.reverse().toString() + S.toString());
      if(reverseCnt % 2 == 1)
        res.reverse();
      System.out.println(res.toString());
  }
}
