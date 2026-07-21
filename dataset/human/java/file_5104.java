import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

public class Main{

    public static void main(String[] args) {

        new Main().solve();
    }

    void solve(){

        String s;
        int q;

        Scanner sc = new Scanner(System.in);
        s = sc.next();
        q = Integer.parseInt(sc.next());                

        int count = 0;

        LinkedList<String> string = new LinkedList<String>();
        for(int i=0; i<s.length(); i++){
            String s1 = "";
            s1 = String.valueOf(s.charAt(i));
            string.push(s1);
        }

        boolean first = false;           //trueのときリストのfirst が先頭
        while(count < q){
            int t = Integer.parseInt(sc.next());
            if(t == 1){                       //反転
                first = !first;
            }
            else{
                int f = Integer.parseInt(sc.next());
                String c = sc.next();

                if(first){
                    if(f == 1){
                        string.addFirst(c);
                    }
                    else{
                        string.addLast(c);
                    }
                }
                else{
                    if(f == 1){
                        string.addLast(c);
                    }
                    else{
                        string.addFirst(c);
                    }
                }
            }
            count ++;
        }
        sc.close();
        
        String output;
        StringBuilder sb = new StringBuilder();
        if(first){
            ListIterator<String> it = string.listIterator(0);
            while(it.hasNext()){
                sb.append(it.next());
            }
        }
        else{
            ListIterator<String> it = string.listIterator(string.size());
            while(it.hasPrevious()){
                sb.append(it.previous());
            }
        }
        output = sb.toString();

        System.out.println(output);
    }
}
