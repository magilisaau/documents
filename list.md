| 序号 | 功能/语言        | Python                                                       | C                                                            |
| ---- | ---------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 1    | 插入             | .insert(  i, e )                                             | 1.  insert( it, e )，这里的it代表迭代器Iterator，不是整型.     <br />2. 从另一个链表中插入一段 insert( it_pos, it_start, it_end） |
| 2    | 索引删除         | .pop(  i )                                                   | .erase(  iterator)                                           |
| 3    | 删除一段         | 1.  list[a:b]=[]     2. del list[a:b]                        | .erase(it_start,it_end)                                      |
| 4    | 删除元素         | .remove(  e )，只会删除第1个符合条件的元素                   | .remove(  e ), c++会删除所有的e                              |
| 5    | 清空             | .clear()                                                     | .clear()                                                     |
| 6    | 遍历             | 正序：for  x in list：print(x)                        倒序：for i in range(-1, -len-1, -1): print( list[ i ] ) | 正序1： for (int x:lst) cout<<x；     <br />正序2： for(list<int>::iterator it=lst.begin();    it!=lst.end();  it++) {cout<<*it; }     <br />倒序 ：for(… it=lst.rbegin(); it!=lst.rend(); it++) |
| 7    | 切片             | list[  start : end : step]                                   | list1.asign(it_start,it_end)                                 |
| 8    | 排序             | .sort(key=lambda)      <br /> 假设y=f(x), lambda返回的是y    | .sort(cmp),  cmp返回bool,小于返回true                        |
| 9    | 逆序             | .reverse()                                                   | .reverse()                                                   |
| 10   | 删除重复         | set(list)，转换成集合                                        | list.unique()                                                |
| 11   | 查找             | .index(  e )                                                 | .find(  e )返回it                                            |
| 12   | 链表长度         | len(  list )                                                 | .size()                                                      |
| 13   | 单个元素个数     | .count(  e )                                                 | .count(  e )                                                 |
| 14   | 拷贝链表         | .copy()                                                      | ='  直接用赋值                                               |
| 15   | 取第一个元素     | list[  0 ]                                                   | list.front()                                                 |
| 16   | 取最后一个元素   | list[-1]                                                     | list.back()                                                  |
| 17   | 删除第一个元素   | list.pop(  0 )                                               | list.pop_front()                                             |
| 18   | 删除最后一个元素 | list.pop(  -1 )                                              | list.pop_back()                                              |
| 19   | 左边插入元素     | list.insert(  0, e )                                         | list.push_front(  e )                                        |
| 20   | 右边插入元素     | list.append(  e )                                            | list.push_back(  e )                                         |
| 21   | 两链表合         | L=L1+L2                                                      | list1.merge(list2)                                           |