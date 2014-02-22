Linux Commands
===============
## <code>netstate</code>
<code>netstate</code> 提供与connection, interface, multicast, masquerade, rooute, statistic相关信息。
```vim
usage: netstat [-vWeenNcCF] [<Af>] -r         
       netstat {-V|--version|-h|--help}
       netstat [-vWnNcaeol] [<Socket> ...]
       netstat { [-vWeenNac] -i | [-cWnNe] -M | -s }
```
以下6个选项对应于各个主要功能，他们之间彼此互斥
```vim
        None                     display connections
        -r, --route              display routing table
        -i, --interfaces         display interface table
        -g, --groups             display multicast group memberships
        -s, --statistics         display networking statistics (like SNMP)
        -M, --masquerade         display masqueraded connections
```
近似的通用结果处理选项        
```vim
        -v, --verbose            be verbose
        -W, --wide               don't truncate IP addresses
        -n, --numeric            don't resolve names
        --numeric-hosts          don't resolve host names
        --numeric-ports          don't resolve port names
        --numeric-users          don't resolve user names
        -N, --symbolic           resolve hardware names
        -e, --extend             display other/more information
        -p, --programs           display PID/Program name for sockets
        -c, --continuous         continuous listing
```
状态筛选选项
```vim
        -l, --listening          display listening server sockets
        -a, --all, --listening   display all sockets (default: connected)
        -o, --timers             display timers
        -F, --fib                display Forwarding Information Base (default)
        -C, --cache              display routing cache instead of FIB
```
```
  <Socket>={-t|--tcp} {-u|--udp} {-w|--raw} {-x|--unix} --ax25 --ipx --netrom
  <AF>=Use '-6|-4' or '-A <af>' or '--<af>'; default: inet
  List of possible address families (which support routing):
    inet (DARPA Internet) inet6 (IPv6) ax25 (AMPR AX.25) 
    netrom (AMPR NET/ROM) ipx (Novell IPX) ddp (Appletalk DDP) 
    x25 (CCITT X.25)
```
Example
查看某一端口的状态、关联的程序、进程信息
```console
junze@debian:~/Desktop$ sudo netstat -4 -nap | grep 3306
tcp        0      0 127.0.0.1:3306          0.0.0.0:*               LISTEN      3087/mysqld
```
显示路由表信息
```console
junze@debian:~/Desktop$ netstat -nr
Kernel IP routing table
Destination     Gateway         Genmask         Flags   MSS Window  irtt Iface
0.0.0.0         172.18.71.254   0.0.0.0         UG        0 0          0 eth0
172.18.68.0     0.0.0.0         255.255.252.0   U         0 0          0 eth0
```
查看网络接口信息:
```console
junze@debian:~/Desktop$ netstat -i
Kernel Interface table
Iface   MTU Met   RX-OK RX-ERR RX-DRP RX-OVR    TX-OK TX-ERR TX-DRP TX-OVR Flg
eth0       1500 0    143692      0      5 0         23894      0      0      0 BMRU
lo        16436 0      3020      0      0 0          3020      0      0      0 LRU
junze@debian:~/Desktop$ sudo ifconfig eth0
eth0      Link encap:Ethernet  HWaddr 88:ae:1d:1f:71:c6  
          inet addr:172.18.71.199  Bcast:172.18.71.255  Mask:255.255.252.0
          inet6 addr: 2001:250:3002:4500:8aae:1dff:fe1f:71c6/64 Scope:Global
          inet6 addr: fe80::8aae:1dff:fe1f:71c6/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:148122 errors:0 dropped:5 overruns:0 frame:0
          TX packets:24367 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:47719204 (45.5 MiB)  TX bytes:3034244 (2.8 MiB)
          Interrupt:17 
```

## [<code>tcpdump</code>](http://www.danielmiessler.com/study/tcpdump/) - dump traffic on a network
<code>tcpdump</code>的命令行参数主要包括两大部分，其一是输出控制，其二是筛选控制
### 输出格式控制
```vim
-i any	: Listen on all interfaces just to see if you're seeing any traffic.
-A	: Print each packet (minus its link level header) in ASCII.  
	  Handy for capturing web pages.
-n	: Don't resolve hostnames.
-nn	: Don't resolve hostnames or port names.
-X	: Show the packet's contents in both hex and ASCII.
-XX	: Same as -X, but also shows the ethernet header.
-v, -vv	: Increase the amount of packet information you get back.
-c 	: Only get x number of packets and then stop.
-s 	: Define the snaplength (size) of the capture in bytes. 
	  Use -s0 to get everything, unless you are intentionally capturing less.
-S 	: Print absolute sequence numbers.
-e 	: Get the ethernet header as well.
-q 	: Show less protocol information.
```
### 筛选控制
#### 协议过滤
```shell
tcpdump tcp
```
#### 网段过滤 or 主机地址过滤
```shell
tcpdump ip -i any net 127.0.0/24
tcpdump ip -i any host 127.0.0.1
``` 
#### 端口过滤 <code>port | portrage</code>
#### 方向过滤 <code>dst | src</code>

#### 筛选逻辑组合 <code>and | or | not </code>
#### 筛选的高级选项 <code>grouping | tcp header</code> 
#### 其他
```vim
-D	: Print the list of the network interfaces available on the system and on
	  which tcpdump can capture packets.
```

## [<code>lsof</code>](http://www.danielmiessler.com/study/lsof/) - list open files
