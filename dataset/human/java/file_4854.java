import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
    if(n%2!=0){
      System.out.println(0);
    }
    else{
      long a=0;
      long cur=5;
      while(cur<=n){
        a=a+(n/cur)/2;
        cur=cur*5;
      }
      System.out.println(a);
  } 
  }
}
