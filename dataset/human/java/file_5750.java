import java.util.*;
public class Main{
	public static void main(String[] args){

		Scanner sr = new Scanner(System.in);
		String s = sr.next();
		int sum = 0;
		int a = 0;
		int b = 0;
		int c = 0;
		for(int i = 0; i < s.length(); i++){
			String ch = s.substring(i, i + 1);
			if(ch.indexOf("a") != -1){
				a++;
			}else if(ch.indexOf("b") != -1){
				b++;
			}else if(ch.indexOf("c") != -1){
				c++;
			}
		}
		if(a < 2 && b < 2 && c < 2 && (a + b + c) == 3){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
	}
}
