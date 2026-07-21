import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner scanner = new Scanner(System.in);
        String X = scanner.next();
        String Y = scanner.next();
        int x = X.codePointAt(0);
        int y = Y.codePointAt(0);
        System.out.println(hikaku(x,y));
    }
    public static String hikaku(int x, int y){
        if(x < y){
            return("<");
        }
        if(x > y){
            return(">");
        }
        if(x == y){
            return("=");
        }
        return("error");
    }

}
