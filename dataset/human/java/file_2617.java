import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		// 文字列の入力
		String[] s = sc.next().split("");
        Arrays.sort(s, Comparator.naturalOrder());
        String sortedS;
        String sortedT;
        StringBuilder builder = new StringBuilder();
        for(String value : s) {
          builder.append(value);
        }
        sortedS = builder.toString();
        builder.setLength(0);
        String[] t = sc.next().split("");
        Arrays.sort(t, Comparator.reverseOrder());
        for(String value : t) {
          builder.append(value);
        }
        sortedT = builder.toString();

        String[] list = {sortedS, sortedT};
        Arrays.sort(list, Comparator.naturalOrder());
    
		// 出力
		System.out.println(!sortedS.equals(sortedT) && list[0].equals(sortedS) ? "Yes" : "No");
	}
}
