
class Node: 
    def __init__(self,item):
        self.item = item
        self.next = None
 
class LinkedList:
    
    def __init__(self) :
        self.head : Node = None

    # printing 
    def show_list(self ):
        print_list : Node = self.head

        while print_list is not None:
            print(print_list.item)
            print_list = print_list.next

    def insert_at_beg(self,data ):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self,data):
        list = self.head
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
        else:
            while list.next is not None:
                list = list.next

            list.next = new_node



if __name__ == "__main__":
    linked_list = LinkedList()
    toContinue = True
    choice = 0



    
    while(toContinue):
        print (" 1. show \n 2. insert at beginning \n 3. insert at end  \n 4. exit \n \n \n")
        choice = int(input("Enter choice : "))

        if choice == 1:
            linked_list.show_list()
        elif choice == 2 : 
            data = input("enter data : ")
            linked_list.insert_at_beg(data)
        elif choice == 3 : 
            data = input("enter data : ")
            linked_list.insert_at_end(data)
        elif choice == 4 : 
            toContinue = False
        else :
            print(' wront choice try again \n\n')

