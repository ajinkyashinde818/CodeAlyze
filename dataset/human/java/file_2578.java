import java.util.*;
class Main
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.next(), t = sc.next(), ans = "No";
        char[] ss = new char[s.length()];
        char[] tt = new char[t.length()];
        for(int i = 0; i < s.length(); i++)
            ss[i] = s.charAt(i);
        for(int i = 0; i < t.length(); i++)
            tt[i] = t.charAt(i);
        Arrays.sort(ss);
        Arrays.sort(tt);
        String news = "", newt = "";
        for(int i = 0; i < s.length(); i++)
            news += ss[i];
        for(int i = 0; i < t.length(); i++)
            newt += tt[t.length()-1-i];
        if(news.compareTo(newt) < 0) ans = "Yes";
        System.out.println(ans);
    }
}
