// Example application
import java.io.*;
class Main {
  public static void main(String[] args) throws IOException {
    File file = File.createTempFile("codealyze", ".txt");
    try (PrintWriter writer = new PrintWriter(file)) { writer.println(4); }
    System.out.println(file.length() > 0);
    file.delete();
  }
}
