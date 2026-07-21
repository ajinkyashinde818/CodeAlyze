import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        //文字列を取得
        Scanner scanner = new Scanner(System.in);
        String s1 = scanner.next();
        String s2 = scanner.next();

        //文字列の0番目の文字を取得
        char c1 = s1.charAt(0);
        char c2 = s2.charAt(0);

        if(c1 > c2){
            System.out.println(">");
        }else if(c1 < c2){
            System.out.println("<");
        }else{
            System.out.println("=");
        }
    }
}
