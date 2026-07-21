import java.util.Scanner;
public class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = Integer.parseInt(s.next());
        int r = Integer.parseInt(s.next());

        if(n>=10){
            System.out.println(r);

        }else{
            System.out.println(r+100*(10-n));

        }

    }
}
