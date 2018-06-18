from numpy import *
from numpy.linalg import *

line = raw_input()
line = line.split(' ')
c=int(line[0])
r=int(line[1])
A = []
for i in range(r):
	A.append(raw_input())
	A[i] = A[i].split(' ')
	for j in range(c+1):
		A[i][j] = double(A[i][j])
		
A=asarray(A)
X=A[:,range(len(A[0])-1)]
X2=multiply(X, X)
X3=multiply(X2, X)
X4=multiply(X3, X)
X=concatenate((X, X2, X3),1)
X=concatenate((ones((len(X), 1)), X), 1)
Y=mat(A[:, len(A[0])-1]).T
theta = zeros((len(X[0]), 1))
X=mat(X)
alpha = 0.1
for i in range(4000):
	theta=theta-(multiply(X*theta-Y, X).sum(axis=0)/len(X)*alpha).T

'''
theta = (X.T*X).I * X.T * Y

print mat('1 0.91 0.91')*theta
'''
n = input()
for i in range(n):
	line = raw_input()
	line = line.split(' ')
	for j in range(len(line)):
		line[j] = double(line[j])
	
	line = mat(line)
	line2= multiply(line, line)
	line3= multiply(line2, line)
	line4= multiply(line3, line)
	line = concatenate((line, line2, line3),1)
	line = concatenate((ones((1,1)), line), 1)
	print (line*theta)[0,0]

