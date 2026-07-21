import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    String s=sc.next();
//    int x=sc.nextInt();
//    int a=sc.nextInt();
//    int b=sc.nextInt();
    System.out.println(((s.indexOf('a')!=-1)&&(s.indexOf('b')!=-1)&&(s.indexOf('c')!=-1))?"Yes":"No");
  }
}
