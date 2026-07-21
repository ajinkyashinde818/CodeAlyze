import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int count=0;
		long min=Long.MAX_VALUE;
		long sum=0;
		for(int i = 0; i<n; i++){
			long a = sc.nextLong();
			if(a<0){
				count++;
				a=-a;
				sum+=a;
			}else{
				sum+=a;
			}
			if(min>a){
				min=a;
			}
		}
		if(count%2==1){
			System.out.println(sum-2*min);
		}else{
			System.out.println(sum);
		}
	}
}
