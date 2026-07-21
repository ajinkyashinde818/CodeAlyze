import java.util.ArrayList;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in);

        String s = stdIn.next();
        char[] cs = s.toCharArray();

        int q = stdIn.nextInt();

        boolean isReverse = false;
        ArrayList<Character> front = new ArrayList<Character>();
        ArrayList<Character> back = new ArrayList<Character>();
        int t, f;
        char[] temp;
        char c;
        for(int i=0; i<q; i++){
            t = stdIn.nextInt();
            if(t == 1){
                isReverse = (isReverse) ? false : true;
            }else{
                f = stdIn.nextInt();
                temp = stdIn.next().toCharArray();
                c = temp[0];
                if(((f == 1) && !isReverse) || ((f == 2) && isReverse)){
                    front.add(c);
                }else{
                    back.add(c);
                }
            }
        }

        if(!isReverse){
            for(int i=front.size()-1; i>=0; i--){
                System.out.print(front.get(i));
            }
            System.out.print(s);
            for(int i=0; i<back.size(); i++){
                System.out.print(back.get(i));
            }
        }else{
            for(int i=back.size()-1; i>=0; i--){
                System.out.print(back.get(i));
            }
            for(int i=cs.length-1; i>=0; i--){
                System.out.print(cs[i]);
            }
            for(int i=0; i<front.size(); i++){
                System.out.print(front.get(i));
            }
        }
    }
}
