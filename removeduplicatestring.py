def removeDuplicate(str, n):
    i = 0
    
    for j in range(0, n):
        for k in range(0, j + 1):
            if (str[j] == str[k]):
                break
                 
        if (k == j):
            str[i] = str[j]
            i += 1
             
    string = "".join(str[:i])
    return string
 
str= str(input("Enter String Value:"))
n = len(str)
print(removeDuplicate(list(str), n))