import java.util.Arrays;

public class Node {

    private Node next;
    private int num;

    public Node() {
        this.next = null;
    }
    public Node(int num) {
        this.next = null;
        this.num = num;
    }

    public int getNum() {
        return num;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public static Node assignNums(int[] nums) {

        if( nums.length == 0) {
            return null;
        }
        else {
            Node newNode = new Node(nums[0]);
            int[] newArray = Arrays.copyOfRange(nums,1,nums.length);
            newNode.setNext(assignNums(newArray));
            return newNode;
        }
    }

    public static Node spliceLL(Node node1, Node node2) {

        if (node1 == null) {
            return node2;
        }
        else if (node2 == null) {
            return node1;
        }
        else if (node1.getNum() > node2.getNum()) {
            node2.setNext(spliceLL(node1, node2.getNext()));
            return node2;
        }
        else {
            node1.setNext(spliceLL(node1.getNext(), node2));
            return node1;
        }
    }

}
