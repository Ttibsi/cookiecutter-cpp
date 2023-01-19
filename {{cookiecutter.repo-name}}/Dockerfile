#https://docs.docker.com/config/containers/multi-service_container/
FROM ubuntu:jammy

# hadolint ignore=DL3008
RUN apt-get update && apt-get upgrade -y && \
apt-get install --no-install-recommends \
cmake \
curl \
git \
g++ \
make \
neovim \
tree -y \
&& apt-get clean \
&& rm -rf /var/lib/apt/lists/*

COPY . /{{cookiecutter.repo-name}}/
WORKDIR /{{cookiecutter.repo-name}}
