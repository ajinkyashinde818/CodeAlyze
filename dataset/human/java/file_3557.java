import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int[][] map;
    static int[][] label;


    static ArrayList<String> list;

    static int M;
    static int N;
    static int T;
    static int P;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String a = scanner.next();
        String b = scanner.next();

        if(a.charAt(0) == b.charAt(0)){
            System.out.println("=");
        }else if(a.charAt(0) < b.charAt(0)){
            System.out.println("<");
        }else{
            System.out.println(">");
        }

    }



}
