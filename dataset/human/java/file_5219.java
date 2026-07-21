import java.util.Scanner;
public class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    String S = sc.next();
    StringBuffer sb = new StringBuffer(S);
    StringBuffer head = new StringBuffer();
    StringBuffer tail = new StringBuffer();
    int Q = Integer.parseInt(sc.next());
    int T, F;
    String C;
    boolean rev = false;
    for(int i=0; i<Q; i++){
      T = Integer.parseInt(sc.next());
      if(T==1){
        if(rev)rev=false;
        else rev=true;
      } else if(T==2){
        F = Integer.parseInt(sc.next());
        C = sc.next();
        if(F==1){
          if(rev) tail.append(C);
          else head.append(C);
        } else if(F==2){
          if(rev) head.append(C);
          else tail.append(C);
        }
      }
    }
    if(rev){
      tail.reverse();
      sb.reverse();
      System.out.println(tail.append(sb).append(head));
    } else {
      head.reverse();
      System.out.println(head.append(sb).append(tail));
    }
  }
}
