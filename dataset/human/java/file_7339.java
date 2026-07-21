import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    String s = scan.next();
    while (s.length() > 0){
      int c = s.length();
      if (c >= 7){
        String check2 = s.substring(0,7);
        if (check2.equals("dreamer")){
          if (s.length() == 7){
            System.out.println("YES");
            return;
          }
          else{
            int g = s.length();
            s = s.substring(7,g);
            if (s.length() >= 3){
              String cc = s.substring(0,3);
              if (cc.equals("ase")){
                s = "er" + s;
              }
            }
          }
          continue;
        }
      }

      if (c >= 6){
        String check1 = s.substring(0,6);
        if (check1.equals("eraser")){
          if (s.length() == 6){
            System.out.println("YES");
            return;
          }
          else{
            int g = s.length();
            s = s.substring(6,g);
          }
          continue;
        }
      }

      if (c >= 5){
        String check3 = s.substring(0,5);
        if ((check3.equals("erase")) || (check3.equals("dream"))){
          if (s.length() == 5){
            System.out.println("YES");
            return;
          }
          else{
            int g = s.length();
            s = s.substring(5,g);
          }
          continue;
        }
      }

      System.out.println("NO");
      return;
    }


  }

}
