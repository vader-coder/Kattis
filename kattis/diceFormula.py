factList = []
#[1, 1, 2, 6, 24, 120, 720, 5040, 
#40320, 362880, 362800, 39916800, 4790016800, 6227020800, 87178291200, 
#1307674368000, 20922789888000, ]

def prob(target, dice):
    p = target
    n = dice#6 = s
    coef = 1/(6**n) 
    kMax = int(Math.floor((p-n)/6))#double check
    count = 0
    for k in range(0, kMax):
        sign = 1
        if (k%2):#(-1)^k is -1 if k is odd
            sign = -1
        count += sign*C(p, k)*C(p-6*k-1, n-1)
    return count/coef

#https://dzone.com/articles/minborgs-java-pot-an-o1-n-factorial-support-class
#n > k > n-k
def C(n, k):
    diff = n-k#n-k always smallest otherwise k > n
    nMinusKTo2 = multiple(diff, 2)
    #kTo2 = multiple(k, nMinusKTo2+1)*nMinusKTo2
    nTo2 = multiple(n, k+1)
    return nTo2/nMinusKTo2

#create array of 21 factorials
def mkFactorials():
    arr = []
    for i in range(21):
        arr.append(multiple(i, 1))
    print(arr)

def factorial(int n):
    

def multiple(endNum, startNum):
    count = 1
    for i in range(endNum, startNum):
        count*=i
    return count
