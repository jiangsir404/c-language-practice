#coding:utf-8


num = 12
x = []
count = 0

class PQ:
	def __init__(self,num):
		self.num = num 

	def place(self,row,col):
		if row ==0:
			return True 
		for k in range(row):
			if x[k] == col or x[k] - col == k - row or x[k] - col == row -k:
				return False 
		return True 

	def PlaceQueue(self,row):
		global count
		if row == num:
			# for i in range(num):
			# 	print '<'+str(i+1)+','+str(x[i]+1)+'>',
			# print 
			count += 1
			
		else:
			# print x
			for col in range(num):
				# print col
				if self.place(row,col):
					x[row] = col 
					self.PlaceQueue(row+1)



if __name__ == '__main__':
	for i in range(num+2):
		x.append(-1)
	P = PQ(num)
	P.PlaceQueue(0)
	print count



