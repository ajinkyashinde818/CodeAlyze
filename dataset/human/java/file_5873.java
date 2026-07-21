import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
Scanner scan=new Scanner(System.in);
String a=scan.next();
int ans=0;
if(a.charAt(0)=='a'||a.charAt(1)=='a'||a.charAt(2)=='a') {
	ans++;
}if(a.charAt(0)=='b'||a.charAt(1)=='b'||a.charAt(2)=='b') {
	ans++;
}if(a.charAt(0)=='c'||a.charAt(1)=='c'||a.charAt(2)=='c') {
	ans++;
}
if(ans==3) {
	System.out.println("Yes");
}
else {
	System.out.println("No");
}
	}
	}
