import java.util.*;

class Main{

    Main(){
        Scanner SC = new Scanner(System.in);
        long N = Long.parseLong(SC.next());

        if( (N&1) == 1){
            System.out.println(0);
            return;
        }

        long R = 0;
        long D = 10;
        while(N >= D){
            R += N/D;
            D *= 5;
        }

        System.out.println(R);
    }

    public static void main(String[] args){
        Main main = new Main();
    }
}
