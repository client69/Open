# I declare that my work contains no examples of misconduct, such as plagiarism, or collusion.  
# Any code taken from other sources is referenced within my code solution.
# Student ID: w1833487        
# Date: 23/03/2021

moduleT_count = 0 # declare varible
moduleR_count = 0 # declare varible
exclude_count = 0 # declare varible
progress_count = 0 # declare varible
total_count = 0 # declare varible

pass_credit = 0 # declare varible
defer_credit = 0 # declare varible
fail_credit = 0 # declare varible

dataset = [[120, 0, 0], [100, 20, 0], [100, 0, 20], [80, 20, 20], [60, 40, 20],[40, 40, 40], [20, 40, 60], [20, 20, 80], [20, 0, 100], [0, 0, 120]]
# hardcoded dataset of input values

def Main(): 
    """# Main function
    This Fuction Calls DirectInput and Histogram functions
    """
    print('-'*57) # print dashed line 60char's long
    print('Staff Version with Histogram\n')
    DirectInput() # calls DirectInput function
    HistogramGenerator() # calls HistogramGenerator function

def ValidateInput():
    range_credit_list = [0, 20, 40, 60, 80, 100, 120] # declare list of valid input ranges
    global total_count # declare varible as global
    while True:
        level_credit_list = [] # declare list to store user inputs
        while True:
            try:
                if pass_credit in range_credit_list:
                    break # if condition True: break loop
                else:
                    print('Out of range\n')
            except ValueError:
                print('Integer required\n')

        while True:
            try:
                if defer_credit in range_credit_list:
                    break # if condition True: break loop
                else:
                    print('Out of range\n')
            except ValueError:
                print('Integer required\n')
        
        while True:
            try:
                if fail_credit in range_credit_list:
                    break # if condition True: break loop
                else:
                    print('Out of range\n')
            except ValueError:
                print('Integer required\n')
        
        level_credit_list.extend([pass_credit,defer_credit,fail_credit]) # extend list by adding variables
        # print(sum(level_credit_list)) # for debugging Purpose         
        if sum(level_credit_list) == 120:
            break # if condition True: break loop
        else:
            print('Total incorrect\n')
            level_credit_list.clear # if condition False: clear list
    total_count += 1 # increment variable value by 1
    Logic(level_credit_list) # calls Logic functions and parse list

def Logic(lct): # Logic Fuction with parsed list as parameter
    global progress_count, moduleT_count, moduleR_count, exclude_count # declare varible as global
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
    print()
    print('-'*57) # print dashed line 60char's long
    print('Horizontal Histogram')
    print(f"progress\t{progress_count}: {'*'*progress_count}".expandtabs(4)) # .expandtabs = custom sized tabs
    print(f"Trailer \t{moduleT_count}: {'*'*moduleT_count}".expandtabs(4))
    print(f"Retriever\t{moduleR_count}: {'*'*moduleR_count}".expandtabs(4))
    print(f"Excluded\t{exclude_count}: {'*'*exclude_count}\n".expandtabs(4))
    print(f'{total_count} outcomes in total.')
    print('-'*57) # print dashed line 60char's long

def DirectInput(): # DirectInput function
    global pass_credit, defer_credit, fail_credit # declare varibles as global
    for i in range(len(dataset)):
        pass_credit = dataset[i][0] # assign values from list to variable
        defer_credit = dataset[i][1] # assign values from list to variable
        fail_credit = dataset[i][2] # assign values from list to variable
        ValidateInput() # calls ValidateInput function

if __name__ == "__main__":
    Main() # calls main function
