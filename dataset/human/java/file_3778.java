import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    String x = sc.next();
    String y = sc.next();
    int num_x = 0;
    int num_y = 0;
   
    if(x.equals("A")) num_x=10;
    else if(x.equals("B")) num_x=11;
    else if(x.equals("C")) num_x=12;
    else if(x.equals("D")) num_x=13;
    else if(x.equals("E")) num_x=14;
    else if(x.equals("F")) num_x=15;

    if(y.equals("A")) num_y=10;
    else if(y.equals("B")) num_y=11;
    else if(y.equals("C")) num_y=12;
    else if(y.equals("D")) num_y=13;
    else if(y.equals("E")) num_y=14;
    else if(y.equals("F")) num_y=15;

    if(num_x == num_y) System.out.println("=");
    else if(num_x > num_y) System.out.println(">");
    else System.out.println("<");
    
  }
}
