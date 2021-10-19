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

    def insert_front(self,item):
        if self.is_empty():
            node = Node(item)
            self.head = node
            self.tail = node 
            self.num_item += 1 

        else:
            node = Node(item) 
            node.next = self.head
            self.head.prev = node
            self.head = node
            self.num_item += 1 

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

    def insert_given_locat(self,nodenum):
        if self.num_item < nodenum:
                print("No such a node in the list")
        else: 
            val = input("Enter value :")
            if nodenum == 1:
                if self.head is None:
                    self.head = Node(val)
                else:
                    node = Node(val)
                    node.next = self.head
                    self.head = node  
            elif nodenum > 1:
                i = 1
                trav = self.head
                while i < nodenum-1:
                    trav = trav.next
                    i += 1 
                node = Node(val)
                node.next = trav.next
                trav.next = node
                node.prev = trav
            self.num_item += 1        

    def remove_back(self):
        if self.is_empty():
            raise RuntimeError('Linked list is empty')
        elif self.head == self.tail:
            data = self.head.data
            self.head =None
            self.tail = None
            self.num_item -= 1
            return data
        else:
            data = self.tail.data
            self.tail.prev.next = None
            temp = self.tail
            self.tail = self.tail.prev
            temp.prev = None
            self.num_item -= 1
            return data

    def  remove_given_node(self,nodenum):
        if self.is_empty():
            print("Linked List is empty")
        else:
            if self.num_item < nodenum:
                print("No such a node in the list")
            else:
                trav = self.head
                if nodenum == 1:
                    if self.is_empty():
                       raise RuntimeError('Linked list is empty')
                    elif self.head == self.tail:
                        self.head =None
                        self.tail = None
                        self.num_item -= 1
    
                    else:
                        self.tail.prev.next = None
                        temp = self.tail
                        self.tail = self.tail.prev
                        temp.prev = None
                        self.num_item -= 1
                        
                elif self.num_item == nodenum:
                    self.tail.prev.next = None
                    temp = self.tail
                    self.tail = self.tail.prev
                    temp.prev = None
                    self.num_item -= 1 

                elif nodenum > 1:
                    i = 1
                    while i < nodenum-1:
                        trav = trav.next
                        i += 1  
                    temp =trav.next
                    trav.next = temp.next
                    temp.next.prev = trav
                    temp = None                                               
     
    def dispalay(self):
        trav = self.head
        while trav is not None:
            print(trav.data,end='<-->')
            trav = trav.next
        print() 


Linkedlist = Doubly_Linkeslist()

while True:
    print('''
             1. Insert in begining
             2. Insert at  last
             3. Insert at  given specified locat
             4. Delete from begining
             5. Delete from last
             6. Delete given node specified locat
             7. Display
             8. Exit
             ''')

    choice = input('Enter your choice :')

    if choice=='1':
        val = input('Enter values :')
        Linkedlist.insert_front(val)

    elif choice=='2':
        val = input('Enter values :')
        Linkedlist.insert_back(val)

    elif choice=='3':
        loct = int(input('Enter Location :'))
        Linkedlist.insert_given_locat(loct)
           
    elif  choice=='4':   
         Linkedlist.remove_front()

    elif choice=='5':
         Linkedlist.remove_back()

    elif choice=='6':
         loct = int(input('Enter Location :'))
         Linkedlist.remove_given_node(loct) 

    elif choice=='7':
        Linkedlist.dispalay()

    elif choice=='8':
         break                      



             


