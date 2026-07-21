import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.Arrays;
import java.util.Collections;
import java.util.ArrayList;
import java.util.List;
import java.util.HashSet;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Comparator;

public class Main {
    // 標準入力
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    // 標準入力数値配列用 int
    static int[] inputval() throws Exception {
        String[] strarray = br.readLine().trim().split(" ");
        int[] intarray = new int[strarray.length];
        for (int i = 0; i < intarray.length; i++) {
            intarray[i] = Integer.parseInt(strarray[i]);
        }
        return intarray;
    }

    // 標準入力数値配列用 integer ソート用
    static Integer[] inputvalInteger() throws Exception {
        String[] strarray = br.readLine().trim().split(" ");
        Integer[] intarray = new Integer[strarray.length];
        for (int i = 0; i < intarray.length; i++) {
            intarray[i] = Integer.parseInt(strarray[i]);
        }
        return intarray;
    }

    public static void main(String[] args) throws Exception {
        // write your code here
        String s = br.readLine().trim();
        String t = br.readLine().trim();
        char [] tarray = t.toCharArray();
        List<String> sList = new ArrayList<String>();
        List<String> tList = new ArrayList<String>();
        for (int i=0; i<s.length(); i++){
            sList.add(s.substring(i,i+1));
        }
        for (int i=0; i<t.length(); i++){
            tList.add(t.substring(i,i+1));
        }

        Collections.sort(sList);
        Collections.sort(tList);
        Collections.reverse(tList);

        String comps = "";
        String compt = "";


        for (String ss :sList){
            comps += ss;
        }

        for (String st :tList){
            compt += st;
        }

        if (comps.compareTo(compt) < 0){
            System.out.println("Yes");

        }else{
            System.out.println("No");
        }


    }

}
