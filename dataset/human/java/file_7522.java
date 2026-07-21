import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    String s = sc.next();
    int n=s.length();
    while(n>4){
//      System.out.println(n);
      if(s.substring(n-5,n).equals("dream")){
        n-=5;
      }else if(n>6&&s.substring(n-7,n).equals("dreamer")){
        n-=7;
      }else if(s.substring(n-5,n).equals("erase")){
        n-=5;
      }else if(n>5&&s.substring(n-6,n).equals("eraser")){
        n-=6;
      }else{
        System.out.println("NO");
        return;
      }
    }
    System.out.println("YES");
  }
}
