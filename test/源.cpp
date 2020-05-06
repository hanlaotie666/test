import sys
import pdb

tree=input().strip()
sum=0
max_sum=0
index=0
op=None
path=[]
index1,index2,index3=len(tree),len(tree),len(tree)
while(len(tree)>0):
    index1, index2, index3 = len(tree), len(tree), len(tree)
    if '(' in tree:
        index1=tree.index('(')
    if ')' in tree:
        index2=tree.index(')')
    if ',' in tree:
        index3=tree.index(',')
    index = min(index1,index2,index3)
    if index!=0:
        val = int("".join(x for x in tree[:index]))
        if not op:
            sum += val
        else:
            if op == '(':
                sum += val
            elif op == ')':
                sum -= path[-1]
                path.pop(-1)
                sum += val
            elif op == ',':
                sum -= path[-1]
                path.pop(-1)
                sum += val
        path.append(val)
    else:
        sum-=path[-1]
        path.pop(-1)
    if index==index1:
        op='('
    elif index==index2:
        op=')'
    elif index==index3:
        op=','
    if sum<0:
        sum=0
    if max_sum<sum:
        max_sum=sum
    tree=tree[index+1:]
print(max_sum)