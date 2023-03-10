#coding:utf-8
from multiprocessing import Process,Queue
from threading import Thread
import time


num = 8
x = []
count = 0
cols = Queue()
depth = 0



def place(row,col):
	if row ==0:
		return True 
	for k in range(row):
		if x[k] == col or x[k] - col == k - row or x[k] - col == row -k:
			return False 
	return True 

def PlaceQueue(row):
	global count
	global cols
	global depth #递归层数
	depth += 1
	if row == num:
		for i in range(num):
			print '<'+str(i+1)+','+str(x[i]+1)+'>',
		print 
		count += 1
		
	else:
		# print x
		Q = Queue()#递归，每一次递归用一个队列保持状态
		for col in range(num):
			Q.put(col) #给队列初始化所有列
		# print 'depth:',depth
		# if depth== 1:
		# 	Ps = [Process(target=find,args=(Q,row)) for i in range(2)]
		# 	for p in Ps:
		# 		p.start()
		# 	for p in Ps:
		# 		p.join()
		# while True:
		# 	try:
		# 		col = cols.get(True,1)
		# 		print 'cols:',col
		# 		if place():
		# 			x[row] = col 
		# 			PlaceQueue(row+1)
		# 	except:
		# 		break

		for k in range(Q.qsize()):
				col = Q.get()
				# print col
				if place(row,col):
					x[row] = col 
					# print 'row:',row
					PlaceQueue(row+1)


def find(Q,row):
	global cols #用来存储无冲突列
	while(True):
		try:
			col = Q.get(True,1)
		except:
			break
		# print col
		if place(row,col):
			x[row] = col
			# print 'row:',row,'col:',col
			cols.put(col)
			# PlaceQueue(row+1)

if __name__ == '__main__':
	for i in range(num):
		x.append(-1)
	start = time.time()
	PlaceQueue(0)
	print 'the totle count:',count
	# print 'use time:',time.time()-start
	# print 'cols',cols



