import java.util.Scanner;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long a=sc.nextLong(),b=sc.nextLong(),c=sc.nextLong();
    if(a+b>=c) {
    	System.out.println(b+c);
    }else {
    	System.out.println(a+b+1+b);
    }
  }
}
