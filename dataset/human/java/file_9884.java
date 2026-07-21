import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {

  public static void main(String[] args) {
    resolve(System.in, System.out);
  }

  static void resolve(InputStream is, PrintStream pw) {
    Scanner sc = new Scanner(is);
    int n = Integer.parseInt(sc.next());
    int m = Integer.parseInt(sc.next());
    int x = Integer.parseInt(sc.next());
    List<Book> books = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      Book book = new Book(
        i,
        Integer.parseInt(sc.next())
      );
      int a[] = new int[m];
      for (int j = 0; j < m; j++) {
        a[j] = Integer.parseInt(sc.next());
      }
      book.a = a;
      books.add(book);
    }
    int ans = dfs(books, 0, 0, new Understand(x, m));
    pw.println(ans);
  }

  static int dfs(List<Book> books, int index, int price, Understand understand) {
    if (understand.isOk()) {
      return price;
    }
    boolean found = false;
    int ans = Integer.MAX_VALUE;
    for (int i = index; i < books.size(); i++) {
      Understand copy = new Understand(understand);
      copy.read(books.get(i));
      int childAns = dfs(books, i + 1, price + books.get(i).c, copy);
      if (childAns < 0) {
        continue;
      }
      found = true;
      ans = Math.min(ans, childAns);
    }
    if (found) {
      return ans;
    } else {
      return -1;
    }
  }

  static class Understand {

    int x;
    int current[];
    List<Book> read = new ArrayList<>();

    public Understand(int x, int m) {
      this.x = x;
      current = new int[m];
    }

    public Understand(Understand u) {
      this.x = u.x;
      this.current = Arrays.copyOf(u.current, u.current.length);
      this.read = new ArrayList<>(u.read);
    }

    void read(Book b) {
      read.add(b);
      for (int i = 0; i < b.a.length; i++) {
        current[i] += b.a[i];
      }
    }

    boolean isOk() {
      return Arrays.stream(current).allMatch(i -> i >= x);
    }

    @Override
    public String toString() {
      return
        read.stream().map(b -> String.valueOf(b.index)).collect(Collectors.joining(", ")) + ":"
          + Arrays.toString(current);
    }
  }

  static class Book {

    int index;
    int c;
    int a[];

    public Book(int index, int c) {
      this.index = index;
      this.c = c;
    }
  }
}
