import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		boolean ch=false;
		int i=1;
		for(; (i*(i+1))<=n*2; i++){
			if((i*(i+1))==n*2){
				ch=true;
				break;
			}
		}
		int[][] tmp=new int[i][i];
		int count=1;
		for(int j=0; j<i; j++){
			for(int k=0; k<i; k++){
				if(j>=k){
					tmp[j][k]=count++;
				}
			}
		}
		int[][] ans=new int[i+1][i];
		int cc=0;
		int bb=0;
		boolean tk=false;
		for(int j=0; j<i; j++){
			cc=j;
			bb=0;
			tk=false;
			for(int k=0; k<i; k++){
				if(cc==bb || tk){
					ans[j][k]=tmp[cc][bb];
					tk=true;
					cc++;
				}else{
					ans[j][k]=tmp[cc][bb++];
				}
			}
		}
		for(int j=0; j<i; j++){
			ans[i][j]=tmp[j][j];
		}
		if(ch){
			System.out.println("Yes");
			System.out.println(i+1);
			for(int j=0; j<i+1; j++){
				System.out.print(i+" ");
				for(int k=0; k<i; k++){
					System.out.print(ans[j][k]+" ");
				}
				System.out.println();
			}
		}else{
			System.out.println("No");
		}
	}
}
