import java.util.Scanner;
public class Main {
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		//int a = sc.nextInt();
		// スペース区切りの整数の入力
		//int b = sc.nextInt();
		//int c = sc.nextInt();
		// 文字列の入力
		//String s = sc.next();
		//1文字ずつ
		//s.atChar(i);
		// 出力
		//System.out.println("");
		
		String S=sc.next();
		//int pointer=0;
		//int leng=S.length();
		char x=S.charAt(0);
		char y=S.charAt(1);
		char z=S.charAt(2);
		boolean t=false;
		if(x=='a' && y=='b' && z=='c')t=true;
		if(x=='a' && y=='c' && z=='b')t=true;
		if(x=='b' && y=='a' && z=='c')t=true;
		if(x=='b' && y=='c' && z=='a')t=true;
		if(x=='c' && y=='a' && z=='b')t=true;
		if(x=='c' && y=='b' && z=='a')t=true;	
		if(t){
			System.out.println("Yes");	
		}else{
			System.out.println("No");	
		}
	}
}
