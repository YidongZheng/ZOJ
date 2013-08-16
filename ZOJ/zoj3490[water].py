import sys
#sys.stdin=open('in.txt')
def hasalnum(pat):
	pat=pat[::-1]
	for k,ch in enumerate(pat):
		if ch.isalnum():return k
	return -1

def str_addone(pat):
	index=hasalnum(pat)
	pat_len=len(pat)
	if index==-1:
		return pat[:-1]+chr(ord(pat[-1])+1)
	else:
		pat=pat[::-1]
		tmp_leftmost_num=index
		while True:
			if index==pat_len:
				if pat[tmp_leftmost_num].isdigit():
					pat=pat[:tmp_leftmost_num+1]+'1'+pat[tmp_leftmost_num+1:]
				else:
					pat=pat[:tmp_leftmost_num+1]+pat[tmp_leftmost_num]+pat[tmp_leftmost_num+1:]
				return pat[::-1]
			if pat[index].isalnum():
				tmp_leftmost_num=index
				if pat[index]=='Z':
					pat=pat[:index]+'A'+pat[index+1:]
					index+=1
				elif pat[index]=='9':
					pat=pat[:index]+'0'+pat[index+1:]
					index+=1
				elif pat[index]=='z':
					pat=pat[:index]+'a'+pat[index+1:]
					index+=1
				else:
					pat=pat[:index]+chr(ord(pat[index])+1)+pat[index+1:]
					return pat[::-1]
			else:
				index+=1

T=int(sys.stdin.readline().strip())
for i in range(T):
	my_str,n=sys.stdin.readline().strip().split()
	n=int(n)
	for j in range(n):
		my_str=str_addone(my_str)
		print my_str
	print 
