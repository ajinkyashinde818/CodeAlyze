import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),k=sc.nextInt(),s=sc.nextInt();
		sc.close();
		for(int i=0;i<k;i++) System.out.print(s+" ");
		if(s<1000000000) for(int i=k;i<n;i++) System.out.print((s+1)+" ");
		else for(int i=k;i<n;i++) System.out.print(1+" ");
	}
}
