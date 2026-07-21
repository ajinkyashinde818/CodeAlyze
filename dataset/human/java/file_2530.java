import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
    
        Scanner sc = new Scanner(System.in);
        
        String s = sc.next();
        String t = sc.next();
        int N = s.length();
        int M = t.length();
        char[] S = s.toCharArray(); //String sをchar型で配列に格納
        char[] T = t.toCharArray(); //String tをchar型で配列に格納
        
        //辞書順に文字列を並び替え
        Arrays.sort(S);
        Arrays.sort(T);
        
        //文字列を生成。ただし、Sは昇順、Tは降順とする。
        String ss = "";
        String tt = "";
        for(int i = 0; i < N; i++) ss += S[i];
        for(int i = 0; i < M; i++) tt += T[(M - 1) -i];

        //生成した文字列をcompareTo()で比較
        System.out.println(ss.compareTo(tt) < 0 ? "Yes" : "No");
    }
}
