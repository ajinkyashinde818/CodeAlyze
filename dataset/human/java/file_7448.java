import java.util.*;
class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		s=s.replaceAll("eraser","").replaceAll("erase","").replaceAll("dreamer","").replaceAll("dream","");
		System.out.println(s.length()==0?"YES":"NO");
	}
}
