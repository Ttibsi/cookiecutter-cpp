import os
import shutil
import subprocess

def main():
    if not {{cookiecutter.docker}}:
        os.remove("Dockerfile")
        os.remove("Makefile")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
