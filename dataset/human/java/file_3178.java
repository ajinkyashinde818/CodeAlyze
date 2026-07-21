import java.util.*;
public class Main{
	public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = n%10;
      int l = (n-m)/10;
      if(m == 9||l == 9)System.out.println("Yes");
      else System.out.println("No");
    }
}
