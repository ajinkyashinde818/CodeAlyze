import java.util.*;
 
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String X = sc.next();
    String Y = sc.next();
    
    HashMap<String, Integer> A = new HashMap<>();
    A.put("A", 10);
    A.put("B", 11);
    A.put("C", 12);
    A.put("D", 13);
    A.put("E", 14);
    A.put("F", 15);
    
    if (A.get(X) > A.get(Y)){   
      System.out.println(">");
    }else if(A.get(X) < A.get(Y)){
      System.out.println("<");
    }else{
      System.out.println("=");
    }
  }
}
