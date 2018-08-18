def problem97(c, x, y, z):
    a = pow(x,y,10**z) #returns last z digits of x^y, computed sig more eff than pow(x,y)
    a = (c * a) % 10**z #returns last z digits of c*(x^y)
    a = (a + 1) % 10**z #returns last z digits of 1+c(x^y)
    return a
print problem97(28433, 2, 7830457, 10)
