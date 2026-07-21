import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        List<Character> fr = new ArrayList<>();
        List<Character> bk = new ArrayList<>();
        String S = sc.next();
        int Q = sc.nextInt();
        boolean rev = false;
        for(int i=0;i<Q;i++){
            int qi = sc.nextInt();
            if(qi == 1){
                rev = !rev;
                continue;
            }
            int fi = sc.nextInt();
            String c = sc.next();
            Character ci = c.charAt(0);
            if((!rev && fi == 1) || (rev && fi == 2)){
                fr.add(ci);
            }else{
                bk.add(ci);
            }
        }
        StringBuilder bld = new StringBuilder();
        if(rev){
            for(int i=bk.size()-1;i>=0;i--){
                bld.append(bk.get(i));
            }
            char[] sC = S.toCharArray();
            for(int i=sC.length-1;i>=0;i--){
                bld.append(sC[i]);
            }
            for(Character c:fr){
                bld.append(c);
            }
        }else{
            for(int i=fr.size()-1;i>=0;i--){
                bld.append(fr.get(i));
            }
            bld.append(S);
            for(Character c:bk){
                bld.append(c);
            }
        }
        System.out.println(bld.toString());
    }


}
