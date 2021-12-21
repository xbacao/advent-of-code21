#!/bin/python

x=0
y=0
aim=0


with open('input') as f:
	lines = f.readlines()

for l in lines:
	str_splt=l.split(" ")
	dirc=str_splt[0]
	val=int(str_splt[1])

	if dirc == "forward":
		x+=val
		y+=aim*val
	elif dirc == "down":
		#y+=val
		aim+=val
	elif dirc == "up":
		#y-=val
		aim-=val
	else:
		print("ERROR %s"%(str_splt))


print("X:%d Y:%d Aim:%d Res: %u"%(x,y,aim,x*y))