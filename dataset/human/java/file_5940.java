import java.util.*;
public class Main{
  public static void main(String[]args){
      Scanner sc = new Scanner(System.in);

      String s = sc.nextLine();
      char[] c =new char[3];
      
        for(int i = 0;i<3;i++){
          c[i] = s.charAt(i);
        }

        if(c[0]==c[1]||c[1]==c[2]||c[2]==c[0]){
          System.out.println("No");
        }else{
          System.out.println("Yes");
        }

  }
}
