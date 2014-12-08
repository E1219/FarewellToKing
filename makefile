all: flyByKnightLib

flyByKnightLib: flyByKnightLib.c
	gcc -c flyByKnightLib.c

test: flyByKnightLib.o flyByKnightLibTest.c
	gcc flyByKnightLib.o flyByKnightLibTest.c -o flyByKnightLibTest

clean:
	rm -f *o flyByKnightLibTest

runtest: test
	./flyByKnightLibTest
