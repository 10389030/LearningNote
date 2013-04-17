Design Pattern
==============
+ Chapter 0: 什么是设计模式
	> 设计模式的四个基本要素：pattern name, problem, solution, consequences。  
	> MVC设计模式：M(Model: 应用对象), V(View: 显示), C(Control: 响应用户输入)  
	> V和M的分离：使用Observer模式  

+ Chapter 3: 创建型模式
	> 抽象了实例化对象的过程。将对象的创建，组合和表示独立出来。  
	> **将系统使用那些具体的类的信息封装起来，将对象时如何被放在一起的信息隐藏起来**。   
	> 当对象的复合变得重要的时候，创建型模式也会变得重要起来。 
	> 通过创建型模式可以创建基本的行为集，这些行为集可以被组合成任意数目的更加复杂的行为。  
	> key word: **基本行为集**， **复合** 

	* Abstract Factory(抽象工厂): 提供一个创建一系列相关或相互依赖对象的接口，而无需制定是哪个类实现了这些接口。
	>		Application::createInstance(AbstractFactory);	// AbstractFactory only provide interface for dynamical binding  
	>		[It is a good idea to apply singleton pattern along with Abstract Factory pattern]  
	* Builder: 适用于允许利用相同的（构造）信息创建不同的（表示）对象, 使用方式类同Abstract Factory
	* 参数化工厂
			Product Factory::createor(ProductID);
	+ Prototype: 通过对象的Clone来创建对象，而不是通过构造器来创建。
	+ Singleton: 只能通过static method 来获得唯一的可以全局访问的实例。

+ Chapter 4: 结构型模式
	* Adapter: 将一个接口转换成另一个接口。
	* Bridge: 将抽象接口和具体的实现分离，也就是抽象和实现分属于不同的继承体系。
	* Composite: 可以递归地组合出更大的部件，（保持子部件到父部件的应用可以简化遍历过程）
	* Decorator:
	* Facade(外观): 用于划分出子系统，并对外提供统一的接口。
	* FlyWeight: 共享对象
	* Proxy:

+ 行为模式		
	* Responsibility Chain Link: 类似javascript中的消息冒泡，一般联同Composite使用
	* Command(Action, Transaction): 会掉机制的面向对象替代品
	* Interpretor: 
	* Mediator: 中间人，为对象之间的交互提供渠道。一般将Mediator实现为Observer。 
	* Memonto: 备忘录模式
	* Observer: (一个对象发生改变，依赖于该对象的所有其他对象都会收到通知)
	* state: auto-machine.
	* strategy: encapsulated algorithm.
	* template method: 将算法分成几个部分，通过继承某一部分来修改程序的行为。
	* visitor:
