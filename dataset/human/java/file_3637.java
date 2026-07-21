import java.util.Scanner;

public class Main {

    public static int value(char l){
        switch (l){
            case 'A': l = 10;
            break;
            case 'B': l = 11;
            break;
            case 'C': l = 12;
            break;
            case 'D': l = 13;
            break;
            case 'E': l = 14;
            break;
            case 'F': l = 15;
            break;
        }
        return l;
    }

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        char a = in.next().charAt(0);
        char b = in.next().charAt(0);
        int x = value(a);
        int y = value(b);
        if (x == y){
            System.out.println('=');
        }
        else if (x < y){
            System.out.println('<');
        }
        else{
            System.out.println('>');
        }

    }
}
