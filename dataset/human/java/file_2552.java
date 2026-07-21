import java.util.*;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        //ソートするため配列に
        String[] S = s.split("");
        String[] T = t.split("");
        //ソート
        Arrays.sort(S);
        Arrays.sort(T, Comparator.reverseOrder());
        //compareToするために配列を変数に戻す
        String a = "";
        String b = "";
        for(int i = 0; i < S.length; i++) a += S[i];
        for(int i = 0; i < T.length; i++) b += T[i];
        //S<T -> S-T==-1
        int flag = a.compareTo(b);

        if(flag < 0) System.out.println("Yes");
        else System.out.println("No");
    }
}
