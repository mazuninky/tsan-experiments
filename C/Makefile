tsan_example1:
	clang++ example1.c -fsanitize=thread -fPIE -pie -g  -O0 -o tsan_out1.a

example1:
	clang++ example1.cpp -O0 -o out1.a

dis1:
	otool -tVv out1.a > out1.asm

tsan_dis1:
	otool -tVv tsan_out1.a > tsan_out1.asm

tsan_example2:
	clang++ example2.c -fsanitize=thread -fPIE -pie -O0 -o tsan_out2.a

example2:
	clang++ example2.cpp -O0 -o out2.a

tsan_example4:
	clang example4.c -fsanitize=thread -fPIE -pie -g -O1 -o tsan_out4.a

tsan_example5:
	clang example5.c -fsanitize=thread -fPIE -pie -g -O1 -o tsan_out5.a

tsan_example6:
	clang example6.c -fsanitize=thread -fPIE -pie -g -O1 -o tsan_out6.a

tsan_example7:
	clang++ example7.cpp -fsanitize=thread -fPIE -pie -g -o tsan_out7.a; ./tsan_out7.a

example7:
	clang++ example7.cpp -o tsan_out7.a; ./tsan_out7.a

tsan_example8:
	clang example8.c -fsanitize=thread -fPIE -pie -g -O1 -o tsan_out8.a