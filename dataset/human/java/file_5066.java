import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        boolean flag = false;
        int n = sc.nextInt();
        char[] a = new char[n];
        char[] b = new char[n];
        int bi = 0;
        int ai = 0;
        for (int i = 0; i < n; i++) {
            int q = sc.nextInt();
            if(q == 1){
                flag = !flag;
            }else if(q == 2){
                int t = sc.nextInt();
                char c = sc.next().charAt(0);
                if(t == 1 && flag || t== 2 && !flag){
                    b[bi] = c;
                    bi ++;
                }else {
                    a[ai] = c;
                    ai ++;
                }
            }
        }
        if(flag){
            for (int i = bi - 1; i >= 0; i--) {
                System.out.print(b[i]);
            }
            for (int i = s.length() - 1; i >= 0; i--) {
                System.out.print(s.charAt(i));
            }
            for (int i = 0; i < ai; i++) {
                System.out.print(a[i]);
            }
        }else{
            for (int i = ai - 1; i >= 0; i--) {
                System.out.print(a[i]);
            }
            System.out.print(s);
            for (int i = 0; i < bi; i++) {
                System.out.print(b[i]);
            }
        }
    }
}
