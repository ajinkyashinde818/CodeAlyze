import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    int r = sc.nextInt();
    
    if(r<1200) System.out.print("ABC");
    
    else if(r>=1200) System.out.print("ARC");
  }
}
