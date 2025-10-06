all:
	flex unit.l
	bison -d unit.y
	gcc unit.tab.c lex.yy.c -o cmp
