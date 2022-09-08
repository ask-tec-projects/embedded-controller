.PHONY: all
all: user_manual.pdf

%.pdf: %.tex %.includes/*
	latexmk $< -pvc -pdf -bibtex -output-directory=../
