
.PHONY: build
build:
	bsb -make-world

.PHONY: start
start:
	bsb -make-world -w

.PHONY: clean
clean:
	bsb -clean-world

.PHONY: test
test: build
	./node_modules/.bin/jest
