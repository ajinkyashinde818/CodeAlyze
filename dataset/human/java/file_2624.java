import java.util.*;
import  java.lang.*;



class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.nextLine();
        String b = sc.nextLine();

        List<Character> listA = new ArrayList<>();
        List<Character> listB = new ArrayList<>();

        for (int i = 0; i < a.length(); i++) {
            listA.add(a.charAt(i));
        }

        for (int i = 0; i < b.length(); i++) {
            listB.add(b.charAt(i));
        }

        Collections.sort(listA);
        Collections.sort(listB, Collections.reverseOrder());

        String aSorted = "";
        String bSorted = "";

        for (int i = 0; i < listA.size();i++) {
            aSorted += listA.get(i);
        }

        for (int i = 0; i < listB.size();i++) {
            bSorted += listB.get(i);
        }

        System.out.println(aSorted.compareTo(bSorted) < 0 ? "Yes" : "No");

    }
}
