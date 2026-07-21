import java.util.*;


// 英小文字からなる文字列 S が与えられます。
// T が空文字列である状態から始めて、以下の操作を好きな回数繰り返すことで S=T とすることができるか判定してください。

// T の末尾に "dream", "dreamer", "erase", "eraser" のいずれかを追加する。

public class Main{
    public static void main (String[]args){
        
        Scanner sc = new Scanner(System.in);
        
        // 標準入力
        String S = sc.nextLine();
 
        sc.close();
        
        // 入力文字列をreplaceで分割する→使わない文字列に置き換えてすべて削除
        S = S.replaceAll("eraser", "-");
        S = S.replaceAll("erase", "-");
        S = S.replaceAll("dreamer", "-");
        S = S.replaceAll("dream", "-");
        S = S.replaceAll("-", "");

        if (S.length() == 0){
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }


    }
}
