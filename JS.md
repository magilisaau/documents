HTML 输出流中使用 document.write，相当于添加在原有html代码中添加一串html代码。而如果在文档加载后使用（如使用函数），会覆盖整个文档。



- ```
  使用 **window.alert()** 弹出警告框。
  使用 **document.write()** 方法将内容写到 HTML 文档中。
  使用 **innerHTML** 写入到 HTML 元素。
  使用 **console.log()** 写入到浏览器的控制台。
  ```



每一个标签都可以有一个id，id=“xxxx”, js可以获取到这个id

### 对象的定义

跟MAP一样， 由名称和value组成， 不同是可以内嵌方法

```
var person={
	firstname	:"John", 
	lastname	:"Dsoe", 
	id			:5566
    getnsame(){
         return this.firstname; //这里跟c++不一样了，c++用this->firstname
    	}
	};
```



## Undefined 和 Null

```
Undefined 这个值表示变量不含有值。

可以通过将变量的值设置为 null 来清空变量。
```

## JavaScript 变量的生存期

```
JavaScript 变量的生命期从它们被声明的时间开始。

局部变量会在函数运行以后被删除。

全局变量会在页面关闭后被删除。
```

