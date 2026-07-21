import java.util.*;

class Main{

    Main(){
        Scanner SC = new Scanner(System.in);
        int A = Integer.parseInt(SC.next());
        int B = Integer.parseInt(SC.next());

        System.out.println(LCM(A,B));
    }


    long LCM(long a, long b){
        return a / GCD(a, b) * b;
    }

    long GCD(long a, long b){
        if(b == 0) return a;
        return GCD(b, a%b);
    }

    public static void main(String[] args){
        Main main = new Main();
    }
}
