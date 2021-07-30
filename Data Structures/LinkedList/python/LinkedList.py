
class Node: 
    def __init__(self,item):
        self.item = item
        self.next = None

class LinkedList:
    
    def __init__(self) :
        self.head = None

def show_list(ll : LinkedList):
    list_to_show = ll
    while list_to_show.head != None:
        print(list_to_show.head.item, ", ")
        list_to_show.head = list_to_show.head.next

def insert(data : int, ll : LinkedList = None) -> LinkedList:
    mimicList : LinkedList = ll
    if(mimicList.head == None):
        mimicList.head = Node(data)
    else :
        while(mimicList.head !=None):
            mimicList.head = mimicList.head.next
        mimicList.item = data
        return ll

if __name__ == "__main__":
    linked_list = LinkedList()

    # #defining nodes
    # linked_list.head = Node(1)
    # second = Node(2)
    # third = Node(3)

    # #connecting nodes
    # linked_list.head.next = second
    # second.next = third

    toContinue = True
    choice = 0



    
    while(toContinue):
        print (" 1. show \n 2. insert \n 3. exit \n \n \n")
        choice = int(input("Enter choice : "))

        if choice == 1:
            show_list(linked_list)
        elif choice == 2 : 
            data = input("enter data : ")
            insert(data,linked_list)
        elif choice == 3 : 
            toContinue = False
        else :
            print(' wront choice try again \n\n')

