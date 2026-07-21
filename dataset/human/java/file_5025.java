import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        //Scanner scanner = new Scanner(System.in);
        String str = scanner.readLine();
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        Integer n = Integer.parseInt(scanner.readLine());
        LinkedList<Character> list = new LinkedList<>();
        for (char ch : str.toCharArray())
            list.add(ch);
        boolean isR = false;
        for (int i = 0; i < n; i ++){
            String[] s1 = scanner.readLine().split(" ");
            if (s1[0].equals("1"))
                isR = !isR;
            else if (s1[0].equals("2")){
                if (s1[1].equals("1")){
                    if (isR)
                        list.add(s1[2].charAt(0));
                    else
                        list.addFirst(s1[2].charAt(0));
                }
                else if (s1[1].equals("2")){
                    if (isR)
                        list.addFirst(s1[2].charAt(0));
                    else
                        list.add(s1[2].charAt(0));
                }
            }
        }
        scanner.close();
        StringBuffer stringBuffer = new StringBuffer();
        for (char ch : list)
            stringBuffer.append(ch);
        if (isR) out.println(stringBuffer.reverse());
        else out.println(stringBuffer);
        out.flush();
    }
}
