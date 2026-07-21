import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		long a = Integer.parseInt(sc.next());
		long b= Integer.parseInt(sc.next());
		long r=0,x,tmp;
		x=a*b;
		if(a<b) {
			tmp=a;
			a=b;
			b=tmp;
		}
		r=a%b;
		while(r!=0) {
			a=b;
			b=r;
			r=a%b;
		}
		
		System.out.println(x/b);
	}
}
