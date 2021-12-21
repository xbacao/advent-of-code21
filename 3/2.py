#!/bin/python

numbers=[]

with open('input') as f:
	lines = f.readlines()

	numbers.append()


	size=len(lines[0][:-1])

	count_1=[0]*size
	total=[0]*size
	most_common=[0]*size
	least_common=[0]*size

	for line in lines:
		i=0
		for c in line:
			if c=='1':
				count_1[i]+=1
			elif c!='0':
				continue
			total[i]+=1
			i+=1

	for i in range(0,size):
		if count_1[i]>total[i]/2:
			most_common[i]=1
			least_common[i]=0
		else:
			most_common[i]=0
			least_common[i]=1

	gamma=0
	epsilon=0
	for i in range(0,size):
		gamma|=(most_common[i])<<size-1-i
		epsilon|=(least_common[i])<<size-1-i
	print(most_common, least_common)
	print(gamma, epsilon, gamma*epsilon)