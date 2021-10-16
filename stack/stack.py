class Stack:
    def __init__(self):
        self.items = []
    @property    
    def size(self):
        return len(self.items)

    def is_empty(self):
        return len(self.items)==0    

    def  push(self,item):
        self.items.append(item)

    def pop(self):
             if self.is_empty():
                 print('The stack is empty')
             else:
                return self.items.pop()

    def peek(self):
        if self.is_empty():
             print('The stack is empty')
        else:
            return self.items[-1]

    def display(self):
        if self.is_empty():
            print('The stack is empty')
        else:    
            print('The contents of stack are')
            for item in self.items:
                 print(f'{item}')

Stack = Stack()
while True:
    print('''
             1. Push
             2. pop
             3. Peek
             4.Dispaly
             5. Quit 
             ''')

    choice = input('Enter your choice :')

    if choice=='1':
        push = input('Enter element :')
        Stack.push(push)

    elif choice=='2':
        print(f'{Stack.pop()} poped')

    elif choice=='3':
        print(f'Peek is {Stack.peek()}')  

    elif  choice=='4':
        Stack.display()

    elif choice=='5':
        break                 
