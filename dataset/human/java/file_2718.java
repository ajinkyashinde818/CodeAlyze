import java.util.Scanner;

class Main{
	static Scanner s=new Scanner(System.in);
	static int gInt(){return Integer.parseInt(s.next());}

	public static void main(String[]$){
		String a=get(),b=get();
		b=reverse(b);
		System.out.println(a.compareTo(b)<0?"Yes":"No");
	}
	private static String reverse(String b){
		StringBuilder sb=new StringBuilder();
		for(int i=b.length()-1;i>=0;--i)
			sb.append(b.charAt(i));
		return sb.toString();
	}

	static String get(){
		StringBuilder sb=new StringBuilder();
		s.next().chars().sorted().forEach(i->sb.append((char)i));
		return sb.toString();
	}
}
