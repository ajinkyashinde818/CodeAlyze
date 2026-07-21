import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);

        boolean successFlag = true;
        String str = "";
        String str_tmp = "";
        String S = sc.next();
        sc.close();
        String[] divide = {"dream", "dreamer", "erase", "eraser"};
        
        // 試験対象の文字列を反転させ、前方一致判定の誤りを防ぐ
        StringBuffer sb = new StringBuffer(S);
		S = sb.reverse().toString();
		for (int i = 0; i < 4; i++) {
		    sb = new StringBuffer(divide[i]);
		    divide[i] = sb.reverse().toString();
		}
		//System.out.println(S);
        
        for (int i = 0; i < S.length();) {
            boolean loopFlag = false;

            for (int j = 0; j < 4; j++){
                
                // 一時変数に1文節代入
                str = divide[j];
                //System.out.println(str);
            
                // 分割できるか判定
                //System.out.println(i+" "+S.length());
                //System.out.println("分割前："+str);
                //System.out.println(S.substring(i, str.length()));
                //if (str.length() + i <= S.length()) {
                //    System.out.println("分割対象："+S.substring(i, str.length() + i));
                //}
                
                // 入力文字数を超えず、なおかつ分割可能な場合、分割開始位置iに文節の文字数を足す
                if (str.length() + i <= S.length()) {
                    if (S.substring(i, str.length() + i).equals(str)) {
                        //System.out.println("分割成功："+str.length());
                        loopFlag = true;
                        i += str.length();
                        break;
                    }
                }

            }
            // どの文節でも分割できない場合失敗
            if ( !loopFlag ) {
                successFlag = false;
                break;
            }
        }
        
        if (successFlag) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

    }
}
