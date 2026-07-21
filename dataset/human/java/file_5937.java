import java.util.Scanner;

class Main{
  public static void main(String args[]){
    Scanner scan = new Scanner(System.in);
    String s = scan.next();
    char s1 = s.charAt(0);
    char s2 = s.charAt(1);
    char s3 = s.charAt(2);
    if(s1 != s2){
      if(s1 != s3 && s2 != s3){
        System.out.println("Yes");
      }else{
        System.out.println("No");
      }
    }else{
      System.out.println("No");
    }
  }
}
