SRC=$(wildcard *.tex)

report.pdf:	report.tex $(SRC)
	pdflatex report.tex
	pdflatex report.tex

clear:
	rm *.log *.aux *.out *~ *.toc
