public class Main {

    public static void main (String[] args) {

        int[] nums = {1,6,8,10};
        int[] nums2 = {2,3,7,9};
        Node node = Node.assignNums(nums);
        Node node2 = Node.assignNums(nums2);
        node = Node.spliceLL(node, node2);

        while (node != null) {
            System.out.println(node.getNum());
            node = node.getNext();
        }
    }
}
