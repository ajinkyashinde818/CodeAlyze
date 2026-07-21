import java.util.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // 整数の入力
        String text = sc.next();
        // スペース区切りの整数の入力
      
      	String a="a";
      	String b="b";
      	String c="c";
  
      if(text.matches(".*" + a + ".*")){
       	if(text.matches(".*" + b + ".*")){
      			 if(text.matches(".*" + c + ".*")){
      				System.out.println("Yes");
      			}else{
    			  System.out.println("No");
    			  }
     	 }else{
     	 System.out.println("No");
     	 }
      }else{
      System.out.println("No");
      }
 
    }
}
