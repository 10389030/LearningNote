UNIX Programming
============
```c++
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main()
{
	int f1 = open("/dev/random", O_WRONLY );
	int f2 = open("/dev/random", O_WRONLY );

	close( f2 );

	int f3 = open("/dev/random", O_WRONLY );

	cout << f1 << " " << f2 << " " << f3 << endl;

	return 0;
}

/**
 * junze@debian:~/Desktop$ g++ fd-alloc.cpp 
 * junze@debian:~/Desktop$ ./a.out 
 * 3 4 4
 *
 * ==========================
 * @comment
 *	System will alloc the min-avalidable FD when you require for a new one.
 *	By default, STDIN(0), STDOUT(1), STDERR(2)
 * @note
 * 	FD -> FILE*:	fdopen()
 * 	FILE* -> FD:	fileno()
 */

```
