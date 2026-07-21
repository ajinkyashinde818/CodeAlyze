import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int q = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        StringBuilder sbF = new StringBuilder();
        sb.append(s);
        boolean start = true;
        for (int i = 0; i < q; i++) {
            int t = sc.nextInt();
            if (t == 1) {
                start = !start;
            } else {
                int f = sc.nextInt();
                String c = sc.next();
                if (start) {
                    if (f == 1) {
                        //sb.insert(0, c);
                        sbF.append(c);
                    } else {
                        sb.append(c);
                    }
                } else {
                    if (f == 1) {
                        sb.append(c);
                    } else {
                        sbF.append(c);
                    }                   
                }
            }
        }
        String result;
        if (!start) {
            result = sb.reverse().append(sbF).toString();
        } else {
            result = sbF.reverse().append(sb).toString();
        }
        System.out.println(result);
        sc.close();
    }
}
