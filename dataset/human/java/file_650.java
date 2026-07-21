import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int R = scan.nextInt();
        int I = 0;
        if(N>=10){
            I=R;
            System.out.println(I);
        }
        else{
            I=R+100*(10-N);
            System.out.println(I);
        }
    }
}
