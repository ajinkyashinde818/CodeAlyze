import java.util.*;
public class Main {
    public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      String input = sc.nextLine();
      String[] inputs = input.split(" ");
      
      int n = Integer.parseInt(inputs[0]);
      int r = Integer.parseInt(inputs[1]);
      
      if(n >= 10){
        System.out.println(r);
      }else{
        int num = 100 * (10-n);
        System.out.println(r+num);
      }
    }
}
