class  Node:
    def __init__(self,item):
        self.data = item
        self.next = None

class  Linked_List:
    def __init__(self):
        self.head =None
        self.num_items = 0

    def is_empty(self):
        return self.head is None

    def dispalay(self):
        trav = self.head
        while trav is not None:
            print(trav.data, end='-->')
            trav = trav.next            

    def insert_front(self,item):
        if self.head is None:
            self.head = Node(item)
        else:
            node = Node(item)
            node.next = self.head
            self.head = node  
        self.num_items += 1  

    def  insert_back(self,item):
        if self.is_empty():
            self.head = Node(item)
        else:
            trav = self.head
            while trav.next is not None:
                trav = trav.next
            node = Node(item)    
            trav.next = node 
        self.num_items += 1 

    def insert_given_locat(self,nodenum):
         if self.num_items < nodenum:
                print("No such a node in the list")
         else: 
            val = input("Enter value :")
            trav = self.head
            if nodenum == 1:
                if self.head is None:
                    self.head = Node(val)
                else:
                    node = Node(val)
                    node.next = self.head
                    self.head = node  
            elif nodenum > 1:
                i = 1
                while i < nodenum-1:
                    trav = trav.next
                    i += 1 
                node = Node(val)
                node.next =trav.next
                trav.next = node
            self.num_items += 1  
 

    def remove_front(self):
        if self.is_empty():
            print("Linked List is empty") 
        else:
            self.head = self.head.next  
            self.num_items -=1   

    def remove_back(self):
        if self.is_empty():
            print("Linked List is empty")
        else:
            if self.head.next is None:
                self.head = None
            else:
                trav = self.head
                while trav.next.next is not None:
                    trav = trav.next
                trav.next = trav.next.next
            self.num_items -= 1       

    def  remove_given_node(self,nodenum):
        if self.is_empty():
            print("Linked List is empty")
        else:
            if self.num_items < nodenum:
                print("No such a node in the list")
            else:
                trav = self.head
                if nodenum == 1:
                    self.head = self.head.next

                elif  self.num_items == nodenum:
                    
                    while trav.next.next is not None:
                        trav = trav.next
                    trav.next = trav.next.next

                elif nodenum > 1:
                    i = 1
                    while i < nodenum-1:
                        trav = trav.next
                        i += 1 
                    print(trav.data) 
                    temp = trav.next
                    trav.next = temp.next
            print("Node is deleted")
            self.num_items -= 1                        



Linkedlist = Linked_List()
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
            


