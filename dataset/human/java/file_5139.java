import java.io.*;
import java.util.*;
import static java.lang.System.out;

public class Main{
    static MyReader in = new MyReader();

    public static void main(String[] args){
        String S = in.s();
        final int len = S.length();
        int Q = in.i();
        boolean forward = true;
        LinkedList<Character> list = new LinkedList<>();
        for(int i = 0; i < len; i++){
            list.add(S.charAt(i));
        }
        for(int i = 0; i < Q; i++){
            String[] s = in.ss();
            int T = Integer.parseInt(s[0]);
            if(T == 1){
                forward = !forward;
            } else {
                int F = Integer.parseInt(s[1]);
                char c = s[2].charAt(0);
                if(forward && F == 2 || !forward && F == 1){
                    list.add(c);
                } else {
                    list.addFirst(c);
                }
            }
        }
        char[] ans = new char[list.size()];
        if(forward){
            int i = 0;
            for(char c : list){
                ans[i++] = c;
            }
        } else {
            int i = ans.length-1;
            for(char c : list){
                ans[i--] = c;
            }
        }
        out.println(ans);
    }

    static class MyReader extends BufferedReader{
        MyReader(){
            super(new InputStreamReader(System.in));
        }

        String s(){
            try{return readLine();}catch(IOException e){return "";}
        }

        String[] ss(){
            return s().split(" ");
        }

        int i(){
            return Integer.parseInt(s());
        }

        int[] ii(){
            String[] ss = ss();
            int[] ii = new int[ss.length];
            for(int j = 0; j < ss.length; j++) ii[j] = Integer.parseInt(ss[j]);
            return ii;
        }

        ArrayList<Integer> li(){
            String[] ss = ss();
            ArrayList<Integer> li = new ArrayList<>();
            for(int j = 0; j < ss.length; j++) li.add(Integer.parseInt(ss[j]));
            return li;
        }

        long l(){
            return Long.parseLong(s());
        }

        long[] ll(){
            String[] ss = ss();
            long[] ll = new long[ss.length];
            for(int j = 0; j < ss.length; j++) ll[j] = Long.parseLong(ss[j]);
            return ll;
        }
    }
}
