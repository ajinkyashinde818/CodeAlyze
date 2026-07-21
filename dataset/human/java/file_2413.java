import java.util.Scanner;

public class Main{
	public static void main(String[] args)
	{
		Scanner sc =new Scanner(System.in);
		String s=sc.next(); //入力された文字列
		
		//文字列sから語尾以外の部分を文字列strに入力
		String str=s.substring(0,s.length()-8);
		System.out.println(str);
	}
}
