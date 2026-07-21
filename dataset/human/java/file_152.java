import java.io.*;
import java.util.ArrayList;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int N = Integer.parseInt(str);
        str = br.readLine();
        ArrayList<Integer> A = new ArrayList<>();
        int cont = 0;
        for (String s:str.split(" ")){
            if (Integer.parseInt(s) < 0){
                cont++;
            }
            A.add(Math.abs(Integer.parseInt(s)));
        }
        int min = 1_000_000_000;
        long ans = 0;
        for (int i:A){
            ans += (long)i;
            if (i < min){
                min = i;
            }
        }
        if (cont % 2 == 1){
            ans -= (long)min * 2;
        }
        System.out.println(ans);
    }
}
