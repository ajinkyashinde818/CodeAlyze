import java.util.Arrays;
import java.util.Collections;
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
    String s;
    String t;
    
    //入力
    Main(Scanner sc) {
        this.sc = sc;
        this.s = sc.next();
        this.t = sc.next();
    }
    
    //解答処理
    private String solve() {
        String answer = "No";
        String[] listS = s.split("");
        String[] listT = t.split("");
        Arrays.sort(listS);
        Arrays.sort(listT,Collections.reverseOrder());
        StringBuilder S = new StringBuilder();
        StringBuilder T = new StringBuilder();
        
        for (int i=0; i<listS.length; i++) {
        	S.append(listS[i]);
        }
        for (int i=0; i<listT.length; i++) {
        	T.append(listT[i]);
        }
        
        String s2 = S.toString();
        String t2 = T.toString();
        if(s2.compareTo(t2) < 0) {
        	answer = "Yes";
        }
        return answer;
    }
    
    //出力
    public void show(String answer) {
        System.out.println(answer);
    }

}
