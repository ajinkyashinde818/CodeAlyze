import java.util.*;
import java.lang.*;

class Main{
    Main(){
        Scanner SC = new Scanner(System.in);
        StringBuffer SB = new StringBuffer(SC.next());

        int Q = Integer.parseInt(SC.next());

        StringBuilder head = new StringBuilder(Q);
        StringBuilder tail = new StringBuilder(Q);

        boolean isReverse = false;
        int T, F;
        char C;
        for(int i=0;i<Q;i++){
            T = Integer.parseInt(SC.next());
            if(T==1){
                isReverse = !isReverse;
            } else {
                F = Integer.parseInt(SC.next());
                C = SC.next().charAt(0);

                if(F == 1){
                    if(isReverse){
                        tail.append(C);
                    } else {
                        head.append(C);
                    }
                } else {
                    if(isReverse){
                        head.append(C);
                    } else {
                        tail.append(C);
                    }
                }
            }
        }

        if(isReverse){
            System.out.print(tail.reverse().toString());
            System.out.print(SB.reverse().toString());
            System.out.println(head.toString());
        } else {
            System.out.print(head.reverse().toString());
            System.out.print(SB.toString());
            System.out.println(tail.toString());
        }
    }

    public static void main(String[] args){
        Main main = new Main();
    }
}
