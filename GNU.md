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

----

```c++
#include <stdio.h>
#include <stdlib.h>

void exit_func()
{
	printf("process is exiting!\n");
}

int main(int argc, char* argv[])
{
	atexit( exit_func );	

	return 0;
}
```
----
```c++
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>

int main(){
	int fn_out = open("./append.txt", O_WRONLY | O_TRUNC | O_CREAT );
	
	char buf1[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char buf2[] = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";

	lseek( fn_out, 0, SEEK_SET );
	size_t written = write( fn_out, buf1, sizeof(buf1) );
	printf("%d %d\n", sizeof(buf1), written);
	//assert( written == sizeof(buf1) );

	lseek( fn_out, 4000, SEEK_END );
	written = write( fn_out, buf2, sizeof(buf2) );
	printf("%d %d\n", sizeof(buf2), written);
	//assert( written == sizeof(buf2) );

	close( fn_out );

	return 0;
}
```
