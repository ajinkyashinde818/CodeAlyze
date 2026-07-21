import java.util.*;
public class Main {
	public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	int money_min = 100000000;//金額の最小値をここに求める
    	int ans = -1;//
    	int all_XormorethanX = 1;

    	//N,M,Xの読み込み処理を行う
		int N = sc.nextInt();
		int M = sc.nextInt();
		int X = sc.nextInt();
		int C[] = new int[N+1];
		int A[][] = new int[N+1][M+1];
		int skill_sum[] = new int[M+1];
		int money_sum = 0;

		//CとAの読み込み処理
		for(int i=1;i<=N;i++){
			C[i]=sc.nextInt();
			for(int j=1;j<=M;j++){
				A[i][j]=sc.nextInt();
			}
		}

		//bit全探索処理、探索すると同時に条件を満たすものについては最小値を更新する
		for (int i=0; i<(1<<N); i++) {//ex. 1<<3=1000		
			//条件を満たすかどうかの判定処理
			//1.判断材料を整える処理
			//初期化処理
		    for(int k=1;k<=M;k++){
		        skill_sum[k] = 0;		
		    }

		    for (int j = 0; j < N; j++) {
		        if ((1 & (i >> j)) == 1){//bitからj(0~)桁目を抽出する
		        	for(int k=1;k<=M;k++){
		        		skill_sum[k] = skill_sum[k] + A[j+1][k];

		        	}
		    	}
			}

		    //2.整えた判断材料に対する判断処理
		    all_XormorethanX = 1;//初期化    	
		    for(int l=1;l<=M;l++){
		    	if (skill_sum[l]<X){
		    		all_XormorethanX = -1;
		    		break;
		    	}
		    }
		    //条件を満たす場合は金額の最小値を更新しておく
		    //金額の合計を求める
		    if (all_XormorethanX==1) {
		    	money_sum = 0;
		    	for (int j = 0; j < N; j++) {
		        	if ((1 & (i >> j)) == 1) {//bitからj(0~)桁目を抽出する
		        		money_sum = money_sum + C[j+1];
		        	}
		    	}
		    //金額の合計を最小値に更新する
		    money_min = Math.min(money_sum,money_min);
		    }
		}
		if (money_min==100000000) {
			System.out.println(ans);
		}
		else{
			ans=money_min;
			System.out.println(ans);
		}

	}
}
