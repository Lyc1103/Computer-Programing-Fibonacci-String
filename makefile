all :
	gcc FabonacciString_Version1.c -o fs1
	gcc FabonacciString_Version2.c -o fs2
clean :
	del -f fs1.exe fs2.exe