import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int a=sc.next().charAt(0);
    int b=sc.next().charAt(0);
    System.out.println(a<b?"<":a>b?">":"=");
  }
}
