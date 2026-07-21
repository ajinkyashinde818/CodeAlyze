import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] params = sc.nextLine().split(" " );
        int n = Integer.parseInt( params[0] );
        int r = Integer.parseInt( params[1] );
        int into;
        if( n >= 10 ){
            into = r;
        }
        else {
            into = r + 100 * (10-n);
        }
        System.out.println( into );

    }

}
