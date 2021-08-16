from setuptools import Extension
from setuptools import setup

setup(
    ext_modules=[Extension('_rename_exchange', ['_rename_exchange.c'])],
)
