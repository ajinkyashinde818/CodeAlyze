import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String N = sc.next();
        String ans="No";
        for(int i=0;N.length()>i;i++){
            char tmp =N.charAt(i);
            if('9'==tmp){
                ans="Yes";
                break;
            }
        }
        System.out.println(ans);
    }
}
