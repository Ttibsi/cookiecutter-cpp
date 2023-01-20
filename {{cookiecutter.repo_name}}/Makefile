BINARY := {{cookiecutter.exec_name}}
REPO := {{cookiecutter.repo_name}}
ENV_NAME := $(REPO)_env

.PHONY: all
all: help

help:
	@grep -E '^[a-zA-Z0-9 -]+:.*#'  Makefile | sort | while read -r l; do printf "\033[1;32m$$(echo $$l | cut -f 1 -d':')\033[00m:$$(echo $$l | cut -f 2- -d'#')\n"; done

testenv: # Build a docker environment
	@echo "[Create Env]"
	docker build -f Dockerfile -t env .
	docker run -td --name=$(ENV_NAME) env

generate: testenv # Run CMake in a docker env
	@echo "[Running CMake]"
	docker exec $(ENV_NAME) cmake -DRUN_TESTS=OFF -S /$(REPO)/ -B build/

create: generate # Make the pre-generated makefiles in the docker env
	@echo "[Running generated Makefile]"
	docker exec --workdir="/$(REPO)/build/" $(ENV_NAME) make

run: create
	docker exec $(ENV_NAME) ./build/src/$(BINARY)

local-build: # Build repo locally to build/
	@echo "[Building to build/]"
	rm -rf build
	mkdir build
	cd build; \
	cmake .. && make

env: # Connect to the pre-existing testenv in a tty
	@echo "[Launch existing TTY]"
	docker exec -ti $(ENV_NAME) bash

docker-clean: # Remove docker environments
	@echo "[Removing container]"
	docker kill $$(docker ps -q)
	docker container prune -f
