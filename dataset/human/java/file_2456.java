public class Main{
  public void run(java.io.InputStream in, java.io.PrintStream out){
    java.util.Scanner sc = new java.util.Scanner(in);
    int n, a, b, i;
    String as, bs;
    char[] ac, bc;

    for(n = sc.nextInt();n-- > 0;){
      as = sc.next(); bs = sc.next();
      ac = new char[as.length()]; bc = new char[bs.length()];
      for(i = 0;i < as.length();i++)ac[i] = as.charAt(i);
      for(i = 0;i < bs.length();i++)bc[i] = bs.charAt(i);
      a = getint(ac, as.length()); b = getint(bc, bs.length());
      solve(a + b);
    }

    sc.close();
  }
  public static void main(String[] args){
    (new Main()).run(System.in, System.out);
  }
  private static int getint(char[] c, int n){
    int i, res = 0;
    for(i = 0;i < n;){
      if(c[i] >= '2' && c[i] <= '9'){
        if(c[i + 1] == 'm')res += 1000 * (int)(c[i] - '0');
        else if(c[i + 1] == 'c')res += 100 * (int)(c[i] - '0');
        else if(c[i + 1] == 'x')res += 10 * (int)(c[i] - '0');
        else res += (int)(c[i] - '0');
        i += 2;
      }else{
        if(c[i] == 'm')res += 1000;
        else if(c[i] == 'c')res += 100;
        else if(c[i] == 'x')res += 10;
        else res++;
        i++;
      }
    }
    return res;
  }
  private static void solve(int a){
    int d, i;
    String[] s;
    s = new String[4]; s[0] = "m"; s[1] = "c"; s[2] = "x"; s[3] = "i";
    i = 0;
    for(d = 1000;d > 0;d /= 10){
      if(a / d > 1)System.out.print((a / d) + s[i]);
      else if(a / d == 1)System.out.print(s[i]);
      a %= d; i++;
    }
    System.out.println();
    return;
  }
}
