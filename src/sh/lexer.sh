flex -o ./build/lex.yy.cc ./src/lexer.l
g++ -o ./build/scanner ./build/lex.yy.cc
./build/scanner ./test/lexer/test1.sy
./build/scanner ./test/lexer/test2.sy
./build/scanner ./test/lexer/test3.sy
./build/scanner ./test/lexer/test4.sy
./build/scanner ./test/lexer/test5.sy
./build/scanner ./test/lexer/test6.sy
./build/scanner ./test/lexer/test7.sy
./build/scanner ./test/lexer/test8.sy