TARGET=statement

all:
	pdflatex -shell-escape $(TARGET).tex
	bibtex $(TARGET)
	pdflatex -shell-escape $(TARGET).tex

clean:
	rm $(TARGET).{pdf,aux,log,bbl,blg}
