import sys

def num_of_mass(a,b,c):
	set_mass=set()
	for i in range(3):
		lefta=0
		righta=0
		if i==1:lefta+=a
		elif i==2:righta+=a
		for j in range(3):
			leftb=lefta
			rightb=righta
			if j==1:leftb+=b
			elif j==2:rightb+=b
			for k in range(3):
				leftc=leftb
				rightc=rightb
				if k==1:leftc+=c
				elif k==2:rightc+=c
				mass=int(abs(rightc-leftc))
				if mass>0 and mass not in set_mass:
					set_mass.add(mass)
	#print 'PYTHON: ' ,a,b,c,len(set_mass)
	return len(set_mass)

#fin=open('zoj3706_data_2')
#fout=open('out_py.txt','w')
#sys.stdin=fin
T=int(sys.stdin.readline())
COUNT=0
for n in range(T):
	line=sys.stdin.readline()
	a,b=map(int,line.split())
	tmpmax=0
	for i in range(1,a):
		tmpmax=max(tmpmax,num_of_mass(i,a-i,b))
	for i in range(1,b):
		tmpmax=max(tmpmax,num_of_mass(i,b-i,a))
	print tmpmax
	#print COUNT
	#COUNT+=1
