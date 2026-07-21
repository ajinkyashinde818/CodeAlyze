import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String x[] = new String[2];
    int i = 0;
    while(i < 2){
      x[i] = sc.next();
      i++;
    }
    int num[] = new int[2];
    for(i = 0;i<2;i++){
      if(x[i].equals("A")){
        num[i] = 10;
      }else if(x[i].equals("B")){
        num[i] = 11;
      }else if(x[i].equals("C")){
        num[i] = 12;
      }else if(x[i].equals("D")){
        num[i] = 13;
      }else if(x[i].equals("E")){
        num[i] = 14;
      }else if(x[i].equals("F")){
        num[i] = 15;
      }
    }
    if(num[0] < num[1]){
      System.out.println("<");
    }else if(num[0] == num[1]){
      System.out.println("=");
    }else{
      System.out.println(">");
    }

  }
}
