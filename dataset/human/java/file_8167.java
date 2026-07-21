import java.util.*;
public class Main{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long a = sc.nextLong();
    long b = sc.nextLong();
    long k;
    if(a>=b){
      k = b;
    }else{
      k = a;
    }
    for(long x =k ; x>=1 ; x--){
      if(a%x==0 && b%x==0){
        Long l;
        l = (a*b)/x;
        System.out.println(l);
        break;
      }
    }

  }
}
