import java.util.*;

public class Main{
   public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
  		String t = scanner.nextLine();
  		String t1 = t.replaceAll("eraser", "");
        String t2 = t1.replaceAll("erase", "");
        String t3 = t2.replaceAll("dreamer", "");
        String t4 = t3.replaceAll("dream", "");
     boolean flag = false;	
      if(t4.isEmpty()){
      System.out.println("YES");
      }else{
      System.out.println("NO");
        }
      }
   }
