# I declare that my work contains no examples of misconduct, such as plagiarism, or collusion.  
# Any code taken from other sources is referenced within my code solution.
# Student ID: w1833487        
# Date: 23/03/2021

moduleT_count = 0 # declare varible
moduleR_count = 0 # declare varible
exclude_count = 0 # declare varible
progress_count = 0 # declare varible
total_count = 0 # declare varible

def Main(): 
    """# Main function
    This function calls ReRun and HistogramGenerator functions
    """
    print('-'*57) # print dashed line 60char's long
    print('Staff Version with Histogram\n')
    ReRun() # calls ReRun function
    HistogramGenerator() # calls HistogramGenerator function

def ValidateInput(): 
    """this function take Inputs and Validate"""
    range_credit_list = [0, 20, 40, 60, 80, 100, 120] # declare list of valid input ranges
    global total_count # declare varible as global
    while True:
        level_credit_list = [] # declare list to store user inputs
        while True:
            try:
                pass_credit = int(input('Enter your total PASS credits: ')) # take user input and assign it to a variable
                if pass_credit in range_credit_list:
                    break # if condition True: break loop
                else:
                    print('Out of range\n')
            except ValueError:
                print('Integer required\n')

        while True:
            try:
                defer_credit = int(input('Enter your total DEFER credits: ')) # take user input and assign it to a variable
                if defer_credit in range_credit_list:
                    break # if condition True: break loop
                else:
                    print('Out of range\n')
            except ValueError:
                print('Integer required\n')
        
        while True:
            try:
                fail_credit = int(input('Enter your total FAIL credits: ')) # take user input and assign it to a variable
                if fail_credit in range_credit_list:
                    break # if condition True: break loop
                else:
                    print('Out of range\n')
            except ValueError:
                print('Integer required\n')
        
        level_credit_list.extend([pass_credit,defer_credit,fail_credit]) # extend list by adding variables           
        if sum(level_credit_list) == 120:
            break # if condition True: break loop
        else:
            print('Total incorrect\n')
            level_credit_list.clear # if condition False: clear list
    
    total_count += 1 # increment variable value by 1
    Logic(level_credit_list) # calls Logic functions and parse list

def Logic(lct): # Logic Fuction with parsed list as parameter
    global progress_count, moduleT_count, moduleR_count, exclude_count # declare varibles as global
    if (lct[0] == 0 and lct[1] <= 40) or (lct[0] == 20 and lct[1] <= 20) or (lct[0] == 40 and lct[1] == 0):
        message = 'Exclude' # if condtion True: assign string to variable
        exclude_count += 1 # increment variable value by 1
    elif (lct[0] == 0 and lct[1] >= 60) or (lct[0] == 20 and lct[1] >= 40) or (lct[0] == 40 and lct[1] != 0) or (lct[0] == 60) or (lct[0] == 80):
        message = 'Do not progress - module retriever' # if condtion True: assign string to variable
        moduleR_count += 1 # increment variable value by 1
    elif (lct[0] == 100):
        message = 'Progress (module trailer)' # if condtion True: assign string to variable
        moduleT_count += 1 # increment variable value by 1
    elif (lct[0] == 120):
        message = 'Progress' # if condtion True: assign string to variable
        progress_count += 1 # increment variable value by 1
    print(message)

def HistogramGenerator(): # Histogram Generator Function
    print('-'*57) # print dashed line 60char's long
    print(f'''Vertical Histogram\nProgress {progress_count} | Trailer {moduleT_count} | Retriever {moduleR_count} | Excluded {exclude_count}''')
    space2 = " "*5
    space1 = " "*6
    p_outcome = [progress_count,moduleT_count,moduleR_count,exclude_count] # create list and add variables to list

# Line No:87-96 reference: AllTech, 2018. console horizontal histogram in python 😀. [video] Available at: <https://www.youtube.com/watch?v=h_qlWgIvOZo> [Accessed 25 March 2021]. 
    for i in p_outcome:
        while not all (i <= 0 for i in p_outcome):
            toPrint = '' # declare varible
            for j in range(4):
                if p_outcome[j] > 0:
                    toPrint += space1+'*'+space2
                    p_outcome[j] -= 1
                else:
                    toPrint += space1+' '+space2
            print(toPrint)

    print(f'{total_count} outcomes in total.')
    print('-'*57) # print dashed line 60char's long

def ReRun(): # Ask User for ReRun function
    while True:
        ValidateInput() # calls ValidateInput function
        option = str(input("\nWould you like to enter another set of data?\nEnter 'y' for yes or 'q' to quit and view results: ")) # take user input and assign it to a variable
        print('')
        while option not in ['y','q']:
                print("Invalid Option! Please Enter 'y' or 'q'")
                option = str(input("\nWould you like to enter another set of data?\nEnter 'y' for yes or 'q' to quit and view results: ")) # take user input and assign it to a variable
                print('')
        else:
            if option == 'q':
                break # if condition True: break loop
            else:
                continue

if __name__ == "__main__":
    Main() # calls main function
    