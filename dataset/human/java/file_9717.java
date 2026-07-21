import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.Collectors;

class Node {
    Integer id;
    Integer parentId;
    Integer siblingId;
    Integer depth;
    Integer height;
    Integer type;
    Integer leftId;
    Integer rigthId;

    public boolean haveChild(Integer id) {
        if (id == null || id == -1) {
            return false;
        }
        return true;
    }

    public boolean haveChildren() {
        return haveChild(leftId) || haveChild(rigthId);
    }

    public int countDegree() {
        return (haveChild(leftId) ? 1 : 0) + (haveChild(rigthId) ? 1 : 0);
    }
}

class Main {
    static Map<Integer, Node> nodes = new HashMap<>();

    static final Map<Integer, String> types = new HashMap<Integer, String>() {
      {
          put(1, "root");
          put(2, "internal node");
          put(3, "leaf");
      }
    };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Integer n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            Integer id = sc.nextInt();
            Integer leftId = sc.nextInt();
            Integer rigthId = sc.nextInt();
            Node node = updateNode(id, leftId, rigthId);
            updateChildrenNode(node, leftId, rigthId);
            updateChildrenNode(node, rigthId, leftId);
            node.leftId = leftId;
            node.rigthId = rigthId;
        }

        for (Integer i = 0; i < n; i++) {
            Node node = nodes.get(i);
            System.out.printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
                    node.id,
                    node.parentId,
                    node.siblingId,
                    node.countDegree(),
                    node.depth,
                    node.height,
                    types.get(node.type));
        }
    }

    public static Node updateNode(Integer id, Integer leftId, Integer rigthId) {
        Node node = nodes.get(id);
        if (node == null) {
            node = createNode(id);
            node.parentId = -1;
            node.siblingId = -1;
            node.depth = 0;
            node.type = 1;
            return node;
        }

        if (leftId == -1 && rigthId == -1) {
            node.type = 3;
        } else {
            node.type = 2;
        }

        return node;
    }

    public static Node updateChildrenNode(Node node, Integer childrenId, Integer siblingId) {
        if (childrenId == -1) {
            return null;
        }

        Node childrenNode = nodes.get(childrenId);
        if (childrenNode == null) {
            childrenNode = createNode(childrenId);
        }

        childrenNode.parentId = node.id;
        childrenNode.siblingId = siblingId;
        childrenNode.depth = new Integer(node.depth.intValue() + 1);
        updateDepth(childrenNode, childrenNode.leftId);
        updateDepth(childrenNode, childrenNode.rigthId);
        updateHeight(childrenNode);

        if(childrenNode.haveChildren()) {
            childrenNode.type = 2;
        } else {
            childrenNode.type = 3;
        }
        return childrenNode;
    }

    public static Node createNode(Integer id) {
        Node node = new Node();
        node.id = id;
        node.height = 0;
        nodes.put(id, node);
        return node;
    }

    public static void updateHeight(Node node) {
        Node parent = nodes.get(node.parentId);
        if (parent == null) {
            return;
        }
        if (parent.height > node.height) {
            return;
        }
        parent.height = node.height + 1;
        updateHeight(parent);
    }

    public static void updateDepth(Node node, Integer childrenId) {
        Node children = nodes.get(childrenId);
        if (children == null) {
            return;
        }
        children.depth = node.depth + 1;
        updateDepth(children, children.leftId);
        updateDepth(children, children.rigthId);
    }
}
