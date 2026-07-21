import java.util.*;

public class Main {
	public Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		new Main();
	}
	public Main() {
		new aoj2508().doIt();
	}
	class aoj2508{
		char change(int num,char c){
			String alf = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
			char alf2[] = alf.toCharArray();
			for(int i = 0;i < 52;i++){
				if(alf2[i] == c){
					if(i - num < 0)c = alf2[i - num + 52];
					else c = alf2[i - num];
					break;
				}
			}
			return c;
		}
		void doIt(){
			while(true){
				int n = sc.nextInt();
				if(n == 0)break;
				int a[] = new int [n];
				for(int i = 0;i < n;i++){
					a[i] = sc.nextInt();
				}
				String str = sc.next();
				char ctr[] = str.toCharArray();
				for(int i = 0;i < ctr.length;i++){
					System.out.print(change(a[i % n],ctr[i]));
				}
				System.out.println();
			}
		}
	}
}
