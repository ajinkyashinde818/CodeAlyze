import java.util.*;
import java.util.regex.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // 入力
        String s = sc.next();
        // 文字列反転処理
        StringBuffer sb = new StringBuffer(s);
        String reversedStr = sb.reverse().toString();
        
        // 文字列反転リスト
        List<String> list = Arrays.asList("dream", "dreamer", "erase", "eraser");
        List<String> reversedList = new ArrayList<>();
        for (String str : list) {
            sb.setLength(0);
            sb.append(str);
            reversedList.add(sb.reverse().toString());
        }

        // 正規表現
        String ptnStr = "^(" + String.join("|", reversedList) + ")+$";
        Pattern pattern = Pattern.compile(ptnStr);
        Matcher matcher = pattern.matcher(reversedStr);

        if (matcher.matches()) {
            // 出力
            System.out.println("YES");
        } else {
            // 出力
            System.out.println("NO");
        }
    }
}
