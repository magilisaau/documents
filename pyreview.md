  
PYTHON学习指南  
============

```

#用\连接多行
import  sys
a=  1+\
    2+3\
    +4
# 括号不用\连接
b=[1,
   2,
   3,
   4,
   5]
#字符串连接，单引号和多引号完全一样
s='123' "456"
s='123'+'456'
#字符串下标, -1表示最右边的
#if(s[0]=='1'): pass
assert(s[0]=='1')
#if(s[-1]=='6'): pass
assert(s[-1]=='6')
#抽取字符串
s='123456'
assert(s[0:3]=='123') #抽第1个到第3个数字，注意右边的值是从1开始数的数
#print(s[2:5]) #取出来的是‘345’，个数就是5-2， 例如第5个开始的4个数  4:8
assert(s[2:5]=='345')
#不需要转义的字符串
#print('12345\n')
print(r'12345\n')

#翻转字符串
s1='12345'
s2=s1[-1::-1]
assert(s2=='54321')
#print(s2)

#导入函数,syspath查看path路径，很有用
print('import sys  或者 from sys import path,argv 两种import方法')
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
    print('input in python3 is str',type(a)) #这里输入的总是个字符串  
如何像C语言输入多个参数? 用split分割开, split返回值为一个字符串的list

```

a=input('input several digit\n') #在python2.x里, input根据输入类型返回，但到了python3.0，返回值成了字符串,并不兼容
b=a.split(',') #返回值是个list
for x in b:
    if x.isdigit():
        print(int(x),end=' ')
    else:
        print(x,'is not a valid number\n')
```  
字符串  
=====  
  
1. 字符串为常量，不能改变内容  
2. python3中input输入的返回值为字符串类型，如果想分解多个输入，使用str.split 或者re.split+正则表达式进行拆分  
3. 字符串的格式化,两种方式   
    '%d %x'%(a,b) or   
    f'this is an example{var1} {var2}'  
4. 字符串的取值[a:b:step], 在step为1的情况下，所截取的字符串长度为b-a，如果step为-1则表示从后往前截取，即逆序  
5. print的结尾用 end=' '参数可以实现打印不换行，默认end='\n'  
6. type和isinstance的区别, type是严格类型的，isinstance子类也被认为是父类  
7. 运算符/默认返回浮点数，//返回整数, %返回余数，跟C略有区别  
8. 如果不想转义用 r'abcde\n'实现控制字符的输出，同理用u'abcde'表示用unicode格式编码

```
# print不换行
print('不换行打印测试',end='.') #以句号结尾, 不换行
print('退格测试1',end='\b')#以退格结尾
#print('12345',end='\n') #相当于换行，不加第二个参数

#类型判断，type和isinstance, type是严格类型的

print('type(1)==int ?',type(1)==int)   #注意这的 int不要加引号，是个类的类型，不是字符串类型(*****************)
print('isinstance(1,int) ?',isinstance(1,int))#注意这的 int不要加引号，是个类的类型，不是字符串类型(*****************)

class A:
    pass
class B(A):
    pass
b=B(); #创建类B的一个实例
print('isinstance(b,A)',isinstance(b,A))
print('type(b)==A',type(b)==A)

#除法
print('1/2=',1/2) #返回的是0.5
print('1//2=',1//2) #返回的是0，  //相当于C语言里的/  ， /相当于C语言里的1.0/2 小数整除
print('1%2=',1%2) #取余数跟C是一样的， 也就是说python里  //和%分别取整数和余数部分

```  
字符串分割  
=========  
  
1. 字符串是一个序列，seq，可以传给很多函数，比如list(), set()等等  
2. 字符串分割用 str1.split(' '), 但仅仅支持1个分隔符，并且不好用，比如'1  2    3'用空格作为分隔符时，中间会返回空的''，并不是期望的  
   返回值为list  
3. 更好的分割方法是 re，正则表达式的 import re   re.split('[ ]+',str1) 这种方式可以匹配多个空格  
4. 字符串的操作包括， 字串， 查找， 分割，替换，删除左边的空格，删除右边的空格，大写转换，小写转换  
    查找字串： .find(substr,start,stop)  .rfind  
    删除空格： .lstrip() .rstrip() .strip()   
    大小写相关： .upper() .lower() .isupper()  .islower()  
    字串出现次数：.count(substr,start,stop)  
    是否为数字： .isdigit() .isnumeric() .isdecimal()  
    是否全为空格 .isspace()  
    是否全为字母  .isalpha()  
5.按照分隔符分割.patition(), 返回一个三元素tuple, 例如 .partion('abc=123'), 返回('abc','=','123')  
6. str1.join(seq) 用str1来连接seq  
7. 案例：IP地址分割  str=128.1.1.2 最简单的是用split变成list, MAC地址：00:10:02:11:03:32 , 用.join生成  
8. 字符串格式化  'hello,%s,you are %d years old'%('liuxb',35) 注意格式化不一定用在print中，所以很方便  
9. 字符串格式python3.6之后f-string  f'Today is{year}-{month}-{day}'，好处是不再关心类型  
10. .Format有更强大的格式化功能

```

year=2020
month=12
day=1
strnew='Today is %.4d-%.2d-%.2d'%(year,month,day)
strnew2=f'Today is {year}-{month}-{day}'
print(strnew)
print(strnew2)

#链表1,2,3,4.0,'5'
lst1=[1,2,2,3,4.0,'5']
print('--------------------------------list-----------------------------');
```  
链表  
====  
  
1. 添加元素 insert （index,object)  
2. 删除元素 pop(index)  
3. 删除值为x的第一个元素 remove(x)  
4. 添加到头上 insert(0,x)，请注意insert是在第一个参数的位置index前面插入，而不是后面插入  
5. insert(-1,x)并不是添加到尾巴上，而是倒数第2个位置, append(x)直接加到尾巴上，所以append是必要的函数，无法用insert代替  
6. 删除第1个/最后一个元素 pop(0),pop(-1)， 如果pop不加参数，默认删除最后一个元素  
7. 求链表长度 len(list1)  
8. 分段删除 list1[0:3]=[], 删除前3个元素  
9. 分段删除 del list1[0:3], 删除前3个元素  
10. 关于链表复制，定义链表lsta,lstb, 如果lstb=lsta，两个对象指向同一个元素，修改一个另一个也修改，类似与C++的对象引用, 如果要拷贝则使用,lstb=lsta.copy()， 这个设计比较诡异, 对于基本类型Number，这个不成立，是值传递的。  
11. 统计元素数量，list1.count(x)  
12. 列表的加法 a+b 相当于把两个列表合并, 创建新的列表； 如果在原来基础上加上b怎么办？ 用a.extend(b) b可以为序列。  
13. 列表元素查找，用list1.index(obj) 找到第1个符合条件的下标  
14. 链表元素逆序用 list1.reverse()，不用自己再转换了，字符串有reverse吗? 答案是 没有！  
15. 链表元素排序怎么操作？ 用 list1.sort(key,reverse)，有两个参数，第1个是用哪个字典排序，第2个是升序(默认)还是降序True  
    用法为 lsta.sort(key=sortelem,reverse=True)，迭代对象必需用=赋值，不能直接填参数，why?  
16. 链表直接赋值则为同一个对象，使用copy()赋值，元组也是一样的.

```

print('original list:\t',lst1);
lst=lst1.copy()
#添加一个元素
lst1.insert(1,9)
print('insert（1,9): \t',lst,lst1)
#删除一个元素
lst1=lst.copy()
lst1.pop(1)
print('pop(1): \t\t',lst,lst1);

#删除一个元素,注意注意注意，这里的参数不如索引，而是objecy
lst1=lst.copy()
lst1.remove(2)
print('remove(2)\t\t',lst,lst1)

#如果想把第2个元素(index)删除怎么办呢，答案是
lst1=lst.copy()
lst1[1:2]=[]
print('lst1[1:2]=[] \t',lst,lst1)
#追加
lst1=lst.copy()
lst1.append('abc')
print('append(\'abc\'):\t',lst,lst1)
#删除尾巴
lst1=lst.copy()
lst1[-1:]=[]  #注意这里的:必须保留，否则相当于给最后一个元素赋值为[]
#总结： 删除头用 lst1[0:1]=[], 删除尾用lst1[-1:]=[]
print('lst1[-1:]=[]:\t',lst,lst1)

#还有一个方法可以删除几个元素，
lst1=[x for x in range(10)]
del lst1[0:2]
print('del lst1[0:2]:\t',lst1)

#链表排序
lsta=[(3,'e'),(2,'f'),(5,'b'),(4,'c'),(9,'a'),[4,'b']] #定义一个不同类型元素的链表
def sortelem(e):
    return e[1]
print('before sort\t',lsta)
lsta.sort(key=sortelem)
print('after sort\t',lsta)
lsta.sort(key=sortelem,reverse=True)
print('after sort reversed\t',lsta)


#集合，集合定义的时候，如果是空集合，不用用a={}，因为这默认是个字典的定义
set1={1}
set2=set()#定义一个空集合
print(type(set2))

#集合的特点，1.无序，2.无重复 3.不能用索引 4.操作为交集，并集，求不相同的元素，添加，删除
#题目 1. 统计一篇文章中的总的字数 2.统计一篇文章中不重复的单词  3. 统计文章中有重复的单词
```  
集合  
====  
  
1. 集合没有顺序，不能用索引访问  
2. 无重复元素，可以利用这个规则做点事情，如计算不重复的元素格式,计算重复的元素个数,等等。  
3. 基本操作为 并集，交集，非交集，减集，对应C语言的位操作，分别为 | & ^ -   
4. 基本操作添加一个元素, 删除一个元素， add(x) remove(x) 批量添加 update(序列)  
5. 回顾一下链表的设计  insert/pop为按索引操作，remove是按值操作，对于集合而言，因为没有顺序，不可能按照索引操作，故使用的是remove按值操作删除一个元素  
   同样的道理，del也不适合set操作  
5.1 除了remove外，还有一个discard操作，功能与remove类似，但如果元素不存在不报错。  
6. 尽管如此，python设计者还是为set设计了一个pop(),没有参数，随机删除一个元素，一般没什么鸟用。  
7. 总结下来就是  add/remove是按值操作的， insert和pop是按索引操作的，del也是按值操作的，这句话是精髓。  
8. 任何有序序列(字符串，元组，列表称为有序序列)，都可以初始化给集合，即 set1=set(seq)，这是初始化的时候做的，假如在后面添加，用update(seq)  
9. 问？ 集合有统计一个元素的个数count的功能吗？ 傻冒问题！  
10.集合初始化 s1={1,2,3}, 但是如果空集合用s1={}是错误的，这里实际定义了一个空字典，怎样定义空集合，使用构造函数 s1=set()  
11.遍历链表,集合，字符串 都使用 for x in b, 字典除外，字典是两个元素所以用 for x,y in b.items()这种方式，注意items()  
12. 集合怎么排序？ 用 sorted()函数生成新的排序序列即可，list也可以这样用，跟list.sort()的差别在于一个改变自身，一个不改变

```
text='I am a boy, not a girl, right?'
#lst1=text.replace(',','').replace('?','').split(' ')  #先把标点符号去掉，提取出单词,  replace也可以用正则表达支持多个分隔符
import re
lst1=re.split('[?, ]+',text)
lst1.remove('') #一个分隔符后面即使没有内容，也会多一个空串，所以需要把这个空串去掉
#统计单词的数量,去重复，怎么去? 用集合
set1=set(lst1)
wordcnt= len(set1)
print(text,' different word count ',wordcnt)
#重复的单词是那些？
dict1={}
for x in set1:
    dict1[x]=lst1.count(x)
print(dict1)

#集合的操作，跟C语言的位操作的操作符一样，!&^, 差集为- 而不是~, 其中^在A中不在B中或者在B中不在A中，等于交集的补集
s1={1,2,3,4,5}
s2={2,3,4,5,6}
print(s1,s2,'并集',s1|s2)
print(s1,s2,'交集',s1&s2)
print(s1,s2,'差集',s1-s2)
print(s1,s2,'补集',s1^s2)
#集合，添加元素，删除元素，查找元素
s1.add('#')
s1.remove('#') #如果不存在，则出错
s1.pop() #随机删除元素
s1.discard('#') #如果不存在，不出错
s1.clear()#清空集合
s1.update('12345')#这个是动态添加序列元素到集合，类似于初始化的时候的set('12345')

```  
字典  
=====  
  
1. 字典是无序的, 每个字典元素是一个键值对，key不能重复  
2. 字典初始化的两种方法(a) d1={'a':1,'b':2},注意里面的a和b都要用str，必须加引号  
    第2种方法用构造函数， d1=dict(a=1,b=2) 这里a和b竟然都不需要加引号，加上反而出错，语言设计令人困惑  
    d1={x:x**2 for x in range(1,2,3)) 也是可以的，类似于列表的初始化 lst1=[x for x in range(1:100:2)]  
3. 字典的操作，添加/删除/更改/获取所有的keys/获取所有的values  
    添加和更改方法一样，都是利用下标操作d1['a']=1， 删除用带索引的，所以不是remove而是pop/del, d1.pop('a') ,del d1['a']  
    key唯一，但values不唯一，怎么统计一个values出现了几次呢？ 怎样删除所有values的键值对呢？  
4. d1.keys()返回所有key，d1.values()返回所有value,返回值并不是列表类型，而是dict_keys和dict_values类型, 可以用list转换成list类的  
   list(d1.keys()), list(d1.values())  
5. 字典的key必须为常量，所以list不能做key，str/tuple/数字都可以做key  
6. 可以用一个序列创建一个字典 dict.fromkeys(seq1,value),这是个全局函数，使用返回值生成新的字典，缺点是所有value都一样，比较糟糕  
7. 可以自己写一个两个序列的参数，用于创建一个字典,后面去做吧.  
8. 如何遍历字典，两个方法，1. 拿到所有的keys，再一个找到值，很low 2. 用dict.items()遍历,方法如下  
    for key,value in d1.items():  
        print(key)  
        print(value)  
9. 字典怎么排序？ 字典没有顺序，所以不能直接改变字典的内容  
   需要用 sorted(dict.items(),key=lambda x:x[1],reverse=True/False)来实现，sorted生成新的链表  


```

#字典,字典初始化，用冒号
d1={'a':1,'b':2,'c':3}

d2=dict.fromkeys(['s1','s2','s3','s4','s5'],10)
print('dict.fromkeys（[s1,s2,s3,s4,s5],10）',d2)
#遍历,字典转list
lst5=[]
for d,v in d1.items():
    lst5.append(str(d)+':'+str(v))
print('use for d,v in d1.items() 遍历字典',lst5)

#操作包括 添加，删除，列出所有的key，列出所有的values，key是否在字典中

d1['lala']=9
print('d1[\'lala\']=9\t',d1)
d1.pop('a')
print('d1.pop(\'a\')\t',d1)

del d1['b'] #del也可以删除元素， 跟pop功能一样的，不存在可能会报错
print('del d1[\'b\']\t',d1)
print('list(d1.keys())\t',list(d1.keys()))
print('list(d1.values())\t',list(d1.values()))


#序列转换
s1='12345'
l1=list(s1) #l1变成了['1','2','3','4','5']
#怎样再转换回来呢, 不能用s2=str(l1)，得到的是'['1','2','3','4','5']'
#用字符串的join方法
print('怎样把[\'1\',\'2\',\'3\',\'4\',\'5\']转换成字符串\'12345\'')
print('.join(list1)连接内容为字符串的列表\t',''.join(l1))

#如果是整型list呢
print('怎样把[1,2,3,4,5]转换成字符串\'12345\'')
l3=[1,2,3,4,5]
#print(''.join(l3)) #只有字符串元素才能连接，其他类型不能连接,这里会报错
print(str(l3)[1::3])
s5=''
for x in l3:
    s5+=str(x)
#print(s5)

```  
数字  
====  
  
1. 算术运算符除了/和//与C不一样外, 其他完全相同  
2. 比较运算符与C完全一样，== != > < >= <=  
3. 位运算符与C完全一样 & | ~ ^  
4. 逻辑运算符， and or not，对应c语言的 &&,||,~  
5. is运算符，即是否指向同一个元素，很诡异  
6. math.ceil math.floor math.abs math.max math.min 数学函数

```
#is 运算符的例子
lsta=[]
lstb=lsta
lstb.append(1)
print('is运算符的例子：lsta is lstb\t',lsta is lstb)

```  
随机数函数  
=========  
  
1. 在random类中  
2. random.choice(seq） 返回seq中随机的一个元素  
3. random.random() 返回0-1之间的随机浮点数  
4. random.randrange(start,stop,step)  
5. random.shuffle(seq)，随机打乱seq，由于会改变seq的值，所以参数不能是str，tuple  
6. random.uniform(1.1,2.2) 

```

import random
print('randrange 10-20,step 2',end=': ')
for x in range(20):
    print(random.randrange(10,20,2),end='-')
print('\nrandom.choice(\'123456\'):',random.choice('123456'))

```  
迭代器类  
=======  
  
迭代器类 必需实现两个函数，一个是_inter_ 和 _next_, 以及实现 StopIteration 这个异常处理  
准确的说并不是定义一个迭代器，而是定义一个支持迭代器的类(带迭代器的类)。

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
        self.m_pos=-1 #创建迭代器的时候调用，所以这里必须初始化pos变量, 并且这里的pos只能被迭代器next修改
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
函数参数  
=======  
  
1.函数参数传递, 不变类型为值传递，可变类型类似引用传递，例如 a=10  b=a, 此时a is b， 但当b=20后，a is not b  
2.实际上，不管对什么，python的处理方式为，参数传递均为引用传递；但是与c不同的是，对于数字/元组/字符串，即使引用传进去，也是不能改变的，因此不管函数怎么加工，  
  都不可能改变外面的值； 但对于可变数据 list/dict/set这种，传进去后，是可以改变的，所以外面也跟着改了。 如果不想改就用copy。  
  像 a=10, b=a,此时b和a实际上id是一样的，当b=a+1，则b的id就变化了，也就是说只有b的值发生变化，则b就是一个新的对象。  
3. 匿名函数lambda,  lambda 参数1，参数2，参数3: 表达式处理,只能写一行  
4. 如果函数不返回，默认返回None, 实际上一个函数的返回值可以是不同分支不同类型，这一点很灵活.  
5. 可以用形参=xxx来调用函数，此时参数顺序可以与定义的不一致，比如 addperson(name='lxb',ag=2)  
6. 最灵活的边长参数来了, 如果参数前面带一个*，表示是变参，会以tuple的形式存起来，如果是** 会以字典形式存起来  
7. 如果查找函数名？  用 dir(包名) 就可以显示一个包中的所有符号，太方便了, 如果要显示函数用法用，help(list)查看或者help(list.sort)

```
a=10; b=a; assert id(a)==id(b)
b=10;      assert id(a)==id(b)
b=20;      assert id(a)!=id(b)
a=10; print('id-a',id(a)); a=a+1; print('id-a',id(a)) #这里a赋值发生变化后，id也发生了变化
str1='a'; str2=str1; assert id(str1)==id(str2)
def fun1(str):
    print(id(str))
    str='123'  #这里重新赋值后，str指向发生了变化
    print(id(str))
strr='lalala'
print(id(strr))
fun1(strr)
print('')
def fun2(lst:list):
    print(id(lst))
    lst=[2,3,4,5]  #这里重新赋值后，lst指向也发生了变化
    print(id(lst))
lst=[1]
print(id(lst))
fun2(lst)
print(lst)
#变参
import math
def averge(*para):
    return math.fsum(iter(para))/len(para)
print(averge(1,2,3,4,5,6))
#字典的例子
def addstudent(**para):
    print(para)
addstudent(name='liuxb',age=20,job='IT')

#数据结构, 倒叙遍历用reversed函数，并不改变原来的内容
lst1=[1,3,2,4,5]
for x in reversed(lst1):
    print(x,end=' ')
#如果想按顺序遍历，用sorted，并不改变原来的顺序
for x in sorted(lst1):
    print(x,end=' ')
#字典和集合怎么排序?
set1={1,4,3,2,6}
for x in sorted(set1,reverse=True):
    print(x,end=' ')
dic1=dict(a=1,c=3,b=2,f=5,e=9)
print(dic1)
for x,y in sorted(dic1.items(),key=lambda e: e[1]): #这里使用了匿名函数实现排序算法
    print(x,y,end=' ')
print('')
#两个序列同时遍历，用zip， 要求个数相同才行
for x,y in zip(lst1,set1):
    print(x,y)

```  
列表推导式,作用是：生成序列  
========================  
  
基本语法是： x for x in A if , 其中if可以去掉  
例如：  
    a=[1,2,3,4,5]  
    b=[x*2 for x in a if x>3]  
    c={x:x2 for x in range(1,10,2)} 创建字典  
还可以用双重循环，如  
    A=[1,2,3,4,5]  
    B=['a','b','c','d','e']  
    c={x:y for x in A for y in B}

```
A=[1,2,3,4,5]
B=['a','b','c','d','e']
c={x:y for x in A for y in B}
print(c)

#矩阵转向

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
#或者先取一个元素row，再取row里面的内容row[i]
bb=[[row[i] for row in matrix_a] for i in range(3,-1,-1)]  #这里两个for实际上是双重循环
print(bb)

```  
open(文件名,操作符),常用的是   
==========================  
  
    r+/rb+ 打开一个文件读写，指针放开头  
    [w+/wb+ 打开一个文件读写，指针放开头, 不存在就创建，存在也相当于重新创建，内容都不存在了]  
    a+/ab+ 打开读写，指针放尾巴，不存在就创建  
    不带b的时候，直接写字符串  
    带b的时候，直接写整数，如果写字符串，则 b'12345' 这种形式, b'\x65\x12'直接定义二进制  
    二进制有专门的类 Num.py 以及struct模块  
    os.acces 探测文件是否存在，是否可读，是否可写，是否可执行  
    os.listdir 列出目录下的文件  
    os.path.isfile 判断是否是文件，而非文件夹  
    os.walk 遍历文件夹  
    os.path.join 连接目录和文件成完整路径  
        

```
try:
    f=open('file1','rb+') #文件不存在会报错
    print(f)
except:
    print('file not exist')

f=open('file_wb+','wb+')  #文件不存在会创建
f.write(b'123456')
f.write(b'\x34')
f.close()
f=open('file_wb+','wb+')#使用文件再次打开后，里面的内容竟然没了？？？？？
```  
readdata=f.read(7)  
print(readdata)  
ddata=readdata.decode()  
print(ddata)

```
f.close()

f=open('file_w+','w+') #文件不存在会创建
f.write('123456')
f.close()

f=open('wr_test.txt','w+')
f.write('123\n456\n789\n')
f.writelines(['123\n','456\n','789\n']) #writelines需要自己加换行符，没什么用，可以直接用write取代
f.seek(0,0)
print(f.readlines())
f.close()
#真正的一个完善的代码
```  
写入文件测试  
------------------------------------------------  
  
    1. 判断文件在不在，不在，创建，在，打开  
    2. 判断是否具有修改权限，没有，打印错误，有，继续  
    3. 写文件，关闭

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

files=os.listdir() #只显示文件，不显示子目录
for x in files:
    if os.path.isfile(x):
        print(x)
```  
遍历文件夹，只列出文件, 用walk

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
  
如果open失败会返回异常， 如果write失败也返回异常，使用with...as后不必显式关闭文件和打开文件的异常，省了很多事  
原理: with func as obj   
----------------------   
第一步：obj=func().__enter()__   
第二步：当obj的任何操作遇到异常的时候,调用obj.__exit()__  
在上面的例子中,   
1. file=open().__enter__(), open这个函数返回一个file，预测它的__enter__()返回自己,    
2. 当file生命期结束时调用file.__enter__(),    
3. 出异常时调用 file.__exit__(), 文件的close操作放在__exit__()中  
   那么不出异常时会调用__exit()__吗？ 如果不会就没有关闭file, 来测试一下，测试结果，当with as程序块执行结束时，会调用__exit__  
4. with as用于成对的操作，如果打开/关闭  lock/unlock  数据库操作/回滚，这种  
5. 实际测试表明，即使出现异常调用了__exit__, 类的析构函数__del__仍然会在最后调用, 因此在关闭资源的时候，不要重复处理  
    with as 的原理 https://blog.csdn.net/weixin_33921089/article/details/91454127?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task  
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
    print('here 002')  #实际测试，当with....as 程序块结束时，会调用__exit__
```  
    自定义异常，用自定义的异常继承 Exception

```
class MyException(Exception):
    def __init__(self):
        pass
    def __str__(self):
        return 'except by myself!'
try:
    raise MyException
except MyException as err:
    print(err) #这里会显示 except by myself

```  
内部函数(builtins)  
============================================  
  
1.类的私有变量加2个下划线，私有方法也一样  
2.类内部使用类变量时，一律加 self.前缀  
类的专有方法  
  
    __init__ :  构造函数，在生成对象时调用  
    __del__ :   析构函数，释放对象时使用  
    __repr__ :  打印，转换  对应print  
    __setitem__ : 按照索引赋值  
    __getitem__: 按照索引获取值  
    __len__:    获得长度    对应 len(class)  
    __cmp__:    比较运算    对应(>,<,=,!=的比较)  
    __call__:   函数调用     
    __add__:    加运算      对应+操作  
    __sub__:    减运算      -  
    __mul__:    乘运算      *  
    __truediv__: 除运算  /  
    __mod__:    求余运算    %  
    __pow__:    乘方       **  
      
3. 直接定义在类中的变量是 类变量，不是对象变量，同样没有self的函数是类函数

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
命名空间namespace  
==================  
  
built-in namespace  
global namespace  
local namespace  
python查找顺序为： local namespace->global namespace->built-in namespace，所以可以使用相同的名字  
  
作用域 scope  
--------------  
L（Local）：最内层，包含局部变量，比如一个函数/方法内部。  
E（Enclosing）：包含了非局部(non-local)也非全局(non-global)的变量。比如两个嵌套函数，一个函数（或类） A 里面又包含了一个函数 B ，那么对于 B 中的名称来说 A 中的作用域就为 nonlocal。  
G（Global）：当前脚本的最外层，比如当前模块的全局变量。  
B（Built-in）： 包含了内建的变量/关键字等。，最后被搜索  
Python 中只有模块（module），类（class）以及函数（def、lambda）才会引入新的作用域，其它的代码块（如 if/elif/else/、try/except、for/while等）是不会引入新的作用域的，也就是说这些语句内定义的变量，外部也可以访问，如下代码：  
    >>> if True:  
    ...  msg = 'I am from Runoob'  
    ...   
    >>> msg  
    'I am from Runoob'  
    >>> 

```
# 命名空间测试
Exception=Exception('hello,world')
print(Exception)

liuxb='magi'
def test():
    liuxb='hello'
    print(liuxb)
print(liuxb)
test()
#这里两个 liuxb不一样，一个内部，一个外部, 如果想指向外部变量怎么办？ 用global修饰一下

liuxb='magi'
def test():
    global liuxb
    liuxb='hello'
    print(liuxb)
test()
print(liuxb)

```  
正则表达式  


```
import re
print(re.match('www', 'www.runoob.www'))  # 在起始位置匹配
print(re.match('com', 'www.runoob.com'))  # 不在起始位置匹配
print(re.split('[\W]+',',dogs , are not cats,')) #多出两个""
print(re.split('[\W]+',' dogs , are not cats '.strip(' ')) )#多出两个""

tl=[1,1,2,2,2,3,3,3,3,3,4,4,4,4,5,5,5,5,5,6,6]
print(str(tl))
import re
#结果为'1,1' '2,2,2'  '3,3,3,3,3'  '4,4,4,4' '5,5,5,5,5' '6,6' 每次返回的是匹配的字符串，可以看出iter不关心分组信息
obj=re.finditer(r'(\d+)(,\s\1)*',str(tl))
for x in obj:
    print(x)

#结果为['1','2','3','4','5','6'],可以看出findall会返回分组中的数据，不在分组中不处理
match=re.findall(r'(\d+)(?:,\s\1)*',str(tl))
print(match)

```  
正则表达式基础(regular pattern)  
==============================  
  
^   匹配行开头  
$   匹配行结尾  
\d  匹配一个数字  
\w  匹配一个数字或字母，包括下划线，可以用来匹配关键字，变量名这种  
\D  非数字，等同于[^0-9]  
\W  非数字,非字母,非下划线,等同于[^0-9a-zA-Z_]  
\s  匹配一个空格/TAB键/退格符等非可见字符  
\S  匹配非空白字符  
.   匹配1个任意字符  
.*  匹配任意多个字符  
.*? 非贪婪模式匹配任意长度字符，比如 "123，456，789"   
              用.*匹配全部   
              *?匹配每一个字符   
              .*,匹配 123,456    
              .*?,匹配123 和 456  
\b 匹配单词边界，例如 \b\w+\b 匹配一个单词, \b\S+\b 匹配单词(单词内容可以为特殊字符&^^%)  
{n,m} 匹配最小n次，最多m次  
分组和前向引用 (第一组)\1 后面的\1表示引用第1组的内容，适用于 10 10 10 10 20 20 20 20这种把10 10 10 10一次性提取出来  
  
1. match 和 search均返回match对象, match对象的group(0)表示完全匹配的内容，group(1)表示第1个分组,group(2)表示第2个分组  
2. match和search都是只匹配一次，找到一个匹配的就停止  
3. match只从头匹配，而search可以从中间匹配  
4. findall返回的是一个list，每个元素是一个str，如果存在分组，则每个愿随是一个tuple(group1,group2)  
5. finditer返回的是一个iter, 什么的iter？ match的iter，match结构中又有group  
6. 只有findall是指返回分组的内容，没有分组就是返回所有匹配项，所以它的用途在分组上  
7. 如果既想要分组，又想要匹配项，则使用finditer，这个是功能最强大的  
8. findall的好处是，你不用关心分组名了，都给放到list的tuple里了(如果有多个分组的话)  
9. 正则表达式，先分析规律，写出规律，再转换成pattern  
|修饰符|描述  
|re.I|使匹配对大小写不敏感|  
|re.L|做本地化识别（locale-aware）匹配|  
|re.M|多行匹配，影响 ^ 和 $|  
|re.S|使 . 匹配包括换行在内的所有字符|  
|re.U|根据Unicode字符集解析字符。这个标志影响 \w, \W, \b, \B.|  
|re.X|标志通过给予你更灵活的格式以便你将正则表达式写得更易于理解。|

```
mt=re.match('\d{2}','12345')
print(mt.group()) #返回的是 ‘12’
mt=re.search('\d{2}','12345')
print(mt.group())#返回的也是‘12’
mlst=re.findall('\d{2}','12345')
print(mlst) #返回的是['12','34']
#finditer的返回值是个iter，每个元素都是一个match，用group()来获取数据
mit=re.finditer('\d{2}','12345')
for x in mit: print(x.group()) #返回值为  ‘12’  和 ‘34’
```  
带分组的测试  
===========  
  
    mt=re.match(r'(\d{2}),'12345')  
    print(mt.group()) #返回的是 ‘12’  
    mt=re.search('\d{2}','12345')  
    print(mt.group())#返回的也是‘12’  
    mlst=re.findall('\d{2}','12345')  
    print(mlst) #返回的是['12','34']  
    #finditer的返回值是个iter，每个元素都是一个match，用group()来获取数据  
    mit=re.finditer('\d{2}','12345')  
    for x in mit: print(x.group()) #返回值为  ‘12’  和 ‘34’

```
mt=re.match(r'5(\d{2})','54321')
print(mt.group()) #这里返回的是543
print(mt.group(1)) #这里返回的是43

mt=re.search(r'5(\d{2})','54321')
print(mt.group()) #这里返回的是543
print(mt.group(1)) #这里返回的是43

mlst=re.findall(r'5(\d{2}(\d))','54321')
print(mlst) #这里返回的是 [('432','2')]

mlst=re.findall(r'\d{2}','54321')#没有分组的清空
print(mlst) #这里返回的是 ['54',32']

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