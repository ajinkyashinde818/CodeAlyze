import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args){
	  Scanner sc = new Scanner(System.in);
      String str = sc.nextLine();
      str = str.replaceAll("eraser", " ");
      str = str.replaceAll("erase", " ");
      str = str.replaceAll("dreamer", " ");
      str = str.replaceAll("dream", " ");
      int strNum = str.split(" ").length;
      if(strNum>0){
        System.out.println("NO");
      } else {
        System.out.println("YES");
      } 
	}
}
