import java.util.*;
public class Main {
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

		// 整数の入力
        int a = sc.nextInt();
        int b = sc.nextInt();
        int big = Math.max(a, b);
        int aa = a;
        int bb = b;
        
        int i = 2;
        boolean divided = true;
        ArrayList<Integer> list = new ArrayList<>();
        list.add(1);
        while (divided) {
            i = 2;
            while (i <= big) {
                if (aa % i == 0 && bb % i == 0) {
                    aa = aa / i;
                    bb = bb / i;
                    list.add(i);
                    break;
                }
                i++;
            }
            if (i > big)
                divided = false;
        }
        long ans = 1;
        for (int ele : list) {
            ans *= ele;
        }
        ans = ans * aa * bb;

        System.out.println(ans);
	}
}
