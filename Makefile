.PHONY: install jupyter

install: requirements.txt
    pip install -r requirements.txt

jupyter:
    jupyter lab

