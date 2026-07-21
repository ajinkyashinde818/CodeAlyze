import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;
public class Main {

	public static void main(String[] args) {
		Scanner ob=new Scanner(System.in);
		int n=ob.nextInt();
		int a[]=new int[n];
		int b[]=new int[n];
		for(int i=0;i<n;i++)
		{
		int x=ob.nextInt();
		int y=ob.nextInt();
		a[i]=x;b[i]=y;
		}
		for(int i=0;i<=a.length-3;i++)
		{
		if(a[i]==b[i]&&a[i+1]==b[i+1]&&a[i+2]==b[i+2]){
			System.out.println("Yes");
			System.exit(0);
		}
		}
		System.out.println("No");
	}
}
