import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int x = sc.nextInt();
    String result =  "";
    if(x<1200){
      result = "ABC";
    }else{
     result = "ARC";
    }
    System.out.println(result);
  }
}
