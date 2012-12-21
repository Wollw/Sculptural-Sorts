TARGET=proposal

all:
	pdflatex $(TARGET).tex
	bibtex $(TARGET)
	pdflatex $(TARGET).tex

clean:
	rm $(TARGET).{pdf,aux,log,bbl,blg}
