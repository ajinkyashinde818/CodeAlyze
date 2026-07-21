import java.util.*;

public class Main{
	
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
  	char[] ch=sc.next().toCharArray();
    if(ch[0]=='9'||ch[1]=='9'){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}
