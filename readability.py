#Prompt user for a sentence
sen=input("Text: ")

#initializing variables to 0 to count number of letters, words, and sentences in the text.
l,w,s=0,0,0

for k in sen:
    if (k.isalpha() == True):
        l+=1
    elif (k==" "):
        w+=1
    elif (k=="." or k=="!" or l=="?"):
        s+=1
w+=1
L=(l/w)*100
S=(s/w)*100

index= 0.0588 * round(L) - 0.296 * round(S) - 15.8
print("Grade ", round(index))        
