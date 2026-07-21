import java.util.*;
import java.util.Queue;
import java.util.ArrayDeque;

class Main{
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
 
        String S = sc.next();
        int l = S.length();
        char[] ch = S.toCharArray();
        int Q = sc.nextInt();
        int[] T = new int[Q];
        int reverse = 0;
        ArrayDeque<Character> deq = new ArrayDeque<Character>();

        for(int i=0; i<l; i++){
            deq.add(ch[i]);
        }

        int ad = 0;
        for(int i=0; i<Q; i++){
            T[i] = sc.nextInt();
            if(T[i]==1){
                reverse += 1;
            }
            else{
                ad += 1;
                int F = sc.nextInt();
                char C = sc.next().charAt(0);
                if((F==1 && reverse%2==0) || (F==2 && reverse%2!=0)){
                    deq.push(C);
                }
                else{
                    deq.add(C);
                }
            }
        }
        for(int i=0; i<l+ad; i++){
            if(reverse%2==0){
                System.out.print(deq.pop());
            }
            else{
                System.out.print(deq.removeLast());
            }
        }
        System.out.println("");
    }
}
