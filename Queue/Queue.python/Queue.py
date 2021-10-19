import Dlinkedlist
class Queue:
    def __init__(self):
        self.items = Dlinkedlist.Doubly_Linkeslist()

    def enqueue(self, item):
        self.items.insert_back(item)

    def dequeue(self):
        self.items.remove_front()

    def is_empty(self):
        return self.items.is_empty()
        
    def display(self):
        self.items.display()


q = Queue()

while True:
    print('''
             1. Enqueue
             2. Dequeue
             3. Display
             4. Exit
             
             ''')

    choice = input('Enter your choice :')
    if choice=='1':
        val = input('Enter values :')
        q.enqueue(val) 
    elif choice=='2':
        q.dequeue()   
    elif  choice=='3':
        q.display()   
    elif choice=='4':
          break

          