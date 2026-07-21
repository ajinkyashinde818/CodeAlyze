import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Scanner;

class Main {
    static final int MOD = 1000000007;
    static final int INF = 1 << 30;
    static final int ALF = 26;

    Main() {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        List<Character> slist = new ArrayList<Character>();
        for(char c:s.toCharArray())slist.add(c);
        Collections.sort(slist);
        StringBuffer as = new StringBuffer();
        for(char c:slist)as.append(c);
        String t = sc.next();
        List<Character> tlist = new ArrayList<Character>();
        for(char c:t.toCharArray())tlist.add(c);
        Collections.sort(tlist,Comparator.reverseOrder());
        StringBuffer at = new StringBuffer();
        for(char c:tlist)at.append(c);
        System.err.println(as);
        System.err.println(at);
        System.out.println(as.toString().compareTo(at.toString())<0?"Yes":"No");
    }

    public static void main(String[] args) {
        new Main();
    }
}
