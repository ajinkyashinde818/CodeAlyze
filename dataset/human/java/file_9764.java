import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Main m = new Main(sc);
        m.show(m.solve());
        sc.close();
    }
    
	//フィールド
    Scanner sc;
    int N;	//参考書の数
    int M;	//学びたいアルゴリズムの数
    int X;	//目標理解度
    int[] C;	//参考書の値段
    int[][] A;	//参考書によって上がる理解度の値
    
    //入力
    Main(Scanner sc) {
        this.sc = sc;
        this.N = sc.nextInt();
        this.M = sc.nextInt();
        this.X = sc.nextInt();
        C = new int[N];
        A = new int[N][M];
        for (int i=0; i<N; i++) {
        	C[i] = sc.nextInt();
        	for (int j=0; j<M; j++) {
        		A[i][j] = sc.nextInt();
        	}
        }
    }
    
    //解答処理
    private int solve() {   
        List<Integer> list = new ArrayList<>();
        int cost = -1;
        
        //bit全探索
        for (int i = 0; i < 1<<N; i++) {      	
        	int tmpC = 0;	//金額保持
        	int[] tmpA = new int[M];	//理解度保持
        	boolean judge = true;
        	for (int j = 0; j < N; j++) {
        		if ((1 & i >> j) == 1) { //購入
        			for (int k = 0; k < M; k++) {
        				tmpA[k] += A[j][k];
        			}
        			tmpC += C[j];	//金額の加算
        		}
        	}
        	for (int j = 0; j < M; j++) {
        		if (tmpA[j] < X) {	//理解度が目標に達していなければfalse
        			judge = false;
        			break;
        		}
        	}
        	if (judge) {	//目標に達していればリストに格納
        		list.add(tmpC);
        	}
        }
        
        if (!list.isEmpty()) {
        	Collections.sort(list);
        	cost = list.get(0);
        }
        return cost;
    }
    
    //出力
    public void show(int answer) {
        System.out.println(answer);
    }

}
