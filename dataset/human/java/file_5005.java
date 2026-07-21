import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        
        String s = sc.next();
        ArrayList<Character> lk_min = new ArrayList<Character>();
        ArrayList<Character> lk_over = new ArrayList<Character>();
        
        boolean reversed = false;
        
        int ope_n = Integer.parseInt(sc.next());
        
        int kind=0;
        String tmp="\0";
        char newl = '\0';
        for(int i=0; i<ope_n; i++){
            kind = Integer.parseInt(sc.next());
            if(kind==1){
                reversed=!reversed;
            }else{
                kind = Integer.parseInt(sc.next());
                tmp = sc.next();
                newl = tmp.charAt(0);
                if(kind==1){
                    if(reversed){
                        lk_over.add(newl);
                    }else{
                        lk_min.add(newl);
                    }
                }else{
                    if(reversed){
                        lk_min.add(newl);
                    }else{
                        lk_over.add(newl);
                    }
                }
            }
        }
        StringBuilder bld = new StringBuilder(s);
        for(int i=0; i < lk_over.size(); i++){
            bld.append(lk_over.get(i));
        }
        StringBuilder bld2 = bld.reverse();
        for(int i=0; i < lk_min.size(); i++){
            bld2.append(lk_min.get(i));
        }
        if(reversed) System.out.println(bld2.toString());
        else  System.out.println(bld2.reverse().toString());
    }
    
}
