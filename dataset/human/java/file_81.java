import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
int mi=0;
long min=1999999999;
long sum=0;
		int a[]=new int[n+1];
		for(int i=1;i<=n;i++){
			a[i]=sc.nextInt();
		if(a[i]<0){
			mi++;
		}
		if(min>Math.abs(a[i])){
			min=Math.abs(a[i]);
		}
		sum=sum+Math.abs(a[i]);
		}


if(mi%2==0){
System.out.println(sum);
}else{
	System.out.println((sum-min-min));
}

	}
}
