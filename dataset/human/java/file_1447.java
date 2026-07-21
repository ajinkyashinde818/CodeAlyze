import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
    
		// 整数の入力
		int n = sc.nextInt();
		int m = sc.nextInt();
        String[] aList = new String[n];
        String[] bList = new String[m];
      
        for (int i = 0; i < n; i++) {
          aList[i] = sc.next();
        }
        for (int i = 0; i < m; i++) {
          bList[i] = sc.next();
        }
        String ans = "No";
        hLoop: for (int h = 0; h < (n - m + 1); h++) {
          wLoop: for (int w = 0; w < (n - m + 1); w++){
             if (!aList[h].substring(w, w + m).equals(bList[0])) {
               continue wLoop;
             }
             int candidate = h;
             for (int index = 0; index < m; index++) {
               if (!aList[candidate].substring(w, w + m).equals(bList[index])) {
                 continue wLoop;
               }
               candidate++;
               if (index == m - 1) {
                 ans = "Yes";
                 break hLoop;
               }
             }
          }
        }
    
		// 出力
		System.out.println(ans);
	}
}
