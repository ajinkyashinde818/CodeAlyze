import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Main {
    private static InputReader in;
    private static PrintWriter out;

    // static String convert(String input){
    //     int lgt = input.length();
    //     char last = input.charAt(lgt-1);
    //     if(last == 's'){
    //         return input + "es";
    //     }else{
    //         return input + "s";
    //     }
            
    // }

    static String isInRow(List<Integer> lst){
        int lgt = lst.size();
        int temp3 = 0;
        for(int i =0; i < lgt-2; i++){
            temp3 = lst.get(i);
            if((temp3 != 0) && (lst.get(i+1) != 0) && (lst.get(i+2) != 0) )
                return "Yes";
        }
        return "No";
    }

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        in = new InputReader(inputStream);
        OutputStream outputStream = System.out;
        out = new PrintWriter(outputStream);

        int length = in.nextInt();
        List<Integer> arr = new ArrayList<Integer>();
        List<Integer> arr2 = new ArrayList<Integer>();
        int counter = 0;
        int temp = 0;
        while(counter < length * 2){
            temp = in.nextInt();
            arr.add(temp);
            counter++;
        }
        // System.out.println(arr);

        int temp2 = 0;
        for(int i = 0; i < length; i++){
            temp2 = arr.get(i*2);
            if(temp2 == arr.get(i*2+1)){
                arr2.add(temp2);
            }
            else{
                arr2.add(0);
            }
        }
        System.out.println(isInRow(arr2));
            
        }

    // taken from https://codeforces.com/submissions/Petr
    // together with PrintWriter, these input-output (IO) is much faster than the usual Scanner(System.in) and System.out
    // please use these classes to avoid your fast algorithm gets Time Limit Exceeded caused by slow input-output (IO)
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
 
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
 
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
 
        public int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
