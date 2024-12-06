# 컴파일러 및 플래그
CC = gcc
FLEX = flex
BISON = bison

# 파일 이름
LEX_FILE = tokenizer.l
BISON_FILE = parser.y
OUTPUT = parser

# 생성되는 파일
BISON_C = parser.tab.c
BISON_H = parser.tab.h
LEX_C = lex.yy.c

# 기본 실행 규칙
all: $(OUTPUT)

# Bison 파일 컴파일
$(BISON_C) $(BISON_H): $(BISON_FILE)
	$(BISON) -d $(BISON_FILE)

# Flex 파일 컴파일
$(LEX_C): $(LEX_FILE) $(BISON_H)
	$(FLEX) $(LEX_FILE)

# 최종 실행 파일 생성
$(OUTPUT): $(LEX_C) $(BISON_C)
	$(CC) -o $(OUTPUT) $(LEX_C) $(BISON_C) -lfl

# 정리 규칙
clean:
	rm -f $(OUTPUT) $(LEX_C) $(BISON_C) $(BISON_H)

