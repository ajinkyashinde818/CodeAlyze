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
    int N;
    int M;
    String[] A;
    String[] B;
    
    //入力
    Main(Scanner sc) {
        this.sc = sc;
        this.N = sc.nextInt();
        this.M = sc.nextInt();
        A = new String[N];
        B = new String[M];
        for (int i=0; i<N; i++) {
        	A[i] = sc.next();
        }
        for (int i=0; i<M; i++) {
        	B[i] = sc.next();
        }
    }
    
    //解答処理
    private String solve() {
        String answer = "No";
        boolean judge = false;
        
        for (int i=0; i<N-M+1; i++) {
        	for (int j=0; j<N-M+1; j++) {
              int count = 0;
        		for (int k=0; k<M; k++) {
        			String tmp = A[k+i].substring(j, j+M);
        			if (B[k].equals(tmp)) {
        				count++;
        			} else {
        				break;
        			}
        		}
        		if (count == M) {
        			judge = true;
        			break;
        		}
        	}
        }
        
        if (judge) {
        	answer = "Yes";
        }
        
        return answer;
    }
    
    //出力
    public void show(String answer) {
        System.out.println(answer);
    }

}
