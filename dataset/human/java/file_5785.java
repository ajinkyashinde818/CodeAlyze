import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc =new Scanner(System.in);
		String s=sc.next();
		int a_exi=0;
		int b_exi=0;
		int c_exi=0;
		String ans;

		if(s.contains("a")) a_exi++;
		if(s.contains("b")) b_exi++;
		if(s.contains("c")) c_exi++;

		if(a_exi==1 && b_exi==1 && c_exi==1) ans="Yes";
		else ans="No";

		System.out.println(ans);

	}
}
