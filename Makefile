# 컴파일러 및 플래그
CC = gcc
FLEX = flex
BISON = bison

# 파일 이름
FLEX_FILE = JackTokenizer.l
BISON_FILE = JackAnalyzer.y
OUTPUT = parser

# 생성되는 파일
BISON_C = JackAnalyzer.tab.c
BISON_H = JackAnalyzer.tab.h
FLEX_C = lex.yy.c

# 기본 실행 규칙
all: $(OUTPUT)

# Bison 파일 컴파일
$(BISON_C) $(BISON_H): $(BISON_FILE)
	$(BISON) -d $(BISON_FILE)

# Flex 파일 컴파일
$(FLEX_C): $(FLEX_FILE) $(BISON_H)
	$(FLEX) $(FLEX_FILE)

# 최종 실행 파일 생성
$(OUTPUT): $(FLEX_C) $(BISON_C)
	$(CC) -o $(OUTPUT) $(FLEX_C) $(BISON_C) -lfl

# 정리 규칙
clean:
	rm -f $(OUTPUT) $(FLEX_C) $(BISON_C) $(BISON_H)
