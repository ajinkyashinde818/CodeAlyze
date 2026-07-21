import java.util.Scanner;
 
public class Main {
	public static int pow(int a, int b){
		int x=1;
		while(b>0){
			if((b&1)==1) x=(x*a);
			a=(a*a);
			b>>=1;
		}
		return x;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int D=sc.nextInt();
		int G=sc.nextInt();
		
		int[] p=new int[D+1];
		int[] c=new int[D+1];
		int[] score=new int[D+1];
		
		for(int i=1;i<=D;i++){
			p[i]=sc.nextInt();
			c[i]=sc.nextInt();
			score[i]=100*i*p[i]+c[i];
		}
		
		int pattern=pow(2,D);
		int[] num=new int[pattern];
		int min= 10000;
		for(int i=0;i<pattern;i++){
			int g=G;
			int n=0;
			for(int j=1;j<=D;j++){
				if( ((i>>(j-1))&1)==1 ){
					num[i]+=p[j];
					g-=score[j];
				}
			}
			if(g>0){
				int take=D;
				while(((i>>(take-1))&1)==1) take--;
				if(g>100*take*(p[take]-1)){
					continue;
				}else{
					num[i]+= (g-1)/(100*take)+1;
				}
			}
			min=Math.min(min, num[i]);
		}
		System.out.println(min);
	}
}
