all:
	cl /c LinkedList.cpp
	lib /OUT:LinkedList.lib LinkedList.obj
	cl /c test.cpp
	link test.obj LinkedList.lib
	test

library:
	cl /c LinkedList.cpp
	lib /OUT:LinkedList.lib LinkedList.obj

clean:
	del *.obj
	del *.exe
	del *.lib
