import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import static javax.swing.UIManager.put;

public class Main {

    static Scanner sc = new Scanner(System.in);
    static String x;
    static String y;
    static Map<String,Integer> map = new HashMap<String,Integer>(){
        {put("A", 10);}
        {put("B", 11);}
        {put("C", 12);}
        {put("D", 13);}
        {put("E", 14);}
        {put("F", 15);}
    };


    public static void main(String[] args) {
        read();
        solve();
    }

    public static void read() {
        x = sc.next();
        y = sc.next();
    }

    public static void solve() {
        if(map.get(x)>map.get(y)){
            System.out.println(">");
        } else if(map.get(x)<map.get(y)){
            System.out.println("<");
        }else {
            System.out.println("=");
        }
    }
}
