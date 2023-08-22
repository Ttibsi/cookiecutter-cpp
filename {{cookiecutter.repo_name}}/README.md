# {{cookiecutter.repo_name|upper}}

### HOW TO RUN
{% if cookiecutter.docker %}
Prerequisites: `Docker`, `Make`

```bash
make testenv run
```
{% else %}
Prerequisites: `cmake`, `make`
{% if cookiecutter.tests %}
```bash
cmake -DRUN_TESTS=OFF -S /{{cookiecutter.repo_name}}/ -B build/
( cd build && make )
./build/src/{{cookiecutter.exec_name}}
```
{% else %}
```bash
cmake -S /{{cookiecutter.repo_name}}/ -B build/
( cd build && make )
./build/src/{{cookiecutter.exec_name}}
```
{% endif %}
{% endif %}
