import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Iterator;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;
import java.util.Map;
import java.util.HashMap;
 
class Main{
        public static void main(String args[]){
                Scanner sc = new Scanner(System.in);
                String s = sc.next();
                String t = sc.next();
                ArrayList<Character> S = new ArrayList<Character>();
                for(int i=0; i<s.length(); i++){
                    S.add(s.charAt(i));
                }
                ArrayList<Character> T = new ArrayList<Character>();
                for(int i=0; i<t.length(); i++){
                    T.add(t.charAt(i));
                }
                Collections.sort(S);
                Collections.sort(T,Collections.reverseOrder());
                
                boolean ch = true;
                boolean same = true;
                for(int i=0; i<Math.min(S.size(),T.size()); i++){
                    if(S.get(i)==T.get(i)){
                        same = true;
                        ch = true;
                    }else if(S.get(i)<T.get(i)){
                        same = false;
                        ch = true;
                      	break;
                    }
                    else{
                        same = false;
                        ch = false;
                        break;
                    }
                }
                
                if(ch && !same){
                    System.out.println("Yes");
                }else if(ch && same){
                    if(S.size()<T.size()){
                        System.out.println("Yes");
                    }else{
                        System.out.println("No");
                    }
                }else if(!ch){
                    System.out.println("No");
                }
        }
}
