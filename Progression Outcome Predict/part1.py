# I declare that my work contains no examples of misconduct, such as plagiarism, or collusion.  
# Any code taken from other sources is referenced within my code solution.
# Student ID: w1833487        
# Date: 23/03/2021

def Main(): 
    """# Main function
    This Function take user inputs and parse it to Logic funtion. & Prints Return Value From Logic function
    """
    level_credit_list = [] # declare list to store user inputs 

    print('-'*57) # print dashed line 60char's long
    pass_credit = int(input('Please Enter Your credits at pass: ')) # take user input and assign it to a variable
    defer_credit = int(input('Please Enter Your credits at defer: ')) # take user input and assign it to a variable
    fail_credit = int(input('Please Enter Your credits at fail: ')) # take user input and assign it to a variable

    level_credit_list.extend([pass_credit, defer_credit, fail_credit]) # extend list by adding variables
    message = Logic(level_credit_list) # pass list to logic Fuction and call logic function and store return value
    
    print(message) # print returned values from Logic function
    print('-'*57) # print dashed line 60char's long

def Logic(lct): # Logic Fuction with parsed list as parameter
    if (lct[0] == 0 and lct[1] <= 40) or (lct[0] == 20 and lct[1] <= 20) or (lct[0] == 40 and lct[1] == 0): # condition 1
        message = 'Exclude' # if condtion True: assign string to variable
    elif (lct[0] == 0 and lct[1] >= 60) or (lct[0] == 20 and lct[1] >= 40) or (lct[0] == 40 and lct[1] != 0) or (lct[0] == 60) or (lct[0] == 80): # condition 2
        message = 'Do not progress - module retriever'# if condtion True: assign string to variable
    elif (lct[0] == 100): # condition 3
        message = 'Progress (module trailer)' # if condtion True: assign string to variable
    elif (lct[0] == 120): # condition 4
        message = 'Progress' # if condtion True: assign string to variable
    return message # return varible

if __name__ == "__main__":
    Main() # calls main function
