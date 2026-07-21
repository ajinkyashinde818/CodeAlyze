import java.util.Scanner;

class Main{
	public static void main(String[]$){
		Scanner s=new Scanner(System.in);
		StringBuilder str=new StringBuilder(s.next()
				.replaceAll("eraser","")
				.replaceAll("dream","D")
				.replaceAll("er","R")
				.replaceAll("as","A"));
		String[] m={"RAe","DR","D"};
		loop:
		while(true){
			for(String b:m){
				if(str.toString().endsWith(b)){
					str.delete(str.length()-b.length(),str.length());
					continue loop;
				}
			}
			break;
		}
		System.out.println(str.length()==0?"YES":"NO");
	}
}
