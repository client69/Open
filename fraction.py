# Name: Nathan Menezes da Luz


# function to calculate mdc
def mdc(n, m):
        resto = n%m
        while resto != 0:
                n = m
                m = resto
                resto = n % m
        return m


class Fraction:

    '''Define a classe Fraction Ordinária.'''
    # Construtor da classe

    def __init__(self, topo=0, base=1):
        '''Cria uma instância de Fraction.'''
        if base == 0: raise ValueError("Denominador igual a zero")
        xmdc = mdc(topo, base)
        self.num = topo // xmdc   # Simplificação
        self.den = base // xmdc   # da Fraction a ser armazenada
                

    def __add__(self, f2):
        xnum = self.num * f2.den + self.den*f2.num   # a/b + c/d = (ad + cb)/(bd) 
        xden = self.den * f2.den                    
        xmdc = mdc(xnum, xden)                    
        return Fraction(xnum // xmdc, xden // xmdc) #-- Simplificação do resultado
    
    def __sub__(self, f2):
        xnum = self.num * f2.den - self.den*f2.num # a/b - c/d = (ad - cb)/(bd) 
        xden = self.den * f2.den
        xmdc = mdc(xnum, xden)                  
        return Fraction(xnum // xmdc, xden // xmdc)
    
    def __truediv__(self, f2):
        return (self * Fraction(f2.den,f2.num))    #-- Divisão pelo método da "multiplicação pelo inverso"

    def __mul__(self, f2):

        xnum = self.num * f2.num     # a/b * c/d =  ac/bd
        xden = self.den * f2.den
        xmdc = mdc(xnum, xden)
        return Fraction(xnum // xmdc, xden // xmdc)

    def __pow__(self, n):
        
        xnum = int(self.num) ** n         # a/b ** n = (a**n)/(b**n)
        xden = int(self.den) ** n
        xmdc = mdc(xnum, xden)    
        return Fraction(xnum // xmdc, xden // xmdc)

    def __str__(self):
        if self.num == 0: return str(0)
        return str(self.num) + "/" + str(self.den) # método de impressão

    def __eq__(self, f2):
        return ((self.num == f2.num) and (self.den == f2.den))  # a/b == c/d  <=>  a==c e b==d dado mdc(a,b)=1 e mdc(c,d)=1

    def __ne__(self, f2): 
        return not self == f2 

    def __gt__(self, f2):
        return ((self.num * f2.den) > (f2.num * self.den))

    def __lt__(self, f2):
        return ((self.num * f2.den) < (f2.num * self.den))

    def __le__(self, f2):
        return ((self < f2) or (self == f2))

    def __ge__(self, f2):
        return ((self > f2) or (self == f2))
    
    
