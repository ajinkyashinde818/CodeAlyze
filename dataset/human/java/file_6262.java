import java.util.*;
public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int K=sc.nextInt();
		int S=sc.nextInt();
		int count=0;
		for(int i=0;i<K+1;i++){
			for(int j=0;j<K+1;j++){
				int k=S-i-j;
				int sum=i+j+k;
				if(0<=k && k<=K)count++;
				
			}
		}
		System.out.println(count);
	}

}
