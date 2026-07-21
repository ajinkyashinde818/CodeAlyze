import java.util.Scanner;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long n = Long.parseLong(sc.next());
    long res ;
    if(n%2==1){
      res = 0;
    }else{
      long base = 5;
      res = 0;
      while(n >= base){
        res+=n/base/2;
        base*=5;
      }
    }
    System.out.println(res);
    
  }
}
