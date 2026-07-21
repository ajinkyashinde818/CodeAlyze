import java.util.Scanner;

class Main {
	public static void main(String[] $) {
		Scanner sc = new Scanner(System.in);
		int d=sc.nextInt(),g=sc.nextInt();
		int[] p=new int[d];
		int[] c=new int[d];
		double min=Long.MAX_VALUE;

		for(int i=0;i<d;i++) {
			p[i]=sc.nextInt();
			c[i]=sc.nextInt();
		}
		for(int i=0;i<Math.pow(2, d);i++) {
			int[] status = new int[d];
			double sum=0,count=0;
			int max=0;
			for(int j=0;j<d;j++) {//iを2進数にした場合にどこの桁が1になっているか判定し、1の場合はstatusに代入
				if((1&i>>j)==1) {
					status[j]=1;
				}
			}
			for(int j=0;j<d;j++) {
				if(status[j]==1) {
					sum+=p[j]*(j+1)*100+c[j];
					count+=p[j];
				}else {
					max=j+1;
				}
			}
			if(sum<g) {
				count+=Math.ceil((g-sum)/(max*100));
				sum+=max*100*p[max-1];
			}
			if(sum>=g)min=Math.min(count, min);
			//System.out.println(sum+" "+count+" "+max+" "+min);
		}
		System.out.println((long)min);
	}
}
