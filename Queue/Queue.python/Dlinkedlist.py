class  Node:
    def __init__(self,item):
        self.data = item
        self.next = None
        self.prev = None


class Doubly_Linkeslist:
    def __init__(self):
         self.head = None
         self.tail = None
         self.num_item = 0

    def is_empty(self):
        return self.head == self.tail == None    


    def insert_back(self,item):
        if self.is_empty():
            node = Node(item)
            self.head = node
            self.tail = node 
            self.num_item += 1 
        else:
            node = Node(item)
            self.tail.next = node
            node.prev = self.tail
            self.tail = node
            self.num_item += 1 

    def remove_front(self):
        if self.is_empty():
            raise RuntimeError('Linked list is empty')
        elif self.head == self.tail:
            data = self.head.data
            self.head =None
            self.tail = None
            self.num_item -= 1
            return data
        else:
            data = self.head.data
            self.head.next.prev = None
            temp = self.head
            self.head = self.head.next
            temp.next = None
            self.num_item -= 1
            return data

                            
    def display(self):
        trav = self.head
        while trav is not None:
            print(trav.data,end='<--')
            trav = trav.next
        print() 
                 



             


