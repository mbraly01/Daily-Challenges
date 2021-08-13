class Node(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    def make_chain(self, list):
        if list == []:
            return self
        else:
            temp = Node(list[0],None)
            self.next = temp.make_chain(list[1:])
            return self

def merge(node1,node2):
    if node1 == None:
        return node2
    elif node2 == None:
        return node1
    elif node1.val < node2.val:
        node1.next = merge(node1.next, node2)
        return node1
    else:
        node2.next = merge(node1, node2.next)
        return node2


list1 = [1,2,3,4]
list2 = [1,3,5,7]

node1 = Node(list1[0], None)
node1 = node1.make_chain(list1[1:])
node2 = Node(list2[0], None)
node2 = node2.make_chain(list2[1:])

fin = merge(node1, node2)

while fin != None:
    print(fin.val)
    fin = fin.next