import java.util.*;

public class Main{
  static long cal_5(long n){
    long aa =0;
    int i= 1;
    while(n/((long)Math.pow(5,i)*2)!=0){
      aa += n/((long)Math.pow(5,i)*2);
      i += 1;
    }
    return aa;
  }




  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    long n = sc.nextLong();


    if(n%2==0){
      System.out.println(cal_5(n));
    }else{
      System.out.println(0);
    }
  }
}
