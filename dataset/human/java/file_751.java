import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    String[] data = br.readLine().split(" ");
    int numContest = Integer.parseInt(data[0]);
    int rate = Integer.parseInt(data[1]);
    
    if(numContest<10){
      rate = rate+100*(10-numContest);
    }
    System.out.println(rate);
  }
}
