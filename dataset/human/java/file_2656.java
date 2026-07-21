import java.util.*;
import java.util.Collections;
import java.util.ArrayList;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        String t = sc.next();
        String S = "";
        String T = "";
        int ls = s.length();
        int lt = t.length();
        ArrayList<String> lists = new ArrayList<String>();
        ArrayList<String> listt = new ArrayList<String>();

        for(int i=0; i<ls; i++){
            lists.add(s.substring(i, i+1));
        }
        for(int i=0; i<lt; i++){
            listt.add(t.substring(i, i+1));
        }

        Collections.sort(lists);
        Collections.sort(listt, Collections.reverseOrder());

        ArrayList<String> al = new ArrayList<String>();

        for(int i=0; i<ls; i++){
            S += lists.get(i);
        }
        al.add(S);
        for(int i=0; i<lt; i++){
            T += listt.get(i);
        }
        al.add(T);

        Collections.sort(al);

        if(al.get(0).equals(S) && !S.equals(T)){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
    } 
}
