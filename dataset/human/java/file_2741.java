import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main
{

  static class CharComparatorA implements Comparator<Character>
  {
    @Override
    public int compare(Character o1, Character o2)
    {
      return o1.compareTo(o2);
    }
  }

  static class CharComparatorD implements Comparator<Character>
  {
    @Override
    public int compare(Character o1, Character o2)
    {
      return o2.compareTo(o1);
    }
  }

  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);
    String s = r.readLine();
    String t = r.readLine();
    ArrayList<Character> sa = new ArrayList<Character>();
    ArrayList<Character> ta = new ArrayList<Character>();

    for(int i = 0; i < s.length(); i++)
    {
      sa.add(s.charAt(i));
    }

    for(int i = 0; i < t.length(); i++)
    {
      ta.add(t.charAt(i));
    }

    Collections.sort(sa, new CharComparatorA());
    Collections.sort(ta, new CharComparatorD());

    s = "";
    t = "";
    
    for(Character c : sa)
    {
      s += c;
    }
    
    for(Character c : ta)
    {
      t += c;
    }
    
    System.out.println(s.compareTo(t) < 0 ? "Yes" : "No");

  }

}
