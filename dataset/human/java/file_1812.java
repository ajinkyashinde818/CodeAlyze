import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int D=sc.nextInt();
		int G=sc.nextInt();
		int[][] prbs=new int[D][2];
		int[] toki=new int[D];
		for(int i=0; i<D; i++) {
			prbs[i][0]=sc.nextInt();
			prbs[i][1]=sc.nextInt();
		}

		int brute=1;
		for(int i=0; i<D; i++) {
			brute*=2;
			toki[i]=0;
		}
		int tmp=0;
		int mondaisu=0;
		int min=Integer.MAX_VALUE;
		for(int i=0; i<brute; i++) {
			tmp=0;
			mondaisu=0;
			int a=i;
			for(int j=0; j<D; j++) {
				tmp+=(a%2)*((j+1)*100*prbs[j][0]+prbs[j][1]);
				mondaisu+=prbs[j][0]*(a%2);
				toki[j]=a%2;
				a/=2;
			}
			if(tmp>=G) {
				min=Math.min(min,mondaisu );
			}
			else if(tmp<G){
				int sabun=G-tmp;
				for(int j=0; j<D; j++) {
					if(toki[j]==0) {
						int tuika=Math.min((sabun+(j+1)*100-1)/((j+1)*100), prbs[j][0]);
						if(sabun<=tuika*(j+1)*100) {
							min=Math.min(min, mondaisu+tuika);
						}
					}
				}
			}
		}
		System.out.println(min);
	}
}
