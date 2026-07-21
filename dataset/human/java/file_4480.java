import java.util.*;

class Main{
  public static void main(String args[]){
    Scanner s=new Scanner(System.in);
    int
    a=s.nextInt(),
    b=s.nextInt(),
    c=s.nextInt();
    
    System.out.println(Math.min(a+b+1,c)+b);
    
  }
}
