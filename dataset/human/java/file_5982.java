import java.util.*;

public class Main{
	public static void main(String args[]){
	
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		String m = S.substring(0,1);
		String n = S.substring(1,2);
		String l = S.substring(2,3);
	
		if(!m.equals(n) && !m.equals(l) && !l.equals(n)){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}	
	}
}
