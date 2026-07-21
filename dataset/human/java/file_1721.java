import java.util.Scanner;
public class Main{
	public static void main(String[]args){
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	String b=scan.next();
	long ans=1;
	long alpha[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	for(int i=0;i<b.length();i++) {
		char ch=b.charAt(i);
		alpha[ch-'a']++;
	}
	for(int i=0;i<26;i++) {
		ans*=alpha[i];
		ans%=1000000007;
	}
	System.out.println(ans-1);
	scan.close();
	}
}
