import java.util.*;

class Main{
  public static void main(String args[]){
    
    Scanner scan = new Scanner(System.in);
    String judgeStr = scan.next().contains("9") ? "Yes" : "No" ;
	System.out.println(judgeStr);
	return;
  }
}
