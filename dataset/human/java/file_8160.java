import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc=new Scanner(System.in);
		
		long a=sc.nextLong();
		long b=sc.nextLong();
		long c= 0;
		
		int i=1;		//最小公倍数を求める
		while(i<=b){
			if((long)a*i%b==0) {
				c=(long)a*i;
				break;
			}
			else{
				i++;
			}
		}
 		 System.out.println(c);
		 sc.close();
	}
}
