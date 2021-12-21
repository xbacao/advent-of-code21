#!/bin/python

x=0
y=0


with open('input') as f:
	lines = f.readlines()

for l in lines:
	str_splt=l.split(" ")

	if str_splt[0] == "forward":
		x+=int(str_splt[1])
	elif str_splt[0] == "down":
		y+=int(str_splt[1])
	elif str_splt[0] == "up":
		y-=int(str_splt[1])
	else:
		print("ERROR %s"%(str_splt))


print("Res: %u"%(x*y))