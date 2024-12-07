# 컴파일러 및 플래그
CC = gcc
FLEX = flex

# 파일 이름
FLEX_FILE = JackTokenizer.l
OUTPUT = tokenizer

# 생성되는 파일
FLEX_C = lex.yy.c

# 기본 실행 규칙
all: $(OUTPUT)

# Flex 파일 컴파일
$(FLEX_C): $(FLEX_FILE)
	$(FLEX) $(FLEX_FILE)

# 최종 실행 파일 생성
$(OUTPUT): $(FLEX_C) 
	$(CC) -o $(OUTPUT) $(FLEX_C)

# 정리 규칙
clean:
	rm -f $(OUTPUT) $(FLEX_C)
