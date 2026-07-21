import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int x = sc.nextInt();
    
    if (n < 10)
      x += 100 * (10 - n);
    
    System.out.println(x);
  }
}
