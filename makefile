all:
	flex unit.l
	bison -d unit.y
	g++ unit.tab.c lex.yy.c -o cmp
