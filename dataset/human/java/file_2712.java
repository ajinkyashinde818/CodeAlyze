import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception {
        List<String> s = new ArrayList<String>(Arrays.asList(br.readLine().split("")));
        List<String> t = new ArrayList<String>(Arrays.asList(br.readLine().split("")));
        int mins;
        int maxt;
        int sindex=0;
        int tindex=0;
        int minsize = Math.min(s.size(), t.size());
        for (int i = 0; i < minsize; i++) {
            mins = Integer.MAX_VALUE;
            maxt = Integer.MIN_VALUE;
            for (int j = 0; j < s.size(); j++) {
                if (s.get(j).charAt(0) < mins) {
                    mins = s.get(j).charAt(0);
                    sindex = j;
                }
            }
            for (int j = 0; j < t.size(); j++) {
                if (t.get(j).charAt(0) > maxt) {
                    maxt = t.get(j).charAt(0);
                    tindex = j;
                }
            }
            if (mins < maxt) {
                System.out.println("Yes");
                return;
            }else if(mins > maxt){
                System.out.println("No");
                return;
            }
            s.remove(sindex);
            t.remove(tindex);
        }
        if(s.size() < t.size()){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }


    }


    static int[] inputval() throws Exception {
        String[] strarray = br.readLine().trim().split(" ");
        int[] intarray = new int[strarray.length];
        for (int i = 0; i < intarray.length; i++) {
            intarray[i] = Integer.parseInt(strarray[i]);
        }
        return intarray;
    }

    static void array_sout(int[][] array) {
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[0].length; j++) {
                System.out.print(array[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void array_sout(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
}
