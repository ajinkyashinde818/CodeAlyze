import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

class Node {
    public int parent;
    public int left;
    public int right;
}

public class Main implements Runnable {
    static final int MAX = 25;
    static final int NIL = -1;
    Node[] T = new Node[MAX];
    int[] D = new int[MAX];
    int[] H = new int[MAX];

    public static void main(String[] args) throws Exception {
        Thread.setDefaultUncaughtExceptionHandler((t, e) -> System.exit(1));
        new Thread(null, new Main(), "", 16 * 1024 * 1024).start();
    }

    public void run() {
        int nodeTotalCount = 0;
        int root = 0;

        // 入力
        for (int i = 0; i < T.length; i++) {
            T[i] = new Node();
            T[i].parent = NIL;
        }
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));) {
            nodeTotalCount = Integer.parseInt(br.readLine());
            for (int i = 0; i < nodeTotalCount; i++) {
                String[] line = br.readLine().split(" ");
                int id = Integer.parseInt(line[0]);
                int left = Integer.parseInt(line[1]);
                int right = Integer.parseInt(line[2]);
                T[id].left = left;
                T[id].right = right;
                if (T[id].left != NIL) {
                    T[left].parent = id;
                }
                if (T[id].right != NIL) {
                    T[right].parent = id;
                }
            }
            for (int i = 0; i < nodeTotalCount; i++) {
                if (T[i].parent == NIL) {
                    root = i;
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        // 深さ計算
        setDepth(root, 0);
        // 高さ計算
        setHeight(root);

        // 出力
        for (int i = 0; i < nodeTotalCount; i++) {
            print(i);
        }
    }

    void print(int id) {
        StringBuilder sb = new StringBuilder();
        sb.append("node ").append(id);
        sb.append(": parent = ").append(T[id].parent);
        int sibling = calcSibling(id);
        sb.append(", sibling = ").append(sibling);
        int degree = 0;
        if (T[id].left != NIL)
            degree++;
        if (T[id].right != NIL)
            degree++;
        sb.append(", degree = ").append(degree);
        sb.append(", depth = ").append(D[id]);
        sb.append(", height = ").append(H[id]);
        if (T[id].parent == NIL) {
            sb.append(", root");
        } else if (T[id].left == NIL && T[id].right ==NIL) {
            sb.append(", leaf");
        } else {
            sb.append(", internal node");
        }
        System.out.println(sb.toString());
    }

    int calcSibling(int id) {
        int parentID = T[id].parent;
        if (parentID == NIL) {
            // 親がいなけりゃ兄弟もいない
            return NIL;
        }
        if (T[parentID].left != id && T[parentID].left != NIL) {
            // 親のleftが自分でない、かつNILでないなら兄弟
            return T[parentID].left;
        }
        if (T[parentID].right != id && T[parentID].right != NIL) {
            return T[parentID].right;
        }
        return NIL;
    }

    int setHeight(int id) {
        int leftHeight = 0, rightHeight = 0;
        if (T[id].left != NIL) {
            leftHeight = setHeight(T[id].left) + 1;
        }
        if (T[id].right != NIL) {
            rightHeight = setHeight(T[id].right) + 1;
        }
        H[id] = Math.max(leftHeight, rightHeight);
        return H[id];
    }

    void setDepth(int id, int d) {
        D[id] = d;
        if (T[id].right != NIL) {
            setDepth(T[id].right, d + 1);
        }
        if (T[id].left != NIL) {
            setDepth(T[id].left, d + 1);
        }
    }
}
