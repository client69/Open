import part1 #import part1.py
import part2 #import part2.py
import part3 #import part3.py
import part4 #import part4.py
import part5 #import part5.py

def Main():
    """This is the main this function calls other functions"""
    menuInputValidation()


def MenuUI():
    """# Menu UI
    This function Prints Programs terminal UI"""
    space1 = ' '*2 # no of spaces
    menuItemlist = ['Progression Outcome Predictor','Student Version',"Student Version (Validation)","Staff Version with Histogram",
                    "Vertical Histogram (optional extension)","Alternative Staff Version (optional extension)",
                   "Q/q","Exit Program"] # this list contains all the menu items
    print(f"+{'-'*55}+\n|\t{menuItemlist[0]}\t|\n+{'-'*5}+{'-'*49}+".expandtabs(14))
    print(f"|{space1 + '1' + space1}|{space1 + menuItemlist[1]}{' '*32}|\n|{space1 + '2' + space1}|{space1 + menuItemlist[2]}{' '*19}|")
    print(f"|{space1 + '3' + space1}|{space1 + menuItemlist[3]}{' '*19}|\n|{space1 + '4' + space1}|{space1 + menuItemlist[4]}{' '*8}|")
    print(f"|{space1 + '5' + space1}|{space1 + menuItemlist[5]} |\n| {menuItemlist[6]} |{space1 + menuItemlist[7]}{' '*35}|")

def menuInputValidation():
    """This function validate input"""
    global option
    range_valid_list = [ '1', '2', '3', '4', '5', 'q', 'Q']
    option = '0'
    newline = '\n'*2
    while option not in range_valid_list[-2:]:
        MenuUI()
        option = str(input(f"+{'-'*5}+{'-'*49}+\nPlease Select an Option: "))
        toPrint = f'{option} Selected!'
        if option not in range_valid_list:
            print(f"Invalid option selected!!\nPlease Enter Option (1 , 2 , 3 , 4 , 5 ,q or Q){newline}")
        else:
            if option == '1':
                print(toPrint)
                part1.Main()
                print(newline)
            elif option == '2':
                print(toPrint)
                part2.Main()
                print(newline)
            elif option == '3':
                print(toPrint)
                part3.Main()
                print(newline)
            elif option == '4':
                print(toPrint)
                part4.Main()
                print(newline)
            elif option == '5':
                print(toPrint)
                part5.Main()
                print(newline)
    print(f'{toPrint}\tProgram Terminated.')

Main()