//import java.lang.Math;
import java.util.Scanner;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();

        int R;
        if(n>10){
            R = r;
        }else{
            R = r+100*(10-n);
        }
        System.out.print(R);
    }
}
