import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{

  public static void main(String[] args) throws IOException
  {

    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);
    String s;
    String[] sl;

    s = r.readLine();
    long n = Long.parseLong(s);

    int k = 0;
    for(k = 0; k * (k - 1) / 2 < n; k++);
    
    if(k * (k - 1) / 2 > n)
    {
      System.out.println("No");
      System.exit(0);
    }
    System.out.println("Yes");
    System.out.println(k);
    
    int a[][] = new int[500][500];
    
    int z[] = new int[500];
    int w[] = new int[500];
    
    int v = 1;
    
    StringBuilder sb = new StringBuilder();
    
    for(int i = 0; i < k; i++)
    {
      for(int j = 0; j < i; j++)
      {
        a[i][z[i]] = a[j][w[j]];
        z[i]++;
        w[i]++;
        w[j]++;
      }
      while(z[i] < k - 1)
      {
        a[i][z[i]] = v;
        z[i]++;
        v++;
      }
    }
    
    for(int i = 0; i < k; i++)
    {
      sb.append(z[i]);
      for(int j = 0; j < z[i]; j++)
      {
        sb.append(" ");
        sb.append(a[i][j]);
      }
      sb.append("\n");
    }
    
    System.out.println(sb);
  }

}
