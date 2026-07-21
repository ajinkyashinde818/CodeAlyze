import javax.swing.text.StringContent;
import java.util.*;

public class Main {

    /* チェックリスト
     * 結果はintの範囲を超えていませんか？(必要な時以外はlongを使いましょう)
     * TLEしそうな処理はありませんか？
     */
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        String[] as = sc.nextLine().split(" ");
        String[] bs = sc.nextLine().split(" ");
        String[] cs = sc.nextLine().split(" ");
        List<Integer> al = new ArrayList<Integer>();
        List<Integer> bl = new ArrayList<Integer>();
        List<Integer> cl = new ArrayList<Integer>();
        for(String a : as){
            al.add(Integer.parseInt(a));
        }
        for(String b : bs){
            bl.add(Integer.parseInt(b));
        }
        for(String c : cs){
            cl.add(Integer.parseInt(c));
        }
        long r = 0;
        long prev = -2;
        long goodMood = 0;
        for(int i : al){
            long rep = bl.get(i-1);
            r += rep;
            if(prev + 1 == i){
                r += goodMood;
            }
            prev = i;
            if(i != al.size()){
                goodMood = cl.get(i-1);
            }else{
                goodMood = 0;
            }
        }
        System.out.println(r);
    }
}
