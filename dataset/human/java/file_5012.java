import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    resolve(System.in, System.out);
  }

  static void resolve(InputStream is, PrintStream pw) {
    Scanner sc = new Scanner(is);
    String s = sc.next();
    int q = Integer.parseInt(sc.next());
    List<Operation> operations = new ArrayList<>();
    for (int i = 0; i < q; i++) {
      int type = Integer.parseInt(sc.next());
      Operation op = new Operation();
      op.type = type;
      if (type == 2) {
        op.f = Integer.parseInt(sc.next());
        op.c = sc.next();
      }
      operations.add(op);
    }
    StringBuilder prefix = new StringBuilder();
    StringBuilder suffix = new StringBuilder();
    boolean forward = true;
    for (int i = 0; i < operations.size(); i++) {
      Operation op = operations.get(i);
      if (op.type == 1) {
        if (i + 1 < operations.size()) {
          if (operations.get(i + 1).type == 1) {
            i++;
            continue;
          }
        }
        forward = !forward;
        StringBuilder temp = suffix;
        suffix = prefix;
        prefix = temp;
      } else {
        if (op.f == 1) {
          prefix.append(op.c);
        } else {
          suffix.append(op.c);
        }
      }
    }
    if (!forward) {
      s = new StringBuilder(s).reverse().toString();
    }
    pw.println(prefix.reverse().toString() + s + suffix.toString());
  }

  static class Operation {

    int type;
    int f;
    String c;
  }
}
