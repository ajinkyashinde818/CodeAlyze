import java.util.*;
import java.util.stream.Collectors;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
      
        String s = sc.next();
        List<String> words = Arrays.asList("dream", "erase", "dreamer", "eraser");

        int tmpIndex = s.length();
        while (true) {
            int tmpIndex2  = tmpIndex;
            for (String word : words) {
                if(s.startsWith(word, tmpIndex - word.length())) {
                    tmpIndex = s.indexOf(word, tmpIndex - word.length());
                    break;

                }
            }

            if (tmpIndex == 0 || tmpIndex == tmpIndex2) {
                break;
            }
        }
        String result = "NO";
        if (tmpIndex == 0) {
            result = "YES";
        }


        System.out.println(result);
    }
}
