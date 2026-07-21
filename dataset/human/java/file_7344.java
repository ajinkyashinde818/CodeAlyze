import java.util.*;

public class Main {
	public static void main(String[] args)  {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		String ans ;
		String A = S.replace("eraser","");
		String B = A.replace("erase","");
		String C = B.replace("dreamer","");
		String D = C.replace("dream","");
		if(D.length() == 0){
			ans = "YES";
		}else{
			ans = "NO";
		}
			System.out.println(ans);
	}
}
