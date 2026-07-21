import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		String gomi=sc.nextLine();
		for(int j=0;j<n;++j){
			String a=sc.next();
			String b=sc.next();
			String[] a2=a.split("");
			String[] b2=b.split("");
			int sum_a=0,sum_b=0;
			for(int i=0;i<a2.length;++i){
				int num=1;
				if(a2[i].matches("[2-9]")){ num=Integer.parseInt(a2[i]); i++; }
				if(a2[i].equals("m")) num*=1000;
				else if(a2[i].equals("c")) num*=100;
				else if(a2[i].equals("x")) num*=10;
				else if(a2[i].equals("i")) num*=1;
				sum_a+=num;
			}
			for(int i=0;i<b2.length;++i){
				int num=1;
				if(b2[i].matches("[2-9]")){	num=Integer.parseInt(b2[i]); i++; }
				if(b2[i].equals("m")) num*=1000;
				else if(b2[i].equals("c")) num*=100;
				else if(b2[i].equals("x")) num*=10;
				else if(b2[i].equals("i")) num*=1;
				sum_b+=num;
			}
			int ans=sum_a+sum_b;
			if(ans/1000>0){
				if(ans/1000!=1) System.out.print(ans/1000+"m");
				else System.out.print("m");
				ans-=ans/1000*1000;
			}
			if(ans/100>0){
				if(ans/100!=1) System.out.print(ans/100+"c");
				else System.out.print("c");
				ans-=ans/100*100;
			}
			if(ans/10>0){
				if(ans/10!=1) System.out.print(ans/10+"x");
				else System.out.print("x");
				ans-=ans/10*10;
			}
			if(ans/1>0){
				if(ans/1!=1) System.out.println(ans+"i");
				else System.out.println("i");
			} else {
				System.out.println();
			}
		}
	}
}
