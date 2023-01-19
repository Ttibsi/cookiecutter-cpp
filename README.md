# cookiecutter-cpp

A cookiecutter to setup all the default files I use in a c++ repo. This 
includes my clang setup, CMake, pre-commit, and a dockerfile for ubuntu 
development

### How to use
Run the below command in a clean repo (it's all one line, just copy and paste
the whole block into your terminal)

```bash
python3 -m virtualenv venv && \
. venv/bin/activate && \
pip install cookiecutter \
&& cookiecutter gh:ttibsi/cookiecutter-cpp \
&& deactivate && \
rm -rf venv && \
mv template/* . && \
mv template/.* . && \
rmdir template
```
