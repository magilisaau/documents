  
PYTHONѧϰָ��  
============

```

#��\���Ӷ���
import  sys
a=  1+\
    2+3\
    +4
# ���Ų���\����
b=[1,
   2,
   3,
   4,
   5]
#�ַ������ӣ������źͶ�������ȫһ��
s='123' "456"
s='123'+'456'
#�ַ����±�, -1��ʾ���ұߵ�
#if(s[0]=='1'): pass
assert(s[0]=='1')
#if(s[-1]=='6'): pass
assert(s[-1]=='6')
#��ȡ�ַ���
s='123456'
assert(s[0:3]=='123') #���1������3�����֣�ע���ұߵ�ֵ�Ǵ�1��ʼ������
#print(s[2:5]) #ȡ�������ǡ�345������������5-2�� �����5����ʼ��4����  4:8
assert(s[2:5]=='345')
#����Ҫת����ַ���
#print('12345\n')
print(r'12345\n')

#��ת�ַ���
s1='12345'
s2=s1[-1::-1]
assert(s2=='54321')
#print(s2)

#���뺯��,syspath�鿴path·����������
print('import sys  ���� from sys import path,argv ����import����')
import sys
print(sys.path)
print(sys.argv)

```  
print  
=====  
  
    from sys import path,argv  
    print(path)  
    print(argv)  
    a=input('please input \n')  
    print('input in python3 is str',type(a)) #������������Ǹ��ַ���  
�����C��������������? ��split�ָ, split����ֵΪһ���ַ�����list

```

a=input('input several digit\n') #��python2.x��, input�����������ͷ��أ�������python3.0������ֵ�����ַ���,��������
b=a.split(',') #����ֵ�Ǹ�list
for x in b:
    if x.isdigit():
        print(int(x),end=' ')
    else:
        print(x,'is not a valid number\n')
```  
�ַ���  
=====  
  
1. �ַ���Ϊ���������ܸı�����  
2. python3��input����ķ���ֵΪ�ַ������ͣ������ֽ������룬ʹ��str.split ����re.split+������ʽ���в��  
3. �ַ����ĸ�ʽ��,���ַ�ʽ   
    '%d %x'%(a,b) or   
    f'this is an example{var1} {var2}'  
4. �ַ�����ȡֵ[a:b:step], ��stepΪ1������£�����ȡ���ַ�������Ϊb-a�����stepΪ-1���ʾ�Ӻ���ǰ��ȡ��������  
5. print�Ľ�β�� end=' '��������ʵ�ִ�ӡ�����У�Ĭ��end='\n'  
6. type��isinstance������, type���ϸ����͵ģ�isinstance����Ҳ����Ϊ�Ǹ���  
7. �����/Ĭ�Ϸ��ظ�������//��������, %������������C��������  
8. �������ת���� r'abcde\n'ʵ�ֿ����ַ��������ͬ����u'abcde'��ʾ��unicode��ʽ����

```
# print������
print('�����д�ӡ����',end='.') #�Ծ�Ž�β, ������
print('�˸����1',end='\b')#���˸��β
#print('12345',end='\n') #�൱�ڻ��У����ӵڶ�������

#�����жϣ�type��isinstance, type���ϸ����͵�

print('type(1)==int ?',type(1)==int)   #ע����� int��Ҫ�����ţ��Ǹ�������ͣ������ַ�������(*****************)
print('isinstance(1,int) ?',isinstance(1,int))#ע����� int��Ҫ�����ţ��Ǹ�������ͣ������ַ�������(*****************)

class A:
    pass
class B(A):
    pass
b=B(); #������B��һ��ʵ��
print('isinstance(b,A)',isinstance(b,A))
print('type(b)==A',type(b)==A)

#����
print('1/2=',1/2) #���ص���0.5
print('1//2=',1//2) #���ص���0��  //�൱��C�������/  �� /�൱��C�������1.0/2 С������
print('1%2=',1%2) #ȡ������C��һ���ģ� Ҳ����˵python��  //��%�ֱ�ȡ��������������

```  
�ַ����ָ�  
=========  
  
1. �ַ�����һ�����У�seq�����Դ����ܶຯ��������list(), set()�ȵ�  
2. �ַ����ָ��� str1.split(' '), ������֧��1���ָ��������Ҳ����ã�����'1  2    3'�ÿո���Ϊ�ָ���ʱ���м�᷵�ؿյ�''��������������  
   ����ֵΪlist  
3. ���õķָ���� re��������ʽ�� import re   re.split('[ ]+',str1) ���ַ�ʽ����ƥ�����ո�  
4. �ַ����Ĳ��������� �ִ��� ���ң� �ָ�滻��ɾ����ߵĿո�ɾ���ұߵĿո񣬴�дת����Сдת��  
    �����ִ��� .find(substr,start,stop)  .rfind  
    ɾ���ո� .lstrip() .rstrip() .strip()   
    ��Сд��أ� .upper() .lower() .isupper()  .islower()  
    �ִ����ִ�����.count(substr,start,stop)  
    �Ƿ�Ϊ���֣� .isdigit() .isnumeric() .isdecimal()  
    �Ƿ�ȫΪ�ո� .isspace()  
    �Ƿ�ȫΪ��ĸ  .isalpha()  
5.���շָ����ָ�.patition(), ����һ����Ԫ��tuple, ���� .partion('abc=123'), ����('abc','=','123')  
6. str1.join(seq) ��str1������seq  
7. ������IP��ַ�ָ�  str=128.1.1.2 ��򵥵�����split���list, MAC��ַ��00:10:02:11:03:32 , ��.join����  
8. �ַ�����ʽ��  'hello,%s,you are %d years old'%('liuxb',35) ע���ʽ����һ������print�У����Ժܷ���  
9. �ַ�����ʽpython3.6֮��f-string  f'Today is{year}-{month}-{day}'���ô��ǲ��ٹ�������  
10. .Format�и�ǿ��ĸ�ʽ������

```

year=2020
month=12
day=1
strnew='Today is %.4d-%.2d-%.2d'%(year,month,day)
strnew2=f'Today is {year}-{month}-{day}'
print(strnew)
print(strnew2)

#����1,2,3,4.0,'5'
lst1=[1,2,2,3,4.0,'5']
print('--------------------------------list-----------------------------');
```  
����  
====  
  
1. ���Ԫ�� insert ��index,object)  
2. ɾ��Ԫ�� pop(index)  
3. ɾ��ֵΪx�ĵ�һ��Ԫ�� remove(x)  
4. ��ӵ�ͷ�� insert(0,x)����ע��insert���ڵ�һ��������λ��indexǰ����룬�����Ǻ������  
5. insert(-1,x)��������ӵ�β���ϣ����ǵ�����2��λ��, append(x)ֱ�Ӽӵ�β���ϣ�����append�Ǳ�Ҫ�ĺ������޷���insert����  
6. ɾ����1��/���һ��Ԫ�� pop(0),pop(-1)�� ���pop���Ӳ�����Ĭ��ɾ�����һ��Ԫ��  
7. �������� len(list1)  
8. �ֶ�ɾ�� list1[0:3]=[], ɾ��ǰ3��Ԫ��  
9. �ֶ�ɾ�� del list1[0:3], ɾ��ǰ3��Ԫ��  
10. ���������ƣ���������lsta,lstb, ���lstb=lsta����������ָ��ͬһ��Ԫ�أ��޸�һ����һ��Ҳ�޸ģ�������C++�Ķ�������, ���Ҫ������ʹ��,lstb=lsta.copy()�� �����ƱȽϹ���, ���ڻ�������Number���������������ֵ���ݵġ�  
11. ͳ��Ԫ��������list1.count(x)  
12. �б�ļӷ� a+b �൱�ڰ������б�ϲ�, �����µ��б� �����ԭ�������ϼ���b��ô�죿 ��a.extend(b) b����Ϊ���С�  
13. �б�Ԫ�ز��ң���list1.index(obj) �ҵ���1�������������±�  
14. ����Ԫ�������� list1.reverse()�������Լ���ת���ˣ��ַ�����reverse��? ���� û�У�  
15. ����Ԫ��������ô������ �� list1.sort(key,reverse)����������������1�������ĸ��ֵ����򣬵�2��������(Ĭ��)���ǽ���True  
    �÷�Ϊ lsta.sort(key=sortelem,reverse=True)���������������=��ֵ������ֱ���������why?  
16. ����ֱ�Ӹ�ֵ��Ϊͬһ������ʹ��copy()��ֵ��Ԫ��Ҳ��һ����.

```

print('original list:\t',lst1);
lst=lst1.copy()
#���һ��Ԫ��
lst1.insert(1,9)
print('insert��1,9): \t',lst,lst1)
#ɾ��һ��Ԫ��
lst1=lst.copy()
lst1.pop(1)
print('pop(1): \t\t',lst,lst1);

#ɾ��һ��Ԫ��,ע��ע��ע�⣬����Ĳ�����������������objecy
lst1=lst.copy()
lst1.remove(2)
print('remove(2)\t\t',lst,lst1)

#�����ѵ�2��Ԫ��(index)ɾ����ô���أ�����
lst1=lst.copy()
lst1[1:2]=[]
print('lst1[1:2]=[] \t',lst,lst1)
#׷��
lst1=lst.copy()
lst1.append('abc')
print('append(\'abc\'):\t',lst,lst1)
#ɾ��β��
lst1=lst.copy()
lst1[-1:]=[]  #ע�������:���뱣���������൱�ڸ����һ��Ԫ�ظ�ֵΪ[]
#�ܽ᣺ ɾ��ͷ�� lst1[0:1]=[], ɾ��β��lst1[-1:]=[]
print('lst1[-1:]=[]:\t',lst,lst1)

#����һ����������ɾ������Ԫ�أ�
lst1=[x for x in range(10)]
del lst1[0:2]
print('del lst1[0:2]:\t',lst1)

#��������
lsta=[(3,'e'),(2,'f'),(5,'b'),(4,'c'),(9,'a'),[4,'b']] #����һ����ͬ����Ԫ�ص�����
def sortelem(e):
    return e[1]
print('before sort\t',lsta)
lsta.sort(key=sortelem)
print('after sort\t',lsta)
lsta.sort(key=sortelem,reverse=True)
print('after sort reversed\t',lsta)


#���ϣ����϶����ʱ������ǿռ��ϣ�������a={}����Ϊ��Ĭ���Ǹ��ֵ�Ķ���
set1={1}
set2=set()#����һ���ռ���
print(type(set2))

#���ϵ��ص㣬1.����2.���ظ� 3.���������� 4.����Ϊ����������������ͬ��Ԫ�أ���ӣ�ɾ��
#��Ŀ 1. ͳ��һƪ�����е��ܵ����� 2.ͳ��һƪ�����в��ظ��ĵ���  3. ͳ�����������ظ��ĵ���
```  
����  
====  
  
1. ����û��˳�򣬲�������������  
2. ���ظ�Ԫ�أ�����������������������飬����㲻�ظ���Ԫ�ظ�ʽ,�����ظ���Ԫ�ظ���,�ȵȡ�  
3. ��������Ϊ �������������ǽ�������������ӦC���Ե�λ�������ֱ�Ϊ | & ^ -   
4. �����������һ��Ԫ��, ɾ��һ��Ԫ�أ� add(x) remove(x) ������� update(����)  
5. �ع�һ����������  insert/popΪ������������remove�ǰ�ֵ���������ڼ��϶��ԣ���Ϊû��˳�򣬲����ܰ���������������ʹ�õ���remove��ֵ����ɾ��һ��Ԫ��  
   ͬ���ĵ���delҲ���ʺ�set����  
5.1 ����remove�⣬����һ��discard������������remove���ƣ������Ԫ�ز����ڲ�����  
6. ������ˣ�python����߻���Ϊset�����һ��pop(),û�в��������ɾ��һ��Ԫ�أ�һ��ûʲô���á�  
7. �ܽ���������  add/remove�ǰ�ֵ�����ģ� insert��pop�ǰ����������ģ�delҲ�ǰ�ֵ�����ģ���仰�Ǿ��衣  
8. �κ���������(�ַ�����Ԫ�飬�б��Ϊ��������)�������Գ�ʼ�������ϣ��� set1=set(seq)�����ǳ�ʼ����ʱ�����ģ������ں�����ӣ���update(seq)  
9. �ʣ� ������ͳ��һ��Ԫ�صĸ���count�Ĺ����� ɵð���⣡  
10.���ϳ�ʼ�� s1={1,2,3}, ��������ռ�����s1={}�Ǵ���ģ�����ʵ�ʶ�����һ�����ֵ䣬��������ռ��ϣ�ʹ�ù��캯�� s1=set()  
11.��������,���ϣ��ַ��� ��ʹ�� for x in b, �ֵ���⣬�ֵ�������Ԫ�������� for x,y in b.items()���ַ�ʽ��ע��items()  
12. ������ô���� �� sorted()���������µ��������м��ɣ�listҲ���������ã���list.sort()�Ĳ������һ���ı�����һ�����ı�

```
text='I am a boy, not a girl, right?'
#lst1=text.replace(',','').replace('?','').split(' ')  #�Ȱѱ�����ȥ������ȡ������,  replaceҲ������������֧�ֶ���ָ���
import re
lst1=re.split('[?, ]+',text)
lst1.remove('') #һ���ָ������漴ʹû�����ݣ�Ҳ���һ���մ���������Ҫ������մ�ȥ��
#ͳ�Ƶ��ʵ�����,ȥ�ظ�����ôȥ? �ü���
set1=set(lst1)
wordcnt= len(set1)
print(text,' different word count ',wordcnt)
#�ظ��ĵ�������Щ��
dict1={}
for x in set1:
    dict1[x]=lst1.count(x)
print(dict1)

#���ϵĲ�������C���Ե�λ�����Ĳ�����һ����!&^, �Ϊ- ������~, ����^��A�в���B�л�����B�в���A�У����ڽ����Ĳ���
s1={1,2,3,4,5}
s2={2,3,4,5,6}
print(s1,s2,'����',s1|s2)
print(s1,s2,'����',s1&s2)
print(s1,s2,'�',s1-s2)
print(s1,s2,'����',s1^s2)
#���ϣ����Ԫ�أ�ɾ��Ԫ�أ�����Ԫ��
s1.add('#')
s1.remove('#') #��������ڣ������
s1.pop() #���ɾ��Ԫ��
s1.discard('#') #��������ڣ�������
s1.clear()#��ռ���
s1.update('12345')#����Ƕ�̬�������Ԫ�ص����ϣ������ڳ�ʼ����ʱ���set('12345')

```  
�ֵ�  
=====  
  
1. �ֵ��������, ÿ���ֵ�Ԫ����һ����ֵ�ԣ�key�����ظ�  
2. �ֵ��ʼ�������ַ���(a) d1={'a':1,'b':2},ע�������a��b��Ҫ��str�����������  
    ��2�ַ����ù��캯���� d1=dict(a=1,b=2) ����a��b��Ȼ������Ҫ�����ţ����Ϸ����������������������  
    d1={x:x**2 for x in range(1,2,3)) Ҳ�ǿ��Եģ��������б�ĳ�ʼ�� lst1=[x for x in range(1:100:2)]  
3. �ֵ�Ĳ��������/ɾ��/����/��ȡ���е�keys/��ȡ���е�values  
    ��Ӻ͸��ķ���һ�������������±����d1['a']=1�� ɾ���ô������ģ����Բ���remove����pop/del, d1.pop('a') ,del d1['a']  
    keyΨһ����values��Ψһ����ôͳ��һ��values�����˼����أ� ����ɾ������values�ļ�ֵ���أ�  
4. d1.keys()��������key��d1.values()��������value,����ֵ�������б����ͣ�����dict_keys��dict_values����, ������listת����list���  
   list(d1.keys()), list(d1.values())  
5. �ֵ��key����Ϊ����������list������key��str/tuple/���ֶ�������key  
6. ������һ�����д���һ���ֵ� dict.fromkeys(seq1,value),���Ǹ�ȫ�ֺ�����ʹ�÷���ֵ�����µ��ֵ䣬ȱ��������value��һ�����Ƚ����  
7. �����Լ�дһ���������еĲ��������ڴ���һ���ֵ�,����ȥ����.  
8. ��α����ֵ䣬����������1. �õ����е�keys����һ���ҵ�ֵ����low 2. ��dict.items()����,��������  
    for key,value in d1.items():  
        print(key)  
        print(value)  
9. �ֵ���ô���� �ֵ�û��˳�����Բ���ֱ�Ӹı��ֵ������  
   ��Ҫ�� sorted(dict.items(),key=lambda x:x[1],reverse=True/False)��ʵ�֣�sorted�����µ�����  


```

#�ֵ�,�ֵ��ʼ������ð��
d1={'a':1,'b':2,'c':3}

d2=dict.fromkeys(['s1','s2','s3','s4','s5'],10)
print('dict.fromkeys��[s1,s2,s3,s4,s5],10��',d2)
#����,�ֵ�תlist
lst5=[]
for d,v in d1.items():
    lst5.append(str(d)+':'+str(v))
print('use for d,v in d1.items() �����ֵ�',lst5)

#�������� ��ӣ�ɾ�����г����е�key���г����е�values��key�Ƿ����ֵ���

d1['lala']=9
print('d1[\'lala\']=9\t',d1)
d1.pop('a')
print('d1.pop(\'a\')\t',d1)

del d1['b'] #delҲ����ɾ��Ԫ�أ� ��pop����һ���ģ������ڿ��ܻᱨ��
print('del d1[\'b\']\t',d1)
print('list(d1.keys())\t',list(d1.keys()))
print('list(d1.values())\t',list(d1.values()))


#����ת��
s1='12345'
l1=list(s1) #l1�����['1','2','3','4','5']
#������ת��������, ������s2=str(l1)���õ�����'['1','2','3','4','5']'
#���ַ�����join����
print('������[\'1\',\'2\',\'3\',\'4\',\'5\']ת�����ַ���\'12345\'')
print('.join(list1)��������Ϊ�ַ������б�\t',''.join(l1))

#���������list��
print('������[1,2,3,4,5]ת�����ַ���\'12345\'')
l3=[1,2,3,4,5]
#print(''.join(l3)) #ֻ���ַ���Ԫ�ز������ӣ��������Ͳ�������,����ᱨ��
print(str(l3)[1::3])
s5=''
for x in l3:
    s5+=str(x)
#print(s5)

```  
����  
====  
  
1. �������������/��//��C��һ����, ������ȫ��ͬ  
2. �Ƚ��������C��ȫһ����== != > < >= <=  
3. λ�������C��ȫһ�� & | ~ ^  
4. �߼�������� and or not����Ӧc���Ե� &&,||,~  
5. is����������Ƿ�ָ��ͬһ��Ԫ�أ��ܹ���  
6. math.ceil math.floor math.abs math.max math.min ��ѧ����

```
#is �����������
lsta=[]
lstb=lsta
lstb.append(1)
print('is����������ӣ�lsta is lstb\t',lsta is lstb)

```  
���������  
=========  
  
1. ��random����  
2. random.choice(seq�� ����seq�������һ��Ԫ��  
3. random.random() ����0-1֮������������  
4. random.randrange(start,stop,step)  
5. random.shuffle(seq)���������seq�����ڻ�ı�seq��ֵ�����Բ���������str��tuple  
6. random.uniform(1.1,2.2) 

```

import random
print('randrange 10-20,step 2',end=': ')
for x in range(20):
    print(random.randrange(10,20,2),end='-')
print('\nrandom.choice(\'123456\'):',random.choice('123456'))

```  
��������  
=======  
  
�������� ����ʵ������������һ����_inter_ �� _next_, �Լ�ʵ�� StopIteration ����쳣����  
׼ȷ��˵�����Ƕ���һ�������������Ƕ���һ��֧�ֵ���������(������������)��

```
class ringQueue:
    m_queue:list
    m_size:int
    m_pos:int
    def __init__(self,size:int):
        self.m_size=size
        self.m_queue=[]
        self.m_pos=-1
        #self.m_queue.clear()
    def add(self,e)->bool:
        if(len(self.m_queue)>self.m_size):
            return
        else:
            self.m_queue.append(e)
            return True
    def pop(self):
        if(len(self.m_queue)==0):
            return False
        else:
            return self.m_queue.pop(0)
    def __iter__(self):
        self.m_pos=-1 #������������ʱ����ã�������������ʼ��pos����, ���������posֻ�ܱ�������next�޸�
        return self
    def __next__(self):
        if(len(self.m_queue)==0):
            raise StopIteration
        self.m_pos+=1
        if(self.m_pos>=len(self.m_queue)):
            raise StopIteration
        else:
            return self.m_queue[self.m_pos]

rq=ringQueue(5)
rq.add('1')
rq.add(2)
rq.add([1,2,3,4])
it=iter(rq)
try:
    while True: print(next(it))
except StopIteration:
    print('iteration end')

```  
��������  
=======  
  
1.������������, ��������Ϊֵ���ݣ��ɱ������������ô��ݣ����� a=10  b=a, ��ʱa is b�� ����b=20��a is not b  
2.ʵ���ϣ����ܶ�ʲô��python�Ĵ���ʽΪ���������ݾ�Ϊ���ô��ݣ�������c��ͬ���ǣ���������/Ԫ��/�ַ�������ʹ���ô���ȥ��Ҳ�ǲ��ܸı�ģ���˲��ܺ�����ô�ӹ���  
  �������ܸı������ֵ�� �����ڿɱ����� list/dict/set���֣�����ȥ���ǿ��Ըı�ģ���������Ҳ���Ÿ��ˡ� �������ľ���copy��  
  �� a=10, b=a,��ʱb��aʵ����id��һ���ģ���b=a+1����b��id�ͱ仯�ˣ�Ҳ����˵ֻ��b��ֵ�����仯����b����һ���µĶ���  
3. ��������lambda,  lambda ����1������2������3: ���ʽ����,ֻ��дһ��  
4. ������������أ�Ĭ�Ϸ���None, ʵ����һ�������ķ���ֵ�����ǲ�ͬ��֧��ͬ���ͣ���һ������.  
5. �������β�=xxx�����ú�������ʱ����˳������붨��Ĳ�һ�£����� addperson(name='lxb',ag=2)  
6. �����ı߳���������, �������ǰ���һ��*����ʾ�Ǳ�Σ�����tuple����ʽ�������������** �����ֵ���ʽ������  
7. ������Һ�������  �� dir(����) �Ϳ�����ʾһ�����е����з��ţ�̫������, ���Ҫ��ʾ�����÷��ã�help(list)�鿴����help(list.sort)

```
a=10; b=a; assert id(a)==id(b)
b=10;      assert id(a)==id(b)
b=20;      assert id(a)!=id(b)
a=10; print('id-a',id(a)); a=a+1; print('id-a',id(a)) #����a��ֵ�����仯��idҲ�����˱仯
str1='a'; str2=str1; assert id(str1)==id(str2)
def fun1(str):
    print(id(str))
    str='123'  #�������¸�ֵ��strָ�����˱仯
    print(id(str))
strr='lalala'
print(id(strr))
fun1(strr)
print('')
def fun2(lst:list):
    print(id(lst))
    lst=[2,3,4,5]  #�������¸�ֵ��lstָ��Ҳ�����˱仯
    print(id(lst))
lst=[1]
print(id(lst))
fun2(lst)
print(lst)
#���
import math
def averge(*para):
    return math.fsum(iter(para))/len(para)
print(averge(1,2,3,4,5,6))
#�ֵ������
def addstudent(**para):
    print(para)
addstudent(name='liuxb',age=20,job='IT')

#���ݽṹ, ���������reversed�����������ı�ԭ��������
lst1=[1,3,2,4,5]
for x in reversed(lst1):
    print(x,end=' ')
#����밴˳���������sorted�������ı�ԭ����˳��
for x in sorted(lst1):
    print(x,end=' ')
#�ֵ�ͼ�����ô����?
set1={1,4,3,2,6}
for x in sorted(set1,reverse=True):
    print(x,end=' ')
dic1=dict(a=1,c=3,b=2,f=5,e=9)
print(dic1)
for x,y in sorted(dic1.items(),key=lambda e: e[1]): #����ʹ������������ʵ�������㷨
    print(x,y,end=' ')
print('')
#��������ͬʱ��������zip�� Ҫ�������ͬ����
for x,y in zip(lst1,set1):
    print(x,y)

```  
�б��Ƶ�ʽ,�����ǣ���������  
========================  
  
�����﷨�ǣ� x for x in A if , ����if����ȥ��  
���磺  
    a=[1,2,3,4,5]  
    b=[x*2 for x in a if x>3]  
    c={x:x2 for x in range(1,10,2)} �����ֵ�  
��������˫��ѭ������  
    A=[1,2,3,4,5]  
    B=['a','b','c','d','e']  
    c={x:y for x in A for y in B}

```
A=[1,2,3,4,5]
B=['a','b','c','d','e']
c={x:y for x in A for y in B}
print(c)

#����ת��

matrix_a=[
    [1,2,3,4],
    [5,6,7,8],
    [9,10,11,12],
    [13,14,15,16]
]

# 03 13 23 33,
# 02 12 22 32,
# 01 11 21 31,
# 00 10 20 30

b=[[matrix_a[x][y] for x in range(4)] for y in range(3,-1,-1)]
print(b)
#������ȡһ��Ԫ��row����ȡrow���������row[i]
bb=[[row[i] for row in matrix_a] for i in range(3,-1,-1)]  #��������forʵ������˫��ѭ��
print(bb)

```  
open(�ļ���,������),���õ���   
==========================  
  
    r+/rb+ ��һ���ļ���д��ָ��ſ�ͷ  
    [w+/wb+ ��һ���ļ���д��ָ��ſ�ͷ, �����ھʹ���������Ҳ�൱�����´��������ݶ���������]  
    a+/ab+ �򿪶�д��ָ���β�ͣ������ھʹ���  
    ����b��ʱ��ֱ��д�ַ���  
    ��b��ʱ��ֱ��д���������д�ַ������� b'12345' ������ʽ, b'\x65\x12'ֱ�Ӷ��������  
    ��������ר�ŵ��� Num.py �Լ�structģ��  
    os.acces ̽���ļ��Ƿ���ڣ��Ƿ�ɶ����Ƿ��д���Ƿ��ִ��  
    os.listdir �г�Ŀ¼�µ��ļ�  
    os.path.isfile �ж��Ƿ����ļ��������ļ���  
    os.walk �����ļ���  
    os.path.join ����Ŀ¼���ļ�������·��  
        

```
try:
    f=open('file1','rb+') #�ļ������ڻᱨ��
    print(f)
except:
    print('file not exist')

f=open('file_wb+','wb+')  #�ļ������ڻᴴ��
f.write(b'123456')
f.write(b'\x34')
f.close()
f=open('file_wb+','wb+')#ʹ���ļ��ٴδ򿪺���������ݾ�Ȼû�ˣ���������
```  
readdata=f.read(7)  
print(readdata)  
ddata=readdata.decode()  
print(ddata)

```
f.close()

f=open('file_w+','w+') #�ļ������ڻᴴ��
f.write('123456')
f.close()

f=open('wr_test.txt','w+')
f.write('123\n456\n789\n')
f.writelines(['123\n','456\n','789\n']) #writelines��Ҫ�Լ��ӻ��з���ûʲô�ã�����ֱ����writeȡ��
f.seek(0,0)
print(f.readlines())
f.close()
#������һ�����ƵĴ���
```  
д���ļ�����  
------------------------------------------------  
  
    1. �ж��ļ��ڲ��ڣ����ڣ��������ڣ���  
    2. �ж��Ƿ�����޸�Ȩ�ޣ�û�У���ӡ�����У�����  
    3. д�ļ����ر�

```
import os
def wrtest(filename:str):
    if not os.access(filename,os.F_OK):
        try:
            f=open(filename,'w')
            f.close()
        except OSError:
            print(f'create file {filename} failed')
            sys.exit()
    if not os.access(filename,os.W_OK):
        print('no permission to write ')
        sys.exit()
    else:
        f=open(filename,'a+')
        f.write("success to write")
        f.close()
wrtest('wrtest.txt')

files=os.listdir() #ֻ��ʾ�ļ�������ʾ��Ŀ¼
for x in files:
    if os.path.isfile(x):
        print(x)
```  
�����ļ��У�ֻ�г��ļ�, ��walk

```
for root,dir,files in os.walk('.'):
    for f in files:
        if(len(files)!=0):
            print(os.path.join(root,f))

try:
    file = open("file_w+")
    try:
        for aline in file:
            print(aline)
    except Exception as error:
        print(error)
    finally:
        file.close()
except FileNotFoundError as err:
    print(err)

try:
    file = open("dfsddsf")
    for aline in file:
        print(aline)
    file.close()
except Exception as err:
    print(err)

```  
with...as  
=========  
  
���openʧ�ܻ᷵���쳣�� ���writeʧ��Ҳ�����쳣��ʹ��with...as�󲻱���ʽ�ر��ļ��ʹ��ļ����쳣��ʡ�˺ܶ���  
ԭ��: with func as obj   
----------------------   
��һ����obj=func().__enter()__   
�ڶ�������obj���κβ��������쳣��ʱ��,����obj.__exit()__  
�������������,   
1. file=open().__enter__(), open�����������һ��file��Ԥ������__enter__()�����Լ�,    
2. ��file�����ڽ���ʱ����file.__enter__(),    
3. ���쳣ʱ���� file.__exit__(), �ļ���close��������__exit__()��  
   ��ô�����쳣ʱ�����__exit()__�� ��������û�йر�file, ������һ�£����Խ������with as�����ִ�н���ʱ�������__exit__  
4. with as���ڳɶԵĲ����������/�ر�  lock/unlock  ���ݿ����/�ع�������  
5. ʵ�ʲ��Ա�������ʹ�����쳣������__exit__, �����������__del__��Ȼ����������, ����ڹر���Դ��ʱ�򣬲�Ҫ�ظ�����  
    with as ��ԭ�� https://blog.csdn.net/weixin_33921089/article/details/91454127?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task  
    try:  
    with open('file_w+','r+') as file:  
        file.write('hello,baby!')  
    except Exception as err:  
    print('line:',sys._getframe().f_lineno,err)

```
try:
    with open('file_w+','r+') as file:
        file.write('hello,baby!')
except Exception as err:
    print('line:',sys._getframe().f_lineno,err)

class myClass():
    def __enter__(self):
        print('__enter__ called')
        return self
    def __exit__(self, exc_type, exc_val, exc_tb):
        print('__exit__ called')
    def mockExcept(self):
        1/0
    def ok(self):
        pass
    def __del__(self):
        print('__del__ called')
def myopen():
        return myClass()
try:
    with myopen() as testmc:
        testmc.mockExcept()
except Exception as err:
    print(err)
print('example 1 end')
with myopen() as testmc2:
    print('here 000')
    testmc2.ok()
    print('here 001')
    testmc2.ok()
    print('here 002')  #ʵ�ʲ��ԣ���with....as ��������ʱ�������__exit__
```  
    �Զ����쳣�����Զ�����쳣�̳� Exception

```
class MyException(Exception):
    def __init__(self):
        pass
    def __str__(self):
        return 'except by myself!'
try:
    raise MyException
except MyException as err:
    print(err) #�������ʾ except by myself

```  
�ڲ�����(builtins)  
============================================  
  
1.���˽�б�����2���»��ߣ�˽�з���Ҳһ��  
2.���ڲ�ʹ�������ʱ��һ�ɼ� self.ǰ׺  
���ר�з���  
  
    __init__ :  ���캯���������ɶ���ʱ����  
    __del__ :   �����������ͷŶ���ʱʹ��  
    __repr__ :  ��ӡ��ת��  ��Ӧprint  
    __setitem__ : ����������ֵ  
    __getitem__: ����������ȡֵ  
    __len__:    ��ó���    ��Ӧ len(class)  
    __cmp__:    �Ƚ�����    ��Ӧ(>,<,=,!=�ıȽ�)  
    __call__:   ��������     
    __add__:    ������      ��Ӧ+����  
    __sub__:    ������      -  
    __mul__:    ������      *  
    __truediv__: ������  /  
    __mod__:    ��������    %  
    __pow__:    �˷�       **  
      
3. ֱ�Ӷ��������еı����� ����������Ƕ��������ͬ��û��self�ĺ������ຯ��

```
class myNumber:
    __mem:int
    def get(self):
        return self.__mem
    def __init__(self,a:int):
        self.__mem=a
    def __repr__(self):
        return f"myNumber[{self.__mem}]"
    def __add__(self, other):
        return myNumber(self.get()+other.get())
    def __len__(self):
        return self.__mem

c1=myNumber(5)
c2=myNumber(10)
print(c1)
print(c1+c2)
print (len(c1),len(c2))

```  
�����ռ�namespace  
==================  
  
built-in namespace  
global namespace  
local namespace  
python����˳��Ϊ�� local namespace->global namespace->built-in namespace�����Կ���ʹ����ͬ������  
  
������ scope  
--------------  
L��Local�������ڲ㣬�����ֲ�����������һ������/�����ڲ���  
E��Enclosing���������˷Ǿֲ�(non-local)Ҳ��ȫ��(non-global)�ı�������������Ƕ�׺�����һ�����������ࣩ A �����ְ�����һ������ B ����ô���� B �е�������˵ A �е��������Ϊ nonlocal��  
G��Global������ǰ�ű�������㣬���統ǰģ���ȫ�ֱ�����  
B��Built-in���� �������ڽ��ı���/�ؼ��ֵȡ����������  
Python ��ֻ��ģ�飨module�����ࣨclass���Լ�������def��lambda���Ż������µ������������Ĵ���飨�� if/elif/else/��try/except��for/while�ȣ��ǲ��������µ�������ģ�Ҳ����˵��Щ����ڶ���ı������ⲿҲ���Է��ʣ����´��룺  
    >>> if True:  
    ...  msg = 'I am from Runoob'  
    ...   
    >>> msg  
    'I am from Runoob'  
    >>> 

```
# �����ռ����
Exception=Exception('hello,world')
print(Exception)

liuxb='magi'
def test():
    liuxb='hello'
    print(liuxb)
print(liuxb)
test()
#�������� liuxb��һ����һ���ڲ���һ���ⲿ, �����ָ���ⲿ������ô�죿 ��global����һ��

liuxb='magi'
def test():
    global liuxb
    liuxb='hello'
    print(liuxb)
test()
print(liuxb)

```  
������ʽ  


```
import re
print(re.match('www', 'www.runoob.www'))  # ����ʼλ��ƥ��
print(re.match('com', 'www.runoob.com'))  # ������ʼλ��ƥ��
print(re.split('[\W]+',',dogs , are not cats,')) #�������""
print(re.split('[\W]+',' dogs , are not cats '.strip(' ')) )#�������""

tl=[1,1,2,2,2,3,3,3,3,3,4,4,4,4,5,5,5,5,5,6,6]
print(str(tl))
import re
#���Ϊ'1,1' '2,2,2'  '3,3,3,3,3'  '4,4,4,4' '5,5,5,5,5' '6,6' ÿ�η��ص���ƥ����ַ��������Կ���iter�����ķ�����Ϣ
obj=re.finditer(r'(\d+)(,\s\1)*',str(tl))
for x in obj:
    print(x)

#���Ϊ['1','2','3','4','5','6'],���Կ���findall�᷵�ط����е����ݣ����ڷ����в�����
match=re.findall(r'(\d+)(?:,\s\1)*',str(tl))
print(match)

```  
������ʽ����(regular pattern)  
==============================  
  
^   ƥ���п�ͷ  
$   ƥ���н�β  
\d  ƥ��һ������  
\w  ƥ��һ�����ֻ���ĸ�������»��ߣ���������ƥ��ؼ��֣�����������  
\D  �����֣���ͬ��[^0-9]  
\W  ������,����ĸ,���»���,��ͬ��[^0-9a-zA-Z_]  
\s  ƥ��һ���ո�/TAB��/�˸���ȷǿɼ��ַ�  
\S  ƥ��ǿհ��ַ�  
.   ƥ��1�������ַ�  
.*  ƥ���������ַ�  
.*? ��̰��ģʽƥ�����ⳤ���ַ������� "123��456��789"   
              ��.*ƥ��ȫ��   
              *?ƥ��ÿһ���ַ�   
              .*,ƥ�� 123,456    
              .*?,ƥ��123 �� 456  
\b ƥ�䵥�ʱ߽磬���� \b\w+\b ƥ��һ������, \b\S+\b ƥ�䵥��(�������ݿ���Ϊ�����ַ�&^^%)  
{n,m} ƥ����Сn�Σ����m��  
�����ǰ������ (��һ��)\1 �����\1��ʾ���õ�1������ݣ������� 10 10 10 10 20 20 20 20���ְ�10 10 10 10һ������ȡ����  
  
1. match �� search������match����, match�����group(0)��ʾ��ȫƥ������ݣ�group(1)��ʾ��1������,group(2)��ʾ��2������  
2. match��search����ֻƥ��һ�Σ��ҵ�һ��ƥ��ľ�ֹͣ  
3. matchֻ��ͷƥ�䣬��search���Դ��м�ƥ��  
4. findall���ص���һ��list��ÿ��Ԫ����һ��str��������ڷ��飬��ÿ��Ը����һ��tuple(group1,group2)  
5. finditer���ص���һ��iter, ʲô��iter�� match��iter��match�ṹ������group  
6. ֻ��findall��ָ���ط�������ݣ�û�з�����Ƿ�������ƥ�������������;�ڷ�����  
7. �������Ҫ���飬����Ҫƥ�����ʹ��finditer������ǹ�����ǿ���  
8. findall�ĺô��ǣ��㲻�ù��ķ������ˣ������ŵ�list��tuple����(����ж������Ļ�)  
9. ������ʽ���ȷ������ɣ�д�����ɣ���ת����pattern  
|���η�|����  
|re.I|ʹƥ��Դ�Сд������|  
|re.L|�����ػ�ʶ��locale-aware��ƥ��|  
|re.M|����ƥ�䣬Ӱ�� ^ �� $|  
|re.S|ʹ . ƥ������������ڵ������ַ�|  
|re.U|����Unicode�ַ��������ַ��������־Ӱ�� \w, \W, \b, \B.|  
|re.X|��־ͨ������������ĸ�ʽ�Ա��㽫������ʽд�ø�������⡣|

```
mt=re.match('\d{2}','12345')
print(mt.group()) #���ص��� ��12��
mt=re.search('\d{2}','12345')
print(mt.group())#���ص�Ҳ�ǡ�12��
mlst=re.findall('\d{2}','12345')
print(mlst) #���ص���['12','34']
#finditer�ķ���ֵ�Ǹ�iter��ÿ��Ԫ�ض���һ��match����group()����ȡ����
mit=re.finditer('\d{2}','12345')
for x in mit: print(x.group()) #����ֵΪ  ��12��  �� ��34��
```  
������Ĳ���  
===========  
  
    mt=re.match(r'(\d{2}),'12345')  
    print(mt.group()) #���ص��� ��12��  
    mt=re.search('\d{2}','12345')  
    print(mt.group())#���ص�Ҳ�ǡ�12��  
    mlst=re.findall('\d{2}','12345')  
    print(mlst) #���ص���['12','34']  
    #finditer�ķ���ֵ�Ǹ�iter��ÿ��Ԫ�ض���һ��match����group()����ȡ����  
    mit=re.finditer('\d{2}','12345')  
    for x in mit: print(x.group()) #����ֵΪ  ��12��  �� ��34��

```
mt=re.match(r'5(\d{2})','54321')
print(mt.group()) #���ﷵ�ص���543
print(mt.group(1)) #���ﷵ�ص���43

mt=re.search(r'5(\d{2})','54321')
print(mt.group()) #���ﷵ�ص���543
print(mt.group(1)) #���ﷵ�ص���43

mlst=re.findall(r'5(\d{2}(\d))','54321')
print(mlst) #���ﷵ�ص��� [('432','2')]

mlst=re.findall(r'\d{2}','54321')#û�з�������
print(mlst) #���ﷵ�ص��� ['54',32']

mit=re.finditer('5(\d)(\d)','54321')
for x in mit:
    print(x.group()) #543
    print(x.group(1)) #4
    print(x.group(2)) #3
```  
with open  
=========  
with open('fuxi.py','r',encoding='utf_8') as fl:  
    fl.seek(0,2)  
    len=fl.tell()  
    fl.seek(0,0)  
    content=fl.read(len)  
    fl.close()  
    note=re.finditer('\'{3}([\s\S]+?)\'{3}',content,re.S)  
    with open('pyreview.md','w+') as fl:  
        for x in note:  
            fl.writelines(x.group(1).replace('\n','  \n'))

```
with open('fuxi.py','r',encoding='utf_8') as fl:

    abc='''
    aaa
    '''
    fl.seek(0,2)
    len=fl.tell()
    fl.seek(0,0)
    content=fl.read(len)
    fl.close()
    #  \'\'\'((?:[\s\S](?!\'\'\'))+)\n*\'\'\'((?:[\s\S](?!\'\'\'))+)
    note=re.finditer("'''((?:[\s\S](?!(?<=\n)'''))+)\n*'''((?:[\s\S](?!(?<=\n)'''))+)",content)
    with open('pyreview.md','w+') as fl:
        for x in note:
            if(x.group(1)):
                fl.writelines(x.group(1).replace('\n','  \n'))
                fl.write('\n')
            if(x.group(2)):
                fl.writelines('\n```')
                fl.writelines(x.group(2))
                fl.write('\n')
                fl.writelines('```')


```