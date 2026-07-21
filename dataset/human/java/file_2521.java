import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int TC = Integer.parseInt(sc.next(), 10);
        
        while (TC-- > 0) {
            int a = getIntValue(sc.next());
            int b = getIntValue(sc.next());
            System.out.println(convertToMcxi(a + b));
        }
    }
    
    public static int getIntValue(String str) {
        int ret = 0;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (Character.isDigit(c)) {
                i++;
                char d = c;
                c = str.charAt(i);
                int val = Integer.parseInt(d+"", 10);
                switch (c) {
                    case 'm': val *= 1000; break;
                    case 'c': val *= 100; break;
                    case 'x': val *= 10; break;
                    default: break;
                }
                ret += val;
            } else {
                switch (c) {
                    case 'm': ret += 1000; break;
                    case 'c': ret += 100; break;
                    case 'x': ret += 10; break;
                    case 'i': ret += 1; break;
                    default: break;
                }
            }
        }
        // System.out.println(str + " " + ret);
        return ret;
    }
    
    public static String convertToMcxi(int num) {
        String ret = "";
        int m = num / 1000;
        num = num % 1000;
        int c = num / 100;
        num = num % 100;
        int x = num / 10;
        num = num % 10;
        
        switch (m) {
            case 0: break;
            case 1: ret += "m"; break;
            default: ret += m + "m"; break;
        }
        switch (c) {
            case 0: break;
            case 1: ret += "c"; break;
            default: ret += c + "c"; break;
        }
        switch (x) {
            case 0: break;
            case 1: ret += "x"; break;
            default: ret += x + "x"; break;
        }
        switch (num) {
            case 0: break;
            case 1: ret += "i"; break;
            default: ret += num + "i"; break;
        }
        return ret;
    }
}
