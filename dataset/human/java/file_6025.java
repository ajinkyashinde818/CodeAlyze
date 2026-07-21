import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            while (sc.hasNext()) {
                String[] abcs = {"abc", "acb", "bac", "bca", "cab", "cba"};
                System.out.println( (Arrays.asList(abcs).contains(sc.nextLine()))?"Yes":"No"); 
            }
        }
    }
}
