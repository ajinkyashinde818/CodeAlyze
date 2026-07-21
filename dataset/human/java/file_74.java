import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn=new Scanner(System.in);
		int n=scn.nextInt();
		int []arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=scn.nextInt();
		}
		int idx=0;
		long tot=0;
		int  min=Integer.MAX_VALUE;
		for(int i=0;i<n;i++) {
			if(arr[i]<0) {
				idx++;
				idx%=2;
			}
			tot+=Math.abs(arr[i]);
			if(min>Math.abs(arr[i])) {
				min=Math.abs(arr[i]);
			}
			//System.out.println(tot);
		}
		//System.out.println(idx+" "+min+" "+tot);
		if(idx%2!=0)
		System.out.println(tot-2*min);
		else {
			System.out.println(tot);
		}
	}

}
