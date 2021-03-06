+ Lesson 1:
    * 域名与IP的转换
        + DNS与ISP
        + DNS record cache和IP改变 网站重定向
        + DNS record 类型和google Apps外包服务
	* 虚拟主机服务和共享主机服务下的安全和效率问题
    * 网站开发中的多浏览器兼容问题

+ Lesson 2
    * http header 信息（使用firebug查看）
	* Host一行：当同一台服务器（即同一个IP）对应多个网站（即域名）用于区分是将服务请求交给这个服务器上的那个站点。
	* 文件权限 访问者的身份设置与网站的权益。
	* 永久重定向问题
	* 进入PHP模式：<?php ... ?>
    * php 的超全局变量(数组类型）： $_REQUEST  $_POST $_GET
    * php表单提交方式POST和GET的区别（安全方面的考虑：服务器日志 浏览器记录浏览器兼容问题：url长度的限制）
	* http的表单提交策略和超全局变量的使用（对于多值选项的操作）
        + checkbox只有在checked时才会出现在起提交的参数中。
        + list对应的选值是一个数组类型
        + isset函数的使用
        + @前缀前缀的使用（强制php不论如何 只管静默地往下执行）
        + print print_r echo 函数
	* 测试与发布
        + 开启错误report功能
			```php
            <?php 
                error_reporting( E_ALL );
                ini_set( "display_errors" TRUE );
            ?>
			```
        + 不要让用户知道您自身存在的不安全隐患i。

+ lesson 3
    * 目录管理与网站安全( /etc /html /include )
    * xml能够通过DTD对文档内容进行校验
    * 对于少量的数据 可以使用xml文档来代替数据库的功能。
	* 隐藏解释器和服务器的软件版本信息来避免安全隐患。
	* php：session_start()告诉网路服务器记住此用户。（涉及到超全局变量 $_SESSION）
	* 登录或者是注册页面使用https而不是http可以减少因为cookie带来的安全隐患
        （SSL：同时也会对hostname进行加密 这就造成也各IP上只能有一个https网站 例外的是子域名的情况）
    * 判断一个用户是否已近登录了 使用 if( $SESSION["authenticated" ){...} [需要先调用 start_session() 函数]
    * php constant defination formate 'define( "constant_name" "constant_value" )'
    * 对值进行访问之前首相调用isset判断相应的变量是否已经有效。
	* 使用php进行重定向：
        ```php
	$host = $_SERVER["HTTP_HOST"];
        $path = rtrim( dirname( $_SERVER["PHP_SELF"] ) "/\\");
        header("Location: http://$host$path/home.php");
        exit;
	```
	*1 使用count( $_POST )是否为0来判断是否是用户出错了。
	*2 在处理用户输入的时候 注意可能存在服务器端错误地对用户的输入进行解释 导致了服务器执行了用户输入的代码 或者是可能用户的输入导致了网页代码结构被破坏 更有甚者是用户进行SQL注入对网站进行攻击。解决方法：调用php函数: htmlspecialchars()来处理用户的输入;

+ lesson 4
    * 拓展库：ExtJS JQuery YUI Mootools
    * 强制XML解释器不解释某段文本 而仅仅是当作是普通的字符来进行处理 这对于javascript开发以及在xml方便 '<' '?' '>' 等字符的使用非常有效
        语法: <![CDATA[ ... ]]>
    * child element or attribute: 如果XML的某个值需要经常被访问 那么应该设置成为attribute因为attribute更容易访问。当然 attribute是不可拓展的 而child element是可以拓展的。
	* 使用simpleXML处理xml文档
        + 载入xml文档 获得dom数据结构：simplexml_load_file( "path_to_xml_file" );
		+ 访问xml中的child element：使用php中的foreach函数
			```php
            foreach( $dom->child_elem as child ){ .... }
			```
        + 访问xml中的attribute：
			```php
            child[ "attribute_name" ];
			```

+ lesson 5
    * php中require和include的区别：
        require_once / require:文件必须存在 否则会直接出错这往往是我们希望的(推荐使用）
        include_once / include:文件不存在是会忽略include请求 而不会终止php继续执行。
        [ *_once：函数存在性能上的缺陷]
    * xpath的id属性不能以数字开头
	* php中进行xpath查询：
        $dom->xpath( "/child::root_element/child::child_element[ @attribute == ‘predict_value' ]" );
        执行将返回纯在数组中的结果集(上面的'child::'是非必要的 因为默认的轴是child:: )
    * fgetcsv & fputcsv & fopen
    * 判断数据的类型 同时判断数据的值( !== === );
    * php & mysql function:
		```php
        mysql_connect( "hostname" "user_name" "passwd" );
        die( "prompt sentence" );
        mysql_select_db( "database_name" );
        sprintf("format" ... );
        mysql_real_escape_string( "string" );  // 用来避免SQL注入攻击
        mysql_query("query string" );
        mysql_error();
        mysql_num_rows( $mysql_result );
        mysql_fetch_asso( $mysql_result );    // 将sql查询得到的结果转化为数组
		```
+ lesson 6
    * PASSWORD()对用户密码进行简单的加密（采用的是文本的加密方式 得到的是varchar）
	* AES_ENCRYPT()非常安全的加密方法（采用的是二进制的加密方式 加密后得到的是varbinary类型的数据）
        注意：@1 需要特别注意的是二进制数据在转移时比较容易出现问题 需要特别注意数据的类型。
              @2 AES_ENCRYPT()函数有两个参数 第二个参数作为加密的密匙 利用这个密匙可以调用AES_DECRYPT()进行解密 因此通常是将用户的密码作为AES_ENCRYPT的两个参数
	* 从长远的角度来考虑 尽量使用UTC时间
    * 尽量使用简单的数据类型 提高可移植性。
	* database: inner join cross join left outer join right outer join
    * 处理金融数据时因该注意数据的精度 舍入问题 以及race condiction(transaction)

+ lesson 7
    * session劫持
	* javascript执行与浏览器对DOM对象构建的顺序决定javacript代码放置的位置
    * javascript的UI库
	* javascript浏览器兼容库
	* javascript中使用css样式（驼峰式转换）
	* javascript压缩。

+ lesson 8
    * Ajax对象在不同浏览器之间的支持问题：
        IE使用的是ActiveX 其它浏览器采用 XMLHttpRequest
	* 根据同源策略 Ajax只能访问当前页面站点的数据
	* 跨站脚本攻击
	*  JSON
	*  header:Content-type: ....
    * google map javascript API

+ lesson 9
    * suPHP
    * 针对于当前很多网站都是采用https作为登录和注册 但是其它的都是http 那么用户上次登录通过https获得的session cookie如果没有被标记为secure（通过服务器端设置） 那么用户下次登录时就可能由浏览器明文发送session cookie 从而使用户处在不安全的环境中。
	* 防御式开发：不相信任何用户输入 时刻不忘记转义用户的输入和给用户的输出。
    * 伪造请求（GET方法）
    
+ lesson 10
    * memcached服务器 用来缓存php解释后的html 这样避免了每次访问都需要重新解释php文件。
	* RAID磁盘冗余矩阵
	* 对于服务器的可规模化 可以从硬件反面和软件方面下手 硬件方面通过购买高性能的硬件解决 而软件反面则是通过将问题进行分解 然后协调多个性能并不是很优越的机器高效解决问题。（HAPOOD）
	* load balancing
    * HAProxy:实现轮询调度
	* mysql memory cache: mem_cache_set
    * read >> write
    * 分割用户群
	* floating IP


