import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		int n=0;
		for (String ss:s.split("")){
			if (ss.equals("a")){
				n+=1;
			}
			if (ss.equals("b")){
				n+=10;
			}
			if (ss.equals("c")){
				n+=100;
			}
		}
		if (n==111){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
	}
}
