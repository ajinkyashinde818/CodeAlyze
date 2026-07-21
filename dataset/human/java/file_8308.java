import java.util.Scanner;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long A = Integer.parseInt(sc.next());
    long B = Integer.parseInt(sc.next());
    System.out.print(A*B/gcd(A,B));
    return;
  }

  static long gcd(long a, long b){
    long max= Math.max(a,b);
    long min= Math.min(a,b);
    if(max%min==0){
      return min;
    }else{
      return gcd(max%min, min);
    }
  }  
  
}
