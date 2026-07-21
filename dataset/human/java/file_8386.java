import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
      // 整数の入力
		int a = sc.nextInt();
		int b = sc.nextInt();
      

      	int temp;
	long c = a;
	c *= b;
	while((temp = a%b)!=0) {
		a = b;
		b = temp;
	}
      
      
      	System.out.println(c/b);

      
      	
	}
}
