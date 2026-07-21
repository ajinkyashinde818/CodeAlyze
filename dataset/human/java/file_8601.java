import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int a, b, k;
      a=Integer.parseInt(sc.next());
      b=Integer.parseInt(sc.next());
      k=Integer.parseInt(sc.next());

      LinkedList<Integer> ans=new LinkedList<Integer>();
      for(int i=1; i<=100; i++){
        if(a%i==0 && b%i==0){
          ans.add(i);
        }
      }

      System.out.println(ans.get(ans.size()-k));
    
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}
