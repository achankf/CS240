IN= $(shell find -name "*.tex")
OUT= $(IN:.tex=.pdf)

all: $(OUT)
%.pdf:%.tex
	pdflatex $<
	pdflatex $<

.phony: clean
clean:
	rm -f *.{log,aux}
cleanall:clean
	rm -f *.pdf
