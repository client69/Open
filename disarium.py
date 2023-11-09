def is_disarium(n):
    n = str(n)
    value = 0
    for i in n:
        power = int(n.index(str(i))) + 1
        value =  value + int(i) ** power
    if value == int(n):
        return True
    return False
