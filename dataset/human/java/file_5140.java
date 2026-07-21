import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
 
        String strS = scanner.nextLine();
        int iQ = scanner.nextInt();
        
        StringBuilder strStr = new StringBuilder();
        strStr.append(strS);
        StringBuilder strTop = new StringBuilder();
        boolean blTop = true;
        for (int i = 0; i < iQ; i++) {
            int iT = scanner.nextInt();
            if (iT == 1) {
                blTop = !blTop;
            } else {
                int iFn = scanner.nextInt();
                String strC = scanner.next();

                if ((iFn == 1 && blTop == true) || (iFn == 2 && blTop == false))
                    strTop.append(strC);
                else 
                    strStr.append(strC); 
            }
        }
        StringBuilder strOut = new StringBuilder();
        if (blTop) {
            strTop.reverse();
            strOut.append(strTop);
            strOut.append(strStr);
        } else {
            strStr.reverse();
            strOut.append(strStr);
            strOut.append(strTop);
        }
        System.out.println(strOut);  
    }
}
