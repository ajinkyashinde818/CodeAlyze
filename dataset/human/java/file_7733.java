import java.util.Map.Entry;
import java.util.*;
import java.math.*;
import org.w3c.dom.css.Counter;
  
public class Main{
    public static void main(String[] args){
 
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] a = new int[n];
 
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
 
        // 通った街を記録する配列
        ArrayList<Integer> list = new ArrayList<Integer>();
        HashSet<Integer> set = new HashSet<Integer>();
        list.add(1);    // 一つ目の町
        set.add(1);
        // ループの先頭の町がリストの何番目にあるかを格納する変数
        int check = -1;
 
        // 転送先を格納する変数。
        int temp = 1;   // 計算のため初期値１
 
        for (long i = 0; i < k; i++) {
            temp = a[temp-1];   //　転送先設定
            // 訪れた町かチェック
            // 訪れていた場合、ループ前のイントロ部分の長さを求める
            if (set.contains(temp)) {
                check = list.indexOf(temp);
            	break;
            }
            list.add(temp);
            set.add(temp);
        }

        if (check == -1) {
            System.out.println(temp);
            return;
        } 
        // 合計移動回数をループ長で割った余りを求める
        int std = (int)((k-check) % (list.size() - check));
 
        System.out.println(list.get(std + check));
    }
}
