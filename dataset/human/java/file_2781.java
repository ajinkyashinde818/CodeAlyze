import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//int h=sc.nextInt();
		//int w=sc.nextInt();
		//int[][] res=new int[h][w];
		//long n=sc.nextLong(),y=sc.nextLong();
		char buffs='z',bufft='a';
		String ress="",rest="";
		int count=0;
		String s= sc.next();
		String t=sc.next();
		StringBuilder s1=new StringBuilder(s);
		StringBuilder t1=new StringBuilder(t);

		for(int i=0;i<s.length();i++) {
			for(int j=0;j<s1.length();j++) {
				if(s1.charAt(j)<=buffs) {
					buffs=s1.charAt(j);
					count=j;
				}
			}
			ress+=buffs;
			s1.deleteCharAt(count);
			buffs='z';
		}
		for(int i=0;i<t.length();i++) {
			for(int k=0;k<t1.length();k++) {
				if(t1.charAt(k)>=bufft) {
					bufft=t1.charAt(k);
					count=k;
				}
			}
			rest+=bufft;
			t1.deleteCharAt(count);
			bufft='a';
		}

		if(ress.compareToIgnoreCase(rest)<0) {
			System.out.println("Yes");
		}else if(ress.compareToIgnoreCase(rest)>0){
			System.out.println("No");
		}else {
			if(ress.length()<rest.length()) {
				System.out.println("Yes");
			}else {
				System.out.println("No");
			}
		}

	}

}
