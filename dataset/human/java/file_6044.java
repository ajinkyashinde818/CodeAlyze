import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		long[] a=new long[n];
		long[] b=new long[n];
		for(int i=0; i<n; i++){
			a[i]=sc.nextLong();
		}
		for(int i=0; i<n; i++){
			b[i]=sc.nextLong();
		}
		long[] fig=new long[29];
		long ans=0;
		for(int i=0; i<30; i++){
			long t=1<<i;
			long count=0;
			long[] aa=new long[n];
			long[] bb=new long[n];
			for(int j=0; j<n; j++){
				aa[j]=a[j]%(2*t);
				bb[j]=b[j]%(2*t);
			}
			Arrays.sort(bb);
			for(int k=0; k<n; k++){
				count+=lowerBounds(bb,2*t-aa[k])-lowerBounds(bb,t-aa[k]);
				count+=n-lowerBounds(bb,3*t-aa[k]);
			}
			ans|=(count & 1)<<i;
		}
		System.out.println(ans);
	}
	public static int lowerBounds(long[] arr,long value){
	int low=0;
	int high=arr.length;
	int mid;
	while(high>low){
		mid=((high - low) >>> 1) + low;    
		if(arr[mid]<value){
			low=mid+1;
		}else{
			high=mid;
		}
	}
	return low;
}
}
