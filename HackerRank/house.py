from numpy import *
from numpy.linalg import *

#f=open('house.txt')
#A = f.readlines()
#for i in range(len(A)):
#	A[i] = A[i].split(' ')
#	for j in range(len(A[i])):
#		A[i][j] = double(A[i][j])

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
X=concatenate((ones((len(X), 1)), X), 1)
Y=mat(A[:, len(A[0])-1]).T
theta = zeros((len(X[0]), 1))
X=mat(X)
alpha = 0.1
for i in range(4000):
	theta=theta-(multiply(X*theta-Y, X).sum(axis=0)/len(X)*alpha).T

n = input()
for i in range(n):
	line = raw_input()
	line = line.split(' ')
	for j in range(len(line)):
		line[j] = double(line[j])
	
	line = mat(line)
	line = concatenate((ones((1,1)), line), 1)
	print (line*theta)[0,0]

