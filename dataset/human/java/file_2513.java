import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		solve();
	}

	private static void solve() {
		Scanner scn = new Scanner(System.in);
		PrintWriter pr = new PrintWriter(System.out);
		int N = scn.nextInt();
		while(N-->0){
			int sum=0;
			for(int s=0;s<2;s++){
				String a = scn.next();
				int c=1;
				for(int i=0;i<a.length();i++){
					if(a.charAt(i)=='m'){
						sum+=c*1000;
						c=1;
					}else if(a.charAt(i)=='c'){
						sum+=c*100;
						c=1;
					}else if(a.charAt(i)=='x'){
						sum+=c*10;
						c=1;
					}else if(a.charAt(i)=='i'){
						sum+=c;
						c=1;
					}else{
						c=a.charAt(i)-'0';
					}
				}
			}
			if(sum/1000>0){
				if(sum/1000==1){
					pr.print("m");
				}else{
					pr.print(sum/1000+"m");
				}
				sum%=1000;
			}
			if(sum/100>0){
				if(sum/100==1){
					pr.print("c");
				}else{
					pr.print(sum/100+"c");
				}
				sum%=100;
			}
			if(sum/10>0){
				if(sum/10==1){
					pr.print("x");
				}else{
					pr.print(sum/10+"x");
				}
				sum%=10;
			}
			if(sum>0){
				if(sum==1){
					pr.print("i");
				}else{
					pr.print(sum+"i");
				}
			}
			pr.println();
		}
		pr.flush();
		scn.close();
	}

}
